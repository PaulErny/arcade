/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
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

class PacmanGame : public IGames {
    public:
        PacmanGame();
        ~PacmanGame();

        void initGameData(std::string &pseudo);
        void initGraphics();
        void runGame(int &indexGame);
        void setLib(std::shared_ptr<ILibs> &graphics);
        double getFPS();

    private:
        void initMapCell(int x, int y);
        void initMapBorder(int x, int y);
        bool isAdjacentCellForbidden(int x, int y);

        void update();
        void draw();

        std::vector<std::vector<int>> map;
        std::vector<std::vector<Entity>> mapSpritesID;
        std::unique_ptr<Pacman> player;
        std::vector<Ghost> ghosts; //0 = red, 1 = blue, 2 = pink, 3 = yellow

        std::shared_ptr<ILibs> graphics;

        std::clock_t beginFrame;
        std::clock_t endFrame;
        double seconds;
        double deltaTime;
        double frameRate;
        int maxUpdates;
        int frames;


};

#endif /* !PACMANGAME_HPP_ */
