/************************************************
 * StartScreen class
 * Class definition for StartScreen QWidget
 * Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/9/2022
************************************************/
#include "startscreen.h"
#include <QPainter>
#include <QDebug>
#include <QStyle>
#include <QStyleOption>

/**
 * StartScreen constructor
 * @brief SceneWidget::SceneWidget
 * @param parent
 */
StartScreen::StartScreen(QWidget *parent) : QWidget(parent),
    timer(this),
    image(":/GameImages/Images/Logo.png"),
    x(0), y(0),
    xSpeed(20), ySpeed(20)
{
    // Start timer to update logo
    connect(&timer, &QTimer::timeout, this, &StartScreen::updateLogo);
    timer.start(50);
}

/**
 * Redraws the Sloshed logo in its new position.
 * @brief SceneWidget::paintEvent
 */
void StartScreen::paintEvent(QPaintEvent *) {
    // Create a painter
    QPainter painter(this);
    // Draw custom style sheet
    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    //Credit: https://www.youtube.com/watch?v=0j86zuqqTlQ
    //DvD Motion

    // Set the speed and direction of the image's motion
    if(x + image.width() > this->width() || x < 0)
        xSpeed = -xSpeed;

    if(y + image.height() > this->height() || y < 0)
        ySpeed = -ySpeed;

    // Move the x and y coordinates and redraw the Sloshed image
    x = x + xSpeed;
    y = y + ySpeed;
    painter.drawImage((int)(x), (int)(y), image);
}

/**
 * Updates the Sloshed logo to a new position
 * @brief SceneWidget::updateWorld
 */
void StartScreen::updateLogo() {
    update();
}
