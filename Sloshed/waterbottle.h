#ifndef WATERBOTTLE_H
#define WATERBOTTLE_H

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

class WaterBottle : public QGraphicsPixmapItem
{
public:
    WaterBottle(int, int);

protected:
    void advance(int phase);
};

#endif // WATERBOTTLE_H
