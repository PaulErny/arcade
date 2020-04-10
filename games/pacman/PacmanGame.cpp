/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

/**
 * \file PacmanGame.cpp
 * \brief Pac-Man
 */

#include <iostream>
#include "PacmanGame.hpp"

PacmanGame::PacmanGame()
{
    this->map = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 0 = empty -> black
                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, // 1 = wall
                 {1, 2, 5, 1, 1, 6, 2, 5, 1, 1, 1, 6, 2, 1, 1, 2, 5, 1, 1, 1, 6, 2, 5, 1, 1, 6, 2, 1}, 
                 {1, 3, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3, 1}, // 5 = angle 
                 {1, 2, 7, 1, 1, 8, 2, 7, 1, 1, 1, 8, 2, 7, 8, 2, 7, 1, 1, 1, 8, 2, 7, 1, 1, 8, 2, 1}, // 6 = angle 
                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, // 7 = angle
                 {1, 2, 5, 1, 1, 6, 2, 5, 6, 2, 5, 1, 1, 1, 1, 1, 1, 6, 2, 5, 6, 2, 5, 1, 1, 6, 2, 1}, // 8 = angle
                 {1, 2, 7, 1, 1, 8, 2, 1, 1, 2, 7, 1, 1, 6, 5, 1, 1, 8, 2, 1, 1, 2, 7, 1, 1, 8, 2, 1}, 
                 {1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1}, // 2 = small coin
                 {1, 1, 1, 1, 1, 1, 2, 1, 7, 1, 1, 6, 0, 1, 1, 0, 5, 1, 1, 8, 1, 2, 1, 1, 1, 1, 1, 1}, // 3 = big coin
                 {4, 4, 4, 4, 4, 1, 2, 1, 5, 1, 1, 8, 0, 7, 8, 0, 7, 1, 1, 6, 1, 2, 1, 4, 4, 4, 4, 4}, // 4 = unaccessible for player
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 1, 1, 1, 4, 4, 1, 1, 1, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {1, 1, 1, 1, 1, 1, 2, 7, 8, 0, 1, 4, 4, 4, 4, 4, 4, 1, 0, 7, 8, 2, 1, 1, 1, 1, 1, 1},
                 {0, 0, 0, 0, 0, 4, 2, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 1, 0, 0, 0, 2, 4, 0, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1, 1, 2, 5, 6, 0, 1, 4, 4, 4, 4, 4, 4, 1, 0, 5, 6, 2, 1, 1, 1, 1, 1, 1},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 5, 1, 1, 1, 1, 1, 1, 6, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {1, 1, 1, 1, 1, 1, 2, 7, 8, 0, 7, 1, 1, 6, 5, 1, 1, 8, 0, 7, 8, 2, 1, 1, 1, 1, 1, 1},
                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
                 {1, 2, 5, 1, 1, 6, 2, 5, 1, 1, 1, 6, 2, 1, 1, 2, 5, 1, 1, 1, 6, 2, 5, 1, 1, 6, 2, 1},
                 {1, 2, 7, 1, 6, 1, 2, 7, 1, 1, 1, 8, 2, 7, 8, 2, 7, 1, 1, 1, 8, 2, 1, 5, 1, 8, 2, 1},
                 {1, 3, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 3, 1},
                 {1, 1, 6, 2, 1, 1, 2, 5, 6, 2, 5, 1, 1, 1, 1, 1, 1, 6, 2, 5, 6, 2, 1, 1, 2, 5, 1, 1},
                 {1, 1, 8, 2, 7, 8, 2, 1, 1, 2, 7, 1, 1, 6, 5, 1, 1, 8, 2, 1, 1, 2, 7, 8, 2, 7, 1, 1},
                 {1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1},
                 {1, 2, 5, 1, 1, 1, 1, 8, 7, 1, 1, 6, 2, 1, 1, 2, 5, 1, 1, 8, 7, 1, 1, 1, 1, 6, 2, 1},
                 {1, 2, 7, 1, 1, 1, 1, 1, 1, 1, 1, 8, 2, 7, 8, 2, 7, 1, 1, 1, 1, 1, 1, 1, 1, 8, 2, 1},
                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    this->deltaTime = 0.0;
    this->remainingTime = 0.0;
    this->frameRate = 30;
    this->frames = 0;
    this->frameTime = 0.01; // in sec -> 10ms per frame -> 100 FPS
    this->maxUpdates = 5;
    this->score = 0;
    this->remainingCoins = 246;
    this->gameLost = false;
}

