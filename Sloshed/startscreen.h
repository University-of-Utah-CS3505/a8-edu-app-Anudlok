/************************************************
 * StartScreen class
 * Class definition for StartScreen QWidget
 * Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/9/2022
************************************************/
#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>

class StartScreen : public QWidget
{
    Q_OBJECT
public:
    explicit StartScreen(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:

public slots:
    void updateLogo();

private:
    QTimer timer;
    QImage image;
    int x;
    int y;
    int xSpeed;
    int ySpeed;
};

#endif // STARTSCREEN_H
