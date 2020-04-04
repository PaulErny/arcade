#ifndef NIBBLER_HPP
#define NIBLLER_HPP

#include <vector>
#include <memory>
#include "../../lib/ILibs.hpp"
#include "../IGames.hpp"
#include "../Entity.hpp"

enum Direction {
    RIGTH,
    LEFT,
    UP,
    DOWN,
    NO
};

class Nibbler : public IGames
{
private:
    Direction dir;
    int speed;
    std::shared_ptr<Entity> food;
    std::vector<int> indexSnake;
    std::vector<std::shared_ptr<Entity>> snake;
    std::shared_ptr<ILibs> Lib;
    int prevPosx;
    int prevPosy;
    int indexTitle;
    int indexPseudo;
    std::string pseudo;
    int indexGameLoose;
public:
    Nibbler();
    void setLib(std::shared_ptr<ILibs> &Lib);
    void keyPressed(int &indexGame, int &indexLib);
    void moove();
    void eatFood();
    void setPos();
    void initGameData(std::string &pseudo);
    void initGraphics();
    void runGame(int &indexGame, int &indexLib);
    void checkLoose();
    void endGame();
};

#endif