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

void NcursesLib::init_menu()
{
    this->_ky = 0;
    this->_ky2 = 0;

    this->_counter_lib = 0;
    this->_offset_lib = 0;
    this->_selection_lib = 0;
    this->_row_lib = 1;
    this->_col_lib = 4;
    this->_arraylength_lib = 4;
    this->_width_lib = 5;
    this->_menulength_lib = 5;

    this->_counter_game = 0;
    this->_offset_game = 0;
    this->_selection_game = 0;
    this->_row_game = 1;
    this->_col_game = 3;
    this->_arraylength_game = 3;
    this->_width_game = 4;
    this->_menulength_game = 4;
}

int NcursesLib::menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib)
{
    libsNames;
    gamesNames;
    highScores;
    close = true;
    int t, e;
    int i = 0;
    this->_indexLib = 0;
    this->init_menu();
    getmaxyx(stdscr, t, e);
    this->test(10, e);

    while (_ky2 != 27)
    {
        _ky2 = getch();
        if (pseudo.empty() == true)
            pseudo = this->enterName(pgState, close);
        this->libSelectionMenu(pgState, close, libsNames);
        this->gameSelectionMenu(pgState, close, gamesNames, highScores);
        this->nextGraphicLib(indexLib);
        // std::cout << "ici ->>>>>" << this->_indexLib << std::endl;
        // indexLib = this->_indexLib;
        // std::cout << "après ->>>>" << this->_indexLib << std::endl;
    }
    return (0);
}