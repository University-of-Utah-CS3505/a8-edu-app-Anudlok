/************************************************
 * Player class
 * Class definition for Player QObject
 * Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/9/2022
************************************************/
#include "player.h"
#include <QPainter>

Player::Player(QObject *parent)
    : QObject{parent}
{
    player = new QImage(":/GameImages/Images/SpriteSketch1.png");
    x = 200;
    y = 400;
}
