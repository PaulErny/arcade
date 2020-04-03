#include "Core.hpp"

Core::Core(char *arg) : m_arg(arg) 
{
    indexLib = -1;
    isMenuInit = false;
    isGameInit = false;
    pgState = NOTHING;
    m_pseudo = "";

    m_handle = dlopen(m_arg, RTLD_LAZY);
    if (dlerror() != NULL)
        throw "Cannot open lib";
    std::shared_ptr<ILibs> (*create)();
    create = (std::shared_ptr<ILibs>(*)())dlsym(m_handle, "create_object");
    if (dlerror() != NULL)
        throw "Cannot open lib";
    Lib = (std::shared_ptr<ILibs>)create();

    this->fillLibVector();
    this->fillGamesVector();
    this->indexLibFill();
    this->Lib->createWindow(1080, 1080, "Arcade");
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
    std::shared_ptr<ILibs> (*create)();
    create = (std::shared_ptr<ILibs>(*)())dlsym(m_handle, "create_object");
    if (dlerror() != NULL)
        throw "Cannot open lib";
    std::shared_ptr<ILibs> Lib = (std::shared_ptr<ILibs>)create();
}

void Core::changeLib()
{
    // dlclose(m_handle);
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
    std::shared_ptr<ILibs> (*create)();
    create = (std::shared_ptr<ILibs>(*)())dlsym(m_handle, "create_object");
    if (dlerror() != NULL)
        throw "Cannot open lib";
    std::cout << "ok" << std::endl;
    Lib = (std::shared_ptr<ILibs>)create();
}

void Core::changeGame()
{
    if (dlerror() != NULL)
        throw dlerror();
    if (indexLib >= (int)m_games.size()) {
        indexLib = 0;
    }
    if (indexLib < 0) {
        indexLib = (int)m_games.size() - 1;
    }
    std::string open("games/games_arcade_" + m_games.at(indexLib) + ".so");
    m_handleGame = dlopen(open.c_str(), RTLD_LAZY);
    if (dlerror() != NULL)
        throw "Cannot open Lib";
    std::shared_ptr<IGames> (*create)();
    create = (std::shared_ptr<IGames>(*)())dlsym(m_handleGame, "create_object");
    if (dlerror() != NULL)
        throw "Cannot open lib";
    Games = (std::shared_ptr<IGames>)create();
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

void Core::fillGamesVector()
{
    DIR *rep = NULL;
    rep = opendir("games/");
    if (rep == NULL)
        throw "No lib directory";
    std::string fileString;
    std::string toVector;
    std::regex regGames("lib_arcade_.*[.so]$");
    struct dirent *file = NULL;
    while ((file = readdir(rep)) != NULL)
    {
        fileString.assign(file->d_name);
        if (std::regex_search(fileString, regGames))
        {
            for (auto i = 11; i < (int)fileString.find(".so"); i++)
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

void Core::laodLib(int currentLib)
{
    if (currentLib != indexLib) {
        this->Lib->deleteWindow();
        this->changeLib();
        this->isMenuInit = false;
        this->isGameInit = false;
        this->Lib->createWindow(1080, 1080, "Arcade");
    }
}

void Core::loadGameLib(int gameIndex)
{
    if (gameIndex != indexLib) {
        this->changeGame();
        this->isMenuInit = false;
    }
}

void Core::run()
{
    // TMP
    std::vector<std::vector<std::string>> highScores{{"pseudo1\t10655", "pseudo2\t10385", "pseudo1\t4521"}, {"pseudo1\t53", "pseudo2\t41", "pseudo1\t9"}};

    int chosenGame = -1;
    int currentLib = 0;
    int gameIndex = 0;
    this->pgState = MENU;

    while (this->Lib->isWindowOpen()) {
        currentLib = this->indexLib;
        
        // run the menu
        if (this->pgState == MENU) {
            //check if the menu has to be init
            if (!this->isMenuInit) {
                this->Lib->init_menu(this->m_libs, m_games, highScores, this->m_pseudo);
                this->isMenuInit = true;
            }
            // in case we want to change game
            if (this->isGameInit)
                this->isGameInit = false;

            // if no game was chosen yet chosenGame should be equal to -1, else its the index of the game in m_games
            chosenGame = this->Lib->menu(this->pgState, false, this->m_libs, m_games, highScores, this->m_pseudo, this->indexLib);
        }
        // this->Lib->nextGraphicLib(indexLib);
        // this->Lib->prevGraphicLib(indexLib);
        if (this->pgState == GAME && chosenGame != -1) {
            if (!this->isGameInit) {
                this->loadGameLib(chosenGame);
                this->Games->initGameData();
                this->Games->initGraphics();
                this->isGameInit = true;
            }
            this->Games->runGame();
        }    
        // check for lib changment  
        this->laodLib(currentLib);
    }
}