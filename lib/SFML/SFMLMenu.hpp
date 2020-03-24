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

        int menu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo);
        void chooseGame();
        void rechoose();
        void chooseAction();
        void displayHighScores(std::vector<std::vector<int>> scoreTextID, std::vector<int> gamesNamesID, bool &isHighscoresMenu);
        void getPseudo(state pgState, std::string &pseudo, int bgID, int fontID);

    private:
        SFMLLib *graphics;
        int currentBtn = 2;
        int chosenGame = -1;
        int chosenAction = -1;
        std::vector<int> buttons;
        bool isKeyDown=false;
};

#endif /* !SFMLMENU_HPP_ */
