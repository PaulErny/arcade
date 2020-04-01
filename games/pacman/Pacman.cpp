/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#include <iostream>
#include "Pacman.hpp"

Pacman::Pacman(std::shared_ptr<ILibs> &graphics)
{
    this->graphics = graphics;
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

    this->mapSpritesID = std::vector<std::vector<int>>(this->map.size(), std::vector<int>(this->map[0].size()));
}

Pacman::~Pacman()
{
}

void Pacman::initGameData()
{
}

bool Pacman::isAdjacentCellForbidden(int x, int y)
{
    // check if any of the 8 surrounding cells are forbiden for PacMan to walk in
    if (this->map[y - 1][x] == 4 || this->map[y + 1][x] == 4 || this->map[y - 1][x - 1] == 4 || this->map[y - 1][x +1] == 4 \
        || this->map[y + 1][x - 1] == 4 || this->map[y + 1][x + 1] == 4 || this->map[y][x - 1] == 4 || this->map[y][x + 1] == 4)
        return true;
    return false;
}

void Pacman::initMapCell(int x, int y)
{
    if (y != 0 && x != 0 && !this->isAdjacentCellForbidden(x, y)) {
        if (this->map[y - 1][x] == 1 && this->map[y][x - 1] == 1)
            this->mapSpritesID[y][x] = this->graphics->createImageFromFile("parman/resources/turn_down_left.png");
        else if (this->map[y - 1][x] == 1 && this->map[y][x + 1] == 1)
            this->mapSpritesID[y][x] = this->graphics->createImageFromFile("parman/resources/turn_down_right.png");
        else if (this->map[y + 1][x] == 1 && this->map[y][x - 1] == 1)
            this->mapSpritesID[y][x] = this->graphics->createImageFromFile("parman/resources/turn_up_left.png");
        else if (this->map[y + 1][x] == 1 && this->map[y][x + 1] == 1)
            this->mapSpritesID[y][x] = this->graphics->createImageFromFile("parman/resources/turn_up_right.png");
        else if (this->map[y - 1][x] == 2 || this->map[y - 1][x] == 3)
            this->mapSpritesID[y][x] = this->graphics->createImageFromFile("parman/resources/wall_horizontal_down.png");
        else if (this->map[y + 1][x] == 2 || this->map[y + 1][x] == 3)
            this->mapSpritesID[y][x] = this->graphics->createImageFromFile("parman/resources/wall_horizontal_up.png");
        else if (this->map[y][x - 1] == 2 || this->map[y][x - 1] == 3)
            this->mapSpritesID[y][x] = this->graphics->createImageFromFile("parman/resources/wall_vertical_right.png");
        else if (this->map[y][x + 1] == 2 || this->map[y][x + 1] == 3)
            this->mapSpritesID[y][x] = this->graphics->createImageFromFile("parman/resources/wall_vertical_left.png");
    } else {
        // this->mapSpritesID[y][x] = this->graphics->createShape(RECTANGLE, 25, 25);
        // this->graphics->setShapeColor(this->mapSpritesID[y][x], 30, 30, 230);
    }
    
}

void Pacman::initGraphics()
{
    for (size_t y = 0; y < this->map.size(); y++) {
        for (size_t x = 0; x < this->map[y].size(); x++) {
            if (this->map[y][x] == 1) {
                this->initMapCell(x, y);

                // this->mapSpritesID[y][x] = this->graphics->createShape(RECTANGLE, 25, 25);
                // this->graphics->setShapeColor(this->mapSpritesID[y][x], 30, 30, 230);
            } else {
                this->mapSpritesID[y][x] = this->graphics->createShape(RECTANGLE, 35, 35);
                this->graphics->setShapeColor(this->mapSpritesID[y][x], 0, 0, 0);
            }
            this->graphics->setShapePos(this->mapSpritesID[y][x], 35*x, 35*y);
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
            this->graphics->drawShape(this->mapSpritesID[y][x]);
        }
    }
}

extern "C" std::shared_ptr<Pacman> create_object()
{
    return std::make_shared<Pacman>();
}