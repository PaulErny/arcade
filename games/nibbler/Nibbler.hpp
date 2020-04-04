/**
 * \file Nibbler.hpp
 * \brief Game Nibbler
 */

#ifndef NIBBLER_HPP
#define NIBLLER_HPP

#include <vector>
#include <memory>
#include "../../lib/ILibs.hpp"
#include "../IGames.hpp"
#include "../Entity.hpp"

/**
 * \enum Direction
 * \brief Direction player
 * 
 * RIGHT / LEFT / UP / DOWN / NO
 */
enum Direction {
    RIGTH,
    LEFT,
    UP,
    DOWN,
    NO
};

/*! \class Nibbler
   * \brief class of Nibbler
   */
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
/**
 * \fn Nibbler();
 * \brief Constructor
 * 
 */
    Nibbler();
    void setLib(std::shared_ptr<ILibs> &Lib);
    /**
 * \fn void keyPressed(int &indexGame, int &indexLib);
 * \brief Function that manage the event with the keyboard
 * 
 * \param indexGame of vector game
 * \param indexLib of vector lib
 * 
 */
    void keyPressed(int &indexGame, int &indexLib);
    /**
 * \fn void moove();
 * \brief Function that manage the player's movement
 */
    void moove();
    /**
 * \fn void eatFood();
 * \brief Function that see if the player eat food
 */
    void eatFood();
    /**
 * \fn void setPos();
 * \brief Function that set pos the player
 * 
 */
    void setPos();
    void initGameData(std::string &pseudo);
    void initGraphics();
    void runGame(int &indexGame, int &indexLib);
    /**
 * \fn void checkLoose();
 * \brief Function that check if the game is Loose.
 * If the player touch the wall is loose.
 * 
 */
    void checkLoose();
    /**
 * \fn void endGame();
 * \brief End Screen
 */
    void endGame();
};

#endif