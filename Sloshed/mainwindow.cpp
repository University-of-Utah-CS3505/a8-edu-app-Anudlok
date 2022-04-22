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
#include <QGraphicsBlurEffect>
#include <QKeyEvent>
#include "player.h"
#include "scenewidget.h"
#include "gamescreen.h"

//QGraphicsScene - Container for game objects. A Player, a tree, etc. Think of it as a map or a world
//QGraphicsItem - Object that you want to put into a scene. The player class must be derived from the QGraphicsItem class
//QGraphicsItem --> QGraphicsRecItem (Just a rectangle that its derived from)
//QGraphicsView - Used to visualize the scene

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

   //use code below to blur the screen
  //  QGraphicsBlurEffect *effect = new QGraphicsBlurEffect;
  //  effect->setBlurRadius(50);
  //  effect->blurRadius();
  //  this->setGraphicsEffect(effect);
    //Test

    connect(ui->gameplayScreen, &GameScreen::sendHydrationTimer, this, &MainWindow::receiveHydrationTimer);
    connect(ui->gameplayScreen, &GameScreen::sendCollideScreen, this, &MainWindow::CollideScreenDelay);
    connect(ui->gameplayScreen, &GameScreen::addWater, this, &MainWindow::addWaterToBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GameStartScreen() {
   this->setGraphicsEffect(0);
   ui->stackWindow->setCurrentIndex(0);
}

void MainWindow::on_startButton_clicked()
{
    restartGame();
}

/**
 * Starts or resumes the game.
 * Does NOT end or pause previous games.
 * @brief MainWindow::startGame
 */
void MainWindow::startGame() {
    this->setGraphicsEffect(0);
    ui->stackWindow->setCurrentIndex(3);
    ui->gameplayScreen->startGame();
    changeBarToBlue();
}

/**
 * Restarts the game from the beginning.
 * @brief MainWindow::startGame
 */
void MainWindow::restartGame() {
    this->setGraphicsEffect(0);
    ui->stackWindow->setCurrentIndex(3);
    ui->gameplayScreen->restartGame();
    changeBarToBlue();
    ui->hydrationBar->setValue(100);
}

void MainWindow::PauseScreen(){
    ui->gameplayScreen->stopGame();
  //  QGraphicsBlurEffect *effect = new QGraphicsBlurEffect;
    ui->stackWindow->setCurrentIndex(2);
    //insert code to stop all on screen movement here
   // QWidget *pauseScreen = ui->stackWindow->widget(2);
    //blur game screen
    //effect->setBlurRadius(20);
   // effect->blurRadius();
    //pauseScreen->setGraphicsEffect(effect);
  //  ui->gameplayScreen->setGraphicsEffect(effect);
}
void MainWindow::CollideScreen(){
    ui->gameplayScreen->stopGame();
    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect;
    ui->stackWindow->setCurrentIndex(0);
    //blur game screen
    effect->setBlurRadius(20);
    effect->blurRadius();
    this->setGraphicsEffect(effect);
}

//the console says "no matching signal for on_restartButton_clicked(); but i'm working on it
void MainWindow::on_restartButton_clicked(){
    //probably have to reset all player movement
   // this->setGraphicsEffect(0);
    GameStartScreen();
}

//the console says "no matching signal for on_returnButton_clicked(); but i'm working on it
void MainWindow::on_resumeButton_clicked(){
    this->setGraphicsEffect(0);
    startGame();
}


// https://www.qtcentre.org/threads/40779-keyboard-detecting-key-pressed
// https://doc.qt.io/qt-5/qkeyevent.html
// https://stackoverflow.com/questions/12558988/qt-keypress-event
void MainWindow::keyPressEvent(QKeyEvent * k){
    switch(k->key()){
    case Qt::Key_P:
        //when its not on the game start screen or pause screen
        if(ui->stackWindow->currentIndex()!=0 && ui->stackWindow->currentIndex()!=2)
            PauseScreen();
        break;
    case Qt::Key_Escape:
        if(ui->stackWindow->currentIndex()!=0 && ui->stackWindow->currentIndex()!=2)
            PauseScreen();
        break;
    //case Qt::KeyUp:       <-format for key switch statements for when we add more game stuff
    //  break;
    default:
        break;
    }
}

void MainWindow::receiveHydrationTimer() {
    int currVal = ui->hydrationBar->value();

    // Sets bar to purple below 50%
    if (currVal == 50) {
        changeBarToPurple();
    }
    else if (currVal > 50) {
        changeBarToBlue();
    }

    ui->hydrationBar->setValue(currVal - 1);
}

void MainWindow::changeBarToPurple() {
    ui->hydrationBar->setStyleSheet("QProgressBar::chunk {background: r rgb(104, 21, 159)}");
}

void MainWindow::changeBarToBlue() {
    ui->hydrationBar->setStyleSheet("QProgressBar::chunk {background: r rgb(30, 169, 255)}");
}

void MainWindow::addWaterToBar() {
    int currVal = ui->hydrationBar->value();
    currVal+= 50;
    ui->hydrationBar->valueChanged(currVal);
}

/**
 * Calls the collide screen after a 1.2 second delay (to be able to see trucks
 * spin before the screen comes up).
 * @brief MainWindow::CollideScreenDelay
 */
void MainWindow::CollideScreenDelay() {
    QTimer::singleShot(1200, this, &MainWindow::CollideScreen);
}
