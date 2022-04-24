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
    void resumeGame();
    void startGame(bool fromLevelOne = true);
    void pauseGame();
    void stopGame();
    void nextLevel();

public slots:
    void addWaterToBar();

signals:
  void sendHydrationTimer();
  void sendCollideScreen();
  void addWater();
  void updateLevelView(int);

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
    int MAX_SPAWN_DELAY = 2000;
    int MAX_ADVANCE_DELAY = 25;
    int truckSpawnDelay = MAX_SPAWN_DELAY;
    int sceneAdvanceDelay = MAX_ADVANCE_DELAY;
    int mouseDelay = 100;
    int waterDelay = 400;
    int level = 1;
    int const MAX_LEVEL = 5;
    Player *player;
};

#endif // GAMESCREEN_H
