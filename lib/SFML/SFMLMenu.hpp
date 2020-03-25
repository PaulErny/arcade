/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLMenu
*/

#ifndef SFMLMENU_HPP_
#define SFMLMENU_HPP_

#include <iostream>

#include "SFMLLib.hpp"

class SFMLLib;

class SFMLMenu {
    public:
        SFMLMenu(SFMLLib *lib);
        ~SFMLMenu();

        void init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo);
        int menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib);
        void chooseGame();
        void rechoose();
        void chooseAction();
        void displayHighScores(std::vector<int> gamesNamesID);
        void getPseudo(state pgState, std::string &pseudo);

    private:
        SFMLLib *graphics;
        int currentBtn = 2;
        int chosenGame = -1;
        int chosenAction = -1;
        std::vector<int> buttons;
        bool isKeyDown=false;
        bool isHighscoresMenu = false;

        int bgID;
        int fontID;
        int nibblerImgID;
        int pacmanImgID;
        std::vector<std::vector<int>> scoreTextID;
};

#endif /* !SFMLMENU_HPP_ */
