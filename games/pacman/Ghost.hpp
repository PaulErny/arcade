/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ghost
*/
/**
 * \file Ghost.hpp
 * \brief Ghost
 */

#ifndef GHOST_HPP_
#define GHOST_HPP_

#include "../../lib/ILibs.hpp"
#include "../Entity.hpp"
#include "Pacman.hpp"

/*! \class Ghost
   * \brief class of Ghost
   *
   */
class Ghost : public Entity {
    public:
    /**
 * \fn Ghost(std::shared_ptr<ILibs> lib);
 * \brief Constructor
 * 
 * \param lib Lib available
 */
        Ghost(std::shared_ptr<ILibs> lib);
        /**
 * \fn ~Ghost();
 * \brief Destructor
 * 
 */
        ~Ghost();
/**
 * \fn void initGraphics();
 * \brief Function that init graphic for the Ghosts in Pac-Man
 */
        void initGraphics();
        /**
 * \fn void movePlayer(double deltaTime, std::vector<std::vector<int>> &map);
 * \brief Function that get FPS in Pac-Man
 * 
 * \param deltaTime time of execution a boucle round
 * \param map It's the map of the game
 */
        void movePlayer(double deltaTime, std::vector<std::vector<int>> &map);
        /**
 * \fn bool hitPlayer(std::shared_ptr<Pacman> pacman);
 * \brief Function that manage hit in the game
 * 
 * \param pacman It's the player
 * 
 * \return bool
 */
        bool hitPlayer(std::shared_ptr<Pacman> pacman);
        /**
 * \fn void goRight();
 * \brief Function that move player to the right
 */
        void goRight();
   /**
 * \fn void goLeft();
 * \brief Function that move player to the left
 */
        void goLeft();
   /**
 * \fn void goUp();
 * \brief Function that move player to the up
 */
        void goUp();
   /**
 * \fn void goDown();
 * \brief Function that move player to the down
 */
        void goDown();

    private:
        bool isCellWalkable(int x, int y, std::vector<std::vector<int>> &map);
        void chooseDirection(std::vector<std::vector<int>> &map);
        void chooseRandomDirection(std::vector<std::vector<int>> &map);

        bool directionChosen;
        bool rightDirection;
        bool leftDirection;
        bool upDirection;
        bool downDirection;
};

#endif /* !GHOST_HPP_ */