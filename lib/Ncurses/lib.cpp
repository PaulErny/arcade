/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib
*/

#include "lib.hpp"

/* ------------------------------- RELATED TO SHAPES ------------------------------- */

int libNcurses::createShape(ShapeType type, int width, int height)
{
}

void libNcurses::drawShape(int index)
{
}

void libNcurses::setShapeColor(int index, int r, int g, int b, int a)
{
}

void libNcurses::deleteShape(int index)
{
}

void libNcurses::setShapePos(int index, int x, int y)
{
}

/* ------------------------------- RELATED TO SPRITES ------------------------------- */

int libNcurses::createImageFromFile(std::string filename)
{
    return (0);
}

void libNcurses::drawImage(int ImageId)
{
}

void libNcurses::setImagePos(int ImageId, int x, int y)
{
}

void libNcurses::deleteImage(int ImageId)
{
}

/* ------------------------------- RELATED TO TEXT ------------------------------- */

int libNcurses::createFontFromFile(const std::string filename)
{
    return (0);
}

int libNcurses::createText(std::string text, int fontId)
{
    return (0);
}

void libNcurses::drawText(int textId)
{
}

void libNcurses::setTextString(int textId, std::string str)
{
}

void libNcurses::setTextPos(int textId, int x, int y)
{
}

void libNcurses::setTextCharSize(int textId, int charSize)
{
}

void libNcurses::setTextColor(int textId, int r, int g, int b, int a)
{
}

void libNcurses::deleteText(int TextId)
{
}

void libNcurses::deleteFont(int FontId)
{
}

/* ------------------------------- RELATED TO WINDOWS ------------------------------- */

void libNcurses::createWindow(int width, int height, std::string name)
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

bool libNcurses::isWindowOpen(void)
{
}

void libNcurses::clearWindow(void)
{
    clear();
}

void libNcurses::update(void)
{
    refresh();
}

void libNcurses::resizeWindow(int width, int height)
{
}

void libNcurses::renameWindow(std::string name)
{
}

void libNcurses::deleteWindow(void)
{
    endwin();    
}

/* ------------------------------- RELATED TO EVENTS ------------------------------- */

bool libNcurses::events(void)
{
    return (0);
}

void libNcurses::closeWindowEvent(void)
{
}