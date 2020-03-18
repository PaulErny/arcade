#include <exception>
#include <iostream>
#include <dlfcn.h>
#include <memory>
#include "../lib/ALibs.hpp"

int main(int ac, char *av[])
{
    try {
        if (ac != 2)
            throw "Arcade accept 2 arguments";
        void *handle = dlopen("../lib/SFML/lib_arcade_SFML.so", RTLD_LAZY);
       
        std::unique_ptr<ALibs>(*create)();
        create = (std::unique_ptr<ALibs> (*)()) dlsym(handle, "create_object");
        std::cout << "ok" << std::endl;
        std::unique_ptr<ALibs> Lib = (std::unique_ptr<ALibs>)create();
        Lib->createWindow(1080, 1080, "test");
        while (Lib->isWindowOpen()) {
            // Lib->update();
        }
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    } catch (char const *str) {
        std::cerr << str << std::endl;
    }
}
