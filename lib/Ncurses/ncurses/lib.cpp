/*
** EPITECH PROJECT, 2020
** ncurses
** File description:
** lib
*/

#include "main.hpp"

const char *lib_list[] = {
    "Ncurses",
    "SFML",
    "SDL",
    "Exit",
};

int MenuNcurse::check_lib(int selection)
{
    if (strcmp(lib_list[selection], "Ncurses") == 0)
        mvprintw(20, 0, "Ncurses", lib_list[selection]);
    else if (strcmp(lib_list[selection], "SFML") == 0)
        mvprintw(20, 0, "SFML", lib_list[selection]);
    else if (strcmp(lib_list[selection], "SDL") == 0)
        mvprintw(20, 0, "SDL", lib_list[selection]);
    return (27);
}

void MenuNcurse::menu_lib(MenuNcurse lib)
{
    int counter, offset = 0, ky = 0;

    while (ky != 27)
    {
        for (counter = 0; counter < lib._menulength - 1; counter++)
        {
            if (counter + offset == lib._selection)
                attron(A_REVERSE);
            mvprintw(lib._row + counter + 20, lib._col + 100, lib_list[counter + offset]);
            attroff(A_REVERSE);
        }
        ky = getch();
        switch (ky)
        {
        case KEY_UP:
            if (lib._selection)
            {
                lib._selection--;
                if (lib._selection < offset)
                    offset--;
            }
            break;
        case KEY_DOWN:
            if (lib._selection < lib._arraylength - 1)
            {
                lib._selection++;
                if (lib._selection > offset + lib._menulength - 1)
                    offset++;
            }
            break;
        case KEY_HOME:
            lib._selection = 0;
            offset = 0;
            break;
        case KEY_END:
            lib._selection = lib._arraylength - 1;
            offset = lib._arraylength - lib._menulength;
            break;
        case KEY_PPAGE:
            lib._selection -= lib._menulength;
            if (lib._selection < 0)
                lib._selection = 0;
            offset -= lib._menulength;
            if (offset < 0)
                offset = 0;
            break;
        case KEY_NPAGE:
            lib._selection += lib._menulength;
            if (lib._selection > lib._arraylength - 1)
                lib._selection = lib._arraylength - 1;
            offset += lib._menulength;
            if (offset > lib._arraylength - lib._menulength)
                offset = lib._arraylength - lib._menulength;
            break;
        case 10: //enter
            ky = check_lib(lib._selection);
            break;
        }
        mvprintw(0, 0, "%i", lib._selection);
    }
}