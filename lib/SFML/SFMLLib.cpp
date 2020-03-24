/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLib
*/

#include "SFMLLib.hpp"

SFMLLib::SFMLLib()
{
    this->main_menu = std::make_unique<SFMLMenu>(this);
}

SFMLLib::~SFMLLib()
{
}

/* ------------------------------- RELATED TO SHAPES ------------------------------- */

int SFMLLib::createShape(ShapeType type, int width, int height)
{
    if (type == RECTANGLE) {
        this->shapes.push_back(std::make_unique<sf::RectangleShape>(sf::Vector2f(width, height)));
    } else if (type == CIRCLE) {
        this->shapes.push_back(std::make_unique<sf::CircleShape>(width));
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

void SFMLLib::setShapePos(int index, int x, int y)
{
    if (this->shapes.size() > index && this->shapes[index])
        this->shapes[index]->setPosition(sf::Vector2f(x, y));
    else
        throw "SFML setShapePos() -> unknown index";    
}

void SFMLLib::deleteShape(int index)
{
}


/* ------------------------------- RELATED TO SPRITES ------------------------------- */

int SFMLLib::createImageFromFile(std::string filename)
{
    // creates the texture
    this->textures.push_back(std::make_unique<sf::Texture>());
    if (!this->textures[this->textures.size() - 1])
        throw "SFML createImageFromFile() -> could not create texture";
    if (!this->textures[this->textures.size() - 1]->loadFromFile(filename))
        throw "SFML createImageFromFile() -> could not load texture from file " + filename;
    // creates the sprite
    this->sprites.push_back(std::make_unique<sf::Sprite>(*this->textures[this->textures.size() - 1].get()));
    if (!this->sprites[this->sprites.size() - 1])
        throw "SFML createImageFromFile() -> could not create sprite from " + filename;
    return(this->sprites.size() - 1);
}

void SFMLLib::drawImage(int ImageId)
{
    if (this->sprites[ImageId])
        this->window.draw(*this->sprites[ImageId].get());
    else
        throw "SFML drawImage() -> unknown index";
}

void SFMLLib::setImagePos(int ImageId, int x, int y)
{
    if (this->sprites[ImageId])
        this->sprites[ImageId]->setPosition(x, y);
    else
        throw "SFML setImagePos() -> unknown index";
}

void SFMLLib::deleteImage(int ImageId)
{
}

/* ------------------------------- RELATED TO TEXT ------------------------------- */

int SFMLLib::createFontFromFile(const std::string filename)
{
    this->fonts.push_back(std::make_unique<sf::Font>());
    if (!this->fonts[this->fonts.size() - 1])
        throw "SFML createFontFromFile() -> could not create font";
    if (!this->fonts[this->fonts.size() - 1]->loadFromFile(filename))
        throw "SFML createFontFromFile() -> could not load font from file " + filename;
    return(this->fonts.size() - 1);
}

int SFMLLib::createText(std::string text, int fontId)
{
    if (!this->fonts[fontId])
        throw "SFML createText() -> given font unknown";
    this->texts.push_back(std::make_unique<sf::Text>(text, *this->fonts[fontId].get()));
    if (!this->texts[this->texts.size() - 1])
        throw "SFML createText() -> couldn't create text";
    return (this->texts.size() - 1);
}

void SFMLLib::drawText(int textId)
{
    if (this->texts.size() > textId && this->texts[textId])
        this->window.draw(*this->texts[textId].get());
    else
        throw "SFML drawText() -> unknown index";
}

void SFMLLib::setTextString(int textId, std::string str)
{
    if (this->texts.size() > textId && this->texts[textId])
        this->texts[textId]->setString(str);
    else
        throw "SFML setTextString() -> unknown index";
}

void SFMLLib::setTextPos(int textId, int x, int y)
{
    if (this->texts.size() > textId && this->texts[textId])
        this->texts[textId]->setPosition(sf::Vector2f(x, y));
    else
        throw "SFML setTextPos() -> unknown index"; 
}

void SFMLLib::setTextCharSize(int textId, int charSize)
{
    if (this->texts.size() > textId && this->texts[textId])
        this->texts[textId]->setCharacterSize(charSize);
    else
        throw "SFML setTextCharSize() -> unknown index"; 
}

void SFMLLib::setTextColor(int textId, int r, int g, int b, int a)
{
    if (this->texts.size() > textId && this->texts[textId])
        this->texts[textId]->setFillColor(sf::Color(r, g, b, a));
    else
        throw "SFML setTextColor() -> unknown index"; 
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
    this->window.setKeyRepeatEnabled(false);
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

sf::Event SFMLLib::getEvt(void)
{
    return (this->event);
}

bool SFMLLib::closeWindowEvent(void)
{
    if (this->event.type == sf::Event::Closed) {
        this->window.close();
        return true;
    }
    return false;
}

bool SFMLLib::keyReleasedEvent(void)
{
    if (this->event.type == sf::Event::KeyReleased)
        return (true);
    return false;
}

/* ------------------------------- MENU ------------------------------- */
void SFMLLib::init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo)
{
    this->main_menu->init_menu(libsNames, gamesNames, highScores, pseudo);
}

int SFMLLib::menu(state &pgState, bool close,  std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo)
{
    return (this->main_menu->menu(pgState, close, libsNames, gamesNames, highScores, pseudo));
}

int SFMLLib::libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames)
{
    return (-1);
}

int SFMLLib::gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores)
{
    return (-1);
}

std::string SFMLLib::enterName(state &pgState, bool close)
{
    return (nullptr);
}

extern "C" std::unique_ptr<SFMLLib> create_object()
{
    return std::make_unique<SFMLLib>();
}