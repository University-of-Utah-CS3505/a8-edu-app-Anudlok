/************************************************
 * Truck class
 * Class definition for Truck QGraphicsPixmapItem
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/18/2022
************************************************/
#ifndef TRUCK_H
#define TRUCK_H

#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QList>
#include <QTimer>
#include <QObject>

class Truck : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Truck(int, int, int, bool);
    static int const HEIGHT = 120;
    static int const WIDTH = 360;

protected:
    void advance(int phase);
    void move();
    void remove();

private:
    qreal angle;
    qreal speed;
    qreal collideTime;
    QString imgPath = ":/GameImages/Images/Truck.png";
    QPixmap pixmap;
    bool movingRight;
    bool isColliding;

signals:

};

#endif // TRUCK_H
