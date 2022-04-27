/************************************************
 * MainWindow class
 * Class definition for MainWindow QWidget
 * Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/9/2022
************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPalette>
#include <QKeyEvent>
#include "player.h"
#include "startscreen.h"
#include "gamescreen.h"
#include <QSoundEffect>
#include <QGraphicsBlurEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(WIDTH, HEIGHT);

    // Set up start screen
    ui->startButton->setParent(ui->stackWindow->widget(0));
    ui->stackWindow->setCurrentIndex(0);

    connect(ui->gameplayScreen, &GameScreen::sendHydrationTimer, this, &MainWindow::receiveHydrationTimer);
    connect(ui->gameplayScreen, &GameScreen::sendCollideScreen, this, &MainWindow::CollideScreenDelay);
    connect(ui->gameplayScreen, &GameScreen::resetWater, this, &MainWindow::resetHydrationBar);
    connect(ui->gameplayScreen, &GameScreen::addWater, this, &MainWindow::addWaterToBar);
    connect(ui->gameplayScreen, &GameScreen::updateLevelView, this, &MainWindow::updateLevel);
    connect(ui->gameplayScreen, &GameScreen::wonGame, this, &MainWindow::WinScreen);
    ui->blackoutLabel->setVisible(false);

    // Set up drinking (gluglug) sound
    effect.setSource(QUrl("qrc:/Sounds/Sound/drinkingSound.wav"));
    effect.setLoopCount(1);
    effect.setVolume(0.25f);

    ui->instructionsLabel->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * Shows the game's start screen.
 * @brief MainWindow::GameStartScreen
 */
void MainWindow::GameStartScreen() {
    blurScreen(0);
   ui->stackWindow->setCurrentIndex(0);
}

/**
 * Slot for when the player presses the start button.
 * @brief MainWindow::on_startButton_clicked
 */
void MainWindow::on_startButton_clicked()
{
    ui->instructionsLabel->show();
    instructionsPoppedUp = true;
}

/**
 * Starts or resumes the game.
 * Does NOT end or pause previous games.
 * @brief MainWindow::resumeGame
 */
void MainWindow::resumeGame() {
    ui->stackWindow->setCurrentIndex(3); // move this?
    ui->gameplayScreen->resumeGame();
    changeBarToBlue();
    blurScreen(0);
}

/**
 * Restarts the game from the beginning.
 * @brief MainWindow::startGame
 */
void MainWindow::startGame(bool setting) {
    ui->instructionsLabel->hide();
    ui->stackWindow->setCurrentIndex(3); // move this?
    ui->gameplayScreen->startGame(setting); // move this?
    changeBarToBlue();
    blurScreen(0);    
}

/**
 * Shows a screen when the player pauses the game.
 * @brief MainWindow::PauseScreen
 */
void MainWindow::PauseScreen(){
    ui->gameplayScreen->pauseGame();
    ui->stackWindow->setCurrentIndex(2);
}

/**
 * @brief MainWindow::CollideScreen the screen that shows up when a player collides,
 * displaying the trivia questions they must answer
 */
void MainWindow::CollideScreen(){
    blurScreen(0);
    ui->gameplayScreen->stopGame();
    ui->stackWindow->setCurrentIndex(1);
   std::vector<QString> trivia =  ui->collideScreen->giveMeARandomQuestion();
   ui->questionLabel->setText(trivia[0]);
   ui->answerButton1->setText(trivia[1]);
   ui->answerButton2->setText(trivia[2]);
   ui->answerButton3->setText(trivia[3]);
}

/**
 * Shows an "INTOXICATED" screen when the player dies due to dehydration.
 * @brief MainWindow::LoseScreen
 */
void MainWindow::LoseScreen() {
    ui->gameplayScreen->stopGame();
    ui->stackWindow->setCurrentIndex(4);
}

/**
 * Shows a "CRASHED" screen when the player collides with a truck and loses trivia.
 * @brief MainWindow::crashedScreen
 */
