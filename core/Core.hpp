/**
 * \file Core.hpp
 * \brief Core
 */
#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <dlfcn.h>
#include <memory>
#include <vector>
#include <dirent.h>
#include <regex>
#include "../games/IGames.hpp"
#include "../lib/ILibs.hpp"
#include "Loader.hpp"

/*! \class Core
   * \brief class of Core
   *
   */
class Core
{
private:
  void *m_handle;
  void *m_handleGame;
  char *m_arg;
  int indexLib;
  int indexGame = -1;
  bool isMenuInit;
  bool isGameDataInit;
  bool isGameInit;

  state pgState;
  std::string m_pseudo = "";

  std::vector<std::string> m_libs;
  std::vector<std::string> m_games;
  std::shared_ptr<ILibs> Lib;
  std::shared_ptr<IGames> Games;

public:
  /**
 * \fn Core(char *arg);
 * \brief Constructor
 * 
 * \param arg is the arguments
 */
  Core(char *arg);
  /**
 * \fn ~Core();
 * \brief Destructor
 */
  ~Core();
  /**
 * \fn std::vector<std::string> &getLibs()
 * \brief Function that get Library available
 *
 * \return int
 */
  const std::vector<std::string> &getLibs() const;
  /**
 * \fn std::vector<std::string> &getGames()
 * \brief Function that get Games available
 *
 * \return int
 */
  const std::vector<std::string> &getGames() const;
  /**
 * \fn void nextLib(std::string libName)
 * \brief  Function that change the lib
 * 
 * \param libName Name of the Lib
 */
  void nextLib(std::string libName);
  /**
 * \fn void indexLibFill()
 * \brief create index for lib
 */
  void indexLibFill();
  /**
 * \fn void changeLib()
 * \brief Function that change the Library
 */
  void changeLib();
  /**
 * \fn void fillLibVector()
 * \brief Function that get library available in a vector
 */
  void fillLibVector();
  /**
 * \fn void fillGamesVector()
 * \brief Function that get games available in a vector
 */
  void fillGamesVector();
  /**
 * \fn void laodLib(int currentLib)
 * \brief Function that load library
 * 
 * \param currentLib is current library
 */
  void laodLib(int currentLib);
  /**
 * \fn void loadGame(int currentGame)
 * \brief Function that load game
 * 
 * \param currentGame is current game
 */
  void loadGame(int currentGame);
  /**
 * \fn void loadGameLib(int gameIndex, int indexGame)
 * \brief Function that load game with the current library
 * 
 * \param gameIndex of vector
 * \param indexGame of vector
 */
  void loadGameLib(int gameIndex, int indexGame);
  /**
 * \fn void changeGame(int choosenGame)
 * \brief Function that change game
 * 
 * \param choosenGame It's game chosen
 */
  void changeGame(int choosenGame);
  /**
 * \fn void run()
 * \brief Function that launch the Arcade
 */
  void run();
  /**
 * \fn void game()
 * \brief Function that launch the game
 */
  void game();
};

#endif