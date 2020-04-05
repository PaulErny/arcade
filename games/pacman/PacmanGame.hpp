/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

/**
 * \file PacmanGame.hpp
 * \brief Pacman-Man
 */

#ifndef PACMANGAME_HPP_
#define PACMANGAME_HPP_

#include <map>
#include <memory>
#include <ctime>
#include <unistd.h>
#include "../../lib/ILibs.hpp"
#include "../IGames.hpp"
#include "../Entity.hpp"
#include "Pacman.hpp"
#include "Ghost.hpp"

/*! \class PacmanGame
   * \brief class of PacmanGame
   *
   */
class PacmanGame : public IGames {
    public:
    /**
 * \fn PacmanGame();
 * \brief Constructor
 * 
 */
        PacmanGame();
        /**
 * \fn ~PacmanGame();
 * \brief Destructor
 * 
 */
        ~PacmanGame();

        void initGameData(std::string &pseudo);
        void initGraphics();
        void runGame(int &indexGame, int &indexLib);
        void setLib(std::shared_ptr<ILibs> &graphics);
        /**
 * \fn double getFPS();
 * \brief Function that get FPS in Pacman
 * 
 * \return double
 */
        double getFPS();

    private:
        void initMapCell(size_t x, size_t y);
        void initMapBorder(size_t x, size_t y);
        bool isAdjacentCellForbidden(size_t x, size_t y);

        void update();
        void draw();

        std::string name;
        int score;
        int remainingCoins;
        int fontID;
        std::string scoreText;
        int scoreTextID;

        std::vector<std::vector<int>> map;
        std::vector<std::vector<Entity>> mapSpritesID;
        std::shared_ptr<Pacman> player;
        std::vector<std::unique_ptr<Ghost>> ghosts; //0 = red, 1 = blue, 2 = pink, 3 = yellow

        std::shared_ptr<ILibs> graphics;

        std::clock_t beginFrame;
        std::clock_t endFrame;
        double remainingTime;
        double deltaTime;
        double frameRate;
        double frameTime;
        int maxUpdates;
        int frames;
};

#endif /* !PACMANGAME_HPP_ */
