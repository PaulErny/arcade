/**
 * \file ILibs.hpp
 * \brief ILibs
 */

#ifndef ILIBS_HPP
#define ILIBS_HPP

#include <string>
#include <vector>
#include <iostream>

/**
 * \enum ShapeType
 * \brief Rectangle or Circle
 * 
 * RECTANGLE / CIRCLE
 */
enum ShapeType
{
    RECTANGLE,
    CIRCLE,
};

/**
 * \enum state
 * \brief state of menu
 * 
 * NOTHING / MENU / PAUSE / GAME
 */
enum state
{
    NOTHING,
    MENU,
    PAUSE,
    GAME
};

/*! \class ILibs
   * \brief class of ILibs
   *
   */
class ILibs
{
  public:
    virtual ~ILibs() = default;

    /* ------------------------------- RELATED TO SHAPES ------------------------------- */
    /**
 * \fn virtual int createShape(ShapeType type, int width, int height)
 * \brief explicit. if rectangle -> use $width and $height, if sphere -> $width = radius
 *
 * \param type is for the type of form
 * \param width is for the width
 * \param height is for the height
 * \return the index of the newly created shape in a std::vector of shapes
 */
    virtual int createShape(ShapeType, int width, int height = 0) = 0;
    /**
 * \fn virtual void drawShape(int index)
 * \brief draws the shape contained at $index of the vector of shapes
 * 
 * \param index of vector
 */
    virtual void drawShape(int index) = 0;
    /**
 * \fn virtual void setShapePos(int index, float x, float y)
 * \brief sets the position of the shape contained at $index of the vector of shapes
 * 
 * \param index of vector
 * \param x for the coordinates
 * \param y for the coordinates
 */
    virtual void setShapePos(int index, float x, float y) = 0;
    /**
 * \fn virtual void setShapeColor(int index, int r, int g, int b, int a)
 * \brief sets the color of the shape contained at $index of the vector of shapes
 * 
 * \param index of vector
 * \param r for the color
 * \param g for the color
 * \param b for the color
 * \param a for the color
 */
    virtual void setShapeColor(int index, int r, int g, int b, int a = 255) = 0;
    /**
 * \fn virtual void deleteShape(int index)
 * \brief deletes the shape contained at $index of the vector of shapes
 * 
 * \param index of vector
 */
    virtual void deleteShape(int index) = 0;

    /* ------------------------------- RELATED TO SPRITES ------------------------------- */
    /**
 * \fn virtual int createImageFromFile(std::string filename)
 * \brief creates a sprite from an image and return its ID to later modify it
 * 
 * \param filename is path of image
 * \return int
 */
    virtual int createImageFromFile(std::string filename) = 0;
    /**
 * \fn virtual void drawImage(int ImageId)
 * \brief draws the sprite contained at $ImageId of the vector of shapes
 * 
 * \param ImageId of vector
 */
    virtual void drawImage(int ImageId) = 0;
    /**
 * \fn virtual void setImagePos(int ImageId, float x, float y)
 * \brief sets the position of the sprite contained at $ImageId of the vector of shapes
 * 
 * \param ImageId of vector 
 * \param x for the coordinates
 * \param y for the coordinates
 */
    virtual void setImagePos(int ImageId, float x, float y) = 0;

    /**
 * \fn virtual void deleteImage(int ImageId)
 * \brief deletes the sprite contained at $ImageId of the vector of sprites
 * 
 * \param ImageId of vector
 */
    virtual void deleteImage(int ImageId) = 0;

    /* ------------------------------- RELATED TO TEXT ------------------------------- */
    /**
 * \fn virtual int createFontFromFile(const std::string filename)
 * \brief creates a texture from the image file given as parameter
 * 
 * \param filename is path of image
 * \return the index of the newly created texture
 */
    virtual int createFontFromFile(const std::string filename) = 0;
    /**
 * \fn virtual int createText(std::string text, int fontId)
 * \brief creates a text and sets if font according to the id returned by createFontFromFile()
 * 
 * \param text is string that you would display
 * \param fontId of vector
 * \return the index of the newly created text
 */
    virtual int createText(std::string text, int fontId) = 0;
    /**
 * \fn virtual void drawText(int textId)
 * \brief draws the text contained at $textId of the vector of shapes
 * 
 * \param textId of vector
 */
    virtual void drawText(int textId) = 0;
    /**
 * \fn virtual void setTextString(int textId, std::string str)
 * \brief sets the string of a text element
 * 
 * \param textId of vector 
 * \param string that you would display
 */
    virtual void setTextString(int textId, std::string str) = 0;
    /**
 * \fn virtual void setTextPos(int textId, float x, float y)
 * \brief sets the position of the sprite contained at $spriteId of the vector of shapes
 * 
 * \param textId of vector 
 * \param x for the coordinates
 * \param y for the coordinates
 */
    virtual void setTextPos(int textId, float x, float y) = 0;
    /**
 * \fn virtual void setTextCharSize(int textId, int charSize)
 * \brief sets the size of the text to $charSize
 * 
 * \param textId of vector 
 * \param charSize for change the size of text
 */
    virtual void setTextCharSize(int textId, int charSize) = 0;
    /**
 * \fn virtual void setTextColor(int textId, int r, int g, int b, int a)
 * \brief changes the color of the text
 * 
 * \param textId of vector 
 * \param r for the color
 * \param g for the color
 * \param b for the color
 * \param a for the color
 */
    virtual void setTextColor(int textId, int r, int g, int b, int a = 255) = 0;
    /**
 * \fn virtual void deleteText(int TextId)
 * \brief deletes the text contained at $textId of the vector of texts
 * 
 * \param textId of vector
 */
    virtual void deleteText(int TextId) = 0;
    /**
 * \fn virtual void deleteFont(int FontId)
 * \brief deletes the font contained at $fontId of the vector of fonts
 * 
 * \param textId of vector
 */
    virtual void deleteFont(int FontId) = 0;

