#include "SDLLib.hpp"

/* ------------------------------- MENU ------------------------------- */
// menu for selecting the graphical lib. returns 0 if nCurses is selected, 2 for SFML and 3 for SDL -1 for errors
int SDLLib::libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames)
{
    return (-1);
}
// menu to select the game. returns 0 for game 0 if $gamesNames, 1 for game 2 if $gamesNames, etc...
int SDLLib::gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores)
{
    return (-1);
}
// menu to enter the name. returns string with the name
std::string SDLLib::enterName(state &pgState, bool close)
{
    return ("");
}

void SDLLib::eventMenu(int &indexLib)
{
    while (SDL_PollEvent(&e) != 0) {
        this->closeWindowEvent();
        if ((e.type == SDL_TEXTINPUT || e.type == SDL_KEYDOWN) && name == "") {
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0)
                    text = text.substr(0, text.length() - 1);
                else if (e.key.keysym.sym == 13 && text.length() > 0) {
                    name = text;
                }
            } else if (e.type == SDL_TEXTINPUT)
                this->text += e.text.text;
            rendertext = true;
        }
        else if (name != "") {
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_UP) {
                    if (indexGame > 0)
                        indexGame -= 1;
                }
                if (e.key.keysym.sym == SDLK_DOWN) {
                    if (indexGame < sizeGamesName) {
                        indexGame += 1;
                    }
                }
                if (e.key.keysym.sym == SDLK_e) {
                    std::cout << "bite" << std::endl;
                    this->nextGraphicLib(indexLib);
                }
                if (e.key.keysym.sym == SDLK_a) {
                    this->prevGraphicLib(indexLib);
                }
            }
        }
    }
}

void SDLLib::init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo)
{
    name = pseudo;
    font = TTF_OpenFont("resources/ARCADE_I.TTF", 14);
    if (font == NULL)
        throw "cannot open font";
    color = {255, 255, 255};
    yellowColor = {255, 255, 0};
    surfacePseudo = TTF_RenderText_Solid(font, "", color);
    texturePseudo = SDL_CreateTextureFromSurface(gRenderer, surfacePseudo);
    surfaceEnterPseudo = TTF_RenderText_Solid(font, "Enter your name :", color);
    textureEnterPseudo = SDL_CreateTextureFromSurface(gRenderer, surfaceEnterPseudo);
    surfaceNextLib = TTF_RenderText_Solid(font, "Press E for next lib", color);
    textureNextLib = SDL_CreateTextureFromSurface(gRenderer, surfaceNextLib);
    surfacePrevLib = TTF_RenderText_Solid(font, "Press A for previous lib", color);
    texturePrevLib = SDL_CreateTextureFromSurface(gRenderer, surfacePrevLib);
    surfaceYourName = TTF_RenderText_Solid(font, "Your name : ", color);
    textureYourName = SDL_CreateTextureFromSurface(gRenderer, surfaceYourName);
    sizeGamesName = (int)gamesNames.size() - 1;
    for (auto i = 0; i < (int)gamesNames.size(); i++) {
        gamesSurface.push_back(TTF_RenderText_Solid(font, gamesNames.at(i).c_str(), color));
        gamesTexture.push_back(SDL_CreateTextureFromSurface(gRenderer, gamesSurface.at(i)));
        gamesRect.push_back({600, i * 100 + 200, (int)gamesNames.at(i).size() * 50, 100});
    }
    for (auto i = 0; i < (int)libsNames.size(); i++) {
        libsSurface.push_back(TTF_RenderText_Solid(font, libsNames.at(i).c_str(), color));
        libsTexture.push_back(SDL_CreateTextureFromSurface(gRenderer, libsSurface.at(i)));
        libsRect.push_back({10, i * 100 + 500, (int)libsNames.at(i).size() * 50, 100});
    }
    SDL_StartTextInput();
    SDL_QueryTexture(texturePseudo, NULL, NULL, &texW, &texH);
}

int SDLLib::menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesName, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib)
{
    pseudo = name;
    this->eventMenu(indexLib);
    this->clearWindow();
    if (name == "") {
        rectPseudo = {240, 540, (int)text.size() * 50, 100};
        SDL_RenderCopy(gRenderer, texturePseudo, NULL, &rectPseudo);
        SDL_RenderCopy(gRenderer, textureEnterPseudo, NULL, &rectEnterPseudo);
        if (rendertext && name == "") {
            surfacePseudo = TTF_RenderText_Solid(font, text.c_str(), color);
            texturePseudo = SDL_CreateTextureFromSurface(gRenderer, surfacePseudo);
            SDL_SetTextInputRect(&rectPseudo);
        }
    } else {
        if (count == 0) {
            rectPseudo = {400, 0, (int)name.size() * 50, 100};
            surfacePseudo = TTF_RenderText_Solid(font, name.c_str(), color);
            texturePseudo = SDL_CreateTextureFromSurface(gRenderer, surfacePseudo);
        }
        SDL_RenderCopy(gRenderer, textureYourName, NULL, &rectYourName);
        SDL_RenderCopy(gRenderer, texturePseudo, NULL, &rectPseudo);
        SDL_RenderCopy(gRenderer, textureNextLib, NULL, &rectNextLib);
        SDL_RenderCopy(gRenderer, texturePrevLib, NULL, &rectPrevLib);
        for (auto i = 0; i < (int)gamesName.size(); i++) {
            if (i == indexGame) {
                if (indexGame < (int)gamesSurface.size()) {
                gamesSurface.at(indexGame) = TTF_RenderText_Solid(font, gamesName.at(indexGame).c_str(), yellowColor);
                gamesTexture.at(indexGame) = SDL_CreateTextureFromSurface(gRenderer, gamesSurface.at(indexGame));
                }
            } else {
                gamesSurface.at(i) = TTF_RenderText_Solid(font, gamesName.at(i).c_str(), color);
                gamesTexture.at(i) = SDL_CreateTextureFromSurface(gRenderer, gamesSurface.at(i));
            }
            SDL_RenderCopy(gRenderer, gamesTexture.at(i), NULL, &gamesRect.at(i));
        }
        for (size_t i = 0; i < libsNames.size(); i++) {
            SDL_RenderCopy(gRenderer, libsTexture.at(i), NULL, &libsRect.at(i));
        }
        count = 1;
    }
    this->update();
    rendertext = false;
}