#include "player.h"

Player::Player()
{
    setPos(mapToParent(650, 700));
    setPixmap(imgPath);
    speed = 20;
    angle = 20;
}
