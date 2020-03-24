#include "Core.hpp"

Core::Core(char *arg) : m_arg(arg) 
{

}

Core::~Core()
{

}

void Core::nextLib(std::string libName)
{
    if (m_handle != NULL)
        dlclose(m_handle);
    std::string open("lib/lib_arcade_" + libName);
    m_handle = dlopen(open.c_str(), RTLD_LAZY);
    std::unique_ptr<ILibs> (*create)();
    create = (std::unique_ptr<ILibs>(*)())dlsym(m_handle, "create_object");
    if (dlerror() != NULL)
        throw "Cannot open lib";
    std::unique_ptr<ILibs> Lib = (std::unique_ptr<ILibs>)create();
}

void Core::previousLib(std::string libName)
{
    if (m_handle != NULL)
        dlclose(m_handle);
    std::string open("lib/lib_arcade_" + libName);
    m_handle = dlopen(open.c_str(), RTLD_LAZY);
    std::unique_ptr<ILibs> (*create)();
    create = (std::unique_ptr<ILibs>(*)())dlsym(m_handle, "create_object");
    if (dlerror() != NULL)
        throw "Cannot open lib";
    std::unique_ptr<ILibs> Lib = (std::unique_ptr<ILibs>)create();
}

const std::vector<std::string> &Core::getLibs() const
{
    return (m_libs);
}

const std::vector<std::string> &Core::getGames() const
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
    std::regex regLib("lib_arcade_.*[.so]$");
    struct dirent *file = NULL;
    while ((file = readdir(rep)) != NULL) {
        fileString.assign(file->d_name);
        if (std::regex_search(fileString, regLib)) {
            for (auto i = 11; i < (int)fileString.find(".so"); i++) {
                toVector.push_back(fileString[i]);
            }
            m_libs.push_back(toVector);
            toVector.clear();
        }
    }
    closedir(rep);
}

//

void Core::fillGamesVector()
{
    DIR *rep = NULL;
    rep = opendir("games/");
    if (rep == NULL)
        throw "No lib directory";
    std::string fileString;
    std::string toVector;
    std::regex regGames("games_arcade_.*[.so]$");
    struct dirent *file = NULL;
    while ((file = readdir(rep)) != NULL)
    {
        fileString.assign(file->d_name);
        if (std::regex_search(fileString, regGames))
        {
            for (auto i = 13; i < (int)fileString.find(".so"); i++)
            {
                toVector.push_back(fileString[i]);
            }
            m_games.push_back(toVector);
            toVector.clear();
        }
    }
    closedir(rep);
}

void Core::laodLib()
{
    m_handle = dlopen(m_arg, RTLD_LAZY);

    if (dlerror() != NULL)
        throw "Cannot open lib";
    std::unique_ptr<ILibs> (*create)();
    create = (std::unique_ptr<ILibs>(*)())dlsym(m_handle, "create_object");
    if (dlerror() != NULL)
        throw "Cannot open lib";
    std::unique_ptr<ILibs> Lib = (std::unique_ptr<ILibs>)create();
    Lib->createWindow(1080, 1080, "Arcade");
    state pgState = MENU;
    std::vector<std::string> names{"pacman", "nibbler"};
    std::vector<std::string> libs{"SDL", "SFML", "ncurses"};
    std::vector<std::vector<std::string>> highScores{{"pseudo1\t10655", "pseudo2\t10385", "pseudo1\t4521"}, {"pseudo1\t53", "pseudo2\t41", "pseudo1\t9"}};
    std::string pseudo = "";
    Lib->init_menu(libs, names, highScores, pseudo);

    while (Lib->isWindowOpen())
    {
        if (pgState == MENU)
            Lib->menu(pgState, false, libs, names, highScores, pseudo);
    }
}