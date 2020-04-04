/**
 * \file NcursesLib.cpp
 * \brief Ncurses Library
 */

#include "NcursesLib.hpp"

/* ------------------------------- RELATED TO SHAPES ------------------------------- */
/**
 * \fn int NcursesLib::createShape(ShapeType type, int width, int height)
 * \brief explicit. if rectangle -> use $width and $height, if sphere -> $width = radius
 *
 * \param type is for the type of form
 * \param width is for the width
 * \param height is for the height
 * \return the index of the newly created shape in a std::vector of shapes
 */
int NcursesLib::createShape(ShapeType type, int width, int height)
{
    nShape.push_back(width);
    posyShape.push_back(0);
    posxShape.push_back(0);
    return (int)(nShape.size() - 1);
}

/**
 * \fn void NcursesLib::drawShape(int index)
 * \brief draws the shape contained at $index of the vector of shapes
 * 
 * \param index of vector
 */
void NcursesLib::drawShape(int index)
{
    mvprintw(posxShape.at(index), posyShape.at(index), "%c" , nShape.at(index));
}

/**
 * \fn void NcursesLib::setShapeColor(int index, int r, int g, int b, int a)
 * \brief sets the color of the shape contained at $index of the vector of shapes
 * 
 * \param index of vector
 * \param r for the color
 * \param g for the color
 * \param b for the color
 * \param a for the color
 */
void NcursesLib::setShapeColor(int index, int r, int g, int b, int a)
{
}

/**
 * \fn void NcursesLib::deleteShape(int index)
 * \brief deletes the shape contained at $index of the vector of shapes
 * 
 * \param index of vector
 */
void NcursesLib::deleteShape(int index)
{
}

/**
 * \fn void NcursesLib::setShapePos(int index, float x, float y)
 * \brief sets the position of the shape contained at $index of the vector of shapes
 * 
 * \param index of vector
 * \param x for the coordinates
 * \param y for the coordinates
 */
void NcursesLib::setShapePos(int index, float x, float y)
{
    posxShape.at(index) = (int)x;
    posyShape.at(index) = (int)y;
}

/* ------------------------------- RELATED TO SPRITES ------------------------------- */

/**
 * \fn int NcursesLib::createImageFromFile(std::string filename)
 * \brief creates a sprite from an image and return its ID to later modify it
 * 
 * \param filename is path of image
 * \return int
 */
int NcursesLib::createImageFromFile(std::string filename)
{
    return (0);
}

/**
 * \fn void NcursesLib::drawImage(int ImageId)
 * \brief draws the sprite contained at $ImageId of the vector of shapes
 * 
 * \param ImageId of vector
 */
void NcursesLib::drawImage(int ImageId)
{
}

/**
 * \fn void NcursesLib::setImagePos(int ImageId, float x, float y)
 * \brief sets the position of the sprite contained at $ImageId of the vector of shapes
 * 
 * \param ImageId of vector 
 * \param x for the coordinates
 * \param y for the coordinates
 */
void NcursesLib::setImagePos(int ImageId, float x, float y)
{
}

/**
 * \fn void NcursesLib::deleteImage(int ImageId)
 * \brief deletes the sprite contained at $ImageId of the vector of sprites
 * 
 * \param ImageId of vector
 */
void NcursesLib::deleteImage(int ImageId)
{
}

/* ------------------------------- RELATED TO TEXT ------------------------------- */

/**
 * \fn int NcursesLib::createFontFromFile(const std::string filename)
 * \brief creates a texture from the image file given as parameter
 * 
 * \param filename is path of image
 * \return the index of the newly created texture
 */
int NcursesLib::createFontFromFile(const std::string filename)
{
    posx.push_back(0);
    posy.push_back(0);
    return (0);
}

/**
 * \fn int NcursesLib::createText(std::string text, int fontId)
 * \brief creates a text and sets if font according to the id returned by createFontFromFile()
 * 
 * \param text is string that you would display
 * \param fontId of vector
 * \return the index of the newly created text
 */
