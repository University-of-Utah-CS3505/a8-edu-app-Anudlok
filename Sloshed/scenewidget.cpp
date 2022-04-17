/************************************************
 * SceneWidget class
 * Class definition for SceneWidget QWidget
 * Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/9/2022
************************************************/
#include "scenewidget.h"
#include <QPainter>
#include <QDebug>

SceneWidget::SceneWidget(QWidget *parent) : QWidget(parent),
    world(b2Vec2(0.0f, 10.0f)),
    timer(this),
    image(":/GameImages/Images/LogoSketch2.png"), // Make a resource file - mac executables are in a hidden folder
    x(0), y(0),
    xSpeed(20), ySpeed(20)
{
    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 20.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(50.0f, 10.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);

    body = world.CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;
    // Override the default friction.
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.9;
    // Add the shape to the body.
    body->CreateFixture(&fixtureDef);
    connect(&timer, &QTimer::timeout, this, &SceneWidget::updateWorld);
    timer.start(50);
}

void SceneWidget::paintEvent(QPaintEvent *) {
    // Create a painter
    QPainter painter(this);
    //b2Vec2 position = body->GetPosition();
    //float angle = body->GetAngle();

    /*
     //Credit: https://www.youtube.com/watch?v=0j86zuqqTlQ
    //DvD Motion
     body->SetAngularVelocity(0.785398);
    int x = position.x;
    int y = position.y;
    int xSpeed = 20;
    int ySpeed = 20;

    int width = this->width();
    int height= this->height();

    if(x+ image.width() == width||x==0){
     xSpeed = -xSpeed;
    }

    if( y + image.height() == height|| y == 0){
    ySpeed = -ySpeed;
    }
    painter.drawImage((int)(position.x*xSpeed), (int) (position.y*ySpeed), image);
    */
    //painter.drawImage((int)(position.x*20), (int)(position.y*20), image);

    //painter.end();


    //NOTES:
    //Not actually a working solution with the physics engine, will need to modify
    //Changed the changed the x,y position of the central widget from 19 to 0 and the y height to 900 from 859.
    //Also changed the x,y position of the scene widget to do this and made it match the size of the central widget.
    //Credit: https://www.youtube.com/watch?v=0j86zuqqTlQ
    //DvD Motion
    //b2Vec2 position = body->GetPosition();

    int width = this->width();
    int height = this->height();

    if(x + image.width() > width || x < 0)
        xSpeed = -xSpeed;

    if(y + image.height() > height || y < 0)
        ySpeed = -ySpeed;

    x = x + xSpeed;
    y = y + ySpeed;
    painter.drawImage((int)(x), (int)(y), image);
}

void SceneWidget::updateWorld() {
    // It is generally best to keep the time step and iterations fixed.
    world.Step(1.0/60.0, 6, 2);

    update();
}
