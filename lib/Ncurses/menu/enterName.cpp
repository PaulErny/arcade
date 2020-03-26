/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** name
*/

#include "../NcursesLib.hpp"

std::string NcursesLib::get_name(int row, int col)
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

std::string NcursesLib::menu_name(void)
{
    int row, col;
    std::string thename;
    initscr();
    getmaxyx(stdscr, row, col);
    this->test(10, col);
    thename = this->get_name(row, col);
    return (thename);
}

std::string NcursesLib::enterName(state &pgState, bool close)
{
    pgState = MENU;
    close = true;
    std::string thename;

    thename = menu_name();
    mvprintw(3, 150, "Your name = %s", thename.c_str());
    return (thename);
}