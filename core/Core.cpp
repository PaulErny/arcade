#include "Core.hpp"

Core::Core(char *arg) : m_arg(arg) 
{

}

Core::~Core()
{

}

std::vector<std::string> Core::getLibs() const
{
    return (m_libs);
}

std::vector<std::string> Core::getGames() const
{
    return (m_games);
}

void Core::fillLibVector()
{
    DIR *rep = NULL;
    rep = opendir("lib/");
    if (rep == NULL)
        throw "No lib directory";
    std::string fileString;
    std::string toVector;
    struct dirent *file = NULL;
    while ((file = readdir(rep)) != NULL) {
        fileString.assign(file->d_name);
        if (fileString.find(".so") != std::string::npos && 
        fileString.find("lib_") == 0 && 
        fileString.find("arcade_") == 4) {
            for (auto i = 11; i < (int)fileString.find(".so"); i++) {
                toVector.push_back(fileString[i]);
            }
            m_libs.push_back(toVector);
            toVector.clear();
        }
    }
}

void Core::fillGamesVector()
{
    DIR *rep = NULL;
    rep = opendir("games/");
    if (rep == NULL)
        throw "No lib directory";
    std::string fileString;
    std::string toVector;
    struct dirent *file = NULL;
    while ((file = readdir(rep)) != NULL)
    {
        fileString.assign(file->d_name);
        if (fileString.find(".so") != std::string::npos &&
            fileString.find("games_") == 0 &&
            fileString.find("arcade_") == 6)
        {
            for (auto i = 13; i < (int)fileString.find(".so"); i++)
            {
                toVector.push_back(fileString[i]);
            }
            m_games.push_back(toVector);
            toVector.clear();
        }
    }
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