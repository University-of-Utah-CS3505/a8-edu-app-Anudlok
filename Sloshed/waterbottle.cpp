#include "waterbottle.h"

WaterBottle::WaterBottle(int x, int y)
{
    setPos(mapToParent(x, y));
}

void WaterBottle::advance(int phase) {
    if(!phase) return;

    if(scene()->collidingItems(this).isEmpty()) {

    }
        // If item not colliding, advance truck left or right
}
