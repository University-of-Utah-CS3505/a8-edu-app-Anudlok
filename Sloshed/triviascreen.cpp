/************************************************
 * TriviaScreen class
 * Class definition for TriviaScreen QWidget
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian, Angela Mishler
 * @date: 4/24/2022
************************************************/
#include "triviascreen.h"
#include "qgraphicseffect.h"
#include <QPainter>
#include <QStyle>
#include <QStyleOption>
#include <QDebug>
#include <QRandomGenerator>

/**
 * Constructor for TriviaScreen.
 * Initializes variables, especially the images and Box2D objects.
 * Also populates the trivia vector.
 * @brief TriviaScreen::TriviaScreen
 * @param parent
 */
TriviaScreen::TriviaScreen(QWidget *parent)
    : QWidget(parent),
    world(b2Vec2(0.0f, 10.0f)),
    timer(this),
    image(":/GameImages/Images/Trivia.png"),
    x(0), y(0),
    xSpeed(20), ySpeed(20)
{
    populateTrivia();
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

/**
 * Draws the style sheet and redraws the bouncing "Trivia" image.
 * @brief TriviaScreen::paintEvent
 */
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

/**
 * Updates the Box2D world to make the "Trivia" image bounce.
 * @brief TriviaScreen::updateWorld
 */
void TriviaScreen::updateWorld() {
    // It is generally best to keep the time step and iterations fixed.
    world.Step(1.0/60.0, 6, 2);
    update();
}

/**
 * @brief TriviaScreen::populateTrivia called upon initialization of game, populates trivia vector with questions and answers
 */
void TriviaScreen::populateTrivia(){
  triviaVector.push_back(std::vector<QString>{"A standard drink is a unit of measurement. In the United States, a standard drink contains 0.6 fluid ounces of alcohol. Which of these drinks represents a standard drink?",
                                         "12 oz Bottle of Beer",
                                         "5 oz glass of spiked punch",
                                         "1 mixed drink"});
  triviaVector.push_back(std::vector<QString>{"Most hard alcohol (like vodka and rum) is approximately how high in percentage of alcohol?",
                                              "40%",
                                              "20%",
                                              "5%"});
  triviaVector.push_back(std::vector<QString>{"What do you think is the top reason given by students who choose to not drink?",
                                              "They are going to drive",
                                              "They dont want to spend the money",
                                              "They dont have to drink to have a good time"});
  triviaVector.push_back(std::vector<QString>{"What percentage of college students don’t drink at all?",
                                              "36%",
                                              "67%",
                                              "12%"});
  triviaVector.push_back(std::vector<QString>{"Which of these types of drinks can speed up alcohol absorption?",
                                              "Carbonated mixers",
                                              "Sweet Mixers",
                                              "Caffeinated Beverages"});
  triviaVector.push_back(std::vector<QString>{"True or False: Eating something substantial like a burger or pasta before or while drinking can cause alcohol to spend more time in the stomach where it is absorbed much more slowly?",
                                              "True",
                                              "False",
                                              ""});
  triviaVector.push_back(std::vector<QString>{"The ___ a person drinks, the ___ their BAC rises.",
                                              "Faster",
                                              "Slower",
                                              ""});
  triviaVector.push_back(std::vector<QString>{"True or False: Time is the only way to lower BAC.",
                                              "True",
                                              "False",
                                              ""});
  triviaVector.push_back(std::vector<QString>{"BAC typically rises quickly for females than males",
                                              "True",
                                              "False",
                                              ""});
  triviaVector.push_back(std::vector<QString>{"In which BAC levels will you experience confusion, dizziness or slurred speech?",
                                              ".11-.20",
                                              ".05-.10",
                                              ".21-.35"});
  triviaVector.push_back(std::vector<QString>{"True or False: Mixing alcohol with energy drinks will not mask the feeling of alcohol impairment.",
                                              "False",
                                              "True",
                                              ""});
  triviaVector.push_back(std::vector<QString>{"Drinking alcohol _____ reduce the the effectiveness of oral contraceptives.",
                                              "Does not",
                                              "Does",
                                              ""});
  triviaVector.push_back(std::vector<QString>{"A person is ___ responsible for obtaining clear consent for sexual activity regardlesss of whether they have been drinking alcohol",
                                              "Always",
                                              "Never",
                                              ""});
  triviaVector.push_back(std::vector<QString>{"What time period for a college student is most vulnerable for heavy drinking and alcohol-related consequences?",
                                              "First 6 weeks of freshman year",
                                              "Every finals week ",
                                              "Last 6 weeks of senior year"});
  //stopped at mixing alcohol with substances
  triviaVector.push_back(std::vector<QString>{"True or False: When alcohol is combined with opioids it magnifies and amplifies the effects of opioids to a dangerous level.",
                                              "True",
                                              "False",
                                               ""});
  triviaVector.push_back(std::vector<QString>{"Which of these effects do Alcohol and Adderall have on the heart when combined?",
                                              "All of the above",
                                              "Increased blood pressure",
                                              "Increased heart rate"});
  triviaVector.push_back(std::vector<QString>{"Antidepressants and alcohol ___ the impacts of each other.",
                                              "Magnify",
                                              "Lessen ",
                                              ""});
  triviaVector.push_back(std::vector<QString>{"Which of these puts extreme pressure and stress on the heart?",
                                              "Mixing alcohol and cocaine ",
                                              "Drinking a shot after a beer",
                                              "Running after drinking a beer"});

  triviaVector.push_back(std::vector<QString>{"*Which of these are common side effects when mixing Marijuana and Alcohol?",
                                              "All of the above",
                                              "Compromised judgment",
                                              "Decreased attention, perception and memory"});
  triviaVector.push_back(std::vector<QString>{"True or False: Marijuana suppresses the gag reflex and may leave intoxicated individuals unable to throw up, causing alcohol poisoning.",
                                              "True",
                                              "False ",
                                              ""});
}

/**
 * @brief TriviaScreen::giveMeARandomQuestion run by mainwindow and prompts trivia screen to send a random question
 * @return a vector of Qstrings with teh possible answers
 */
std::vector<QString> TriviaScreen::giveMeARandomQuestion(){
   int questionIndex = QRandomGenerator::global()->bounded(20); //20 is size of trivia vector
   return randomizeTrivia(triviaVector.at(questionIndex));
}

/**
 * @brief TriviaScreen::checkAnswer checks whether the given answer is correct
 * @param answerNum
 * @return
 */
bool TriviaScreen::checkAnswer(int answerNum){
        return answerNum == correctIndex;
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
std::vector<QString> TriviaScreen::randomizeTrivia(std::vector<QString> questionVec){
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
    correctIndex = i0+1;

    // Add answers to a vector and return
    std::vector<QString> answerVec = {questionVec[0],"", "", ""};
    answerVec[i0+1] = questionVec[1];
    answerVec[i1+1] = questionVec[2];
    answerVec[i2+1] = questionVec[3];

    return answerVec;
}
