#include "player.h"
#include <QDebug>

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

    int speed_x = (x() - x_pos + 60) / (abs(x() - x_pos + 60)) * speed;
    int speed_y = (y() - y_pos + 60) / (abs(y() - y_pos + 60)) * speed;

    if (x() - x_pos + 60 == 0)
        speed_x = 0;
    if (y() - y_pos + 60 == 0)
        speed_y = 0;

    if(scene()->collidingItems(this).isEmpty()) {
        setPos(x() - speed_x, y() - speed_y);
    }
}

void Player::mousePosition(int x, int y) {
    x_pos = x;
    y_pos = y;
}


