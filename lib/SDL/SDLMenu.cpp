#include "SDLLib.hpp"

/* ------------------------------- MENU ------------------------------- */
// menu for selecting the graphical lib. returns 0 if nCurses is selected, 2 for SFML and 3 for SDL -1 for errors
int SDLLib::libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames)
{

}
// menu to select the game. returns 0 for game 0 if $gamesNames, 1 for game 2 if $gamesNames, etc...
int SDLLib::gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores)
{

}
// menu to enter the name. returns string with the name
std::string SDLLib::enterName(state pgState, bool close)
{

}

void SDLLib::eventMenu()
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
            }
        }
    }
}

int SDLLib::DrawMenu(state pgState, bool close, std::vector<std::string> gamesName, std::vector<std::vector<std::string>> highScores)
{
    this->createWindow(1080, 1080, "Menu SDL");
    TTF_Font *font = TTF_OpenFont("../../resources/Roboto-Medium.ttf", 14);
    if (font == NULL)
        throw "cannot open font";
    SDL_Color color = {255, 255, 255};
    SDL_Color yellowColor = {255, 255, 0};
    SDL_Surface *surfacePseudo = TTF_RenderText_Solid(font, "", color);
    SDL_Texture *texturePseudo = SDL_CreateTextureFromSurface(gRenderer, surfacePseudo);
    SDL_Surface *surfaceEnterPseudo = TTF_RenderText_Solid(font, "Enter your name :", color);
    SDL_Texture *textureEnterPseudo = SDL_CreateTextureFromSurface(gRenderer, surfaceEnterPseudo);
    SDL_Surface *surfaceNextLib = TTF_RenderText_Solid(font, "Press E for next lib", color);
    SDL_Texture *textureNextLib = SDL_CreateTextureFromSurface(gRenderer, surfaceNextLib);
    SDL_Surface *surfacePrevLib = TTF_RenderText_Solid(font, "Press A for previous lib", color);
    SDL_Texture *texturePrevLib = SDL_CreateTextureFromSurface(gRenderer, surfacePrevLib);
    SDL_Surface *surfaceYourName = TTF_RenderText_Solid(font, "Your name : ", color);
    SDL_Texture *textureYourName = SDL_CreateTextureFromSurface(gRenderer, surfaceYourName);
    std::vector<SDL_Surface *> gamesSurface;
    std::vector<SDL_Texture *> gamesTexture;
    std::vector<SDL_Rect> gamesRect;
    sizeGamesName = (int)gamesName.size() - 1;
    for (auto i = 0; i < (int)gamesName.size(); i++) {
        gamesSurface.push_back(TTF_RenderText_Solid(font, gamesName.at(i).c_str(), color));
        gamesTexture.push_back(SDL_CreateTextureFromSurface(gRenderer, gamesSurface.at(i)));
        gamesRect.push_back({600, i * 100 + 200, (int)gamesName.at(i).size() * 50, 100});
    }
    std::cout << gamesTexture.size() << std::endl;
    SDL_StartTextInput();
    int texW = 1000;
    int texH = 200;
    int count = 0;
    SDL_QueryTexture(texturePseudo, NULL, NULL, &texW, &texH);

    SDL_Rect rectPseudo = {240, 540, 100, 100};
    SDL_Rect rectEnterPseudo = {10, 100, texW, texH};
    SDL_Rect rectNextLib = {0, 200, 500, 100};
    SDL_Rect rectPrevLib = {0, 300, 500, 100};
    SDL_Rect rectYourName = {10, 10, 300, 50};
    while (!this->isWindowOpen()) {
        this->eventMenu();
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
            SDL_RenderCopy(gRenderer, textureNextLib, NULL, &rectPrevLib);
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
            count = 1;
        }
        rendertext = false;
        this->update();
    }
    SDL_StopTextInput();
}