int NcursesLib::createText(std::string text, int fontId)
{
    nText.push_back(text);
    return (int)(nText.size() - 1);
}

/**
 * \fn void NcursesLib::drawText(int textId)
 * \brief draws the text contained at $textId of the vector of shapes
 * 
 * \param textId of vector
 */
void NcursesLib::drawText(int textId)
{
    mvprintw(posx.at(textId), posy.at(textId), nText.at(textId).c_str());
}

/**
 * \fn void NcursesLib::setTextString(int textId, std::string str)
 * \brief sets the string of a text element
 * 
 * \param textId of vector 
 * \param string that you would display
 */
void NcursesLib::setTextString(int textId, std::string str)
{
    nText.at(textId) = str;
}

/**
 * \fn void NcursesLib::setTextPos(int textId, float x, float y)
 * \brief sets the position of the sprite contained at $spriteId of the vector of shapes
 * 
 * \param textId of vector 
 * \param x for the coordinates
 * \param y for the coordinates
 */
void NcursesLib::setTextPos(int textId, float x, float y)
{
    posx.at(textId) = (int)x;
    posy.at(textId) = (int)y;
}

/**
 * \fn void NcursesLib::setTextCharSize(int textId, int charSize)
 * \brief sets the size of the text to $charSize
 * 
 * \param textId of vector 
 * \param charSize for change the size of text
 */
void NcursesLib::setTextCharSize(int textId, int charSize)
{
}

/**
 * \fn void NcursesLib::setTextColor(int textId, int r, int g, int b, int a)
 * \brief changes the color of the text
 * 
 * \param textId of vector 
 * \param r for the color
 * \param g for the color
 * \param b for the color
 * \param a for the color
 */
void NcursesLib::setTextColor(int textId, int r, int g, int b, int a)
{
}

/**
 * \fn void NcursesLib::deleteText(int TextId)
 * \brief deletes the text contained at $textId of the vector of texts
 * 
 * \param textId of vector
 */
void NcursesLib::deleteText(int TextId)
{
}

/**
 * \fn void NcursesLib::deleteFont(int FontId)
 * \brief deletes the font contained at $fontId of the vector of fonts
 * 
 * \param textId of vector
 */
void NcursesLib::deleteFont(int FontId)
{
}

/* ------------------------------- RELATED TO WINDOWS ------------------------------- */

/**
 * \fn void NcursesLib::createWindow(int width, int height, std::string name)
 * \brief creates a window of size ($width * $height) and named $name
 * 
 * \param width for the width
 * \param height for the height
 * \param name the name of the window
 */
void NcursesLib::createWindow(int width, int height, std::string name)
{
}

/**
 * \fn bool NcursesLib::isWindowOpen(void)
 * \brief returns true if the window is open
 * 
 * \return bool
 */
bool NcursesLib::isWindowOpen(void)
{
    if (this->_ky == 27 || this->_ky2 == 27)
        return (false);
    else 
        return (true);
}

/**
 * \fn void NcursesLib::clearWindow(void)
 * \brief refreshes the window
 * 
 */
void NcursesLib::clearWindow(void)
{
    clear();
}

/**
 * \fn void NcursesLib::update(void)
 * \brief updates the display
 * 
 */
void NcursesLib::update(void)
{
    refresh();
}

/**
 * \fn void NcursesLib::resizeWindow(int width, int height)
 * \brief resizes window to ($width * $height)
 * 
 * \param width for the width
 * \param height for the height
 */
void NcursesLib::resizeWindow(int width, int height)
{
}

/**
 * \fn void NcursesLib::renameWindow(std::string name)
 * \brief renames the window to $name
 * 
 * \param name for the new name
 */
void NcursesLib::renameWindow(std::string name)
{
}

/**
 * \fn void NcursesLib::deleteWindow(void)
 * \brief deletes the window
 * 
 */
void NcursesLib::deleteWindow(void)
{
    endwin();    
}


/* ------------------------------- RELATED TO EVENTS ------------------------------- */

/**
 * \fn bool NcursesLib::events(void)
 * \brief handle events occuring in the window
 * 
 * \return bool
 */
