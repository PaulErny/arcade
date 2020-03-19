/*
** EPITECH PROJECT, 2020
** ncurses
** File description:
** main
*/

#include "main.hpp"
using namespace std;

MenuNcurse::MenuNcurse(int selection, int row, int col,
                       int arraylength, int width, int menulength)
{
    this->_selection = selection;
    this->_row = row;
    this->_col = col;
    this->_arraylength = arraylength;
    this->_width = width;
    this->_menulength = menulength;
}

MenuNcurse::~MenuNcurse()
{
}

void MenuNcurse::test(int row, int col)
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

string MenuNcurse::get_name(int row, int col)
{
    char title[] = "ENTER YOUR NAME";
    char str[80];
    initscr();
    getmaxyx(stdscr, row, col);
    mvprintw(row / 2, (col - strlen(title)) / 2, "%s", title);
    mvprintw(row / 2 + 1, (col - strlen(title)) / 2, "\t");
    getstr(str);
    clear();
    return (str);
}

string MenuNcurse::menu_name(void)
{
    int row, col;
    string thename;

    initscr();
    getmaxyx(stdscr, row, col);
    this->test(10, col);
    thename = this->get_name(row, col);
    endwin();
    return (thename);
}

void MenuNcurse::DrawMenu(void)
{
    MenuNcurse lib(0, 1, 4, 4, 5, 5);
    MenuNcurse game(0, 1, 3, 3, 4, 4);
    string name;
    int row, col;


    initscr();
    getmaxyx(stdscr, row, col);
    this->test(row, col);
    name = this->get_name(row, col);
    this->test(10, col);
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    mvprintw(3, 150, "Your name = %s", name.c_str());
    //lib.menu_lib(lib);
    game.menu_game(game);
    refresh();
    getch();
    endwin();
}

/* ------------------------------- RELATED TO SHAPES ------------------------------- */

int MenuNcurse::createShape(ShapeType type, int width, int height)
{
    return (0);
}

void MenuNcurse::drawShape(int index)
{
}

void MenuNcurse::setShapeColor(int index, int r, int g, int b, int a)
{
}

void MenuNcurse::deleteShape(int index)
{
}

void MenuNcurse::setShapePos(int index, int x, int y)
{   
}

/* ------------------------------- RELATED TO SPRITES ------------------------------- */

int MenuNcurse::createImageFromFile(std::string filename)
{
    return (0);
}

void MenuNcurse::drawImage(int ImageId)
{
}

void MenuNcurse::setImagePos(int ImageId, int x, int y)
{
}

void MenuNcurse::deleteImage(int ImageId)
{
}

/* ------------------------------- RELATED TO TEXT ------------------------------- */

int MenuNcurse::createFontFromFile(const std::string filename)
{
    return (0);
}

int MenuNcurse::createText(std::string text, int fontId)
{
    return (0);
}

void MenuNcurse::drawText(int textId)
{
}

void MenuNcurse::setTextString(int textId, std::string str)
{
}

void MenuNcurse::setTextPos(int textId, int x, int y)
{
}

void MenuNcurse::setTextCharSize(int textId, int charSize)
{
}

void MenuNcurse::setTextColor(int textId, int r, int g, int b, int a)
{
}

void MenuNcurse::deleteText(int TextId)
{
}

void MenuNcurse::deleteFont(int FontId)
{
}

/* ------------------------------- RELATED TO WINDOWS ------------------------------- */

void MenuNcurse::createWindow(int width, int height, std::string name)
{
}

bool MenuNcurse::isWindowOpen(void)
{
}

void MenuNcurse::clearWindow(void)
{
}

void MenuNcurse::update(void)
{
}

void MenuNcurse::resizeWindow(int width, int height)
{
}

void MenuNcurse::renameWindow(std::string name)
{
}

void MenuNcurse::deleteWindow(void)
{
}

/* ------------------------------- RELATED TO EVENTS ------------------------------- */

bool MenuNcurse::events(void)
{
    return (true);
}

void MenuNcurse::closeWindowEvent(void)
{
}

/* ------------------------------- MENU ------------------------------- */

int MenuNcurse::libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames)
{
    pgState = NOTHING;
    libsNames;
    close = true;
    MenuNcurse lib(0, 1, 4, 4, 5, 5);
    int which_lib = 0;

    which_lib = menu_lib(lib);
    return (which_lib);
}

int MenuNcurse::gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores)
{
    pgState = NOTHING;
    gamesNames;
    highScores;
    close = true;
    MenuNcurse game(0, 1, 3, 3, 4, 4);
    int which_game = 0;

    which_game = menu_game(game);
    return (which_game);
}

string MenuNcurse::enterName(state &pgState, bool close)
{
    pgState = NOTHING;
    close = true;
    string thename;

    thename = menu_name();
    return (thename);
}

int main(void)
{
    state pgState = NOTHING;
    std::vector<std::string> libsNames;
    std::vector<std::string> gamesNames;
    std::vector<std::vector<std::string>> highScores;
    bool close = true;
    MenuNcurse *menu = NULL;

    menu->enterName(pgState, close);
    menu->libSelectionMenu(pgState, close, libsNames);
    menu->gameSelectionMenu(pgState, close, gamesNames, highScores);
    string entername(state &pgState, bool close);
    return (0);
}