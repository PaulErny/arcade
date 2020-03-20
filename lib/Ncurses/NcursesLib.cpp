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
    initscr();            /* init de ncurses */
    keypad(stdscr, TRUE); /* pour récupérer les événements du clavier */
    noecho();             /* pour masquer l'affichage du buffer stdin dans la console */

    while (1)
    {
        if (getch() == 27)
            break;
    }
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

void NcursesLib::closeWindowEvent(void)
{
}