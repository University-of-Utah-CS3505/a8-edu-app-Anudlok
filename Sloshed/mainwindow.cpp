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
#include "scenewidget.h"
#include "gamescreen.h"
#include <QSoundEffect>
#include <QGraphicsBlurEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(WIDTH, HEIGHT);

    // The stack window contains each of the gameplay screens.
    // Index 0 is the start screen
    // Index 1 is the gameplay screen
    // We can add other screens to future widgets.

    // Note: To add a SceneWidget to the mainwindow.ui, add a QWidget (SceneWidget's parent class)
    // to the UI, right-click the QWidget, and click Promote to -> SceneWidget.

    // If you want to add new custom classes that inherits from QWidget, you'll need to add
    // the promoted class to the mainwindow.ui first. Right-click the QWidget, click Promote to...,
    // and add your custom class in the window that pops up.

    // Set up start screen
    ui->startButton->setParent(ui->stackWindow->widget(0));
    ui->stackWindow->setCurrentIndex(0);

    connect(ui->gameplayScreen, &GameScreen::sendHydrationTimer, this, &MainWindow::receiveHydrationTimer);
    connect(ui->gameplayScreen, &GameScreen::sendCollideScreen, this, &MainWindow::CollideScreenDelay);
    connect(ui->gameplayScreen, &GameScreen::resetWater, this, &MainWindow::resetHydrationBar);
    connect(ui->gameplayScreen, &GameScreen::addWater, this, &MainWindow::addWaterToBar);
    connect(ui->gameplayScreen, &GameScreen::updateLevelView, this, &MainWindow::updateLevel);

    // Set up glug glug sound
    effect.setSource(QUrl("qrc:/Sounds/Sound/drinkingSound.wav"));
    effect.setLoopCount(1);
    effect.setVolume(0.25f);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GameStartScreen() {
    blurScreen(0);
   //ui->stackWindow->setStyleSheet("background-image: url(:/GameImages/Images/Background.png)");
   ui->stackWindow->setCurrentIndex(0);
}

void MainWindow::on_startButton_clicked()
{
    startGame(true);
}

/**
 * Starts or resumes the game.
 * Does NOT end or pause previous games.
 * @brief MainWindow::startGame
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
    ui->stackWindow->setCurrentIndex(3); // move this?
    ui->gameplayScreen->startGame(setting); // move this?
    changeBarToBlue();
    blurScreen(0);    
}

void MainWindow::PauseScreen(){
    ui->gameplayScreen->pauseGame();
    ui->stackWindow->setCurrentIndex(2);
}

/**
 * @brief MainWindow::CollideScreen the screen that shows up when a player collides,
 * displaying the trivia questions they must answer
 */
void MainWindow::CollideScreen(){
    ui->gameplayScreen->stopGame();
    ui->stackWindow->setCurrentIndex(1);
   std::vector<QString> trivia =  ui->collideScreen->giveMeARandomQuestion();
   ui->questionLabel->setText(trivia[0]);
   ui->answerButton1->setText(trivia[1]);
   ui->answerButton2->setText(trivia[2]);
   ui->answerButton3->setText(trivia[3]);
}

void MainWindow::LoseScreen() {
    ui->gameplayScreen->stopGame();
    ui->stackWindow->setCurrentIndex(4);
}

void MainWindow::crashedScreen() {
    ui->gameplayScreen->stopGame();
    ui->stackWindow->setCurrentIndex(5);
}

void MainWindow::on_restartButton_clicked(){

    //probably have to reset all player movement
    GameStartScreen();
}

//the console says "no matching signal for on_returnButton_clicked(); but i'm working on it
void MainWindow::on_resumeButton_clicked(){
    blurScreen(0);
    resumeGame();
}


// https://www.qtcentre.org/threads/40779-keyboard-detecting-key-pressed
// https://doc.qt.io/qt-5/qkeyevent.html
// https://stackoverflow.com/questions/12558988/qt-keypress-event
void MainWindow::keyPressEvent(QKeyEvent * k){
    if(k->key() == Qt::Key_Escape){
        if(ui->stackWindow->currentIndex()!=0 && ui->stackWindow->currentIndex()!=2)
            PauseScreen();
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

    // Sets bar to purple at 50%
    if (currVal <= 50) {
        changeBarToPurple();

        //blur game screen
        blurScreen(5);
    }
    else if (currVal > 50) {
        changeBarToBlue();
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
 * @brief MainWindow::resetWater
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
    blurEffect->setBlurRadius(blurRadius);
    blurEffect->blurRadius();
    this->setGraphicsEffect(blurEffect);
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
    ui->levelLabel->setText(QString("Level %1/10").arg(level));
}

void MainWindow::on_answerButton1_clicked()
{
    checkButtonAnswer(1);
}
void MainWindow::checkButtonAnswer(int buttonNum){
    attempts++;
    if(ui->collideScreen->checkAnswer(buttonNum)){ //if correct, resume
        startGame(false);
    }
    else if(attempts%2 == 0){ //if incorrect and first attempt, let them try again but disconnect the button
     //if incorrect and second attempt
           crashedScreen();
    }
}


void MainWindow::on_answerButton2_clicked()
{
    checkButtonAnswer(2);
}


void MainWindow::on_answerButton3_clicked()
{
    checkButtonAnswer(3);
}


void MainWindow::on_resetButton_clicked()
{
    GameStartScreen();
}


void MainWindow::on_crashedResetButton_clicked()
{
    GameStartScreen();
}

