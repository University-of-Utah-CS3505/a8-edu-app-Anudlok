/************************************************
 * Player class
 * Class definition for Player QGraphicsPixmapItem
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/18/2022
************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QList>
#include <QTimer>
#include <QObject>
#include "truck.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void mousePosition(int x, int y);
    void changeSpeed(int speed);

public slots:
    void endLevel();

protected:
    void advance(int phase);

private:
    QString imgPath = ":/GameImages/Images/Player.png";
    qreal angle;
    qreal speed;
    int mouse_x_pos;
    int mouse_y_pos;
    bool isColliding;
    int const SCREEN_SIZE = 800;
    int width;
    int height;
    double const SCALE_FACTOR = 0.6;

    void checkBoundaries();

signals:
    void hasCollided();
    void nextLevel();
};

#endif // PLAYER_H
