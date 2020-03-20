#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <dlfcn.h>
#include <memory>
#include <vector>
#include <dirent.h>
#include "../lib/ILibs.hpp"

class Core
{
private:
    char *m_arg;
    std::vector<std::string> m_libs;
    std::vector<std::string> m_games;
public:
    Core(char *arg);
    ~Core();
    std::vector<std::string> getLibs() const;
    std::vector<std::string> getGames() const;
    void fillLibVector();
    void fillGamesVector();
    void laodLib();
};

#endif