/************************************************
 * GameScreen class
 * Class definition for GameScreen QWidget
 * Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/18/2022
************************************************/
#include "gamescreen.h"
#include <QStyle>
#include <QStyleOption>

/**
 * GameScreen constructor
 * @brief GameScreen::GameScreen
 * @param parent
 */
GameScreen::GameScreen(QWidget *parent)
    : QWidget{parent}
{
    gameplayView = new QGraphicsView();
    gameplayView->setParent(this);
    gameplayView->resize(MainWindow::WIDTH, MainWindow::HEIGHT);
    gameplayScene = new QGraphicsScene(this);
    gameplayView->setRenderHint(QPainter::SmoothPixmapTransform);
    gameplayView->setScene(gameplayScene);
    gameplayScene->setSceneRect(0, 0, MainWindow::WIDTH, MainWindow::HEIGHT);
    emit updateLevelView(level);

    // Set up player (Note: moved this here so we can make connect calls without crashing)
    addPlayer();

    // Timer for the whole scene and send trucks
    initTimers();

    // Turns off scrollbar horizontally or vertically
    this->gameplayView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->gameplayView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

/**
 * Initializes the game timers.
 * @brief GameScreen::initTimers
 */
void GameScreen::initTimers() {
    sceneTimer = new QTimer(this);
    truckTimer = new QTimer(this);
    mouseTimer = new QTimer(this);
    hydrationTimer = new QTimer(this);
    connect(sceneTimer, &QTimer::timeout, gameplayScene, &QGraphicsScene::advance);
    connect(truckTimer, &QTimer::timeout, this, &GameScreen::sendTruck);
    connect(mouseTimer, &QTimer::timeout, this, &GameScreen::sendMousePosition);
    connect(hydrationTimer, &QTimer::timeout, this, &GameScreen::sendHydrationTimer);
    connect(player, &Player::hasCollided, this, &GameScreen::handleCollision);
    connect(player, &Player::nextLevel, this, &GameScreen::nextLevel);
}

/**
 * Adds the player to the game.
 * @brief GameScreen::addPlayer
 */
void GameScreen::addPlayer() {
    player = new Player();

    player->setTransformOriginPoint(player->boundingRect().width()/2 , player->boundingRect().height()/2);
    player->setScale(0.6);
    gameplayScene->addItem(player);
}

/**
 * Stops any old games and starts a new game. (Actually starts gameplay!)
 * @brief GameScreen::restartGame
 * @param fromLevelOne True by default or if you want to start the game from level 1. False otherwise.
 */
void GameScreen::startGame(bool fromLevelOne) {
    stopGame();
    if (fromLevelOne) {
        level = 1;
        emit updateLevelView(level);
    }
    addPlayer();
    initTimers();
    emit resetWater();
    placeWaterBottles();
    resumeGame();
}

/**
 * Starts the game from where it left off.
 * Will NOT stop or reset any old games.
 * @brief GameScreen::startGame
 */
void GameScreen::resumeGame() {
    sceneTimer->start(sceneAdvanceDelay);
    truckTimer->start(truckSpawnDelays[level - 1]);
    mouseTimer->start(mouseDelay);
    hydrationTimer->start(waterDelay);
    emit sendHydrationTimer();
}

/**
 * Pauses the game. (Does NOT stop or reset game.)
 * @brief GameScreen::startGame
 */
void GameScreen::pauseGame() {
    sceneTimer->stop();
    truckTimer->stop();
    mouseTimer->stop();
    hydrationTimer->stop();
}

/**
 * Stops the currently running game.
 * @brief GameScreen::stopGame
 */
void GameScreen::stopGame() {
    pauseGame();
    gameplayScene->clear();
}

/**
 * Adds a truck to a lane.
 * @brief GameScreen::sendTruck
 */
void GameScreen::sendTruck() {
    // y coordinates of the 4 lanes
    QList<int> lanes = {165, 300, 440, 575};
    // Get random lane
    int laneNum = QRandomGenerator::global()->bounded(lanes.size());
    // 0th and 3rd lane have trucks moving right. Other lanes move left.
    bool movingRight = laneNum % 2 == 0;
    // Define truck attributes
    Truck *truck;
    int y_pos = lanes[laneNum];
    int speed = truckSpeeds[level - 1];
    // Place truck
    if (movingRight)
        truck = new Truck(0 - Truck::HEIGHT, y_pos, speed, true);
    else
        truck = new Truck(MainWindow::WIDTH + Truck::WIDTH, y_pos, speed, false);
    // Set truck to transform (e.g. spin) from its center point
    truck->setTransformOriginPoint(truck->boundingRect().width()/2, truck->boundingRect().height()/2);
    gameplayScene->addItem(truck);
}

/**
 * Advances the game to the next level, or if level 10 is beat, tells MainWindow the game is won.
 * @brief GameScreen::nextLevel
 */
void GameScreen::nextLevel() {
    // Change truckSpawnDelay and sceneAdvanceDelay
    if (level < MAX_LEVEL) {
        level++;
        emit updateLevelView(level);
        startGame(false);
    }
    else {
        emit wonGame();
    }
}

/**
 * Adds water bottles to the level
 * @brief GameScreen::placeWaterBottles
 */
void GameScreen::placeWaterBottles() {
    // x coordinates
    QList<int> cols = {60, 188, 316, 444, 572, 700};
    // y coordinates of the 4 lanes (center)
    QList<int> lanes = {145, 280, 420, 555};

    // Place a bottle in each lane
    foreach (int y, lanes) {
        // Get random x coordinate
        int x = cols[QRandomGenerator::global()->bounded(cols.size())];

        // Place water bottle
        WaterBottle *bottle = new WaterBottle(nullptr, x, y);
        gameplayScene->addItem(bottle);
        connect(bottle, &WaterBottle::addWater, this, &GameScreen::addWaterToBar);
    }
}

/**
 * Sends the current mouse position to the player object.
 * @brief GameScreen::sendMousePosition
 */
void GameScreen::sendMousePosition() {
    int x = this->mapFromGlobal(QCursor::pos()).x();
    int y = this->mapFromGlobal(QCursor::pos()).y();
    player->mousePosition(x, y);
}

/**
 * Stops the game after a 1.5 second delay when the player collides with
 * a truck. Emits a signal to bring up the CollideScreen in MainWindow.
 * @brief GameScreen::handleCollision
 */
void GameScreen::handleCollision() {
    // Delay before stopping game
    QTimer::singleShot(1500, this, &GameScreen::stopGame);
    emit sendCollideScreen();
}

/**
 * Adds water to the hydration bar.
 * @brief GameScreen::addWaterToBar
 */
void GameScreen::addWaterToBar() {
    emit addWater();
}

/**
 * Paints the GameScreen's style sheet.
 * @brief GameScreen::paintEvent
 */
void GameScreen::paintEvent(QPaintEvent *) {
    // Draw custom style sheet
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

/**
 * Changes the player's speed to a new value
 * @brief GameScreen::changeSpeed
 * @param speed the new speed value for player
 */
void GameScreen::changeSpeed(int speed) {
    player->changeSpeed(speed);
}
