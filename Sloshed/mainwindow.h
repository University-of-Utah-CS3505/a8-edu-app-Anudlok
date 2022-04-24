/************************************************
 * MainWindow class
 * Class definition for MainWindow QWidget
 * Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/9/2022
************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "truck.h"
#include "player.h"
#include <QTimer>
#include <QSoundEffect>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void resumeGame();
    void startGame();
    void GameStartScreen();
    void PauseScreen();
    void CollideScreen();
    void CollideScreenDelay();
    static int const WIDTH = 800;
    static int const HEIGHT = 800;

private slots:
    void on_startButton_clicked();

    void on_restartButton_clicked();
    void on_resumeButton_clicked();
    void addWaterToBar();
    void keyPressEvent(QKeyEvent *k);
    void receiveHydrationTimer();
    void updateLevel(int level);

private:
    Ui::MainWindow *ui;
    QSoundEffect effect;
    void changeBarToPurple();
    void changeBarToBlue();
    void blurScreen(int blurRadius);
    bool isPurple = false;
};
#endif // MAINWINDOW_H
