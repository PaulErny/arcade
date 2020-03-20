#include "SDLLib.hpp"

/* ------------------------------- MENU ------------------------------- */
// menu for selecting the graphical lib. returns 0 if nCurses is selected, 2 for SFML and 3 for SDL -1 for errors
int SDLLib::libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames)
{

}
// menu to select the game. returns 0 for game 0 if $gamesNames, 1 for game 2 if $gamesNames, etc...
int SDLLib::gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores)
{

}
// menu to enter the name. returns string with the name
std::string SDLLib::enterName(state &pgState, bool close)
{

}