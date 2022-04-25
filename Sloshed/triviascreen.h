#ifndef TRIVIASCREEN_H
#define TRIVIASCREEN_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>
#include <vector>


class TriviaScreen : public QWidget
{
    Q_OBJECT
public:
    explicit TriviaScreen(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void populateTrivia();

signals:

public slots:
    void updateWorld();

private:
    b2World world;
    b2Body* body;
    QTimer timer;
    QImage image;
    std::vector<std::vector<QString>> triviaVector;
    std::vector<QString> randomizeTrivia(std::vector<QString> questionVec, int &correctIndex);
    int x;
    int y;
    int xSpeed;
    int ySpeed;

};

#endif // TRIVIASCREEN_H
