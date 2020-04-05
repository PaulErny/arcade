/**
 * \file SDLLib.cpp
 * \brief SDL Lib
 */

#include "SDLLib.hpp"

SDLLib::SDLLib()
{
}

SDLLib::~SDLLib()
{
}

/* ------------------------------- RELATED TO SHAPES ------------------------------- */

int SDLLib::createShape(ShapeType type, int width, int height)
{
    shapeRect.push_back({0, 0, width, height});
    shapeType.push_back(type);
    return (int)(shapeRect.size() - 1);
}

void SDLLib::drawShape(int index)
{
    if (index < (int)shapeRect.size() && shapeType.at(index) == RECTANGLE) {
        SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
        SDL_RenderFillRect(gRenderer, &shapeRect.at(index));
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    }
    // else if (index < (int)shapeRect.size() && shapeType.at(index) == CIRCLE) {
    //     SDL_RenderDraw
    // }
}

void SDLLib::setShapeColor(int index, int r, int g, int b, int a)
{
    // SDL_SetRenderDrawColor(gRenderer, a, g, b, a);
}

void SDLLib::deleteShape(int index)
{

}

void SDLLib::setShapePos(int index, float x, float y)
{
    if (index < (int)shapeRect.size()) {
        shapeRect.at(index).x = (int)x;
        shapeRect.at(index).y = (int)y;
    }
}

/* ------------------------------- RELATED TO SPRITES ------------------------------- */

int SDLLib::createImageFromFile(std::string filename)
{
    SDL_Surface *image = IMG_Load(filename.c_str());
    textureImage.push_back(SDL_CreateTextureFromSurface(gRenderer, image));
    int w, h;
    SDL_QueryTexture(textureImage.at(textureImage.size() - 1), NULL, NULL, &w, &h);
    SDL_Rect texr;
    texr.x = 0;
    texr.y = 0;
    texr.h = h * 2;
    texr.w = w * 2;
    rectImage.push_back(texr);
    return (int)(textureImage.size() - 1);
}

void SDLLib::drawImage(int ImageId)
{
    SDL_RenderCopy(gRenderer, textureImage.at(ImageId), NULL, &rectImage.at(ImageId));
}

void SDLLib::setImagePos(int ImageId, float x, float y)
{
    rectImage.at(ImageId).x = (int)x;
    rectImage.at(ImageId).y = (int)y;
}

void SDLLib::deleteImage(int ImageId)
{
}

/* ------------------------------- RELATED TO TEXT ------------------------------- */

int SDLLib::createFontFromFile(const std::string filename)
{
    gFont.push_back(TTF_OpenFont(filename.c_str(), 24));
    return (gFont.size() - 1);
}

int SDLLib::createText(std::string text, int fontId)
{
    if (fontId < gFont.size() + 1) {
        SDL_Rect Message_rect;   //create a rect
        Message_rect.x = 0; //controls the rect's x coordinate
        Message_rect.y = 0; // controls the rect's y coordinte
        Message_rect.w = 200;    // controls the width of the rect
        Message_rect.h = 200;
        gRect.push_back(Message_rect);
        this->setTextColor(fontId, 255, 255, 255);
        std::cout << fontId << "test" << gColor.size() << "tes2" << gFont.size() << std::endl;
        gTextSurface.push_back(TTF_RenderText_Solid(gFont.at(fontId), text.c_str(), gColor.at(fontId)));
        gTexture.push_back(SDL_CreateTextureFromSurface(gRenderer, gTextSurface.at(fontId)));
        if (gTextSurface.at(gTextSurface.size() - 1) == NULL)
            throw "Unable to create texture from rendered text";
    }
    return (gTexture.size() - 1); // may not be the right vector
}

void SDLLib::drawText(int textId)
{
    SDL_RenderCopy(gRenderer, gTexture.at(textId), NULL, &gRect.at(textId));
}

