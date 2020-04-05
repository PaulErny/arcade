/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLib
*/

/**
 * \file SFMLLib.hpp
 * \brief SFML Lib
 */

#ifndef SFMLLIB_HPP
#define SFMLLIB_HPP

#include <iostream>

#include <vector>
#include <unistd.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "../ILibs.hpp"
#include "SFMLMenu.hpp"

class SFMLMenu;

/*! \class SFMLLib
   * \brief class of SFML Library
   *
   */
class SFMLLib : public ILibs
{
  public:
    /**
 * \fn SFMLLib();
 * \brief Constructor
 */
    SFMLLib();
    /**
 * \fn ~SFMLLib();
 * \brief Destructor
 */
    ~SFMLLib();

    /* ------------------------------- RELATED TO SHAPES ------------------------------- */
    // explicit. if rectangle -> use $width and $height, if sphere -> $width = radius
    // returns the index of the newly created shape in a std::vector of shapes
    int createShape(ShapeType, int width, int height = 0);
    // draws the shape contained at $index of the vector of shapes
    void drawShape(int index);
    // sets the position of the shape contained at $index of the vector of shapes
    void setShapePos(int index, float x, float y);
    // sets the color of the shape contained at $index of the vector of shapes
    void setShapeColor(int index, int r, int g, int b, int a = 255);
    // deletes the shape contained at $index of the vector of shapes
    void deleteShape(int index);

    /* ------------------------------- RELATED TO SPRITES ------------------------------- */
    // creates a sprite from an image and return its ID to later modify it
    int createImageFromFile(std::string filename);
    // draws the sprite contained at $ImageId of the vector of shapes
    void drawImage(int ImageId);
    // sets the position of the sprite contained at $ImageId of the vector of shapes
    void setImagePos(int ImageId, float x, float y);
    // deletes the sprite contained at $ImageId of the vector of sprites
    void deleteImage(int ImageId);

    /* ------------------------------- RELATED TO TEXT ------------------------------- */
    // creates a texture from the image file given as parameter
    // returns the index of the newly created texture
    int createFontFromFile(const std::string filename);
    // creates a text and sets if font according to the id returned by createFontFromFile()
    // returns the index of the newly created text
    int createText(std::string text, int fontId);
    // draws the text contained at $textId of the vector of shapes
    void drawText(int textId);
    // sets the string of a text element
    void setTextString(int textId, std::string str);
    // sets the position of the sprite contained at $spriteId of the vector of shapes
    void setTextPos(int textId, float x, float y);
    // sets the size of the text to $charSize
    void setTextCharSize(int textId, int charSize);
    // changes the color of the text
    void setTextColor(int textId, int r, int g, int b, int a = 255);
    // deletes the text contained at $textId of the vector of texts
    void deleteText(int TextId);
    // deletes the font contained at $fontId of the vector of fonts
    void deleteFont(int FontId);

    /* ------------------------------- RELATED TO WINDOWS ------------------------------- */
    // creates a window of size ($width * $height) and named $name
    void createWindow(int width, int height, std::string name);
    // returns true if the window is open
    bool isWindowOpen(void);
    // refreshes the window
    void clearWindow(void);
    // updates the display
    void update(void);
    // resizes window to ($width * $height)
    void resizeWindow(int width, int height);
    // renames the window to $name
    void renameWindow(std::string name);
    // deletes the window
    void deleteWindow(void);

    /* ------------------------------- RELATED TO EVENTS ------------------------------- */
    // handle events occuring in the window
    bool events(void);
    /**
 * \fn sf::Event getEvt(void);
 * \brief check the event in the menu
 * 
 * \return the SFML event variable
 */
    sf::Event getEvt(void);
    // closes the window in case of such an event
    bool closeWindowEvent(void);
    // returns true if a key was released
    bool keyReleasedEvent(void);
    // checks if a btn to change lib is pressed and changes indexLib accordingly
    void nextGraphicLib(int &indexLib);
    void prevGraphicLib(int &indexLib);
    bool upArrow(void);
    bool downArrow(void);
    bool leftArrow(void);
    bool rigthArrow(void);
    void nextGameLib(int &indexGame);
    void prevGameLib(int &indexGame);
    void goToMenu(state &pgState);
    bool restartGame();

    /* ------------------------------- MENU ------------------------------- */
    // menu for selecting the graphical lib. returns 0 if nCurses is selected, 2 for SFML and 3 for SDL -1 for errors
    int libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames);
    // menu to select the game. returns 0 for game 0 if $gamesNames, 1 for game 2 if $gamesNames, etc...
    int gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores);
    // menu to enter the name. returns string with the name
    std::string enterName(state &pgState, bool close);
    void init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo);
    int menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib);

  private:
    std::vector<std::unique_ptr<sf::Texture>> textures;
    std::vector<std::unique_ptr<sf::Sprite>> sprites;
    std::vector<std::unique_ptr<sf::Font>> fonts;
    std::vector<std::unique_ptr<sf::Text>> texts;
    std::vector<std::unique_ptr<sf::Shape>> shapes;
    sf::RenderWindow window;
    sf::Event event;
    std::unique_ptr<SFMLMenu> main_menu;

    bool isKeyDown = false;
};

#endif /* !SFMLLIB_HPP_ */
