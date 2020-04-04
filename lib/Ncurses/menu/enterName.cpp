/**
 * \file enterName.cpp
 * \brief Menu for enter name
 */

#include "../NcursesLib.hpp"
/**
 * \fn std::string NcursesLib::get_name(int row, int col)
 * \brief Function to get the pseudo
 *
 * \param row is for row
 * \param col is for column
 * 
 * \return string(the pseudo)
 */
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

/**
 * \fn std::string NcursesLib::menu_name(void)
 * \brief Main function to get the pseudo
 *
 * \return string(the pseudo)
 */
std::string NcursesLib::menu_name(void)
{
    int row;
    int col;
    std::string thename;

    initscr();
    getmaxyx(stdscr, row, col);
    this->displayArcade(10, col);
    thename = this->get_name(row, col);
    return (thename);
}

/**
 * \fn std::string NcursesLib::enterName(state &pgState, bool close)
 * \brief Main methode to get the pseudo
 *
 * \param pgState is enumeration
 * \param close to know the windows is close ?
 * \return string(the pseudo)
 */
std::string NcursesLib::enterName(state &pgState, bool close)
{
    pgState = MENU;
    close = true;
    std::string thename;

    thename = menu_name();
    mvprintw(3, 150, "Your name = %s", thename.c_str());
    return (thename);
}