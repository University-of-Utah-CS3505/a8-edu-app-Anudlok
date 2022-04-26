/************************************************
 * Player class
 * Class definition for Player QGraphicsPixmapItem
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
    setPos(mapToParent(345, 705));
    setPixmap(imgPath);
    width = pixmap().width();
    height = pixmap().height();
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

    int speed_x = (x() - mouse_x_pos + 45) / (abs(x() - mouse_x_pos + 45)) * speed;
    int speed_y = (y() - mouse_y_pos + 45) / (abs(y() - mouse_y_pos + 45)) * speed;

    checkBoundaries();

    if (x() - mouse_x_pos + 45 == 0)
        speed_x = 0;
    if (y() - mouse_y_pos + 45 == 0)
        speed_y = 0;

    QList<QGraphicsItem *> list = scene()->collidingItems(this) ;

    if(!isColliding) {  // Needed so that hasCollided only emits once
        setPos(x() - speed_x, y() - speed_y);
        foreach(QGraphicsItem * i , list)
        {
            // If player colliding with truck, remove from scene
            Truck *item= dynamic_cast<Truck *>(i);
            if (item)
            {
                isColliding = true;
                emit hasCollided();
            }
        }
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

/**
 * Makes sure the player's position is within the screen boundaries.
 * @brief Player::checkBoundaries
 */
void Player::checkBoundaries() {

    // Check if player is too far right
    if (x() >= SCREEN_SIZE - width*SCALE_FACTOR)
        setPos(SCREEN_SIZE - width*SCALE_FACTOR, y());
    // Check if player is too far left
    if (x() <= 0 - width/2*SCALE_FACTOR)
        setPos(0 - width/2*SCALE_FACTOR, y());
    // Check if player is too low
    if (y() >= SCREEN_SIZE - height*SCALE_FACTOR)
        setPos(x(), SCREEN_SIZE - height*SCALE_FACTOR);
}

void Player::changeSpeed(int speedChange) {
    speed = speedChange;
}