void SDLLib::setTextString(int textId, std::string str)
{
    if (textId < (int)gTexture.size()) {
        SDL_FreeSurface(gTextSurface.at(textId));
        SDL_free(gTexture.at(textId));
        gTextSurface.at(textId) = (TTF_RenderText_Solid(gFont.at(textId), str.c_str(), gColor.at(textId)));
        gTexture.at(textId) = (SDL_CreateTextureFromSurface(gRenderer, gTextSurface.at(textId)));
    }
    else
        throw "SDL2 -> setTexString : unknown index";
}

void SDLLib::setTextPos(int textId, float x, float y)
{
    gRect.at(textId).x = int(x);
    gRect.at(textId).y = int(y);
}

void SDLLib::setTextCharSize(int textId, int charSize)
{

}

void SDLLib::setTextColor(int textId, int r, int g, int b, int a)
{
    gColor.push_back({static_cast<Uint8>(r), static_cast<Uint8>(g), static_cast<Uint8>(b)});
}

void SDLLib::deleteText(int TextId)
{
}

void SDLLib::deleteFont(int FontId)
{
    TTF_CloseFont(gFont.at(FontId));
}

/* ------------------------------- RELATED TO WINDOWS ------------------------------- */

void SDLLib::createWindow(int width, int height, std::string name)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->quit = false;
    gWindow = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
        throw ("Window could not be created!");

        //Create renderer for window
        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL)
        throw("Renderer could not be created!");
    else
    {
        //Initialize renderer color
        // SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags))
        {
            throw("SDL_image could not initialize!");
        }
        if (TTF_Init() == -1)
            throw "SDL_TTF coud not initialize!";
    }
}

bool SDLLib::isWindowOpen(void)
{
    return (!quit);
}

void SDLLib::clearWindow(void)
{
    SDL_RenderClear(gRenderer);
}

void SDLLib::update(void)
{
    SDL_RenderPresent(gRenderer);
}

void SDLLib::resizeWindow(int width, int height)
{
}

void SDLLib::renameWindow(std::string name)
{
}

void SDLLib::deleteWindow(void)
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    if (font != NULL)
        TTF_CloseFont(font);
    gWindow = NULL;
    gRenderer = NULL;
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

/* ------------------------------- RELATED TO EVENTS ------------------------------- */

bool SDLLib::events(void)
{
    return (SDL_PollEvent(&e));
}

bool SDLLib::closeWindowEvent(void)
{
    if (e.type == SDL_QUIT) {
        quit = true;
        return (true);
    }
    return (false);
}

void SDLLib::nextGraphicLib(int &indexLib)
{
    if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.sym == SDLK_e)
            indexLib++;
    }
}

void SDLLib::prevGraphicLib(int &indexLib)
{
    if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.sym == SDLK_a)
            indexLib--;
    }
}

bool SDLLib::upArrow()
{
    if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.sym == SDLK_UP)
            return (true);
    }
    return false;
}

bool SDLLib::downArrow()
{
    if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.sym == SDLK_DOWN)
            return (true);
    }
    return false;
}

bool SDLLib::leftArrow()
{
    if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.sym == SDLK_LEFT)
            return (true);
    }
    return false;
}

bool SDLLib::rigthArrow()
{
    if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.sym == SDLK_RIGHT)
            return (true);
    }
    return false;
}

bool SDLLib::keyReleasedEvent(void)
{
    return (false);
}

void SDLLib::nextGameLib(int &indexGame)
{
    if (e.type == SDL_KEYDOWN)
    {
        if (e.key.keysym.sym == SDLK_d)
            indexGame++;
    }
}

void SDLLib::prevGameLib(int &indexGame)
{
    if (e.type == SDL_KEYDOWN)
    {
        if (e.key.keysym.sym == SDLK_q)
            indexGame--;
    }
}

extern "C" std::shared_ptr<SDLLib> create_object()
{
    return std::make_shared<SDLLib>();
}