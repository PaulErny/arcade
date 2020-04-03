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

class Core
{
private:
    void *m_handle;
    void *m_handleGame;
    char *m_arg;
    int indexLib;
    int indexGame;
    bool isMenuInit;
    bool isGameInit;
    state pgState;
    std::string m_pseudo = "";

    std::vector<std::string> m_libs;
    std::vector<std::string> m_games;
    std::shared_ptr<ILibs> Lib;
    std::shared_ptr<IGames> Games;

public : Core(char *arg);
    ~Core();
    const std::vector<std::string> &getLibs() const;
    const std::vector<std::string> &getGames() const;
    void nextLib(std::string libName);
    void indexLibFill();
    void changeLib();
    void fillLibVector();
    void fillGamesVector();
    void laodLib(int currentLib);
    void loadGame(int currentGame);
    void loadGameLib(int gameIndex);
    void changeGame(int choosenGame, int indexGame);
    void run();
    void game();

};

#endif