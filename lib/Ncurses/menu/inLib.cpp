/**
 * \file inLib.cpp
 * \brief Menu to choice the library
 */

#include "../NcursesLib.hpp"

int NcursesLib::check_lib(int selection, std::vector<std::string> &libsNames)
{
    mvprintw(20, 0, libsNames[selection].c_str());
    return (27);
}

int NcursesLib::inLib(std::vector<std::string> &libsNames)
{
    while (this->_ky != 27)
    {
        for (this->_counter_lib = 0; this->_counter_lib < this->_menulength_lib - 1; this->_counter_lib++)
        {
            if (this->_counter_lib + this->_offset_lib == this->_selection_lib)
                attron(A_REVERSE);
            mvprintw(this->_row_lib + this->_counter_lib + 20, this->_col_lib + 100, libsNames.at(this->_counter_lib + this->_offset_lib).c_str());
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
            this->_ky = check_lib(this->_selection_lib, libsNames);
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
    return (this->_indexLib);
}

int NcursesLib::menu_lib(std::vector<std::string> &libsNames)
{
    int temp = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    getmaxyx(stdscr, this->_row_gen, this->_col_gen);
    this->displayArcade(10, this->_col_gen);
    mvprintw(21, 27, "Press E for the next lib");
    mvprintw(23, 27, "Press A for the previous lib");
    temp = this->inLib(libsNames);
    refresh();
    endwin();
    return (temp);
}