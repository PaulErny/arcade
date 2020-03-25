/*
** EPITECH PROJECT, 2020
** ncurses
** File description:
** main
*/

#include "../NcursesLib.hpp"

NcursesLib::NcursesLib()
{
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

/* ------------------------------- MENU ------------------------------- */

int NcursesLib::libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames)
{
    pgState = NOTHING;
    libsNames;
    close = true;
    int which_lib = 0;

    which_lib = menu_lib();
    return (which_lib);
}

int NcursesLib::gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores)
{
    pgState = NOTHING;
    gamesNames;
    highScores;
    close = true;
    int which_game = 0;

    which_game = menu_game();
    return (which_game);
}

int NcursesLib::menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib)
{
    libsNames;
    gamesNames;
    highScores;
    close = true;
    int row, col;
    getmaxyx(stdscr, row, col);
    this->test(10, col);

    // while (_ky2 != 27)
    // {
        this->_ky_gen = getch();
        if (pseudo.empty() == true)
            pseudo = this->enterName(pgState, close);
        indexLib = this->libSelectionMenu(pgState, close, libsNames);
        indexLib = this->_indexLib;
        indexLib = this->gameSelectionMenu(pgState, close, gamesNames, highScores);
        this->nextGraphicLib(indexLib);
        // std::cout << "ici ->>>>>" << this->_indexLib << std::endl;
        // std::cout << "après ->>>>" << this->_indexLib << std::endl;
    // }
    return (0);
}