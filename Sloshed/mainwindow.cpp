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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GameStartScreen() {

}

void MainWindow::on_startButton_clicked()
{
    startGame();
}

void MainWindow::startGame() {
    ui->stackWindow->setCurrentIndex(1);
    ui->gameplayScreen->startGame();
}

void MainWindow::PauseScreen(){
    ui->gameplayScreen->stopGame();
    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect;
    //insert code to stop all on screen movement here
//    ui->stackWindow->addWidget(new SceneWidget());
//    ui->stackWindow->setCurrentIndex(3);
    //blur game screen
    effect->setBlurRadius(50);
    effect->blurRadius();
    this->setGraphicsEffect(effect);
   //ok now add the buttons
    QPushButton returnButton("return to game", ui->stackWindow->widget(3));
    QPushButton restartButton("restart game", ui->stackWindow->widget(3));

}

/*

//the console says "no matching signal for on_restartButton_clicked(); but i'm working on it
void MainWindow::on_restartButton_clicked(){
    //probably have to reset all player movement
    this->setGraphicsEffect(0); //0 removes all graphics effects?
    GameStartScreen();
}
//the console says "no matching signal for on_returnButton_clicked(); but i'm working on it
void MainWindow::on_returnButton_clicked(){
    this->setGraphicsEffect(0);
    ui->stackWindow->widget(1);
    //restart all player movement here
}

*/

// https://www.qtcentre.org/threads/40779-keyboard-detecting-key-pressed
// https://doc.qt.io/qt-5/qkeyevent.html
// https://stackoverflow.com/questions/12558988/qt-keypress-event
void MainWindow::keyPressEvent(QKeyEvent * k){
    switch(k->key()){
    case Qt::Key_P:
        PauseScreen();
        break;
    case Qt::Key_Escape:
        PauseScreen();
        break;
    //case Qt::KeyUp:       <-format for key switch statements for when we add more game stuff
    //  break;
    default:
        break;
    }
}




