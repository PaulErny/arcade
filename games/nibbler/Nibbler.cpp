/**
 * \file Nibbler.cpp
 * \brief Game Nibbler
 */
#include "Nibbler.hpp"

Nibbler::Nibbler()
{
}

void Nibbler::setLib(std::shared_ptr<ILibs> &Lib)
{
    this->Lib = Lib;
}

void Nibbler::initGameData(std::string &pseudo)
{
    this->dir = NO;
    this->pseudo = pseudo;
}

void Nibbler::initGraphics()
{
    int fontID = Lib->createFontFromFile("./resources/ARCADE_I.TTF");
    int fontID2 = Lib->createFontFromFile("./resources/ARCADE_I.TTF");
    indexPseudo = Lib->createText(pseudo, fontID);
    indexGameLoose = Lib->createText("YOU LOOSE", fontID2);
    Lib->setTextPos(indexPseudo, 0, 0);
    Lib->setTextPos(indexGameLoose, 400, 400);
    food = std::make_shared<Entity>();
    food->setLibPtr(Lib);
    food->setType(SHAPE);
    food->addShape(32, 32);
    food->setPosition(rand() % 1080, rand() % 1080);
    std::shared_ptr<Entity> head = std::make_shared<Entity>();
    head->setType(SHAPE);
    head->setLibPtr(Lib);
    head->addShape(32, 32);
    head->setPosition(500, 500);
    snake.push_back(head);
}

void Nibbler::endGame()
{
    while (Lib->isWindowOpen()) {
        while (Lib->events()) {
            Lib->closeWindowEvent();
        }
        Lib->clearWindow();
        Lib->drawText(indexGameLoose);
        Lib->update();
    }
}

void Nibbler::checkLoose()
{
    if (snake.at(0)->getXposition() >= 1080 || snake.at(0)->getXposition() < 0 
    || snake.at(0)->getYposition() >= 1080 || snake.at(0)->getYposition() < 0)
    {
        endGame();
    }
}

void Nibbler::runGame(int &indexGame, int &indexLib)
{
    keyPressed(indexGame, indexLib);
    // std::cout << "food "<< food->getXposition() << " " << food->getYposition() << std::endl;
    // std::cout << "snake " << snake.at(0)->getXposition() << " " << snake.at(0)->getYposition() << std::endl;
    if (food->getXposition() + 32 > snake.at(0)->getXposition() &&
        food->getXposition() - 32 < snake.at(0)->getXposition() &&
        food->getYposition() + 32 > snake.at(0)->getYposition() &&
        food->getYposition() - 32 < snake.at(0)->getYposition())
    {
        eatFood();
        std::cout << snake.size() << std::endl;
    }
    Lib->drawShape(food->getVectorOfShape().at(0));
    moove();
    Lib->drawText(indexPseudo);
    for (int i = 0; i < (int)snake.size(); i++) {
        Lib->drawShape(snake.at(i)->getVectorOfShape().at(0));
    }
    checkLoose();
}

void Nibbler::moove()
{
    if (dir == UP) {
        prevPosy = snake.at(0)->getYposition();
        snake.at(0)->move(0, -0.4);
        for (int i = 0; i < (int)snake.size() - 1; i++) {
            snake.at(i + 1)->move(0, prevPosy);
            prevPosy = snake.at(i)->getYposition();
        }
    } else if (dir == DOWN) {
        prevPosy = snake.at(0)->getYposition();
        snake.at(0)->move(0, 0.4);
        for (int i = 0; i < (int)snake.size() - 1; i++) {
            snake.at(i + 1)->move(0, prevPosy);
            prevPosy = snake.at(i)->getYposition();
        }
    } else if (dir == LEFT) {
        prevPosx = snake.at(0)->getXposition();
        snake.at(0)->move(-0.4, 0);
        for (int i = 0; i < (int)snake.size() - 1; i++) {
            snake.at(i + 1)->move(prevPosx, 0);
            prevPosx = snake.at(i)->getXposition();
        }
    } else if (dir == RIGTH) {
        prevPosx = snake.at(0)->getXposition();
        snake.at(0)->move(0.4, 0);
        for (int i = 0; i < (int)snake.size() - 1; i++) {
            snake.at(i + 1)->move(prevPosx, 0);
            prevPosx = snake.at(i)->getXposition();
        }
    }
}

void Nibbler::keyPressed(int &indexGame, int &indexLib)
{
    while (Lib->events()) {
        if (Lib->upArrow())
            dir = UP;
        else if (Lib->downArrow())
            dir = DOWN;
        else if (Lib->leftArrow())
            dir = LEFT;
        else if (Lib->rigthArrow())
            dir = RIGTH;
        Lib->nextGameLib(indexGame);
        Lib->prevGameLib(indexGame);
        Lib->nextGraphicLib(indexLib);
        Lib->prevGraphicLib(indexLib);
        Lib->closeWindowEvent();
    }
}

void Nibbler::eatFood()
{
    std::shared_ptr<Entity> tail = std::make_shared<Entity>();
    tail->setLibPtr(Lib);
    tail->setType(SHAPE);
    tail->addShape(32, 32);
    tail->setPosition(snake.at(0)->getXposition() - 32, snake.at(0)->getYposition() -32);
    snake.push_back(tail);
    food->setPosition(rand() % 1080, rand() % 1080);
}

extern "C" std::shared_ptr<Nibbler> create_object()
{
    return std::make_shared<Nibbler>();
}