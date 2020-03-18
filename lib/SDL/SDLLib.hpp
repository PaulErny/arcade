#ifndef SDL_HPP
#define SDL_HPP

#include "SDL2/SDL.h"
#include "../ILibs.hpp"
#include <memory>

class SDLLib : public ILibs
{
private:
    /* data */
public:
    SDLLib(/* args */);
    ~SDLLib();
    /* ------------------------------- RELATED TO SHAPES ------------------------------- */
    // explicit. if rectangle -> use $width and $height, if sphere -> $width = radius
    // returns the index of the newly created shape in a std::vector of shapes
    int createShape(ShapeType, int width, int height = 0);
    // draws the shape contained at $index of the vector of shapes
    void drawShape(int index);
    // sets the position of the shape contained at $index of the vector of shapes
    void setShapePos(int index, int x, int y);
    // sets the color of the shape contained at $index of the vector of shapes
    void setShapeColor(int index, int r, int g, int b, int a = 255);
    // deletes the shape contained at $index of the vector of shapes
    void deleteShape(int index);

    /* ------------------------------- RELATED TO SPRITES ------------------------------- */
    // creates a sprite from an image and return its ID to later modify it
    int createImageFromFile(std::string filename);
    // draws the sprite contained at $ImageId of the vector of shapes
    void drawImage(int ImageId);
    // sets the position of the sprite contained at $ImageId of the vector of shapes
    void setImagePos(int ImageId, int x, int y);
    // deletes the sprite contained at $ImageId of the vector of sprites
    void deleteImage(int ImageId);

    /* ------------------------------- RELATED TO TEXT ------------------------------- */
    // creates a texture from the image file given as parameter
    // returns the index of the newly created texture
    int createFontFromFile(const std::string filename);
    // creates a text and sets if font according to the id returned by createFontFromFile()
    // returns the index of the newly created text
    int createText(std::string text, int fontId);
    // draws the text contained at $textId of the vector of shapes
    void drawText(int textId);
    // sets the string of a text element
    void setTextString(int textId, std::string str);
    // sets the position of the sprite contained at $spriteId of the vector of shapes
    void setTextPos(int textId, int x, int y);
    // sets the size of the text to $charSize
    void setTextCharSize(int textId, int charSize);
    // changes the color of the text
    void setTextColor(int textId, int r, int g, int b, int a = 255);
    // deletes the text contained at $textId of the vector of texts
    void deleteText(int TextId);
    // deletes the font contained at $fontId of the vector of fonts
    void deleteFont(int FontId);

    /* ------------------------------- RELATED TO WINDOWS ------------------------------- */
    // creates a window of size ($width * $height) and named $name
    void createWindow(int width, int height, std::string name);
    // returns true if the window is open
    bool isWindowOpen(void);
    // refreshes the window
    void clearWindow(void);
    // updates the display
    void update(void);
    // resizes window to ($width * $height)
    void resizeWindow(int width, int height);
    // renames the window to $name
    void renameWindow(std::string name);
    // deletes the window
    void deleteWindow(void);

    /* ------------------------------- RELATED TO EVENTS ------------------------------- */
    // handle events occuring in the window
    bool events(void);
    // closes the window in case of such an event
    void closeWindowEvent(void);
};

#endif