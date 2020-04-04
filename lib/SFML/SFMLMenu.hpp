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

/*! \class SFMLMenu
   * \brief class of SFML Menu
   *
   */
class SFMLMenu
{
  public:
    /**
 * \fn SFMLMenu(SFMLLib *lib)
 * \brief Constructor
 * 
 * \param lib is SFMLLib
 */
    SFMLMenu(SFMLLib *lib);
    /**
 * \fn ~SFMLMenu()
 * \brief Destructor
 */
    ~SFMLMenu();
    /**
 * \fn void init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo)
 * \brief init variable of the menu
 * 
 * \param libsNames of vector
 * \parama gamesNames of vector
 * \param highScores of vector
 * \param pseudo is the pseudo
 * 
 * \return bool
 */
    void init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo);
    /**
 * \fn int menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib)
 * \brief Main method of the menu
 * 
 * \param pgState is a enumeration
 * \param close to check if the window is closed
 * \param libsNames of vector
 * \param gamesNames of vector
 * \param highScores of vector
 * \param pseudo is the pseudo
 * \param indexLib is for change the lib
 * \return int
 */
    int menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib);
    /**
 * \fn void chooseGame()
 * \brief choose the game
 * 
 */
    void chooseGame();
    /**
 * \fn void rechoose()
 * \brief Rechoose the game if you go back
 * 
 */
    void rechoose();
    /**
 * \fn void chooseAction()
 * \brief Choose between Play or Highscores
 * 
 */
    void chooseAction();
    /**
 * \fn void displayHighScores(std::vector<int> gamesNamesID);
 * \brief Display the HighScores;
 * 
 * \param gamesNamesID of vector
 * 
 */
    void displayHighScores(std::vector<int> gamesNamesID);
    /**
 * \fn void getPseudo(state pgState, std::string &pseudo);
 * \brief Function that to get the pseudo;
 * 
 * \param pgState is a enumeration
 * \param pseudo is the pseudo
 */
    void getPseudo(state pgState, std::string &pseudo);

  private:
    SFMLLib *graphics;
    int currentBtn = 0;
    int chosenGame = -1;
    int chosenAction = -1;
    std::vector<int> buttons;
    bool isKeyDown = false;
    bool isHighscoresMenu = false;

    int bgID;
    int fontID;
    int nibblerImgID;
    int pacmanImgID;
    std::vector<std::vector<int>> scoreTextID;
    std::vector<int> textLibsID;
    int nextLibTxtID;
    int prevLibTxtID;
};

#endif /* !SFMLMENU_HPP_ */
