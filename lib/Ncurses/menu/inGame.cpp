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
    int counter, offset = 0, ky = 0;
    int selection = 0;
    int row = 1;
    int col = 3;
    int arraylength = 3;
    int width = 4;
    int menulength = 4;
    const char *game_list[] = {
        "Snake",
        "PAC-MAN",
        "Exit",
    };
    while (ky != 27)
    {
        for (counter = 0; counter < menulength - 1; counter++)
        {
            if (counter + offset == selection)
                attron(A_REVERSE);
            mvprintw(row + counter + 20, col + 120, game_list[counter + offset]);
            attroff(A_REVERSE);
        }
        ky = getch();
        switch (ky)
        {
        case KEY_UP:
            if (selection)
            {
                selection--;
                if (selection < offset)
                    offset--;
            }
            break;
        case KEY_DOWN:
            if (selection < arraylength - 1)
            {
                selection++;
                if (selection > offset + menulength - 1)
                    offset++;
            }
            break;
        case 10: //enter
            ky = check_game(selection, game_list);
            break;
        case 122:
            this->_indexLib = this->_indexLib - 1;
        case 101:
            this->_indexLib = this->_indexLib + 1;
        }
        mvprintw(0, 0, "%i", selection);
    }
    return (18);
}

int NcursesLib::menu_game()
{
    initscr();
    //    getmaxyx(stdscr, row, col);
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    this->inGame();
    refresh();
    getch(); // a enlever pour lancer direct après enter
    endwin();
    return (0);
}