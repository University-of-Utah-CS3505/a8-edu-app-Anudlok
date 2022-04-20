#ifndef PLAYER_H
#define PLAYER_H

#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QList>
#include <QTimer>
#include <QObject>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void mousePosition(int x, int y);

protected:
    void advance(int phase);

private:
    QString imgPath = ":/GameImages/Images/SpriteSketch1.png";
    qreal angle;
    qreal speed;
    int x_pos;
    int y_pos;
    bool isColliding;

signals:
    void hasCollided();
};

#endif // PLAYER_H
