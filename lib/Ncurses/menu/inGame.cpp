/*
** EPITECH PROJECT, 2020
** ncurses
** File description:
** game
*/

#include "../NcursesLib.hpp"

int NcursesLib::check_game(int selection, std::vector<std::string> &gamesNames)
{
    if (!gamesNames.at(selection).compare("Snake"))
        mvprintw(20, 20, "Snake", gamesNames[selection]);
    else if (!gamesNames.at(selection).compare("PAC-MAN"))
        mvprintw(20, 20, "PAC-MAN", gamesNames[selection]);
    return (27);
}

int NcursesLib::inGame(std::vector<std::string> &gamesNames)
{
    while (this->_ky2 != 27)
    {
        for (this->_counter_game = 0; this->_counter_game < this->_menulength_game - 1; this->_counter_game++)
        {
            if (this->_counter_game + this->_offset_game == this->_selection_game)
                attron(A_REVERSE);
            mvprintw(this->_row_game + this->_counter_game + 20, this->_col_game + 120, gamesNames.at(this->_counter_game + this->_offset_game).c_str());
            attroff(A_REVERSE);
        }
        this->_ky2 = getch();
        switch (this->_ky2)
        {
        case KEY_UP:
            if (this->_selection_game)
            {
                this->_selection_game--;
                if (this->_selection_game < this->_offset_game)
                    this->_offset_game--;
            }
            break;
        case KEY_DOWN:
            if (this->_selection_game < this->_arraylength_game - 1)
            {
                this->_selection_game++;
                if (this->_selection_game > this->_offset_game + this->_menulength_game - 1)
                    this->_offset_game++;
            }
            break;
        case 10: //enter
            this->_ky2 = check_game(this->_selection_game, gamesNames);
            break;
        case 'a':
            this->_indexLib = this->_indexLib - 1;
            return (-1);
            break;
        case 'e':
            this->_indexLib = this->_indexLib + 1;
            return (-1);
            break;
        }
    }
    return (18);
}

int NcursesLib::menu_game(std::vector<std::string> &gamesNames)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    int temp = 0;
    temp = this->inGame(gamesNames);
    refresh();
    endwin();
    return (temp);
}