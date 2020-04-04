/**
 * \file NcursesLib.hpp
 * \brief Fichier .hpp pour la librairie Ncurses
 */

#ifndef LIB_HPP_
#define LIB_HPP_

#include <ncurses.h>
#include <cstring>
#include <memory>
#include "../ILibs.hpp"

/*! \class NcursesLib
   * \brief class of Ncurses Library
   *
   */
class NcursesLib : public ILibs
{
private:
  int row, col;
  int _indexLib = 0;
  int _counter_lib;
  int _offset_lib;
  int _selection_lib;
  int _row_lib;
  int _col_lib;
  int _arraylength_lib;
  int _width_lib;
  int _menulength_lib;

  int _counter_game;
  int _offset_game;
  int _selection_game;
  int _row_game;
  int _col_game;
  int _arraylength_game;
  int _width_game;
  int _menulength_game;

  int _ky = 0;
  int _ky2 = 0;
  int _ky_gen;
  int _row_gen;
  int _col_gen;
  std::vector<std::string> nText;
  std::vector<int> posx;
  std::vector<int> posy;
  std::vector<char> nShape;
  std::vector<int> posxShape;
  std::vector<int> posyShape;

public:
/**
 * \fn NcursesLib()
 * \brief Constructor
 */
  NcursesLib();
  /**
 * \fn ~NcursesLib()
 * \brief Destructor
 */
  ~NcursesLib();

/**
 * \fn int check_lib(int selection, std::vector<std::string> &libsNames)
 * \brief Function that checks which library are selected
 *
 * \param selection is the selection
 * \param libsNames of vector
 * \return int
 */
  int check_lib(int selection, std::vector<std::string> &libsNames);
  /**
 * \fn int check_game(int selection, std::vector<std::string> &gamesNames)
 * \brief Function that checks which game are selected
 *
 * \param selection is the selection
 * \param gamesNames of vector
 * \return int
 */
  int check_game(int selection, std::vector<std::string> &gamesNames);
  /**
 * \fn menu_lib(std::vector<std::string> &libsNames)
 * \brief Main function of the library menu
 * \brief THe function display too, the commands for change the library
 *
 * \param libsNames of vector
 * \return int
 */
  int menu_lib(std::vector<std::string> &libsNames);
  /**
 * \fn inLib(std::vector<std::string> &libsNames)
 * \brief Function that checks with getch(), which key are activated with the keyboard
 *
 * \param libsNames of vector
 * \return int
 */
  int inLib(std::vector<std::string> &libsNames);
  /**
 * \fn inGame(std::vector<std::string> &gamesNames)
 * \brief Function that checks with getch(), which key are activated with the keyboard
 *
 * \param gamesNames of vector
 * \return int
 */
  int inGame(std::vector<std::string> &gamesNames);
  /**
 * \fn int menu_game(std::vector<std::string> &gamesNames)
 * \brief Main function of the game menu
 *
 * \param gamesNames of vector
 * \return int
 */
  int menu_game(std::vector<std::string> &gamesNames);
  /**
 * \fn std::string get_name(int row, int col)
 * \brief Function to get the pseudo
 *
 * \param row is for row
 * \param col is for column
 * 
 * \return string(the pseudo)
 */
  std::string get_name(int, int);
  /**
 * \fn std::string menu_name(void)
 * \brief Main function to get the pseudo
 *
 * \return string(the pseudo)
 */
  std::string menu_name(void);
  /**
 * \fn void displayArcade(int row, int col)
 * \brief to display "ARCADE" in color
 * \brief And to put the color in Ncurses
 * 
 * \param row is for row
 * \param col is for column
 */
  void displayArcade(int, int);

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
  // closes the window in case of such an event
  bool closeWindowEvent(void);
  // returns true if a key was released
  bool keyReleasedEvent(void);
  // checks if a btn to change lib is pressed and changes indexLib accordingly
  void nextGraphicLib(int &indexLib);
  // checks if a btn to change lib is pressed and changes indexLib accordingly
  void prevGraphicLib(int &indexLib);
  // checks if a btn to change game is pressed and changes indexGame accordingly
  void nextGameLib(int &indexGame);
  // checks if a btn to change game is pressed and changes indexGame accordingly
  void prevGameLib(int &indexGame);
  // checks if a btn to change upArrow is pressed and return true if he is pressed
  bool upArrow();
  // checks if a btn to change downArrow is pressed and return true if he is pressed
  bool downArrow();
  // checks if a btn to change leftArrow is pressed and return true if he is pressed
  bool leftArrow();
  // checks if a btn to change rightArrow is pressed and return true if he is pressed
  bool rigthArrow();

  /* ------------------------------- MENU ------------------------------- */
  // menu for selecting the graphical lib. returns 0 if nCurses is selected, 2 for SFML and 3 for SDL -1 for errors
  int libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames);
  // menu to select the game. returns 0 for game 0 if $gamesNames, 1 for game 2 if $gamesNames, etc...
  int gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores);
  // menu to enter the name. returns string with the name
  std::string enterName(state &pgState, bool close);
  void init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo);
  // draw menu
  int menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib);
};

#endif /* !LIB_HPP_ */