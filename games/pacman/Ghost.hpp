/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ghost
*/

/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#ifndef GHOST_HPP_
#define GHOST_HPP_

#include "../../lib/ILibs.hpp"
#include "../Entity.hpp"
#include "Pacman.hpp"

class Ghost : public Entity {
    public:
        Ghost(std::shared_ptr<ILibs> lib);
        ~Ghost();

        void initGraphics();
        void movePlayer(double deltaTime, std::vector<std::vector<int>> &map);
        bool hitPlayer(std::shared_ptr<Pacman> pacman);

    private:
        void chooseRandomDirection(std::vector<std::vector<int>> &map);

        bool directionChosen;
        bool rightDirection;
        bool leftDirection;
        bool upDirection;
        bool downDirection;
};

#endif /* !GHOST_HPP_ */