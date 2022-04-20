/************************************************
 * Truck class
 * Class definition for Truck QGraphicsPixmapItem
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/18/2022
************************************************/
#include "truck.h"
#include "player.h"

/**
 * Truck constructor
 * @brief Truck::Truck
 * @param x The X coordinate of the Truck
 * @param y The Y coordinate of the Truck
 * @param movingRight
 */
Truck::Truck(int x, int y, bool movingRight) {
    setPos(mapToParent(x, y));
    setPixmap(imgPath);

    this->movingRight = movingRight;

    // If truck is moving left, it should face opposite direction
    if (!movingRight)
        setRotation(rotation() + 180);
    isColliding = false;
    speed = 20;
    angle = 20;
}

/**
 * Updates the instance of the truck. Detects collisions with the player.
 * @brief Truck::advance
 * @param phase
 */
void Truck::advance(int phase) {
    if(!phase) return;

    QList<QGraphicsItem *> list = scene()->collidingItems(this) ;

    // Check if truck is colliding with player
    foreach(QGraphicsItem * i , list)
    {
        Player * item= dynamic_cast<Player *>(i);
        if (item)
        {
           isColliding = true;
        }
    }

    // If item not colliding, advance truck left or right
    if (!isColliding) {
        if (movingRight)
            setPos(x() + speed, y());
        else
            setPos(x() - speed, y());
    } else {
        // If item is colliding, make it spin
        setRotation(rotation() + angle);
    }
    // Remove truck if it's is out of bounds
    if (x() < 0 - WIDTH || x() > 1300 + WIDTH) {
        remove();
    }
}

/**
 * Removes the truck from the scene.
 * @brief Truck::remove
 */
void Truck::remove() {
    scene()->removeItem(this);
}
