/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <map>
#include <memory>
#include "../IGames.hpp"
#include "../Entity.hpp"

class Pacman : public IGames {
    public:
        Pacman(std::shared_ptr<ILibs> &graphics);
        ~Pacman();

        void initGameData();
        void initGraphics();
        void runGame();

    private:
        void initMapCell(int x, int y);
        bool isAdjacentCellForbidden(int x, int y);

        std::vector<std::vector<int>> map;
        std::vector<std::vector<int>> mapSpritesID;
        std::shared_ptr<ILibs> graphics;
};

#endif /* !PACMAN_HPP_ */