PacmanGame::~PacmanGame()
{
}

void PacmanGame::setLib(std::shared_ptr<ILibs> &lib)
{
    this->graphics = lib;
}

void PacmanGame::initGameData(std::string &pseudo)
{
    this->mapSpritesID = std::vector<std::vector<Entity>>(this->map.size(), std::vector<Entity>(this->map[0].size()));
    for (size_t y = 0; y < this->map.size(); y++) {
        for (size_t x = 0; x < this->map[y].size(); x++) {
            this->mapSpritesID[y][x].setLibPtr(this->graphics);
            this->mapSpritesID[y][x].setPosition(92 + x*32, 44 + y*32);
        }
    }
    this->player = std::make_shared<Pacman>(this->graphics);
    this->name = pseudo;
    // for (size_t i = 0; i < 4; i++) {
        this->ghosts.push_back(std::make_unique<Ghost>(this->graphics));
        this->ghosts[this->ghosts.size() - 1]->setPosition(/* xOffset */92 + /* x */14 * 32, /* yOffset */44 + /* y */ 11 *32);
        this->ghosts.push_back(std::make_unique<Ghost>(this->graphics));
        this->ghosts[this->ghosts.size() - 1]->setPosition(/* xOffset */92 + /* x */12 * 32, /* yOffset */44 + /* y */ 11 *32);
        this->ghosts.push_back(std::make_unique<Ghost>(this->graphics));
        this->ghosts[this->ghosts.size() - 1]->setPosition(/* xOffset */92 + /* x */16 * 32, /* yOffset */44 + /* y */ 11 *32);
        this->ghosts.push_back(std::make_unique<Ghost>(this->graphics));
        this->ghosts[this->ghosts.size() - 1]->setPosition(/* xOffset */92 + /* x */18 * 32, /* yOffset */44 + /* y */ 11 *32);
    // }
}

bool PacmanGame::isAdjacentCellForbidden(size_t x, size_t y)
{
    // check if any of the 8 surrounding cells are forbiden for PacMan to walk in
    if (x == 0 || x == this->map[0].size() -1 || y == 0 || y == this->map.size() -1)
        return (true);
    if (this->map[y - 1][x] == 4 || this->map[y + 1][x] == 4 || this->map[y - 1][x - 1] == 4 || this->map[y - 1][x +1] == 4 \
        || this->map[y + 1][x - 1] == 4 || this->map[y + 1][x + 1] == 4 || this->map[y][x - 1] == 4 || this->map[y][x + 1] == 4)
        return true;
    return false;
}

void PacmanGame::initMapBorder(size_t x, size_t y)
{
    if (y == 0 && x == 0) { // top left corner
        this->mapSpritesID[y][x].setType(SHAPE);
        this->mapSpritesID[y][x].addShape(32, 32, 30, 30, 230);
    } else if (y == this->map.size() - 1 && x == this->map[0].size() - 1) { // bot right corner
        this->mapSpritesID[y][x].setType(SHAPE);
        this->mapSpritesID[y][x].addShape(32, 32, 30, 30, 230);
    } else if (y == 0 && x == this->map[0].size() - 1) { // top right corner
        this->mapSpritesID[y][x].setType(SHAPE);
        this->mapSpritesID[y][x].addShape(32, 32, 30, 30, 230);
    } else if (y == this->map.size() - 1 && x == 0) { // bot left corner
        this->mapSpritesID[y][x].setType(SHAPE);
        this->mapSpritesID[y][x].addShape(32, 32, 30, 30, 230);
    } else if (y == 0) { // top row
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("games/pacman/resources/border_4.png");
    } else if (y == this->map.size() - 1) { // bot row
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("games/pacman/resources/border_3.png");
    } else if (x == 0) { // first column
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("games/pacman/resources/border_2.png");
    } else if (x == this->map[0].size() - 1) { // last column
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("games/pacman/resources/border_1.png");
    } else {
        this->mapSpritesID[y][x].setType(SHAPE);
        this->mapSpritesID[y][x].addShape(32, 32, 30, 30, 230);
    }
}

