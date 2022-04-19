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

class GameScreen : public QWidget
{
    Q_OBJECT
public:
    explicit GameScreen(QWidget *parent = nullptr);
    void startGame();
    void stopGame();
    void nextLevel();

signals:

private:
    void sendTruck();
    QGraphicsView *gameplayView;
    QGraphicsScene *gameplayScene;
    QTimer *sceneTimer;
    QTimer *truckTimer;

    // Variables to tweak gameplay
    int truckSpawnDelay = 2000;
    int sceneAdvanceDelay = 25;
    int level = 1;
    int const MAX_LEVEL = 5;
};

#endif // GAMESCREEN_H
