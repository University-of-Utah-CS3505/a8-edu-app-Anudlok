#include "truck.h"

Truck::Truck(int x, int y) {
    xPos = x;
    yPos = y;
    setPos(mapToParent(xPos, yPos));
    setPixmap(imgPath);
    collided = false;
}

void Truck::advance(int phase) {
    if(!phase) return;

    if(scene()->collidingItems(this).isEmpty())
        setPos(this->pos().x() + 20, yPos);
    else {
        doCollision();
    }
}

void Truck::remove() {
    if (!scene()->sceneRect().contains(boundingRect()) || collided) {
        scene()->removeItem(this);
        delete this;
    }
}

void Truck::doCollision() {
    setRotation(rotation() + 20);
    collided = true;
    //emit stopTrucks();
}

bool Truck::isCollided() {
    return collided;
}


