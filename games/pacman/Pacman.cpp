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

    this->rightDirection = false;
    this->leftDirection = false;
    this->upDirection = false;
    this->downDirection = false;
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
    if (!this->leftDirection) {
        this->rightDirection = false;
        this->leftDirection = true;
        this->upDirection = false;
        this->downDirection = false;
    }
}

void Pacman::goUp()
{
    if (!this->upDirection) {
        this->rightDirection = false;
        this->leftDirection = false;
        this->upDirection = true;
        this->downDirection = false;
    }
}

void Pacman::goDown()
{
    if (!this->downDirection) {
        this->rightDirection = false;
        this->leftDirection = false;
        this->upDirection = false;
        this->downDirection = true;
    }
}

void Pacman::movePlayer(double deltaTime, std::vector<std::vector<int>> map) // deltaTime in sec
{
    // get map pos
    float topLeftMapPosX = (this->posX + 7 - 92) / 32; // - 7 and + 24 to reduce the hitbox of pacman from 32x32px to 17x17px makes turning easier
    float topLeftMapPosY = (this->posY + 7 - 44) / 32; // -92 and -44 are xOffset and yOffset used to put sprites in the center of the window
    float botRightMapPosX = (this->posX + 24 - 92) / 32; // 32 is the default size of a sprite -> divide by 32 to obtain the sprite pos in the map
    float botRightMapPosY = (this->posY + 24 - 44) / 32;
    // move pacman if possible
    if (this->rightDirection) {
        if (map[(int)botRightMapPosY][(int)(botRightMapPosX + ((200 * deltaTime) / 32))] == 2 || // 2 is small coin
            map[(int)botRightMapPosY][(int)(botRightMapPosX + ((200 * deltaTime) / 32))] == 3 || // 3 is big coin
            map[(int)botRightMapPosY][(int)(botRightMapPosX + ((200 * deltaTime) / 32))] == 0) // 0 is an empty tile
            this->move(200 * deltaTime, 0);
    }
    if (this->leftDirection) {
        if (map[(int)topLeftMapPosY][(int)(topLeftMapPosX + ((-200 * deltaTime) / 32))] == 2 || 
            map[(int)topLeftMapPosY][(int)(topLeftMapPosX + ((-200 * deltaTime) / 32))] == 3 || 
            map[(int)topLeftMapPosY][(int)(topLeftMapPosX + ((-200 * deltaTime) / 32))] == 0)
            this->move(-200 * deltaTime, 0);
    }
    if (this->upDirection) {
        if (map[(int)(topLeftMapPosY + ((-200 * deltaTime) / 32))][(int)topLeftMapPosX] == 2 || 
            map[(int)(topLeftMapPosY + ((-200 * deltaTime) / 32))][(int)topLeftMapPosX] == 3 || 
            map[(int)(topLeftMapPosY + ((-200 * deltaTime) / 32))][(int)topLeftMapPosX] == 0)
            this->move(0, -200 * deltaTime);
    }
    if (this->downDirection){
        if (map[(int)(botRightMapPosY + ((200 * deltaTime) / 32))][(int)botRightMapPosX] == 2 || 
            map[(int)(botRightMapPosY + ((200 * deltaTime) / 32))][(int)botRightMapPosX] == 3 || 
            map[(int)(botRightMapPosY + ((200 * deltaTime) / 32))][(int)botRightMapPosX] == 0)
            this->move(0, 200 * deltaTime);
    }
}