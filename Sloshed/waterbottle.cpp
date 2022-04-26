/************************************************
 * WaterBottle class
 * Class definition for WaterBottle QGraphicsPixmapItem
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/18/2022
************************************************/
#include "waterbottle.h"

/**
 * The WaterBottle constructor
 * @brief WaterBottle::WaterBottle
 * @param parent The parent QObject
 * @param x The x coordinate of the water bottle
 * @param y The y coordinate of the water bottle
 */
WaterBottle::WaterBottle(QObject *parent, int x, int y)
    : QObject{parent}
{
    setPos(mapToParent(x, y));
    setPixmap(imgPath);
}

/**
 * Updates the instance of the water bottle. Detects collision with the player.
 * @brief WaterBottle::advance
 * @param phase
 */
void WaterBottle::advance(int phase) {
    if(!phase) return;

    QList<QGraphicsItem *> list = scene()->collidingItems(this) ;

    // Check if player is colliding with water bottle
    foreach(QGraphicsItem * i , list)
    {
        // If player colliding with water bottle, remove from scene
        Player * item= dynamic_cast<Player *>(i);
        if (item)
        {
            remove();
        }
    }
}

/**
 * Removes the water bottle from the scene.
 * @brief WaterBottle::remove
 */
void WaterBottle::remove() {
    emit addWater();
    scene()->removeItem(this);
}
