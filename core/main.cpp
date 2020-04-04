/**
 * \file main.cpp
 * \brief Main
 */
#include <exception>
#include <iostream>
#include <dlfcn.h>
#include <memory>
#include "../lib/ILibs.hpp"
#include "Core.hpp"

int main(int ac, char *av[])
{
    try {
        if (ac != 2)
            throw "Arcade accept 2 arguments";
        Core core(av[1]);
        core.run();
        //core.fillLibVector();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    } catch (char const *str) {
        std::cerr << str << std::endl;
    }
}
