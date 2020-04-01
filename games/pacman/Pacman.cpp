/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#include <iostream>
#include "Pacman.hpp"

Pacman::Pacman()
{
    this->map = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 0 = empty -> black
                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, // 1 = wall
                 {1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1}, // 2 = small coin
                 {1, 3, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3, 1}, // 3 = big coin
                 {1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1}, // 4 = unaccessible for player
                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
                 {1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1},
                 {1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1},
                 {1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1},
                 {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 1, 1, 1, 4, 4, 1, 1, 1, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 4, 4, 4, 4, 4, 4, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1},
                 {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 4, 4, 4, 4, 4, 4, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1},
                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
                 {1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1},
                 {1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1},
                 {1, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 1},
                 {1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1},
                 {1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1},
                 {1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1},
                 {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1},
                 {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1},
                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    this->mapSpritesID = std::vector<std::vector<Entity>>(this->map.size(), std::vector<Entity>(this->map[0].size()));
}

Pacman::~Pacman()
{
}

void Pacman::setLib(std::shared_ptr<ILibs> &lib)
{
    this->graphics = lib;
}

void Pacman::initGameData()
{
    for (size_t y = 0; y < this->map.size(); y++) {
        for (size_t x = 0; x < this->map[y].size(); x++) {
            this->mapSpritesID[y][x].setLibPtr(this->graphics);
            this->mapSpritesID[y][x].setPosition(x*32, y*32);
        }
    }
}

bool Pacman::isAdjacentCellForbidden(int x, int y)
{
    // check if any of the 8 surrounding cells are forbiden for PacMan to walk in
    if (x == 0 || x == this->map[0].size() -1 || y == 0 || y == this->map.size() -1)
        return (true);
    if (this->map[y - 1][x] == 4 || this->map[y + 1][x] == 4 || this->map[y - 1][x - 1] == 4 || this->map[y - 1][x +1] == 4 \
        || this->map[y + 1][x - 1] == 4 || this->map[y + 1][x + 1] == 4 || this->map[y][x - 1] == 4 || this->map[y][x + 1] == 4)
        return true;
    return false;
}

void Pacman::initMapCell(int x, int y)
{
    if (y > 0 && y < this->map.size() && x > 0 && x < this->map[0].size() && !this->isAdjacentCellForbidden(x, y)) {
        this->mapSpritesID[y][x].setType(SPRITE);
        if (this->map[y - 1][x] == 1 && this->map[y][x - 1] == 1 && this->map[y + 1][x] != 1 && this->map[y][x + 1] != 1)
            this->mapSpritesID[y][x].addImage("pacman/resources/turn_down_left.png");
        else if (this->map[y - 1][x] == 1 && this->map[y][x + 1] == 1 && this->map[y + 1][x] != 1 && this->map[y][x - 1] != 1)
            this->mapSpritesID[y][x].addImage("pacman/resources/turn_down_right.png");
        else if (this->map[y + 1][x] == 1 && this->map[y][x - 1] == 1 && this->map[y - 1][x] != 1 && this->map[y][x + 1] != 1)
            this->mapSpritesID[y][x].addImage("pacman/resources/turn_up_left.png");
        else if (this->map[y + 1][x] == 1 && this->map[y][x + 1] == 1 && this->map[y - 1][x] != 1 && this->map[y][x - 1] != 1)
            this->mapSpritesID[y][x].addImage("pacman/resources/turn_up_right.png");
        else if (this->map[y - 1][x] == 2 || this->map[y - 1][x] == 3)
            this->mapSpritesID[y][x].addImage("pacman/resources/wall_horizontal_down.png");
        else if (this->map[y + 1][x] == 2 || this->map[y + 1][x] == 3)
            this->mapSpritesID[y][x].addImage("pacman/resources/wall_horizontal_up.png");
        else if (this->map[y][x - 1] == 2 || this->map[y][x - 1] == 3)
            this->mapSpritesID[y][x].addImage("pacman/resources/wall_vertical_right.png");
        else if (this->map[y][x + 1] == 2 || this->map[y][x + 1] == 3)
            this->mapSpritesID[y][x].addImage("pacman/resources/wall_vertical_left.png");
    } else {
        this->mapSpritesID[y][x].setType(SHAPE);
        this->mapSpritesID[y][x].addShape(32, 32, 30, 30, 230);
    }
}

void Pacman::initGraphics()
{
    for (size_t y = 0; y < this->map.size(); y++) {
        for (size_t x = 0; x < this->map[y].size(); x++) {
            if (this->map[y][x] == 1) {
                this->initMapCell(x, y);
            } else if (this->map[y][x] == 2) {
                this->mapSpritesID[y][x].setType(SPRITE);
                this->mapSpritesID[y][x].addImage("pacman/resources/small_coin.png");
            } else if (this->map[y][x] == 3) {
                this->mapSpritesID[y][x].setType(SPRITE);
                this->mapSpritesID[y][x].addImage("pacman/resources/big_coin_1.png");
            } else if (this->map[y][x] == 0 || this->map[y][x] == 4) {
                this->mapSpritesID[y][x].setType(SPRITE);
                this->mapSpritesID[y][x].addImage("pacman/resources/empty.png");
            }
            this->mapSpritesID[y][x].updatePosition();
        }
    }
}

void Pacman::runGame()
{
    while (this->graphics->events()) {
        this->graphics->closeWindowEvent();
    }

    for (size_t y = 0; y < this->map.size(); y++) {
        for (size_t x = 0; x < this->map[y].size(); x++) {
            std::cout << x << " " << y << std::endl;
            this->mapSpritesID[y][x].draw();
        }
    }
}

extern "C" std::shared_ptr<Pacman> create_object()
{
    return std::make_shared<Pacman>();
}