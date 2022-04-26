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
#include <QGraphicsBlurEffect>

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
    void startGame(bool);
    void GameStartScreen();
    void PauseScreen();
    void CollideScreen();
    void CollideScreenDelay();
    void LoseScreen();
    void crashedScreen();
    void WinScreen();
    static int const WIDTH = 800;
    static int const HEIGHT = 800;

private slots:
    void on_startButton_clicked();

    void on_restartButton_clicked();
    void on_resumeButton_clicked();
    void addWaterToBar();
    void resetHydrationBar();
    void keyPressEvent(QKeyEvent *k);
    void receiveHydrationTimer();
    void updateLevel(int level);

    void on_answerButton1_clicked();

    void on_answerButton2_clicked();

    void on_answerButton3_clicked();

    void on_resetButton_clicked();

    void on_crashedResetButton_clicked();

    void on_winResetButton_clicked();

    void on_winQuitButton_clicked();

private:
    Ui::MainWindow *ui;
    QSoundEffect effect;
    QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect();
   void checkButtonAnswer(int buttonNum);
    void changeBarToPurple();
    void changeBarToBlue();
    void blurScreen(int blurRadius);
    bool isPurple = false;
    int attempts;
};
#endif // MAINWINDOW_H
