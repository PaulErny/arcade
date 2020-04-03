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
    nShape.push_back(width);
    posyShape.push_back(0);
    posxShape.push_back(0);
    return (int)(nShape.size() - 1);
}

void NcursesLib::drawShape(int index)
{
    mvprintw(posxShape.at(index), posyShape.at(index), (char *)nShape.at(index));
}

void NcursesLib::setShapeColor(int index, int r, int g, int b, int a)
{
}

void NcursesLib::deleteShape(int index)
{
}

void NcursesLib::setShapePos(int index, int x, int y)
{
    posxShape.at(index) = x;
    posyShape.at(index) = y;
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
    posx.push_back(0);
    posy.push_back(0);
    return (0);
}

int NcursesLib::createText(std::string text, int fontId)
{
    nText.push_back(text);
    return (int)(nText.size() - 1);
}

void NcursesLib::drawText(int textId)
{
    mvprintw(posx.at(textId), posy.at(textId), nText.at(textId).c_str());
}

void NcursesLib::setTextString(int textId, std::string str)
{
    nText.at(textId) = str;
}

void NcursesLib::setTextPos(int textId, int x, int y)
{
    posx.at(textId) = x;
    posy.at(textId) = y;
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
    if (this->_ky == 27 || this->_ky2 == 27)
        return (false);
    else 
        return (true);
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
    this->_ky = 0;
    this->_ky2 = 0;
    this->_ky_gen = 0;

    this->_counter_lib = 0;
    this->_offset_lib = 0;
    this->_selection_lib = 0;
    this->_row_lib = 1;
    this->_col_lib = 3;
    this->_arraylength_lib = 3;
    this->_width_lib = 4;
    this->_menulength_lib = 4;

    this->_counter_game = 0;
    this->_offset_game = 0;
    this->_selection_game = 0;
    this->_row_game = 1;
    this->_col_game = 2;
    this->_arraylength_game = 2;
    this->_width_game = 3;
    this->_menulength_game = 3;
}

void NcursesLib::nextGraphicLib(int &indexLib)
{
    if (getch() == 'a') {
        indexLib--;
    }
}

void NcursesLib::prevGraphicLib(int &indexLib)
{
    if (getch() == 'e') {
        indexLib++;
    }
}

void NcursesLib::nextGameLib(int &indexGame)
{
    if (getch() == 'q')
    {
        indexGame--;
    }
}

void NcursesLib::prevGameLib(int &indexGame)
{
    if (getch() == 'd') {
        indexGame++;
    }
}

bool NcursesLib::upArrow()
{
    if (getch() == KEY_UP)
        return (true);
    else
        return (false);
}

bool NcursesLib::downArrow()
{
    if (getch() == KEY_DOWN)
        return (true);
    else
        return (false);
}

bool NcursesLib::leftArrow()
{
    if (getch() == KEY_LEFT)
        return (true);
    else
        return (false);
}

bool NcursesLib::rigthArrow()
{
    if (getch() == KEY_RIGHT)
        return (true);
    else
        return (false);
}

extern "C" std::shared_ptr<NcursesLib> create_object()
{
    return std::make_shared<NcursesLib>();
}