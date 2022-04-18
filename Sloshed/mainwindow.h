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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void startGame();
    void GameStartScreen();
    void PauseScreen();

private slots:
    void on_startButton_clicked();
    /* working on this so ignore it :)
    void on_restartButton_clicked();
    void on_returnButton_clicked();
    */
    void keyPressEvent(QKeyEvent *k);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
