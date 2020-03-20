#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <dlfcn.h>
#include <memory>
#include <vector>
#include "../lib/ILibs.hpp"

class Core
{
private:
    char *m_arg;
    std::vector<std::string> libs;
    std::vector<std::string> games;
public:
    Core(char *arg);
    ~Core();
    std::vector<std::string> getLibs();
    std::vector<std::string> getGames();
    void fillLibVector();
    void fillGamesVector();
    void laodLib();
};

#endif