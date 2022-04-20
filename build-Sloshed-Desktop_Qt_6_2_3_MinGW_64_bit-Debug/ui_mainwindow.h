/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "SceneWidget.h"
#include "gamescreen.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackWindow;
    SceneWidget *startScreen;
    QPushButton *startButton;
    SceneWidget *collideScreen;
    SceneWidget *pauseScreen;
    QPushButton *resumeButton;
    QPushButton *restartButton;
    GameScreen *gameplayScreen;
    QProgressBar *hydrationBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1300, 900);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/BackgroundSketch1.png)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackWindow = new QStackedWidget(centralwidget);
        stackWindow->setObjectName(QString::fromUtf8("stackWindow"));
        stackWindow->setGeometry(QRect(0, 0, 1300, 900));
        startScreen = new SceneWidget();
        startScreen->setObjectName(QString::fromUtf8("startScreen"));
        startButton = new QPushButton(startScreen);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(480, 510, 319, 200));
        startButton->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/StartSketch1.png)"));
        stackWindow->addWidget(startScreen);
        collideScreen = new SceneWidget();
        collideScreen->setObjectName(QString::fromUtf8("collideScreen"));
        stackWindow->addWidget(collideScreen);
        pauseScreen = new SceneWidget();
        pauseScreen->setObjectName(QString::fromUtf8("pauseScreen"));
        resumeButton = new QPushButton(pauseScreen);
        resumeButton->setObjectName(QString::fromUtf8("resumeButton"));
        resumeButton->setGeometry(QRect(160, 70, 301, 361));
        restartButton = new QPushButton(pauseScreen);
        restartButton->setObjectName(QString::fromUtf8("restartButton"));
        restartButton->setGeometry(QRect(479, 71, 301, 361));
        stackWindow->addWidget(pauseScreen);
        gameplayScreen = new GameScreen();
        gameplayScreen->setObjectName(QString::fromUtf8("gameplayScreen"));
        hydrationBar = new QProgressBar(gameplayScreen);
        hydrationBar->setObjectName(QString::fromUtf8("hydrationBar"));
        hydrationBar->setGeometry(QRect(1220, 20, 51, 451));
        hydrationBar->setStyleSheet(QString::fromUtf8("QProgressBar::chunk {background: r rgb(30, 169, 255)}"));
        hydrationBar->setValue(100);
        hydrationBar->setTextVisible(false);
        hydrationBar->setOrientation(Qt::Vertical);
        stackWindow->addWidget(gameplayScreen);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1300, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackWindow->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QString());
        resumeButton->setText(QCoreApplication::translate("MainWindow", "Resume", nullptr));
        restartButton->setText(QCoreApplication::translate("MainWindow", "Restart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
