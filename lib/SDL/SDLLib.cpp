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

}

void SDLLib::drawShape(int index)
{
}

void SDLLib::setShapeColor(int index, int r, int g, int b, int a)
{
}

void SDLLib::deleteShape(int index)
{

}

void SDLLib::setShapePos(int index, int x, int y)
{

}

/* ------------------------------- RELATED TO SPRITES ------------------------------- */

int SDLLib::createImageFromFile(std::string filename)
{

}

void SDLLib::drawImage(int ImageId)
{

}

void SDLLib::setImagePos(int ImageId, int x, int y)
{

}

void SDLLib::deleteImage(int ImageId)
{
}

/* ------------------------------- RELATED TO TEXT ------------------------------- */

/*bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface *textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    if (textSurface == NULL)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (mTexture == NULL)
        {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }

    //Return success
    return mTexture != NULL;
}*/

int SDLLib::createFontFromFile(const std::string filename)
{

}

int SDLLib::createText(std::string text, int fontId)
{

}

void SDLLib::drawText(int textId)
{

}

void SDLLib::setTextString(int textId, std::string str)
{

}

void SDLLib::setTextPos(int textId, int x, int y)
{

}

void SDLLib::setTextCharSize(int textId, int charSize)
{

}

void SDLLib::setTextColor(int textId, int r, int g, int b, int a)
{

}

void SDLLib::deleteText(int TextId)
{

}

void SDLLib::deleteFont(int FontId)
{

}

/* ------------------------------- RELATED TO WINDOWS ------------------------------- */

void SDLLib::createWindow(int width, int height, std::string name)
{
    gWindow = SDL_CreateWindow("SDL WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 1080, SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
        throw ("Window could not be created!");
    else
    {
        //Create renderer for window
        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
        if (gRenderer == NULL)
            throw ("Renderer could not be created!");
        else
        {
            //Initialize renderer color
            SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags))
            {
                throw ("SDL_image could not initialize!");
            }
        }
    }
}

bool SDLLib::isWindowOpen(void)
{
    return (quit);
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
    gWindow = NULL;
    gRenderer = NULL;
    IMG_Quit();
    SDL_Quit();
}

/* ------------------------------- RELATED TO EVENTS ------------------------------- */

bool SDLLib::events(void)
{
}

void SDLLib::closeWindowEvent(void)
{
    while (SDL_PollEvent(&e) != 0)
    {
        //User requests quit
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }
    }
}

extern "C" std::unique_ptr<SDLLib> create_object()
{
    return std::make_unique<SDLLib>();
}