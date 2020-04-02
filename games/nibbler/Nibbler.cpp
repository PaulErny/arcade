#include "Nibbler.hpp"

Nibbler::Nibbler()
{
}

void Nibbler::setLib(std::shared_ptr<ILibs> &Lib)
{
    this->Lib = Lib;
}

void Nibbler::initGameData()
{

}

void Nibbler::initGraphics()
{
    int fontID = Lib->createFontFromFile("../resources/ARCADE_I.TTF");
    indexPseudo = Lib->createText("THE RV", fontID);
    Lib->setTextColor(indexPseudo, 0, 0, 0);
    Lib->setTextPos(indexPseudo, 400, 0);
    food = std::make_shared<Entity>();
    food->setLibPtr(Lib);
    food->setType(SHAPE);
    food->addShape(40, 40);
    food->setPosition(rand() % 1080, rand() % 1080);
    std::shared_ptr<Entity> head = std::make_shared<Entity>();
    head->setType(SHAPE);
    head->setLibPtr(Lib);
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
    Lib->drawText(indexPseudo);
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
    std::shared_ptr<Entity> tail = std::make_shared<Entity>();
    tail->setLibPtr(Lib);
    tail->setType(SHAPE);
    tail->addShape(40, 40);
    snake.push_back(tail);
    food->setPosition(rand() % 1080, rand() % 1080);
}

// extern "C" std::shared_ptr<Nibbler> create_object()
// {
//     return std::make_shared<Nibbler>();
// }