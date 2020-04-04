/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ghost
*/
/**
 * \file Ghost.cpp
 * \brief Ghost
 */

#include "Ghost.hpp"

Ghost::Ghost(std::shared_ptr<ILibs> lib)
{
    this->setLibPtr(lib);
    this->setType(SHAPE); // TMP

    this->directionChosen = false;
    this->rightDirection = false;
    this->leftDirection = false;
    this->upDirection = false;
    this->downDirection = false;
}

Ghost::~Ghost()
{
}

void Ghost::initGraphics()
{
    this->addShape(32, 32, 220, 20, 10);
    this->updatePosition();
}

void Ghost::chooseRandomDirection(std::vector<std::vector<int>> &map)
{
    if (!this->directionChosen) {
        float topLeftMapPosX = (this->posX - 92) / 32;
        float topLeftMapPosY = (this->posY - 44) / 32; // -92 and -44 are xOffset and yOffset used to put sprites in the center of the window
        float botRightMapPosX = (this->posX + 31 - 92) / 32; // 32 is the default size of a sprite -> divide by 32 to obtain the sprite pos in the map
        float botRightMapPosY = (this->posY + 31 - 44) / 32;
        int dir = std::rand() % 4; // 0 = up; 1 = right; 2 = down; 3 = left;
        this->upDirection = false;
        this->rightDirection = false;
        this->leftDirection = false;
        this->downDirection = false;
        switch (dir) {
            case 0: // up
                if (map[(int)(topLeftMapPosY - 1)][(int)topLeftMapPosX] == 2 || 
                map[(int)(topLeftMapPosY - 1)][(int)topLeftMapPosX] == 3 || 
                map[(int)(topLeftMapPosY - 1)][(int)topLeftMapPosX] == 4 ||
                map[(int)(topLeftMapPosY - 1)][(int)topLeftMapPosX] == 0)
                    this->upDirection = true;
                else
                    this->chooseRandomDirection(map);
                break;
            case 1: // right
                if (map[(int)topLeftMapPosY][(int)topLeftMapPosX + 1] == 2 || 
                map[(int)topLeftMapPosY][(int)topLeftMapPosX + 1] == 3 || 
                map[(int)topLeftMapPosY][(int)topLeftMapPosX + 1] == 4 ||
                map[(int)topLeftMapPosY][(int)topLeftMapPosX + 1] == 0)
                    this->rightDirection = true;
                else
                    this->chooseRandomDirection(map);
                break;
            case 2: // down
            if (map[(int)(topLeftMapPosY + 1)][(int)topLeftMapPosX] == 2 || 
                map[(int)(topLeftMapPosY + 1)][(int)topLeftMapPosX] == 3 || 
                map[(int)(topLeftMapPosY + 1)][(int)topLeftMapPosX] == 4 ||
                map[(int)(topLeftMapPosY + 1)][(int)topLeftMapPosX] == 0)
                    this->leftDirection = true;
                else
                    this->chooseRandomDirection(map);
                break;
            case 3: // left
                if (map[(int)topLeftMapPosY][(int)topLeftMapPosX - 1] == 2 || 
                map[(int)topLeftMapPosY][(int)topLeftMapPosX - 1] == 3 || 
                map[(int)topLeftMapPosY][(int)topLeftMapPosX - 1] == 4 ||
                map[(int)topLeftMapPosY][(int)topLeftMapPosX - 1] == 0)
                    this->downDirection = true;
                else
                    this->chooseRandomDirection(map);
                break;
        }
        this->directionChosen = true;
    }
}

void Ghost::movePlayer(double deltaTime, std::vector<std::vector<int>> &map) // deltaTime in sec
{
    this->chooseRandomDirection(map);

    if (this->rightDirection)
        this->move(200 * deltaTime, 0);
    if (this->leftDirection)
        this->move(-200 * deltaTime, 0);
    if (this->upDirection)
        this->move(0, -200 * deltaTime);
    if (this->downDirection)
        this->move(0, 200 * deltaTime);

    int topLeftMapPosX = (this->posX - 92) / 32; // + 31 because the sprites have a size of 32x32px
    int topLeftMapPosY = (this->posY - 44) / 32; // -92 and -44 are xOffset and yOffset used to put sprites in the center of the window
    int botRightMapPosX = (this->posX + 31 - 92) / 32; // 32 is the default size of a sprite -> divide by 32 to obtain the sprite pos in the map
    int botRightMapPosY = (this->posY + 31 - 44) / 32;

    if (topLeftMapPosX == botRightMapPosX && topLeftMapPosY == botRightMapPosY) // means after the ghost have moved, is it placed on a new tile ? If so -> it can choose anther tile to go to
        this->directionChosen = false;
}

bool Ghost::hitPlayer(std::shared_ptr<Pacman> pacman)
{
    return false;
}