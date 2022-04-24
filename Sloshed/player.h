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

public slots:
    void endLevel();

protected:
    void advance(int phase);

private:
    QString imgPath = ":/GameImages/Images/Player.png";
    qreal angle;
    qreal speed;
    int x_pos;
    int y_pos;
    bool isColliding;

signals:
    void hasCollided();
    void nextLevel();
};

#endif // PLAYER_H
