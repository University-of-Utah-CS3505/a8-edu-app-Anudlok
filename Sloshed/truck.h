#ifndef TRUCK_H
#define TRUCK_H

#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QList>
#include <QTimer>

class Truck : public QGraphicsPixmapItem
{
public:
    Truck(int, int, bool);
    static int const HEIGHT = 120;
    static int const WIDTH = 360;

protected:
    void advance(int phase);
    void move();
    void doCollision();
    bool isCollided();
    void remove();

private:
    qreal angle;
    qreal speed;
    qreal collideTime;
    QString imgPath = R"(C:\Users\gabby\Documents\School Assignments\GitHub\a8-edu-app-Anudlok\Sloshed\Images\EnemySketch1.png)";
            //":/Images/EnemySketch1.png";//R"(C:\Users\arcmi\OneDrive\Documents\2022\UofU\Spring2022\CS 3505\A8Images\EnemySketch1.png)";
    QPixmap pixmap;
    bool collided;
    bool movingRight;

signals:
    void stopTrucks();


};

#endif // TRUCK_H
