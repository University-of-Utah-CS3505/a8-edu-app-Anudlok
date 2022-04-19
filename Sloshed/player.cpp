#include "player.h"

Player::Player()
{
    setPos(mapToParent(610, 800));
    setPixmap(imgPath);
    speed = 3;
    angle = 20;
}

void Player::advance(int phase)
{
    if(!phase) return;

    if(scene()->collidingItems(this).isEmpty()) {
        setPos(x(), y() - speed);
    }
}
