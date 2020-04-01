/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(entityType type, std::unique_ptr<ILibs>)
{
    this->type = type;
}

Entity::~Entity()
{
}

void Entity::move(int xOffset, int yOffset)
{
    this->posX = xOffset;
    this->posY = yOffset;
    for (size_t i = 0; i < this->shapes.size(); i++) {
        if (this->type == SHAPE)
            this->graphics->setShapePos(this->shapes[i], this->posX, this->posY);
        else if (this->type == SPRITE)
            this->graphics->setImagePos(this->shapes[i], this->posX, this->posY);
    }
}

void Entity::addShape(int height, int width, int r=255, int g=255, int b=255)
{
    if (this->type == SHAPE) {
        this->shapes.push_back(this->graphics->createShape(RECTANGLE, width, height));
        this->graphics->setShapeColor(this->shapes[this->shapes.size() - 1], r, g, b);
    }
}

void Entity::addImage(std::string file)
{
    if (this->type == SPRITE)
        this->shapes.push_back(this->graphics->createImageFromFile(file));
}

void Entity::nextShape()
{
    if (this->currentShape >= this->shapes.size() - 1)
        this->currentShape = 0;
    else
        this->currentShape++;
}

void Entity::prevShape()
{
    if (this->currentShape <= 0)
        this->currentShape = this->shapes.size() - 1;
    else
        this->currentShape--;
}

void Entity::changeColor(int r, int g, int b)
{
    if (this->type == SHAPE) {
        for (size_t i = 0; i < this->shapes.size(); i++)
            this->graphics->setShapeColor(this->shapes[i], r, g, b);
    }
}

void Entity::draw()
{
    if (this->type == SHAPE)
        this->graphics->drawShape(this->shapes[this->currentShape]);
    if (this->type == SPRITE)
        this->graphics->drawImage(this->shapes[this->currentShape]);
}

void Entity::setPosition(int x, int y)
{
    this->posX = x;
    this->posY = y;
}

const int &Entity::getXposition() const
{
    return this->posX;
}

const int &Entity::getYposition() const
{
    return this->posY;
}

const std::vector<int> &Entity::getVectorOfShape() const
{
    return this->shapes;
}