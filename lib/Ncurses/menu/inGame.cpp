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

int NcursesLib::inGame(NcursesLib game)
{
    int counter, offset = 0, ky = 0;
    const char *game_list[] = {
    "Snake",
    "PAC-MAN",
    "Exit",
    };
    while (ky != 27)
    {
        for (counter = 0; counter < game._menulength - 1; counter++)
        {
            if (counter + offset == game._selection)
                attron(A_REVERSE);
            mvprintw(game._row + counter + 20, game._col + 120, game_list[counter + offset]);
            attroff(A_REVERSE);
        }
        ky = getch();
        switch (ky)
        {
        case KEY_UP:
            if (game._selection)
            {
                game._selection--;
                if (game._selection < offset)
                    offset--;
            }
            break;
        case KEY_DOWN:
            if (game._selection < game._arraylength - 1)
            {
                game._selection++;
                if (game._selection > offset + game._menulength - 1)
                    offset++;
            }
            break;
        case KEY_HOME:
            game._selection = 0;
            offset = 0;
            break;
        case KEY_END:
            game._selection = game._arraylength - 1;
            offset = game._arraylength - game._menulength;
            break;
        case KEY_PPAGE:
            game._selection -= game._menulength;
            if (game._selection < 0)
                game._selection = 0;
            offset -= game._menulength;
            if (offset < 0)
                offset = 0;
            break;
        case KEY_NPAGE:
            game._selection += game._menulength;
            if (game._selection > game._arraylength - 1)
                game._selection = game._arraylength - 1;
            offset += game._menulength;
            if (offset > game._arraylength - game._menulength)
                offset = game._arraylength - game._menulength;
            break;
        case 10: //enter
            ky = check_game(game._selection, game_list);
            break;
        }
        mvprintw(0, 0, "%i", game._selection);
    }
    return (0);
}

int NcursesLib::menu_game(NcursesLib lib)
{
    int row, col;
    initscr();
    getmaxyx(stdscr, row, col);
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    this->inGame(lib);
    refresh();
    getch(); // a enlever pour lancer direct après enter
    endwin();
    return (0);
}