/************************************************
 * Truck class
 * Class definition for Truck QGraphicsPixmapItem
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/18/2022
************************************************/
#include "truck.h"

Truck::Truck(int x, int y, bool movingRight) {
    setPos(mapToParent(x, y));
    setPixmap(imgPath);

    this->movingRight = movingRight;

    // If truck is moving left, it should face opposite direction
    if (!movingRight)
        setRotation(rotation() + 180);

    collided = false;
    speed = 20;
    angle = 20;
}

void Truck::advance(int phase) {
    if(!phase) return;

    if(scene()->collidingItems(this).isEmpty()) {
        // If item not colliding, advance truck left or right
        if (movingRight)
            setPos(x() + speed, y());
        else
            setPos(x() - speed, y());
    }
    else {
        doCollision();
    }

    // Remove truck if it's is out of bounds
    if (x() < 0 - WIDTH || x() > 1300 + WIDTH) {
        remove();
    }
}

void Truck::remove() {
    //if (!scene()->sceneRect().contains(boundingRect()) || collided) {
    scene()->removeItem(this);
    delete this;
}

void Truck::doCollision() {
    setRotation(rotation() + angle);
    collided = true;
    //emit stopTrucks();
}

bool Truck::isCollided() {
    return collided;
}


