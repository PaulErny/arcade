/*
** EPITECH PROJECT, 2020
** ncurses
** File description:
** lib
*/

#include "../NcursesLib.hpp"

int NcursesLib::check_lib(int selection, const char **lib_list)
{
    if (strcmp(lib_list[selection], "Ncurses") == 0)
        mvprintw(20, 0, "Ncurses", lib_list[selection]);
    else if (strcmp(lib_list[selection], "SFML") == 0)
        mvprintw(20, 0, "SFML", lib_list[selection]);
    else if (strcmp(lib_list[selection], "SDL") == 0)
        mvprintw(20, 0, "SDL", lib_list[selection]);
    return (27);
}

int NcursesLib::inLib(void)
{
    int counter, offset = 0, ky = 0;
    int selection = 0;
    int row = 1;
    int col = 4;
    int arraylength = 4;
    int width = 5;
    int menulength = 5;
    const char *lib_list[] = {
    "Ncurses",
    "SFML",
    "SDL",
    "Exit",
};
    while (ky != 27)
    {
        for (counter = 0; counter < menulength - 1; counter++)
        {
            if (counter + offset == selection)
                attron(A_REVERSE);
            mvprintw(row + counter + 20, col + 100, lib_list[counter + offset]);
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
        // case KEY_HOME:
        //     selection = 0;
        //     offset = 0;
        //     break;
        // case KEY_END:
        //     selection = arraylength - 1;
        //     offset = arraylength - menulength;
        //     break;
        // case KEY_PPAGE:
        //     selection -= menulength;
        //     if (selection < 0)
        //         selection = 0;
        //     offset -= menulength;
        //     if (offset < 0)
        //         offset = 0;
        //     break;
        // case KEY_NPAGE:
        //     selection += menulength;
        //     if (selection > arraylength - 1)
        //         selection = arraylength - 1;
        //     offset += menulength;
        //     if (offset > arraylength - menulength)
        //         offset = arraylength - menulength;
        //     break;
        case 10: //enter
            ky = check_lib(selection, lib_list);
            break;
        case 97:
            return (this->_indexLib = this->_indexLib - 1);
        case 101:
            return (this->_indexLib = this->_indexLib + 1);
        }
        mvprintw(0, 0, "%i", this->_indexLib);
    }
    return (0);
}

int NcursesLib::menu_lib(void)
{
    int row, col;
    int the;

    initscr();
    getmaxyx(stdscr, row, col);
    this->test(10, col);
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    the = this->inLib();
    refresh();
    endwin();
    return (the);
}