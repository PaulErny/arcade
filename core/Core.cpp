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

void Core::changeLib()
{
    // if (dlclose(m_handle);
    if (dlerror() != NULL)
        throw dlerror();
    if (indexLib >= (int)m_libs.size()) {
        indexLib = 0;
    }
    if (indexLib < 0) {
        indexLib = (int)m_libs.size() - 1;
    }
    std::cout << (int)m_libs.size() - 1 << std::endl;
    std::string open("lib/lib_arcade_" + m_libs.at(indexLib) + ".so");
    m_handle = dlopen(open.c_str(), RTLD_LAZY);
    if (dlerror() != NULL)
        throw "Cannot open Lib";
    std::unique_ptr<ILibs> (*create)();
    create = (std::unique_ptr<ILibs>(*)())dlsym(m_handle, "create_object");
    if (dlerror() != NULL)
        throw "Cannot open lib";
    std::cout << "ok" << std::endl;
    Lib = (std::unique_ptr<ILibs>)create();
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

void Core::indexLibFill()
{
    std::regex reg;
    for (int i = 0; i < m_libs.size(); i++) {
        reg = m_libs.at(i);
        if (std::regex_search(m_arg, reg)) {
            indexLib = i; 
        }
    }
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
    Lib = (std::unique_ptr<ILibs>)create();
    Lib->createWindow(1080, 1080, "Arcade");
    state pgState = MENU;
    std::vector<std::string> names{"pacman", "nibbler"};
    // this->fillLibVector();
    m_libs = {"sdl2", "sfml", "ncurses"};
    this->indexLibFill();
    std::cout << indexLib << std::endl;
    std::vector<std::vector<std::string>> highScores{{"pseudo1\t10655", "pseudo2\t10385", "pseudo1\t4521"}, {"pseudo1\t53", "pseudo2\t41", "pseudo1\t9"}};
    std::string pseudo = "";
    Lib->init_menu(m_libs, names, highScores, pseudo);
    int ind = 0;

    while (Lib->isWindowOpen())
    {
        ind = indexLib;
        if (pgState == MENU)
            Lib->menu(pgState, false, m_libs, names, highScores, pseudo, indexLib);
        // std::cout << indexLib << std::endl;
        if (ind != indexLib) {
            Lib->deleteWindow();
            changeLib();
            Lib->createWindow(1080, 1080, "Arcade");
            Lib->init_menu(m_libs, names, highScores, pseudo);
        }
    }
    // dlclose(m_handle);
}


void Core::loop()
{
    state pgState = MENU; // add to class variables ?
    std::vector<std::vector<std::string>> highScores{{"pseudo1\t10655", "pseudo2\t10385", "pseudo1\t4521"}, {"pseudo1\t53", "pseudo2\t41", "pseudo1\t9"}};
    std::vector<std::string> names{"pacman", "nibbler"};
    std::string pseudo = "";
    int gameToLaunch = -1;

    while (this->Lib->isWindowOpen()) {
        while (this->Lib->events()) {
            this->Lib->closeWindowEvent();
        }

        // check for prev or next lib
        // this->Lib->nextGraphicLib();
        // this->Lib->prevGraphicLib();

        this->Lib->clearWindow();

        if (pgState == MENU) {
            if (!this->isMenuInit)
                this->Lib->init_menu(this->m_libs, names, highScores, pseudo);
            gameToLaunch = Lib->menu(pgState, false, m_libs, names, highScores, pseudo, indexLib);
        } else if (pgState == GAME) {
            // start playing
        } else {
            // blem
        }

        this->Lib->update();
    }
}