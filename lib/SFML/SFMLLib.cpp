/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLib
*/

#include "SFMLLib.hpp"

SFMLLib::SFMLLib()
{
}

SFMLLib::~SFMLLib()
{
}

/* ------------------------------- RELATED TO SHAPES ------------------------------- */

int SFMLLib::createShape(ShapeType type, int width, int height)
{
    if (type == RECTANGLE) {
        this->shapes.push_back(std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height)));
    } else if (type == CIRCLE) {
        this->shapes.push_back(std::make_shared<sf::CircleShape>(width));
    } else
        throw "SFML createShape() -> unknown shape requested";
    return(this->shapes.size() - 1);
}

void SFMLLib::drawShape(int index)
{
    if (this->shapes.size() > index && this->shapes[index])
        this->window.draw(*this->shapes[index].get());
    else
        throw "SFML drawShape() -> unknown index"; 
}

void SFMLLib::setShapeColor(int index, int r, int g, int b, int a)
{
    if (this->shapes.size() > index && this->shapes[index])
        this->shapes[index]->setFillColor(sf::Color(r, g, b, a));
    else
        throw "SFML setShapeColor() -> unknown index"; 
}

void SFMLLib::deleteShape(int index)
{
    if (this->shapes.size() > index && this->shapes[index])
        this->shapes.erase(this->shapes.begin() + index);
    else
        throw "SFML deleteShape() -> unknown index"; 
}

void SFMLLib::setShapePos(int index, int x, int y)
{
    if (this->shapes.size() > index && this->shapes[index])
        this->shapes[index]->setPosition(sf::Vector2f(x, y));
    else
        throw "SFML setShapePos() -> unknown index";    
}

/* ------------------------------- RELATED TO SPRITES / TEXTURES ------------------------------- */

int SFMLLib::createTextureFromFile(const std::string filename)
{
    return (-1);
}

int SFMLLib::createSprite(int textureId)
{
    return (-1);
}

void SFMLLib::drawSprite(int spriteId)
{
}

void SFMLLib::setSpritePos(int spriteId, int x, int y)
{
}

void SFMLLib::deleteSprite(int spriteId)
{
}

void SFMLLib::deleteTexture(int spriteId)
{
}

/* ------------------------------- RELATED TO TEXT ------------------------------- */

int SFMLLib::createFontFromFile(const std::string filename)
{
    return (-1);
}

int SFMLLib::createText(std::string text, int fontId)
{
    return (-1);
}

void SFMLLib::drawText(int textId)
{
}

void SFMLLib::setTextString(std::string str)
{
}

void SFMLLib::setTextPos(int textId, int x, int y)
{
}

void SFMLLib::setTextCharSize(int textId, int charSize)
{
}

void SFMLLib::setTextColor(int textId, int r, int g, int b, int a)
{
}

void SFMLLib::deleteText(int TextId)
{
}

void SFMLLib::deleteFont(int FontId)
{
}

/* ------------------------------- RELATED TO WINDOWS ------------------------------- */

void SFMLLib::createWindow(int width, int height, std::string name)
{
    this->window.create(sf::VideoMode(1080, 1080), name, sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
}

bool SFMLLib::isWindowOpen(void)
{
    if (this->window.isOpen())
        return (true);
    return (false);
}

void SFMLLib::clearWindow(void)
{
    this->window.clear(sf::Color(41, 42, 48));
}

void SFMLLib::update(void)
{
    this->window.display();
}

void SFMLLib::resizeWindow(int width, int height)
{
    this->window.setSize(sf::Vector2u(width, height));
}

void SFMLLib::renameWindow(std::string name)
{
    this->window.setTitle(name);
}

void SFMLLib::deleteWindow(void)
{
}

/* ------------------------------- RELATED TO EVENTS ------------------------------- */

bool SFMLLib::events(void)
{
    return(this->window.pollEvent(this->event));
}

void SFMLLib::closeWindowEvent(void)
{
    if (this->event.type == sf::Event::Closed)
        this->window.close();
}

extern "C" std::unique_ptr<SFMLLib> create_object()
{
    return std::make_unique<SFMLLib>();
}