    /* ------------------------------- RELATED TO WINDOWS ------------------------------- */
    /**
 * \fn virtual void createWindow(int width, int height, std::string name)
 * \brief creates a window of size ($width * $height) and named $name
 * 
 * \param width for the width
 * \param height for the height
 * \param name the name of the window
 */
    virtual void createWindow(int width, int height, std::string name) = 0;
    /**
 * \fn virtual bool isWindowOpen(void)
 * \brief returns true if the window is open
 * 
 * \return bool
 */
    virtual bool isWindowOpen(void) = 0;
    /**
 * \fn virtual void clearWindow(void)
 * \brief refreshes the window
 * 
 */
    virtual void clearWindow(void) = 0;
    /**
 * \fn virtual void update(void)
 * \brief updates the display
 * 
 */
    virtual void update(void) = 0;
    /**
 * \fn virtual void resizeWindow(int width, int height)
 * \brief resizes window to ($width * $height)
 * 
 * \param width for the width
 * \param height for the height
 */
    virtual void resizeWindow(int width, int height) = 0;
    /**
 * \fn virtual void renameWindow(std::string name)
 * \brief renames the window to $name
 * 
 * \param name for the new name
 */
    virtual void renameWindow(std::string name) = 0;
    /**
 * \fn virtual void deleteWindow(void)
 * \brief deletes the window
 * 
 */
    virtual void deleteWindow(void) = 0;

    /* ------------------------------- RELATED TO EVENTS ------------------------------- */
    // handle events occuring in the window
    /**
 * \fn virtual bool events(void)
 * \brief handle events occuring in the window
 * 
 * \return bool
 */
    virtual bool events(void) = 0;
    /**
 * \fn virtual bool closeWindowEvent(void)
 * \brief closes the window in case of such an event
 * 
 * \return bool
 */
    virtual bool closeWindowEvent(void) = 0;
    /**
 * \fn virtual bool keyReleasedEvent(void)
 * \brief returns true if a key was released
 * 
 * \return bool
 */
    virtual bool keyReleasedEvent(void) = 0;
    /**
 * \fn virtual void nextGraphicLib(int &indexLib)
 * \brief checks if a btn to change lib is pressed and changes indexLib accordingly
 * 
 * \param indexLib of vector
 */
    virtual void nextGraphicLib(int &indexLib) = 0;
    /**
 * \fn virtual void prevGraphicLib(int &indexLib)
 * \brief checks if a btn to change lib is pressed and changes indexLib accordingly
 * 
 * \param indexLib of vector
 */
    virtual void prevGraphicLib(int &indexLib) = 0;
    /**
 * \fn virtual void nextGameLib(int &indexGame)
 * \brief checks if a btn to change game is pressed and changes indexGame accordingly
 * 
 * \param indexGame of vector
 */
    virtual void nextGameLib(int &indexGame) = 0;
    /**
 * \fn virtual void prevGameLib(int &indexGame)
 * \brief checks if a btn to change game is pressed and changes indexGame accordingly
 * 
 * \param indexGame of vector
 */
    virtual void prevGameLib(int &indexGame) = 0;
    /**
 * \fn virtual bool upArrow()
 * \brief checks if a btn to change upArrow is pressed and return true if he is pressed
 * 
 * \return bool
 */
    virtual bool upArrow() = 0;
    /**
 * \fn virtual bool downArrow()
 * \brief checks if a btn to change downArrow is pressed and return true if he is pressed
 * 
 * \return bool
 */
    virtual bool downArrow() = 0;
    /**
 * \fn virtual bool leftArrow()
 * \brief checks if a btn to change leftArrow is pressed and return true if he is pressed
 * 
 * \return bool
 */
    virtual bool leftArrow() = 0;
    /**
 * \fn virtual bool rigthArrow()
 * \brief checks if a btn to change rightArrow is pressed and return true if he is pressed
 * 
 * \return bool
 */
    virtual bool rigthArrow() = 0;

    /* ------------------------------- MENU ------------------------------- */
    /**
 * \fn virtual int libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames)
 * \brief Main method for the selection of the library
 *
 * \param pgState is a enumeration
 * \param close to check if the window is closed
 * \param libsNames of vector
 * \return int(library)
 */
    virtual int libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames) = 0;
    /**
 * \fn virtual int gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores)
 * \briefMain method for the selection of the game
 * 
 * \param pgState is a enumeration
 * \param close to check if the window is closed
 * \param gamesNames of vector
 * \param highScores of vector
 * \return int(game)
 */
    virtual int gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores) = 0;
    /**
 * \fn virtual std::string enterName(state &pgState, bool close)
 * \brief Main methode to get the pseudo
 *
 * \param pgState is enumeration
 * \param close to know the windows is close ?
 * \return string(the pseudo)
 */
    virtual std::string enterName(state &pgState, bool close) = 0;
    /**
 * \fn virtual void init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo)
 * \brief init variable of the menu
 * 
 * \param libsNames of vector
 * \param gamesNames of vector
 * \param highScores of vector
 * \param pseudo is the pseudo
 * 
 * \return bool
 */
    virtual void init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo) = 0;
    /**
 * \fn virtual int menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib)
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
    virtual int menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib) = 0;
};

#endif /* !ILIBS_HPP */
