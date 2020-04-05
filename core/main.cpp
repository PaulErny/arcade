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

int main(int ac, char *av[], char *env[])
{
    try {
        if (!env)
            throw "no env";
        if (ac != 2)
            throw "Arcade accept 2 arguments";
        srand(time(0));
        std::shared_ptr<Core> core = std::make_shared<Core>(av[1]);
        core->run();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    } catch (char const *str) {
        std::cerr << str << std::endl;
    }
}
