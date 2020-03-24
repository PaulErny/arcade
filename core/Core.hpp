#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <dlfcn.h>
#include <memory>
#include <vector>
#include <dirent.h>
#include <regex>
#include "../lib/ILibs.hpp"

class Core
{
private:
    void *m_handle;
    char *m_arg;
    int indexLib;
    std::vector<std::string> m_libs;
    std::vector<std::string> m_games;
public:
    Core(char *arg);
    ~Core();
    const std::vector<std::string> &getLibs() const;
    const std::vector<std::string> &getGames() const;
    void nextLib(std::string libName);
    void previousLib(std::string libName);
    void fillLibVector();
    void fillGamesVector();
    void laodLib();
};

#endif