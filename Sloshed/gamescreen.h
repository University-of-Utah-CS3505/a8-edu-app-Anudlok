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
    void paintEvent(QPaintEvent *);
    void resumeGame();
    void startGame(bool fromLevelOne);
    void pauseGame();
    void stopGame();

public slots:
    void addWaterToBar();
    void nextLevel();

signals:
  void sendHydrationTimer();
  void sendCollideScreen();
  void resetWater();
  void addWater();
  void updateLevelView(int);
  void wonGame();

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
    QList<int> truckSpawnDelays = {2000, 2000, 1600, 1600, 1300, 1300, 1140, 1140, 1000, 1000}; // Old: 2000, 1400, 980, 686, 480
    QList<int> truckSpeeds = {20, 21, 21, 22, 22, 23, 23, 24, 24, 25}; // Old: 20, 25, 30, 35, 40
    const int sceneAdvanceDelay = 25;
    int mouseDelay = 100;
    int waterDelay = 400;
    int level = 1;
    int const MAX_LEVEL = 10;
    Player *player;
};

#endif // GAMESCREEN_H
