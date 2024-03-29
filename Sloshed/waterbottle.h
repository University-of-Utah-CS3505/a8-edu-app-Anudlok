/************************************************
 * WaterBottle class
 * Class definition for WaterBottle QGraphicsPixmapItem
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/18/2022
************************************************/
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
    WaterBottle(QObject*, int, int);

protected:
    void advance(int phase);
    void remove();

private:
    QString imgPath = ":/GameImages/Images/Bottle.png";

signals:
    void addWater();
};

#endif // WATERBOTTLE_H
