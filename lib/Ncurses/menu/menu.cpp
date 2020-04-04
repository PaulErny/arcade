/**
 * \file menu.cpp
 * \brief Main file, for Ncurses
 */

#include "../NcursesLib.hpp"

/**
 * \fn NcursesLib::NcursesLib()
 * \brief Constructor
 */
NcursesLib::NcursesLib()
{
}

/**
 * \fn NcursesLib::~NcursesLib()
 * \brief Destructor
 */
NcursesLib::~NcursesLib()
{
}

/**
 * \fn void NcursesLib::displayArcade(int row, int col)
 * \brief to display "ARCADE" in color
 * \brief And to put the color in Ncurses
 * 
 * \param row
 */
void NcursesLib::displayArcade(int row, int col)
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

/**
 * \fn int NcursesLib::libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames)
 * \brief Main method for the selection of the library
 *
 * \param pgState is a enumeration
 * \param close to check if the window is closed
 * \param libsNames of vector
 * \return int(library)
 */
int NcursesLib::libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames)
{
    pgState = MENU;
    libsNames;
    close = true;
    int which_lib = 0;

    which_lib = menu_lib(libsNames);
    return (which_lib);
}

/**
 * \fn int NcursesLib::gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores)
 * \briefMain method for the selection of the game
 * 
 * \param pgState is a enumeration
 * \param close to check if the window is closed
 * \param gamesNames of vector
 * \param highScores of vector
 * \return int(game)
 */
int NcursesLib::gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores)
{
    pgState = MENU;
    gamesNames;
    highScores;
    close = true;
    int which_game = 0;

    which_game = menu_game(gamesNames);
    return (which_game);
}

/**
 * \fn int NcursesLib::menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib)
 * \brief Main method of the menu
 * 
 * \param pgState is a enumeration
 * \param close to check if the window is closed
 * \param libsNames
 * \parama gamesNames of vector
 * \param highScores of vector
 * \param pseudo is the pseudo
 * \param indexLib is for change the lib
 * \return int
 */
int NcursesLib::menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib)
{
    this->_indexLib = indexLib;
    if (pseudo.empty() == true)
        pseudo = this->enterName(pgState, close);
    if (this->libSelectionMenu(pgState, close, libsNames) == -1)
    {
        indexLib = this->_indexLib;
        return (0);
    }
    if (this->gameSelectionMenu(pgState, close, gamesNames, highScores) == -1)
    {
        indexLib = this->_indexLib;
        return (0);
    }
    return (0);
}