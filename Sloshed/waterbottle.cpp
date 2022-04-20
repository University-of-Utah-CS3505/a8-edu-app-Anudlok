#include "waterbottle.h"

WaterBottle::WaterBottle(int x, int y)
{
    setPos(mapToParent(x, y));
    setPixmap(imgPath);
}

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

void WaterBottle::remove() {
    scene()->removeItem(this);
}