void MainWindow::crashedScreen() {
    blurScreen(0);
    ui->gameplayScreen->stopGame();
    ui->stackWindow->setCurrentIndex(5);
}

/**
 * Shows an "ARRIVED" screen when the player wins the game.
 * @brief MainWindow::WinScreen
 */
void MainWindow::WinScreen() {
    blurScreen(0);
    ui->gameplayScreen->stopGame();
    ui->stackWindow->setCurrentIndex(6);
}

/**
 * Slot for "Restart" button in the pause screen.
 * @brief MainWindow::on_restartButton_clicked
 */
void MainWindow::on_restartButton_clicked(){
    GameStartScreen();
}

/**
 * Slot for "Resume" button in the pause screen.
 * @brief MainWindow::on_restartButton_clicked
 */
void MainWindow::on_resumeButton_clicked(){
    blurScreen(0);
    resumeGame();
}

/**
 * Handles key presses. Specifically, pauses the game when the escape key is pressed.
 *
 * Sources:
 * https://www.qtcentre.org/threads/40779-keyboard-detecting-key-pressed
 * https://doc.qt.io/qt-5/qkeyevent.html
 * https://stackoverflow.com/questions/12558988/qt-keypress-event
 *
 * @brief MainWindow::keyPressEvent
 * @param k
 */
void MainWindow::keyPressEvent(QKeyEvent * k){
    if(k->key() == Qt::Key_Escape){
        if(ui->stackWindow->currentIndex()!=0 && ui->stackWindow->currentIndex()!=2)
            PauseScreen();
    }
}

/**
 * Detects mouse clicks, specifically on the instructions popUp screen
 * which then hides the instructions and starts the game.
 *
 * @brief MainWindow::mousePressEvent
 * @param event
 */
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (instructionsPoppedUp) {
        if (event->buttons() == Qt::LeftButton) {
            startGame(true);
            instructionsPoppedUp = false;
        }
    }
}

/**
 * Recieves the signal from the gamescreen.cpp file and
 * based on the value of the hydration bar, changes the
 * color to purple (if at 50) or blue if greater than 50.
 *
 * Also continuously minuses 1 from the hydration bar during
 * gameplay. Value for timer can be found in the gamescreen.cpp
 * file.
 *
 * @brief MainWindow::receiveHydrationTimer
 */
void MainWindow::receiveHydrationTimer() {
    int currVal = ui->hydrationBar->value();

    if (currVal <= 0) {
        LoseScreen();
    }

    ui->hydrationBar->setValue(currVal - 1);

    // Sets the blackout level with different levels
    if (currVal <= 25) {
        changeBarToPurple();
        ui->blackoutLabel->setStyleSheet("background-image: url(:/GameImages/Images/Blackout3.png)");
        ui->blackoutLabel->setVisible(true);

        //changes the player's speed
        ui->gameplayScreen->changeSpeed(1);

        blurScreen(7);
    } // Sets bar to purple at 50%
    else if (currVal <= 50) {
        changeBarToPurple();
        ui->blackoutLabel->setStyleSheet("background-image: url(:/GameImages/Images/Blackout2.png)");
        ui->blackoutLabel->setVisible(true);

        ui->gameplayScreen->changeSpeed(2);

        blurScreen(5);
    }
    else if (currVal <= 75) {
        changeBarToBlue();
        ui->blackoutLabel->setStyleSheet("background-image: url(:/GameImages/Images/Blackout1.png)");
        ui->blackoutLabel->setVisible(true);

        ui->gameplayScreen->changeSpeed(3);

        blurScreen(3);
    }
    else {
        ui->blackoutLabel->setVisible(false);
        changeBarToBlue();
        blurScreen(0);

        ui->gameplayScreen->changeSpeed(3);
    }
}

/**
 * Changes the color of the hydration bar to purple.
 * @brief MainWindow::changeBarToPurple
 */