void PacmanGame::initMapCell(size_t x, size_t y)
{
    if (this->map[y][x] == 1) {
        if (y > 0 && y < this->map.size() && x > 0 && x < this->map[0].size() && !this->isAdjacentCellForbidden(x, y)) {
            this->mapSpritesID[y][x].setType(SPRITE);
            if (this->map[y - 1][x] == 1 && this->map[y + 1][x] == 1 && this->map[y][x - 1] == 1 && this->map[y][x + 1] == 1)
                this->mapSpritesID[y][x].addImage("games/pacman/resources/empty.png");
            else if (this->map[y - 1][x] == 2 || this->map[y - 1][x] == 3 || this->map[y - 1][x] == 0)
                this->mapSpritesID[y][x].addImage("games/pacman/resources/wall_horizontal_up.png");
            else if (this->map[y + 1][x] == 2 || this->map[y + 1][x] == 3 || this->map[y + 1][x] == 0)
                this->mapSpritesID[y][x].addImage("games/pacman/resources/wall_horizontal_down.png");
            else if (this->map[y][x - 1] == 2 || this->map[y][x - 1] == 3 || this->map[y][x - 1] == 0)
                this->mapSpritesID[y][x].addImage("games/pacman/resources/wall_vertical_left.png");
            else if (this->map[y][x + 1] == 2 || this->map[y][x + 1] == 3 || this->map[y][x + 1] == 0)
                this->mapSpritesID[y][x].addImage("games/pacman/resources/wall_vertical_right.png");
        } else {
            this->initMapBorder(x, y);
        }
    } else if (this->map[y][x] == 5) {
        if (this->map[y + 1][x + 1] != 1 && this->map[y + 1][x + 1] != 5) {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("games/pacman/resources/inward_coner_4.png");
        } else {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("games/pacman/resources/turn_up_right.png");
        }
    } else if (this->map[y][x] == 6) {
        if (this->map[y + 1][x - 1] != 1 && this->map[y + 1][x - 1] != 6) {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("games/pacman/resources/inward_coner_3.png");
        } else {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("games/pacman/resources/turn_up_left.png");
        }
    } else if (this->map[y][x] == 7) {
        if (this->map[y - 1][x + 1] != 1 && this->map[y - 1][x + 1] != 7) {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("games/pacman/resources/inward_coner_1.png");
        } else {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("games/pacman/resources/turn_down_right.png");
        }
    } else if (this->map[y][x] == 8) {
        if (this->map[y - 1][x - 1] != 1 && this->map[y - 1][x - 1] != 8) {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("games/pacman/resources/inward_coner_2.png");
        } else {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("games/pacman/resources/turn_down_left.png");
        }
    } else if (this->map[y][x] == 2) {
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("games/pacman/resources/small_coin.png");
        this->mapSpritesID[y][x].addImage("games/pacman/resources/empty.png");
    } else if (this->map[y][x] == 3) {
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("games/pacman/resources/big_coin_1.png");
        this->mapSpritesID[y][x].addImage("games/pacman/resources/empty.png");
    } else if (this->map[y][x] == 0 || this->map[y][x] == 4) {
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("games/pacman/resources/empty.png");
    }
    this->mapSpritesID[y][x].updatePosition();
}

