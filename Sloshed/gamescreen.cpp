/************************************************
 * GameScreen class
 * Class definition for GameScreen QWidget
 * Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/18/2022
************************************************/
#include "gamescreen.h"
#include "mainwindow.h"
#include <QGraphicsView>

/**
 * GameScreen constructor
 * @brief GameScreen::GameScreen
 * @param parent
 */
GameScreen::GameScreen(QWidget *parent)
    : QWidget{parent}
{
    setStyleSheet("background-image: url(:/GameImages/Images/GameplaySketch1.png)");
    gameplayView = new QGraphicsView();
    gameplayView->setParent(this);
    gameplayView->resize(MainWindow::WIDTH, MainWindow::HEIGHT);
    qDebug() << "pos: " << gameplayView->pos();
    qDebug() << "size: " << gameplayView->size();
    gameplayScene = new QGraphicsScene(this);
    gameplayView->setScene(gameplayScene);
    gameplayScene->setSceneRect(0, 0, MainWindow::WIDTH, MainWindow::HEIGHT);

    // Timer for the whole scene and send trucks
    sceneTimer = new QTimer(this);
    truckTimer = new QTimer(this);
    connect(sceneTimer, &QTimer::timeout, gameplayScene, &QGraphicsScene::advance);
    connect(truckTimer, &QTimer::timeout, this, &GameScreen::sendTruck);
}

/**
 * Starts trucks moving and spawning.
 * @brief GameScreen::startGame
 */
void GameScreen::startGame() {
    sceneTimer->start(sceneAdvanceDelay);
    truckTimer->start(truckSpawnDelay);
}

/**
 * Stops trucks from moving and spawning.
 * @brief GameScreen::startGame
 */
void GameScreen::stopGame() {
    sceneTimer->stop();
    truckTimer->stop();
}

/**
 * Adds a truck to a lane.
 * @brief GameScreen::sendTruck
 */
void GameScreen::sendTruck() {
    // y coordinates of the 4 lanes
    QList<int> lanes = {155, 315, 475, 635};
    // Get random lane
    int laneNum = QRandomGenerator::global()->bounded(4);
    // 0th and 3rd lane have trucks moving right. Other lanes move left.
    bool movingRight = laneNum % 2 == 0;
    // Place truck
    Truck *truck;
    if (movingRight)
        truck = new Truck(0 - Truck::HEIGHT, lanes[laneNum], true);
    else
        truck = new Truck(MainWindow::WIDTH + Truck::WIDTH, lanes[laneNum], false);
    // Set truck to transform (e.g. spin) from its center point
    truck->setTransformOriginPoint(truck->boundingRect().width()/2, truck->boundingRect().height()/2);
    gameplayScene->addItem(truck);
}

void GameScreen::nextLevel() {
    level++;
    // Change truckSpawnDelay and sceneAdvanceDelay
    if (truckSpawnDelay > MIN_TRUCK_SPAWN_DELAY)
        truckSpawnDelay += 400;
    if (sceneAdvanceDelay > MIN_SCENE_ADVANCE_DELAY)
        sceneAdvanceDelay += 5;
}
