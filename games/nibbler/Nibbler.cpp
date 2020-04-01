#include "Nibbler.hpp"

Nibbler::Nibbler()
{
}

void Nibbler::initGameData()
{

}

void Nibbler::initGraphics()
{
    food = std::make_shared<Entity>(SHAPE, this->Lib);
    food->addShape(40, 40);
    food->setPosition(rand() % 1080, rand() % 1080);
    std::shared_ptr<Entity> head = std::make_shared<Entity>(SHAPE, this->Lib);
    head->addShape(40, 40);
    snake.push_back(head);
}

void Nibbler::runGame()
{
    keyPressed();
    if (food->getXposition() == snake.at(0)->getXposition() &&
    food->getYposition() == snake.at(0)->getYposition()) {
        eatFood();
    }
    Lib->drawShape(food->getVectorOfShape().at(0));
    moove();
    for (int i = 0; i < (int)snake.size(); i++) {
        Lib->drawShape(snake.at(i)->getVectorOfShape().at(0));
    }
}

void Nibbler::moove()
{
    if (dir == UP) {
        prevPosy = snake.at(0)->getYposition();
        snake.at(0)->move(snake.at(0)->getYposition() + 1, snake.at(0)->getXposition());
        for (int i = 0; i < (int)snake.size() - 1; i++) {
            snake.at(i + 1)->move(snake.at(i)->getXposition(), snake.at(i)->getYposition());
        }
    } else if (dir == DOWN) {
        prevPosy = snake.at(0)->getYposition();
        snake.at(0)->move(snake.at(0)->getYposition() - 1, snake.at(0)->getXposition());
        for (int i = 0; i < (int)snake.size() - 1; i++) {
            snake.at(i + 1)->move(snake.at(i)->getXposition(), snake.at(i)->getYposition());
        }
    } else if (dir == LEFT) {
        prevPosy = snake.at(0)->getXposition();
        snake.at(0)->move(snake.at(0)->getYposition(), snake.at(0)->getXposition() - 1);
        for (int i = 0; i < (int)snake.size() - 1; i++) {
            snake.at(i + 1)->move(snake.at(i)->getXposition(), snake.at(i)->getYposition());
        }
    } else if (dir == RIGTH) {
        prevPosy = snake.at(0)->getXposition();
        snake.at(0)->move(snake.at(0)->getYposition(), snake.at(0)->getXposition() + 1);
        for (int i = 0; i < (int)snake.size() - 1; i++) {
            snake.at(i + 1)->move(snake.at(i)->getXposition(), snake.at(i)->getYposition());
        }
    }
}

void Nibbler::keyPressed()
{
    if (Lib->upArrow())
        dir = UP;
    else if (Lib->downArrow())
        dir = DOWN;
    else if (Lib->leftArrow())
        dir = LEFT;
    else if (Lib->rigthArrow())
        dir = RIGTH;
}

void Nibbler::eatFood()
{
    std::shared_ptr<Entity> tail = std::make_shared<Entity>(SHAPE, this->Lib);
    tail->addShape(40, 40);
    snake.push_back(tail);
    food->setPosition(rand() % 1080, rand() % 1080);
}