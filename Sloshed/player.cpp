/************************************************
 * Truck class
 * Class definition for Truck QGraphicsPixmapItem
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/18/2022
************************************************/
#include "player.h"
#include <QDebug>

/**
 * The Player constructor
 * @brief Player::Player
 */
Player::Player()
{
    setPos(mapToParent(355, 800));
    setPixmap(imgPath);
    speed = 3;
    angle = 20;
}

/**
 * Updates the instance of player. Detects collisions with the truck.
 * @brief Player::advance
 * @param phase
 */
void Player::advance(int phase)
{
    if(!phase) return;

    int speed_x = (x() - mouse_x_pos + 60) / (abs(x() - mouse_x_pos + 60)) * speed;
    int speed_y = (y() - mouse_y_pos + 60) / (abs(y() - mouse_y_pos + 60)) * speed;

    if (x() - mouse_x_pos + 60 == 0)
        speed_x = 0;
    if (y() - mouse_y_pos + 60 == 0)
        speed_y = 0;

    if(scene()->collidingItems(this).isEmpty() && !isColliding) {
        setPos(x() - speed_x, y() - speed_y);
    } else if (!isColliding) { // Needed so that hasCollided only emits once
        isColliding = true;
        emit hasCollided();
    }

    if (!isColliding && y() <= 30) {
        isColliding = true; // So that player doesn't move and hasCollided doesn't emit
        QTimer::singleShot(1000, this, &Player::endLevel);
    }
}

/**
 * Gets the current position of the mouse.
 * @brief Player::mousePosition
 * @param x The X coordinate of the mouse
 * @param y The Y coordinate of the mouse
 */
void Player::mousePosition(int x, int y) {
    mouse_x_pos = x;
    mouse_y_pos = y;
}

/**
 * Informs the GameScreen to end current level.
 * @brief Player::endLevel
 */
void Player::endLevel() {
    emit nextLevel();
}


