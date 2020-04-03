/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#include "Pacman.hpp"

Pacman::Pacman(std::shared_ptr<ILibs> lib)
{
    this->setLibPtr(lib);
    this->setType(SPRITE);
    this->setPosition(/* xOffset */92 + /* x */14 * 32 - 16, /* yOffset */44 + /* y */ 23 *32);
}

Pacman::~Pacman()
{
}

void Pacman::initGraphics()
{
    this->addImage("pacman/resources/pacman_up_1.png");
    this->updatePosition();
}

void Pacman::goRight()
{
    if (!this->rightDirection) {
        this->rightDirection = true;
        this->leftDirection = false;
        this->upDirection = false;
        this->downDirection = false;
    }

}

void Pacman::goLeft()
{
    if (!this->rightDirection) {
        this->rightDirection = false;
        this->leftDirection = true;
        this->upDirection = false;
        this->downDirection = false;
    }
}

void Pacman::goUp()
{
    if (!this->rightDirection) {
        this->rightDirection = false;
        this->leftDirection = false;
        this->upDirection = true;
        this->downDirection = false;
    }
}

void Pacman::goDown()
{
    if (!this->rightDirection) {
        this->rightDirection = false;
        this->leftDirection = false;
        this->upDirection = false;
        this->downDirection = true;
    }
}