bool NcursesLib::events(void)
{
    return (0);
}

/**
 * \fn bool NcursesLib::closeWindowEvent(void)
 * \brief closes the window in case of such an event
 * 
 * \return bool
 */
bool NcursesLib::closeWindowEvent(void)
{
    return (false);
}

/**
 * \fn bool NcursesLib::keyReleasedEvent(void)
 * \brief returns true if a key was released
 * 
 * \return bool
 */
bool NcursesLib::keyReleasedEvent(void)
{
    return (false);
}


/**
 * \fn void NcursesLib::nextGraphicLib(int &indexLib)
 * \brief checks if a btn to change lib is pressed and changes indexLib accordingly
 * 
 * \param indexLib of vector
 */
void NcursesLib::nextGraphicLib(int &indexLib)
{
    if (getch() == 'a') {
        indexLib--;
    }
}

/**
 * \fn void NcursesLib::prevGraphicLib(int &indexLib)
 * \brief checks if a btn to change lib is pressed and changes indexLib accordingly
 * 
 * \param indexLib of vector
 */
void NcursesLib::prevGraphicLib(int &indexLib)
{
    if (getch() == 'e') {
        indexLib++;
    }
}

/**
 * \fn void NcursesLib::nextGameLib(int &indexGame)
 * \brief checks if a btn to change game is pressed and changes indexGame accordingly
 * 
 * \param indexGame of vector
 */
void NcursesLib::nextGameLib(int &indexGame)
{
    if (getch() == 'q')
    {
        indexGame--;
    }
}

/**
 * \fn void NcursesLib::prevGameLib(int &indexGame)
 * \brief checks if a btn to change game is pressed and changes indexGame accordingly
 * 
 * \param indexGame of vector
 */
void NcursesLib::prevGameLib(int &indexGame)
{
    if (getch() == 'd') {
        indexGame++;
    }
}

/**
 * \fn bool NcursesLib::upArrow()
 * \brief checks if a btn to change upArrow is pressed and return true if he is pressed
 * 
 * \return bool
 */
bool NcursesLib::upArrow()
{
    if (getch() == KEY_UP)
        return (true);
    else
        return (false);
}

/**
 * \fn bool NcursesLib::downArrow()
 * \brief checks if a btn to change downArrow is pressed and return true if he is pressed
 * 
 * \return bool
 */
bool NcursesLib::downArrow()
{
    if (getch() == KEY_DOWN)
        return (true);
    else
        return (false);
}

/**
 * \fn bool NcursesLib::leftArrow()
 * \brief checks if a btn to change leftArrow is pressed and return true if he is pressed
 * 
 * \return bool
 */
bool NcursesLib::leftArrow()
{
    if (getch() == KEY_LEFT)
        return (true);
    else
        return (false);
}

/**
 * \fn bool NcursesLib::rigthArrow()
 * \brief checks if a btn to change rightArrow is pressed and return true if he is pressed
 * 
 * \return bool
 */
bool NcursesLib::rigthArrow()
{
    if (getch() == KEY_RIGHT)
        return (true);
    else
        return (false);
}

/* ------------------------------- MENU ------------------------------- */


/**
 * \fn void NcursesLib::init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo)
 * \brief init variable of the menu
 * 
 * \return bool
 */
void NcursesLib::init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo)
{
    this->_ky = 0;
    this->_ky2 = 0;
    this->_ky_gen = 0;

    this->_counter_lib = 0;
    this->_offset_lib = 0;
    this->_selection_lib = 0;
    this->_row_lib = 1;
    this->_col_lib = 3;
    this->_arraylength_lib = 3;
    this->_width_lib = 4;
    this->_menulength_lib = 4;

    this->_counter_game = 0;
    this->_offset_game = 0;
    this->_selection_game = 0;
    this->_row_game = 1;
    this->_col_game = 2;
    this->_arraylength_game = 2;
    this->_width_game = 3;
    this->_menulength_game = 3;
}

extern "C" std::shared_ptr<NcursesLib> create_object()
{
    return std::make_shared<NcursesLib>();
}