/************************************************
 * GameScreen class
 * Class definition for GameScreen QWidget
 * Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/18/2022
************************************************/
#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>
#include <QGraphicsScene>
#include "mainwindow.h"
#include "truck.h"
#include "waterbottle.h"
#include <QGraphicsView>

class GameScreen : public QWidget
{
    Q_OBJECT
public:
    explicit GameScreen(QWidget *parent = nullptr);
    void startGame();
    void restartGame(bool fromLevelOne = true);
    void stopGame();
    void nextLevel();

signals:
  void sendHydrationTimer();
  void receiveHydrationTimer();
  void sendCollideScreen();

private:
    void initTimers();
    void addPlayer();
    void sendTruck();
    void placeWaterBottles();
    void sendMousePosition();
    void handleCollision();
    QGraphicsView *gameplayView;
    QGraphicsScene *gameplayScene;
    QTimer *sceneTimer;
    QTimer *truckTimer;
    QTimer* mouseTimer;
    QTimer *hydrationTimer;

    // Variables to tweak gameplay
    int truckSpawnDelay = 2000;
    int sceneAdvanceDelay = 25;
    int mouseDelay = 100;
    int level = 1;
    int const MAX_LEVEL = 5;
    Player *player;
};

#endif // GAMESCREEN_H
