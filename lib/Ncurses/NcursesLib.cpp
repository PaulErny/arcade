/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib
*/

#include "NcursesLib.hpp"

/* ------------------------------- RELATED TO SHAPES ------------------------------- */

int NcursesLib::createShape(ShapeType type, int width, int height)
{
}

void NcursesLib::drawShape(int index)
{
}

void NcursesLib::setShapeColor(int index, int r, int g, int b, int a)
{
}

void NcursesLib::deleteShape(int index)
{
}

void NcursesLib::setShapePos(int index, int x, int y)
{
}

/* ------------------------------- RELATED TO SPRITES ------------------------------- */

int NcursesLib::createImageFromFile(std::string filename)
{
    return (0);
}

void NcursesLib::drawImage(int ImageId)
{
}

void NcursesLib::setImagePos(int ImageId, int x, int y)
{
}

void NcursesLib::deleteImage(int ImageId)
{
}

/* ------------------------------- RELATED TO TEXT ------------------------------- */

int NcursesLib::createFontFromFile(const std::string filename)
{
    return (0);
}

int NcursesLib::createText(std::string text, int fontId)
{
    return (0);
}

void NcursesLib::drawText(int textId)
{
}

void NcursesLib::setTextString(int textId, std::string str)
{
}

void NcursesLib::setTextPos(int textId, int x, int y)
{
}

void NcursesLib::setTextCharSize(int textId, int charSize)
{
}

void NcursesLib::setTextColor(int textId, int r, int g, int b, int a)
{
}

void NcursesLib::deleteText(int TextId)
{
}

void NcursesLib::deleteFont(int FontId)
{
}

/* ------------------------------- RELATED TO WINDOWS ------------------------------- */

void NcursesLib::createWindow(int width, int height, std::string name)
{
}

bool NcursesLib::isWindowOpen(void)
{
}

void NcursesLib::clearWindow(void)
{
    clear();
}

void NcursesLib::update(void)
{
    refresh();
}

void NcursesLib::resizeWindow(int width, int height)
{
}

void NcursesLib::renameWindow(std::string name)
{
}

void NcursesLib::deleteWindow(void)
{
    endwin();    
}

/* ------------------------------- RELATED TO EVENTS ------------------------------- */

bool NcursesLib::events(void)
{
    return (0);
}

bool NcursesLib::closeWindowEvent(void)
{
    return (false);
}

bool NcursesLib::keyReleasedEvent(void)
{
    return (false);
}

void NcursesLib::init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo)
{

}

extern "C" std::unique_ptr<NcursesLib> create_object()
{
    return std::make_unique<NcursesLib>();
}