void MainWindow::changeBarToPurple() {
    if (!isPurple) {
        isPurple = true;
        ui->hydrationBar->setStyleSheet("QProgressBar::chunk {background: r rgb(104, 21, 159)}");
    }
}

/**
 * Changes the color of the hydration bar to blue.
 * @brief MainWindow::changeBarToBlue
 */
void MainWindow::changeBarToBlue() {
    if (isPurple) {
        blurScreen(0);
        isPurple = false;
        ui->hydrationBar->setStyleSheet("QProgressBar::chunk {background: r rgb(30, 169, 255)}");
    }
}

/**
 * Adds 10 values of water to the hydration bar when a water bottle is picked up.
 *
 * Gets it's signals from tthe gamescreen.cpp file.
 * @brief MainWindow::addWaterToBar
 */
void MainWindow::addWaterToBar() {
    effect.play();

    int currVal = ui->hydrationBar->value();
    currVal+= 10;

    if (currVal > 100)
        currVal = 100;

    ui->hydrationBar->setValue(currVal);
}

/**
 * Resets hydration bar to 100%.
 * @brief MainWindow::resetHydrationBar
 */
void MainWindow::resetHydrationBar() {
    ui->hydrationBar->setValue(100);
}

/**
 * Blurs the screen by the given radius integer.
 * @brief MainWindow::blurScreen
 * @param blurRadius - Blurs the screen by this radius
 */
void MainWindow::blurScreen(int blurRadius) {
    if (blurEffect->blurRadius() != blurRadius) {
        blurEffect->setBlurRadius(blurRadius);
        this->setGraphicsEffect(blurEffect);
    }
}

/**
 * Calls the collide screen after a 1.2 second delay (to be able to see trucks
 * spin before the screen comes up).
 * @brief MainWindow::CollideScreenDelay
 */
void MainWindow::CollideScreenDelay() {
    QTimer::singleShot(1200, this, &MainWindow::CollideScreen);
}

/**
 * Updates the level label.
 * @brief MainWindow::UpdateLevel
 * @param level
 */
void MainWindow::updateLevel(int level) {
    ui->levelLabel->setText(QString("Level %1/7").arg(level));
}

/**
 * Checks if the clicked answer is correct.
 * @brief MainWindow::checkButtonAnswer
 * @param buttonNum
 */
void MainWindow::checkButtonAnswer(int buttonNum){
    if(ui->collideScreen->checkAnswer(buttonNum)){ //if correct, resume
        startGame(false);
    }
    else {
        crashedScreen();
    }
}

/**
 * Slot when answer #1 is clicked.
 * @brief MainWindow::on_answerButton1_clicked
 */
void MainWindow::on_answerButton1_clicked()
{
    checkButtonAnswer(1);
}

/**
 * Slot when answer #2 is clicked.
 * @brief MainWindow::on_answerButton2_clicked
 */
void MainWindow::on_answerButton2_clicked()
{
    checkButtonAnswer(2);
}

/**
 * Slot when answer #3 is clicked.
 * @brief MainWindow::on_answerButton3_clicked
 */
void MainWindow::on_answerButton3_clicked()
{
    checkButtonAnswer(3);
}

/**
 * Slot when the reset button on the lose screen is clicked.
 * @brief MainWindow::on_resetButton_clicked
 */
void MainWindow::on_resetButton_clicked()
{
    GameStartScreen();
}

/**
 * Slot when the reset button on the crashed screen is clicked.
 * @brief MainWindow::on_crashedResetButton_clicked
 */
void MainWindow::on_crashedResetButton_clicked()
{
    GameStartScreen();
}

/**
 * Slot when the reset button on the win screen is clicked.
 * @brief MainWindow::on_winResetButton_clicked
 */
void MainWindow::on_winResetButton_clicked()
{
    GameStartScreen();
}

/**
 * Slot when the quit button on the win screen is clicked.
 * @brief MainWindow::on_winQuitButton_clicked
 */
void MainWindow::on_winQuitButton_clicked()
{
    QCoreApplication::quit();
}

