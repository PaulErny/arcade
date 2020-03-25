/*
** EPITECH PROJECT, 2020
** ncurses
** File description:
** game
*/

#include "../NcursesLib.hpp"

int NcursesLib::check_game(int selection, const char **game_list)
{
    if (strcmp(game_list[selection], "Snake") == 0)
        mvprintw(20, 20, "Snake", game_list[selection]);
    else if (strcmp(game_list[selection], "PAC-MAN") == 0)
        mvprintw(20, 20, "PAC-MAN", game_list[selection]);
    return (27);
}

int NcursesLib::inGame()
{
    const char *game_list[] = {
        "Snake",
        "PAC-MAN",
        "Exit",
    };
    while (this->_ky2 != 27)
    {
        for (this->_counter_game = 0; this->_counter_game < this->_menulength_game - 1; this->_counter_game++)
        {
            if (this->_counter_game + this->_offset_game == this->_selection_game)
                attron(A_REVERSE);
            mvprintw(this->_row_game + this->_counter_game + 20, this->_col_game + 120, game_list[this->_counter_game + this->_offset_game]);
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
            this->_ky2 = check_game(this->_selection_game, game_list);
            break;
        }
        mvprintw(0, 0, "%i", this->_selection_game);
    }
    return (18);
}

int NcursesLib::menu_game()
{
    int the;
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    the = this->inGame();
    refresh();
    getch(); // a enlever pour lancer direct après enter
    endwin();
    return (the);
}