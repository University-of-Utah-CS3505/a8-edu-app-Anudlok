#ifndef TRIVIASCREEN_H
#define TRIVIASCREEN_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>


class TriviaScreen : public QWidget
{
    Q_OBJECT
public:
    explicit TriviaScreen(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:

public slots:
    void updateWorld();

private:
    b2World world;
    b2Body* body;
    QTimer timer;
    QImage image;
    int x;
    int y;
    int xSpeed;
    int ySpeed;

};

#endif // TRIVIASCREEN_H
