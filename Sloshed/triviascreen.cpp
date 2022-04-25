#include "triviascreen.h"
#include "qgraphicseffect.h"
#include <QPainter>
#include <QStyle>
#include <QStyleOption>
#include <QDebug>
#include <QRandomGenerator>

TriviaScreen::TriviaScreen(QWidget *parent)
    : QWidget(parent),
    world(b2Vec2(0.0f, 10.0f)),
    timer(this),
    image(":/GameImages/Images/Trivia.png"),
    x(0), y(0),
    xSpeed(20), ySpeed(20)
{
    // Set background
    //setStyleSheet("background-image: url(:/GameImages/Images/End.png)");

    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(4.0f, 13.0f); // formerly 0.0f, 20.0f

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(50.0f, 10.0f); // formerly 50.0f, 10.0f

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(4.5f, -2.0f); // formerly 0.0f, 4.0f

    body = world.CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;
    // Override the default friction.
    fixtureDef.friction = 0.3f; // formerly 0.3f
    fixtureDef.restitution = 1.0; // 0.9
    // Add the shape to the body.
    body->CreateFixture(&fixtureDef);
    connect(&timer, &QTimer::timeout, this, &TriviaScreen::updateWorld);
    timer.start(50);

    populateTrivia();
}

void TriviaScreen::paintEvent(QPaintEvent *) {
    // Create a painter
    QPainter painter(this);

    // Draw custom style sheet
    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    // Draw bouncing "Trivia" image
    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();
    painter.drawImage((int)(position.x*20), (int)(position.y*20), image);
    painter.end();
}

void TriviaScreen::updateWorld() {
    // It is generally best to keep the time step and iterations fixed.
    world.Step(1.0/60.0, 6, 2);
    update();
}

/**
 * @brief TriviaScreen::populateTrivia called upon intialiazation of game, just populates trivia
 */
void TriviaScreen::populateTrivia(){
    std::vector<QString> question = {"A standard drink is a unit of measurement. In the United States, a standard drink contains 0.6 fluid ounces of alcohol. Which of these drinks represents a standard drink?",
                              "12 oz Bottle of Beer (true)",
                              "5 oz glass of spiked punch (false)",
                              "1 mixed drink (false)"};
  triviaVector.push_back(question);
}

/**
 * Randomizes the vector of answers to be displayed, returns vector of answers.
 * The correctIndex reference outputs the index of the correct answer in the returned vector.
 *
 * How to use references:
 *    int i = 0;
 *    int& correctIndex = i;
 *    answerVector = randomizeTrivia(questionVec, correctIndex);
 *
 * @brief TriviaScreen::randomizeTrivia
 * @param questionVec input vector of questions and answers
 * @param correctIndex reference to an int of wehre the correct index is
 * @return a vector of strings to input on trivia interface
 */
std::vector<QString> TriviaScreen::randomizeTrivia(std::vector<QString> questionVec, int &correctIndex){
    // Set i0, i1, and i2 to be UNIQUE random indices between 0 and 2 (inclusive).
    int i0 = QRandomGenerator::global()->bounded(3);
    int i1 = QRandomGenerator::global()->bounded(2);
    if (i1 == i0) { // i1 can't be 2, so if i1 == i0, then i0 != 2
        i1 = 2; // since i0 != 2, i1 is now 2
        // Note that this gives i1 exactly a 1 in 3 chance to equal 2
    }
    int i2 = 0;
    if (i2 == i1 || i2 == i0) {
        i2 = 1;
    }
    if (i2 == i1 || i2 == i0) {
        i2 = 2;
    }

    // The correct answer will be at index i0 in the new array
    correctIndex = i0;

    // Add answers to a vector and return
    std::vector<QString> answerVec = {"", "", ""};
    answerVec[i0] = questionVec[0];
    answerVec[i1] = questionVec[1];
    answerVec[i2] = questionVec[2];

    return answerVec;
}






// [ [question, 1, 2, 3, 4, correct answer],
// [question1, question2,
  //[answer 1, andeer2
//randomly generate a number
//store index 3
//get answer: pull anser[3]
//get options: pull 3 randomly generated # indeces
        //answer[r1[ answer[r2]
//shuffle and show asnwers
//read player answer
// question1.getQuestion()
// question1.getNextAnswer()

//send back something
//auto generate a numnber between 0-length of number of questions
//mod that number by 4
//hashmap<key int, string array>
//[question, 1 , 2, 3, 4]

