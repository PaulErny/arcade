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

    this->directionChosen = true;
    this->rightDirection = true;
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

void Ghost::goRight()
{
    if (!this->rightDirection) {
        this->rightDirection = true;
        this->leftDirection = false;
        this->upDirection = false;
        this->downDirection = false;
    }

}

void Ghost::goLeft()
{
    if (!this->leftDirection) {
        this->rightDirection = false;
        this->leftDirection = true;
        this->upDirection = false;
        this->downDirection = false;
    }
}

void Ghost::goUp()
{
    if (!this->upDirection) {
        this->rightDirection = false;
        this->leftDirection = false;
        this->upDirection = true;
        this->downDirection = false;
    }
}

void Ghost::goDown()
{
    if (!this->downDirection) {
        this->rightDirection = false;
        this->leftDirection = false;
        this->upDirection = false;
        this->downDirection = true;
    }
}

void Ghost::chooseRandomDirection(std::vector<std::vector<int>> &map)
{
}

bool Ghost::isCellWalkable(int x, int y, std::vector<std::vector<int>> &map)
{
    if (map[y][x] == 0 || 
        map[y][x] == 2 ||
        map[y][x] == 3)
        return (true);
    return (false);
}

void Ghost::chooseDirection(std::vector<std::vector<int>> &map)
{
    std::vector<int> nextUp = {(int)((this->posX - 92) / 32), (int)((this->posY - 44) / 32) - 1};
    std::vector<int> nextDown = {(int)((this->posX - 92) / 32), (int)((this->posY - 44) / 32) + 1};
    std::vector<int> nextRight = {(int)((this->posX - 92) / 32) + 1, (int)((this->posY - 44) / 32)};
    std::vector<int> nextLeft = {(int)((this->posX - 92) / 32) - 1, (int)((this->posY - 44) / 32)};
    int changeDir = std::rand() % 2;

    if (this->rightDirection) {
        int dir = std::rand() % 2;
        if (!this->isCellWalkable((int)nextRight[0], (int)nextRight[1], map)) {
            if (dir == 0 && this->isCellWalkable((int)nextUp[0], (int)nextUp[1], map)) {
                this->goUp();
            } else if (dir == 1 && this->isCellWalkable((int)nextDown[0], (int)nextDown[1], map)) {
                this->goDown();
            } else if (this->isCellWalkable((int)nextUp[0], (int)nextUp[1], map))
                this->goUp();
            else if (this->isCellWalkable((int)nextDown[0], (int)nextDown[1], map))
                this->goDown();
        }
        if (changeDir == 0) {
            if (dir == 0 && this->isCellWalkable((int)nextUp[0], (int)nextUp[1], map)) {
                this->goUp();
            } else if (dir == 1 && this->isCellWalkable((int)nextDown[0], (int)nextDown[1], map)) {
                this->goDown();
            } else if (this->isCellWalkable((int)nextUp[0], (int)nextUp[1], map))
                this->goUp();
            else if (this->isCellWalkable((int)nextDown[0], (int)nextDown[1], map))
                this->goDown();
        } 
    } else if (this->leftDirection) {
        int dir = std::rand() % 2;
        if (!this->isCellWalkable((int)nextLeft[0], (int)nextLeft[1], map)) {
            if (dir == 0 && this->isCellWalkable((int)nextUp[0], (int)nextUp[1], map)) {
                this->goUp();
            } else if (dir == 1 && this->isCellWalkable((int)nextDown[0], (int)nextDown[1], map)) {
                this->goDown();
            } else if (this->isCellWalkable((int)nextUp[0], (int)nextUp[1], map))
                this->goUp();
            else if (this->isCellWalkable((int)nextDown[0], (int)nextDown[1], map))
                this->goDown();
        }
        if (changeDir == 0) {
            if (dir == 0 && this->isCellWalkable((int)nextUp[0], (int)nextUp[1], map)) {
                this->goUp();
            } else if (dir == 1 && this->isCellWalkable((int)nextDown[0], (int)nextDown[1], map)) {
                this->goDown();
            } else if (this->isCellWalkable((int)nextUp[0], (int)nextUp[1], map))
                this->goUp();
            else if (this->isCellWalkable((int)nextDown[0], (int)nextDown[1], map))
                this->goDown();
        }
    } else if (this->upDirection) {
        int dir = std::rand() % 2;
        if (!this->isCellWalkable((int)nextUp[0], (int)nextUp[1], map)) {
            if (dir == 0 && this->isCellWalkable((int)nextRight[0], (int)nextRight[1], map)) {
                this->goRight();
            } else if (dir == 1 && this->isCellWalkable((int)nextLeft[0], (int)nextLeft[1], map)) {
                this->goLeft();
            } else if (this->isCellWalkable((int)nextRight[0], (int)nextRight[1], map))
                this->goRight();
            else if (this->isCellWalkable((int)nextLeft[0], (int)nextLeft[1], map))
                this->goLeft();
        }
        if (changeDir == 0) {
            if (dir == 0 && this->isCellWalkable((int)nextRight[0], (int)nextRight[1], map)) {
                this->goRight();
            } else if (dir == 1 && this->isCellWalkable((int)nextLeft[0], (int)nextLeft[1], map)) {
                this->goLeft();
            } else if (this->isCellWalkable((int)nextRight[0], (int)nextRight[1], map))
                this->goRight();
            else if (this->isCellWalkable((int)nextLeft[0], (int)nextLeft[1], map))
                this->goLeft();
        }
    } else if (this->downDirection) {
        int dir = std::rand() % 2;
        if (!this->isCellWalkable(nextDown[0], nextDown[1], map)) {
            if (dir == 0 && this->isCellWalkable(nextRight[0], nextRight[1], map)) {
                this->goRight();
            } else if (dir == 1 && this->isCellWalkable(nextLeft[0], nextLeft[1], map)) {
                this->goLeft();
            } else if (this->isCellWalkable((int)nextRight[0], (int)nextRight[1], map))
                this->goRight();
            else if (this->isCellWalkable((int)nextLeft[0], (int)nextLeft[1], map))
                this->goLeft();
        }
        if (changeDir == 0) {
            if (dir == 0 && this->isCellWalkable(nextRight[0], nextRight[1], map)) {
                this->goRight();
            } else if (dir == 1 && this->isCellWalkable(nextLeft[0], nextLeft[1], map)) {
                this->goLeft();
            } else if (this->isCellWalkable((int)nextRight[0], (int)nextRight[1], map))
                this->goRight();
            else if (this->isCellWalkable((int)nextLeft[0], (int)nextLeft[1], map))
                this->goLeft();
        }
    }
}

void Ghost::movePlayer(double deltaTime, std::vector<std::vector<int>> &map) // deltaTime in sec
{
    static std::vector<int> prevPos = {(int)(this->posX), (int)(this->posY)};

    if (this->rightDirection)
        this->move(200 * deltaTime, 0);
    if (this->leftDirection)
        this->move(-200 * deltaTime, 0);
    if (this->upDirection)
        this->move(0, -200 * deltaTime);
    if (this->downDirection)
        this->move(0, 200 * deltaTime);
    
    if ((int)this->posX == prevPos[0] + 32 || (int)this->posY == prevPos[1] + 32 ||
        (int)this->posX == prevPos[0] - 32 || (int)this->posY == prevPos[1] - 32) {
        prevPos[0] = this->posX;
        prevPos[1] = this->posY;
        this->chooseDirection(map);
    }
}

bool Ghost::hitPlayer(std::shared_ptr<Pacman> pacman)
{
    // If one rectangle is on left side of other 
    if (pacman->getXposition() > this->posX + 31 || pacman->getXposition() + 32 > this->posX) 
        return false; 
  
    // If one rectangle is above other 
    if (pacman->getYposition() > this->posY + 31 || pacman->getYposition() + 32 > this->posY) 
        return false; 
  
    return true;
}