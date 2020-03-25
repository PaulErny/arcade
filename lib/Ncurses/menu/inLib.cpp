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
    const char *lib_list[] = {
    "Ncurses",
    "SFML",
    "SDL",
    "Exit",
};
    while (this->_ky != 27)
    {
        for (this->_counter_lib = 0; this->_counter_lib < this->_menulength_lib - 1; this->_counter_lib++)
        {
            if (this->_counter_lib + this->_offset_lib == this->_selection_lib)
                attron(A_REVERSE);
            mvprintw(this->_row_lib + this->_counter_lib + 20, this->_col_lib + 100, lib_list[this->_counter_lib + this->_offset_lib]);
            attroff(A_REVERSE);
        }
        this->_ky = getch();
        switch (this->_ky)
        {
        case KEY_UP:
            if (this->_selection_lib)
            {
                this->_selection_lib--;
                if (this->_selection_lib < this->_offset_lib)
                    this->_offset_lib--;
            }
            break;
        case KEY_DOWN:
            if (this->_selection_lib < this->_arraylength_lib - 1)
            {
                this->_selection_lib++;
                if (this->_selection_lib > this->_offset_lib + this->_menulength_lib - 1)
                    this->_offset_lib++;
            }
            break;
        case 10: //enter
            this->_ky = check_lib(this->_selection_lib, lib_list);
            break;
        }
        mvprintw(0, 0, "%i", this->_indexLib);
    }
    return (0);
}

int NcursesLib::menu_lib(void)
{
    int row, col;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    getmaxyx(stdscr, row, col);
    this->test(10, col);
    this->inLib();
    refresh();
    // endwin();
    return (0);
}