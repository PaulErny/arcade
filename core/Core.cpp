#include "Core.hpp"

Core::Core(char *arg) : m_arg(arg) 
{

}

Core::~Core()
{

}

std::vector<std::string> Core::getLibs()
{

}

std::vector<std::string> Core::getGames()
{

}

void Core::fillLibVector()
{

}

void Core::fillGamesVector()
{

}

void Core::laodLib()
{
    void *handle = dlopen(m_arg, RTLD_LAZY);

    if (dlerror() == NULL)
        throw "Cannot open lib";
    std::unique_ptr<ILibs> (*create)();
    create = (std::unique_ptr<ILibs>(*)())dlsym(handle, "create_object");
    std::unique_ptr<ILibs> Lib = (std::unique_ptr<ILibs>)create();
}