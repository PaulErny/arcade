/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

/**
 * \file Pacman.hpp
 * \brief Pac-Man
 */

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "../../lib/ILibs.hpp"
#include "../Entity.hpp"

/*! \class Pacman
   * \brief class of Pacman
   *
   */
class Pacman : public Entity {
    public:
    /**
 * \fn Pacman(std::shared_ptr<ILibs> lib);
 * \brief Constructor
 * 
 * \param lib Lib available
 */
        Pacman(std::shared_ptr<ILibs> lib);
        /**
 * \fn ~Pacman();
 * \brief Destructor
 * 
 */
        ~Pacman();
/**
 * \fn void initGraphics();
 * \brief Function that init graphic for Pac-Man
 */
        void initGraphics();
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
   /**
 * \fn void movePlayer(double deltaTime, std::vector<std::vector<int>> &map);
 * \brief Function that get FPS in Pac-Man
 * 
 * \param deltaTime time of execution a boucle round
 * \param map It's the map of the game
 */
        void movePlayer(double deltaTime, std::vector<std::vector<int>> &map);
   /**
 * \fn int eatCoin(std::vector<std::vector<int>> &map, std::vector<std::vector<Entity>> &mapSpritesID, int &remainingCoins);
 * \brief Function that eat coin in the map when you pass over it
 * 
 * \param map It's the map of the game
 * \param mapSpriteID Spirte of the map ID
 * \param remainingCoins How many coins in the map yet ?
 */
        int eatCoin(std::vector<std::vector<int>> &map, std::vector<std::vector<Entity>> &mapSpritesID, int &remainingCoins);

    private:
        bool rightDirection;
        bool leftDirection;
        bool upDirection;
        bool downDirection;
};

#endif /* !PACMAN_HPP_ */
