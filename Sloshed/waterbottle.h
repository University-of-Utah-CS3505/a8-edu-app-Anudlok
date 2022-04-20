#ifndef WATERBOTTLE_H
#define WATERBOTTLE_H

#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "player.h"
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
#include <QObject>

class WaterBottle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    WaterBottle(int, int);

protected:
    void advance(int phase);
    void remove();

private:
    QString imgPath = ":/GameImages/Images/PowerupSketch1.png";
};

#endif // WATERBOTTLE_H
