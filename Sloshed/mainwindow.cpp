#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

//QGraphicsScene - Container for game objects. A Player, a tree, etc. Think of it as a map or a world
//QGraphicsItem - Object that you want to put into a scene. The player class must be derived from the QGraphicsItem class
//QGraphicsItem --> QGraphicsRecItem (Just a rectangle that its derived from)
//QGraphicsView - Used to visualize the scene

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

