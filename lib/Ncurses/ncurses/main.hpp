/*
** EPITECH PROJECT, 2020
** ncurses
** File description:
** main
*/

#ifndef MAIN_HPP_
#define MAIN_HPP_
#include <ncurses.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

class MenuNcurse
{
private:
    /* data */
public:
    MenuNcurse(int, int, int, int, int, int);
    ~MenuNcurse();
    int check_lib(int selection);
    int check_game(int selection, const char **);
    void menu_lib(MenuNcurse lib);
    void menu_game(MenuNcurse game);
    string get_name(int, int);
    void DrawMenu(void);
    
    int _selection;
    int _row;
    int _col;
    int _arraylength;
    int _width;
    int _menulength;
};
    
#endif /* !MAIN_HPP_ */