void PacmanGame::initGraphics()
{
    for (size_t y = 0; y < this->map.size(); y++) {
        for (size_t x = 0; x < this->map[y].size(); x++) {
            this->mapSpritesID[y][x].setLibPtr(this->graphics);
            this->mapSpritesID[y][x].resetGraphics();
            this->initMapCell(x, y);
        }
    }
    for (size_t i = 0; i < this->ghosts.size(); i++) {
        this->ghosts[i]->setLibPtr(this->graphics);
        this->ghosts[i]->resetGraphics();
        this->ghosts[i]->initGraphics();
    }
    this->player->setLibPtr(this->graphics);
    this->player->resetGraphics();
    this->player->initGraphics();
    this->scoreText = this->name + "'s score:" + std::to_string(this->score);
    this->scoreTextID = this->graphics->createText(this->scoreText, this->graphics->createFontFromFile("resources/ARCADE_I.TTF"));
    this->graphics->setTextCharSize(this->scoreTextID, 25);
    this->graphics->setTextPos(this->scoreTextID, 540 - ((this->scoreText.length() * 25) / 2), 5);
    this->winTextID = this->graphics->createText("You Won GG", this->graphics->createFontFromFile("resources/ARCADE_I.TTF"));
    this->graphics->setTextCharSize(this->winTextID, 50);
    this->graphics->setTextPos(this->winTextID, 290, 490);
    this->LoseTextID = this->graphics->createText("You Lost =(", this->graphics->createFontFromFile("resources/ARCADE_I.TTF"));
    this->graphics->setTextCharSize(this->LoseTextID, 50);
    this->graphics->setTextPos(this->LoseTextID, 290, 490);
}

void PacmanGame::update()
{
    for (size_t i = 0; i < this->ghosts.size(); i++){
        this->ghosts[i]->movePlayer(this->deltaTime / (double)CLOCKS_PER_SEC, this->map);
        if (this->ghosts[i]->hitPlayer(this->player)) {
            this->gameLost = true;
        }
    }
    this->player->movePlayer(this->deltaTime / (double)CLOCKS_PER_SEC, this->map);
    this->score += this->player->eatCoin(this->map, this->mapSpritesID, this->remainingCoins);
    this->graphics->setTextString(this->scoreTextID, this->name + "'s score:" + std::to_string(this->score));
    this->graphics->setTextPos(this->scoreTextID, 540 - ((this->scoreText.length() * 25) / 2), 5);
}

void PacmanGame::draw()
{
    if (this->gameLost) {
        //draw the map
        for (size_t y = 0; y < this->map.size(); y++) {
            for (size_t x = 0; x < this->map[y].size(); x++) {
                this->mapSpritesID[y][x].draw();
            }
        }
        // draw 'You Lost'
        this->graphics->drawText(this->LoseTextID);
    } else if (this->remainingCoins > 0) {
        // draw the map
        for (size_t y = 0; y < this->map.size(); y++) {
            for (size_t x = 0; x < this->map[y].size(); x++) {
                this->mapSpritesID[y][x].draw();
            }
        }
        // draw the ghosts
        for (size_t i = 0; i < this->ghosts.size(); i++) {
            this->ghosts[0]->draw();
        }
        // draw pacman
        this->player->draw();
        // draw the score
        this->graphics->drawText(this->scoreTextID);
    } else {
        //draw the map
        for (size_t y = 0; y < this->map.size(); y++) {
            for (size_t x = 0; x < this->map[y].size(); x++) {
                this->mapSpritesID[y][x].draw();
            }
        }
        // draw 'You Won'
        this->graphics->drawText(this->winTextID);
    }
}

void PacmanGame::runGame(int &indexGame, int &indexLib)
{
    this->beginFrame = std::clock();
    while (this->graphics->events()) {
        this->graphics->closeWindowEvent();
        if (this->graphics->rigthArrow())
            this->player->goRight();
        if (this->graphics->leftArrow())
            this->player->goLeft();
        if (this->graphics->upArrow())
            this->player->goUp();
        if (this->graphics->downArrow())
            this->player->goDown();
        this->graphics->nextGraphicLib(indexLib);
        this->graphics->prevGraphicLib(indexLib);
        this->graphics->nextGameLib(indexGame);
        this->graphics->prevGameLib(indexGame);
    }
    this->draw();

    this->update();

    this->endFrame = std::clock();
    this->deltaTime = this->endFrame - this->beginFrame;

    this->remainingTime += this->deltaTime;
    size_t updates = 0;
    while (remainingTime / (double)CLOCKS_PER_SEC > this->frameTime) {
        remainingTime -= this->frameTime * (double)CLOCKS_PER_SEC;
        if (updates++ < this->maxUpdates) // Ensure we don't get stuck if we can't reach our intended number of updates per second
            update(); // Do one game logic tick
    }
}

extern "C" std::shared_ptr<PacmanGame> create_object()
{
    return std::make_shared<PacmanGame>();
}