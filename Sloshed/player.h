/************************************************
 * Player class
 * Class definition for Player QObject
 * Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/9/2022
************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>

class Player : public QObject
{
    Q_OBJECT

private:
    QImage *player;
    int x, y;

public:
    explicit Player(QObject *parent = nullptr);
    void keyPressEvent(QKeyEvent* event);

signals:

};

#endif // PLAYER_H
