/************************************************
 * SceneWidget class
 * Class definition for SceneWidget QWidget
 * Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/9/2022
************************************************/
#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>

class SceneWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SceneWidget(QWidget *parent = nullptr);
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

#endif // SCENEWIDGET_H
