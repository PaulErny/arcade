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

void test(int row, int col)
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

void MenuNcurse::DrawMenu(void)
{
    MenuNcurse lib(0, 1, 4, 4, 5, 5);
    MenuNcurse game(0, 1, 3, 3, 4, 4);
    string name;
    int row, col;


    initscr();
    getmaxyx(stdscr, row, col);
    test(row, col);
    name = this->get_name(row, col);
    test(10, col);
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    mvprintw(3, 150, "Your name = %s", name.c_str());
    lib.menu_lib(lib);
    game.menu_game(game);
    refresh();
    getch();
    endwin();
}

int main(void)
{
    MenuNcurse *menu = NULL;

    menu->DrawMenu();
    return (0);
}