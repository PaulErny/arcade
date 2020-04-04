/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "../../lib/ILibs.hpp"
#include "../Entity.hpp"

class Pacman : public Entity {
    public:
        Pacman(std::shared_ptr<ILibs> lib);
        ~Pacman();

        void initGraphics();
        void goRight();
        void goLeft();
        void goUp();
        void goDown();
        void movePlayer(double deltaTime, std::vector<std::vector<int>> map);

    private:
        bool rightDirection;
        bool leftDirection;
        bool upDirection;
        bool downDirection;
};

#endif /* !PACMAN_HPP_ */
