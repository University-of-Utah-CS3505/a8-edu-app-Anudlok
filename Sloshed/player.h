#ifndef PLAYER_H
#define PLAYER_H

#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QList>
#include <QTimer>

class Player : public QGraphicsPixmapItem
{
public:
    Player();

protected:
    void advance(int phase);

private:
    QString imgPath = ":/GameImages/Images/SpriteSketch1.png";
    qreal angle;
    qreal speed;
};

#endif // PLAYER_H
