#ifndef TRUCK_H
#define TRUCK_H

#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
/************************************************
 * Truck class
 * Class definition for Truck QGraphicsPixmapItem
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/18/2022
************************************************/
#include <QRandomGenerator>
#include <QList>
#include <QTimer>

class Truck : public QGraphicsPixmapItem
{
public:
    Truck(int, int, bool);
    static int const HEIGHT = 120;
    static int const WIDTH = 360;

protected:
    void advance(int phase);
    void move();
    void doCollision();
    bool isCollided();
    void remove();

private:
    qreal angle;
    qreal speed;
    qreal collideTime;
    QString imgPath = ":/GameImages/Images/EnemySketch1.png";
    QPixmap pixmap;
    bool collided;
    bool movingRight;

signals:
    void stopTrucks();


};

#endif // TRUCK_H
