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
}

bool SDLLib::isWindowOpen(void)
{

}

void SDLLib::clearWindow(void)
{

}

void SDLLib::update(void)
{
}

void SDLLib::resizeWindow(int width, int height)
{
}

void SDLLib::renameWindow(std::string name)
{
}

void SDLLib::deleteWindow(void)
{
}

/* ------------------------------- RELATED TO EVENTS ------------------------------- */

bool SDLLib::events(void)
{
}

void SDLLib::closeWindowEvent(void)
{

}

extern "C" std::unique_ptr<SDLLib> create_object()
{
    return std::make_unique<SDLLib>();
}