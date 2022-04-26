/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "SceneWidget.h"
#include "gamescreen.h"
#include "triviascreen.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackWindow;
    SceneWidget *startScreen;
    QPushButton *startButton;
    QLabel *instructionsLabel;
    TriviaScreen *collideScreen;
    QLabel *questionLabel;
    QFrame *verticalFrame;
    QVBoxLayout *verticalLayout;
    QPushButton *answerButton1;
    QPushButton *answerButton2;
    QPushButton *answerButton3;
    QWidget *pauseScreen;
    QPushButton *resumeButton;
    QPushButton *restartButton;
    QLabel *label;
    GameScreen *gameplayScreen;
    QProgressBar *hydrationBar;
    QLabel *levelLabel;
    QLabel *hydrateBarLogo;
    QWidget *loseScreen;
    QLabel *intoxLabel;
    QPushButton *resetButton;
    QWidget *crashedScreen;
    QPushButton *crashedResetButton;
    QLabel *crashedLabel;
    QWidget *winScreen;
    QLabel *label_2;
    QPushButton *winResetButton;
    QPushButton *winQuitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 837);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackWindow = new QStackedWidget(centralwidget);
        stackWindow->setObjectName(QString::fromUtf8("stackWindow"));
        stackWindow->setGeometry(QRect(0, 0, 800, 800));
        QFont font;
        stackWindow->setFont(font);
        stackWindow->setAutoFillBackground(false);
        stackWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/End.png)"));
        startScreen = new SceneWidget();
        startScreen->setObjectName(QString::fromUtf8("startScreen"));
        startScreen->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/Background.png)"));
        startButton = new QPushButton(startScreen);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(270, 630, 275, 125));
        startButton->setStyleSheet(QString::fromUtf8("image: url(:/GameImages/Images/Play.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"background-image: url(:/GameImages/Images/TransparentBG);"));
        instructionsLabel = new QLabel(startScreen);
        instructionsLabel->setObjectName(QString::fromUtf8("instructionsLabel"));
        instructionsLabel->setEnabled(true);
        instructionsLabel->setGeometry(QRect(0, 0, 801, 811));
        instructionsLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/Instructions.png)"));
        stackWindow->addWidget(startScreen);
        collideScreen = new TriviaScreen();
        collideScreen->setObjectName(QString::fromUtf8("collideScreen"));
        collideScreen->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/End.png)"));
        questionLabel = new QLabel(collideScreen);
        questionLabel->setObjectName(QString::fromUtf8("questionLabel"));
        questionLabel->setGeometry(QRect(30, 220, 741, 211));
        QFont font1;
        font1.setPointSize(20);
        questionLabel->setFont(font1);
        questionLabel->setAutoFillBackground(false);
        questionLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/TransparentBG);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(162, 0, 255);"));
        questionLabel->setLineWidth(1);
        questionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        questionLabel->setWordWrap(true);
        questionLabel->setMargin(15);
        verticalFrame = new QFrame(collideScreen);
        verticalFrame->setObjectName(QString::fromUtf8("verticalFrame"));
        verticalFrame->setGeometry(QRect(50, 430, 701, 341));
        verticalFrame->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/TransparentBG);"));
        verticalLayout = new QVBoxLayout(verticalFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        answerButton1 = new QPushButton(verticalFrame);
        answerButton1->setObjectName(QString::fromUtf8("answerButton1"));
        answerButton1->setFont(font1);
        answerButton1->setStyleSheet(QString::fromUtf8("color: rgb(149, 153, 162);\n"
"color: rgb(212, 220, 135);\n"
"background-color: rgb(71, 77, 86);"));

        verticalLayout->addWidget(answerButton1);

        answerButton2 = new QPushButton(verticalFrame);
        answerButton2->setObjectName(QString::fromUtf8("answerButton2"));
        answerButton2->setFont(font1);
        answerButton2->setStyleSheet(QString::fromUtf8("color: rgb(149, 153, 162);\n"
"color: rgb(212, 220, 135);\n"
"background-color: rgb(71, 77, 86);"));

        verticalLayout->addWidget(answerButton2);

        answerButton3 = new QPushButton(verticalFrame);
        answerButton3->setObjectName(QString::fromUtf8("answerButton3"));
        answerButton3->setFont(font1);
        answerButton3->setStyleSheet(QString::fromUtf8("color: rgb(149, 153, 162);\n"
"color: rgb(212, 220, 135);\n"
"background-color: rgb(71, 77, 86);"));

        verticalLayout->addWidget(answerButton3);

        stackWindow->addWidget(collideScreen);
        pauseScreen = new QWidget();
        pauseScreen->setObjectName(QString::fromUtf8("pauseScreen"));
        pauseScreen->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/End.png)"));
        resumeButton = new QPushButton(pauseScreen);
        resumeButton->setObjectName(QString::fromUtf8("resumeButton"));
        resumeButton->setGeometry(QRect(110, 410, 275, 125));
        resumeButton->setStyleSheet(QString::fromUtf8("image: url(:/GameImages/Images/Resume.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"background-image: url(:/GameImages/Images/TransparentBG);"));
        restartButton = new QPushButton(pauseScreen);
        restartButton->setObjectName(QString::fromUtf8("restartButton"));
        restartButton->setGeometry(QRect(440, 410, 275, 125));
        restartButton->setStyleSheet(QString::fromUtf8("image: url(:/GameImages/Images/Reset.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"background-image: url(:/GameImages/Images/TransparentBG);"));
        label = new QLabel(pauseScreen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 771, 751));
        label->setLayoutDirection(Qt::RightToLeft);
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/Pause.png)"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        stackWindow->addWidget(pauseScreen);
        label->raise();
        resumeButton->raise();
        restartButton->raise();
        gameplayScreen = new GameScreen();
        gameplayScreen->setObjectName(QString::fromUtf8("gameplayScreen"));
        gameplayScreen->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/Gameplay.png);"));
        hydrationBar = new QProgressBar(gameplayScreen);
        hydrationBar->setObjectName(QString::fromUtf8("hydrationBar"));
        hydrationBar->setGeometry(QRect(740, 40, 50, 540));
        hydrationBar->setStyleSheet(QString::fromUtf8("QProgressBar::chunk {background: r rgb(30, 169, 255)}"));
        hydrationBar->setValue(100);
        hydrationBar->setTextVisible(false);
        hydrationBar->setOrientation(Qt::Vertical);
        levelLabel = new QLabel(gameplayScreen);
        levelLabel->setObjectName(QString::fromUtf8("levelLabel"));
        levelLabel->setGeometry(QRect(20, 30, 271, 60));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(levelLabel->sizePolicy().hasHeightForWidth());
        levelLabel->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(36);
        levelLabel->setFont(font2);
        levelLabel->setStyleSheet(QString::fromUtf8("color: rgb(245, 245, 245); background-image: url(:/GameImages/Images/TransparentBG)"));
        levelLabel->setAlignment(Qt::AlignCenter);
        hydrateBarLogo = new QLabel(gameplayScreen);
        hydrateBarLogo->setObjectName(QString::fromUtf8("hydrateBarLogo"));
        hydrateBarLogo->setGeometry(QRect(740, 40, 50, 540));
        hydrateBarLogo->setAutoFillBackground(false);
        hydrateBarLogo->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/Gauge.png)"));
        stackWindow->addWidget(gameplayScreen);
        levelLabel->raise();
        hydrationBar->raise();
        hydrateBarLogo->raise();
        loseScreen = new QWidget();
        loseScreen->setObjectName(QString::fromUtf8("loseScreen"));
        loseScreen->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/End.png)"));
        intoxLabel = new QLabel(loseScreen);
        intoxLabel->setObjectName(QString::fromUtf8("intoxLabel"));
        intoxLabel->setGeometry(QRect(90, 170, 621, 221));
        intoxLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/Intoxicated.png)"));
        resetButton = new QPushButton(loseScreen);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(260, 410, 275, 125));
        resetButton->setStyleSheet(QString::fromUtf8("image: url(:/GameImages/Images/Reset.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"background-image: url(:/GameImages/Images/TransparentBG);"));
        stackWindow->addWidget(loseScreen);
        crashedScreen = new QWidget();
        crashedScreen->setObjectName(QString::fromUtf8("crashedScreen"));
        crashedResetButton = new QPushButton(crashedScreen);
        crashedResetButton->setObjectName(QString::fromUtf8("crashedResetButton"));
        crashedResetButton->setGeometry(QRect(260, 410, 275, 125));
        crashedResetButton->setStyleSheet(QString::fromUtf8("image: url(:/GameImages/Images/Reset.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"background-image: url(:/GameImages/Images/TransparentBG);"));
        crashedLabel = new QLabel(crashedScreen);
        crashedLabel->setObjectName(QString::fromUtf8("crashedLabel"));
        crashedLabel->setGeometry(QRect(90, 170, 621, 221));
        crashedLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/Lose.png)"));
        stackWindow->addWidget(crashedScreen);
        winScreen = new QWidget();
        winScreen->setObjectName(QString::fromUtf8("winScreen"));
        winScreen->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/End.png);"));
        label_2 = new QLabel(winScreen);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 120, 601, 201));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/GameImages/Images/Win.png);"));
        winResetButton = new QPushButton(winScreen);
        winResetButton->setObjectName(QString::fromUtf8("winResetButton"));
        winResetButton->setGeometry(QRect(260, 370, 281, 131));
        winResetButton->setAutoFillBackground(false);
        winResetButton->setStyleSheet(QString::fromUtf8("image: url(:/GameImages/Images/Reset.png); \n"
"background-color: rgba(255, 255, 255, 0);\n"
"background-image: url(:/GameImages/Images/TransparentBG);"));
        winQuitButton = new QPushButton(winScreen);
        winQuitButton->setObjectName(QString::fromUtf8("winQuitButton"));
        winQuitButton->setGeometry(QRect(260, 520, 281, 131));
        winQuitButton->setFocusPolicy(Qt::ClickFocus);
        winQuitButton->setStyleSheet(QString::fromUtf8("image: url(:/GameImages/Images/Quit.png); \n"
"background-color: rgba(255, 255, 255, 0);\n"
"background-image: url(:/GameImages/Images/TransparentBG);"));
        stackWindow->addWidget(winScreen);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackWindow->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QString());
        instructionsLabel->setText(QString());
        questionLabel->setText(QCoreApplication::translate("MainWindow", "True or False: Eating something substantial like a burger or pasta before or while drinking can cause alcohol to spend more time in the stomach where it is absorbed much more slowly?", nullptr));
        answerButton1->setText(QCoreApplication::translate("MainWindow", "They dont have to drink to have a good time", nullptr));
        answerButton2->setText(QCoreApplication::translate("MainWindow", "answer2", nullptr));
        answerButton3->setText(QCoreApplication::translate("MainWindow", "answer3", nullptr));
        resumeButton->setText(QString());
        restartButton->setText(QString());
        label->setText(QString());
        levelLabel->setText(QCoreApplication::translate("MainWindow", "Level 1/10", nullptr));
        hydrateBarLogo->setText(QString());
        intoxLabel->setText(QString());
        resetButton->setText(QString());
        crashedResetButton->setText(QString());
        crashedLabel->setText(QString());
        label_2->setText(QString());
        winResetButton->setText(QString());
        winQuitButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
