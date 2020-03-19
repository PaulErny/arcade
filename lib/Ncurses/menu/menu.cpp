/*
** EPITECH PROJECT, 2020
** ncurses
** File description:
** main
*/

#include "menu.hpp"

NcursesLib::NcursesLib(int selection, int row, int col,
                       int arraylength, int width, int menulength)
{
    this->_selection = selection;
    this->_row = row;
    this->_col = col;
    this->_arraylength = arraylength;
    this->_width = width;
    this->_menulength = menulength;
}

NcursesLib::~NcursesLib()
{
}

void NcursesLib::test(int row, int col)
{
    char title1[] = "   ____    ___  _________    ____  _____";
    char title2[] = "   /   |  / __ |/ ____/   |  / __ |/ ___/";
    char title3[] = "  / /| | / /_/ / /   / /| | / / / / __/   ";
    char title4[] = " / ___ |/ _, _/ /___/ ___ |/ /_/ / /___   ";
    char title5[] = "/_/  |_/_/ |_/_____/_/  |_/_____/______/ ";
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

	attron(COLOR_PAIR(1));
    mvprintw(row / 2 - 5, (col - strlen(title1)) / 2, "%s", title1);
    mvprintw(row / 2 - 4, (col - strlen(title2)) / 2, "%s", title2);
    mvprintw(row / 2 - 3, (col - strlen(title3)) / 2, "%s", title3);
    mvprintw(row / 2 - 2, (col - strlen(title4)) / 2, "%s", title4);
    mvprintw(row / 2 - 1, (col - strlen(title5)) / 2, "%s", title5);
    attroff(COLOR_PAIR(1));
}

/* ------------------------------- RELATED TO SHAPES ------------------------------- */

int NcursesLib::createShape(ShapeType type, int width, int height)
{
    return (0);
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
}

void NcursesLib::update(void)
{
}

void NcursesLib::resizeWindow(int width, int height)
{
}

void NcursesLib::renameWindow(std::string name)
{
}

void NcursesLib::deleteWindow(void)
{
}

/* ------------------------------- RELATED TO EVENTS ------------------------------- */

bool NcursesLib::events(void)
{
    return (0);
}

void NcursesLib::closeWindowEvent(void)
{
}

/* ------------------------------- MENU ------------------------------- */

int NcursesLib::libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames)
{
    pgState = NOTHING;
    libsNames;
    close = true;
    NcursesLib lib(0, 1, 4, 4, 5, 5);
    int which_lib = 0;

    which_lib = menu_lib(lib);
    return (which_lib);
}

int NcursesLib::gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores)
{
    pgState = NOTHING;
    gamesNames;
    highScores;
    close = true;
    NcursesLib game(0, 1, 3, 3, 4, 4);
    int which_game = 0;

    which_game = menu_game(game);
    return (which_game);
}

int main(void)
{
    state pgState = NOTHING;
    std::vector<std::string> libsNames;
    std::vector<std::string> gamesNames;
    std::vector<std::vector<std::string>> highScores;
    bool close = true;
    NcursesLib *menu = NULL;

    menu->enterName(pgState, close);
    menu->libSelectionMenu(pgState, close, libsNames);
    menu->gameSelectionMenu(pgState, close, gamesNames, highScores);
    return (0);
}