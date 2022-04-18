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
    Truck(int, int);

protected:
    void advance(int phase);
    void move();
    void doCollision();
    bool isCollided();
    void remove();

private:
    qreal angle;
    qreal speed;
    qreal xPos;
    qreal yPos;
    qreal collideTime;
    QString imgPath = R"(C:\Users\arcmi\OneDrive\Documents\2022\UofU\Spring2022\CS 3505\A8Images\EnemySketch1.png)";
    QPixmap pixmap;
    bool collided;

signals:
    void stopTrucks();


};

#endif // TRUCK_H
