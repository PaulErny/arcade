/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ILibs
*/

#ifndef ILIBS_HPP
#define ILIBS_HPP

#include <string>

enum ShapeType {
    RECTANGLE,
    CIRCLE,
};

class ILibs {
    public:
        virtual ~ILibs()=default;

        /* ------------------------------- RELATED TO SHAPES ------------------------------- */
        // explicit. if rectangle -> use $width and $height, if sphere -> $width = radius
        // returns the index of the newly created shape in a std::vector of shapes
        virtual int createShape(ShapeType, int width, int height=0)=0;
        // draws the shape contained at $index of the vector of shapes
        virtual void drawShape(int index)=0;
        // sets the position of the shape contained at $index of the vector of shapes
        virtual void setShapePos(int index, int x, int y)=0;
        // sets the color of the shape contained at $index of the vector of shapes
        virtual void setShapeColor(int index, int r, int g, int b, int a=255)=0;
        // deletes the shape contained at $index of the vector of shapes
        virtual void deleteShape(int index)=0;

        /* ------------------------------- RELATED TO SPRITES ------------------------------- */
        // creates a sprite from an image and return its ID to later modify it
        virtual int createImageFromFile(std::string filename)=0;
        // draws the sprite contained at $ImageId of the vector of shapes
        virtual void drawImage(int ImageId)=0;
        // sets the position of the sprite contained at $ImageId of the vector of shapes
        virtual void setImagePos(int ImageId, int x, int y)=0;
        // deletes the sprite contained at $ImageId of the vector of sprites
        virtual void deleteImage(int ImageId)=0;

        /* ------------------------------- RELATED TO TEXT ------------------------------- */
        // creates a texture from the image file given as parameter
        // returns the index of the newly created texture
        virtual int createFontFromFile(const std::string filename)=0;
        // creates a text and sets if font according to the id returned by createFontFromFile()
        // returns the index of the newly created text
        virtual int createText(std::string text, int fontId)=0;
        // draws the text contained at $textId of the vector of shapes
        virtual void drawText(int textId)=0;
        // sets the string of a text element
        virtual void setTextString(int textId, std::string str)=0;
        // sets the position of the sprite contained at $spriteId of the vector of shapes
        virtual void setTextPos(int textId, int x, int y)=0;
        // sets the size of the text to $charSize
        virtual void setTextCharSize(int textId, int charSize)=0;
        // changes the color of the text
        virtual void setTextColor(int textId, int r, int g, int b, int a=255)=0;
        // deletes the text contained at $textId of the vector of texts
        virtual void deleteText(int TextId)=0;
        // deletes the font contained at $fontId of the vector of fonts
        virtual void deleteFont(int FontId)=0;

        /* ------------------------------- RELATED TO WINDOWS ------------------------------- */
        // creates a window of size ($width * $height) and named $name
        virtual void createWindow(int width, int height, std::string name)=0;
        // returns true if the window is open
        virtual bool isWindowOpen(void)=0;
        // refreshes the window
        virtual void clearWindow(void)=0;
        // updates the display
        virtual void update(void)=0;
        // resizes window to ($width * $height)
        virtual void resizeWindow(int width, int height)=0;
        // renames the window to $name
        virtual void renameWindow(std::string name)=0;
        // deletes the window
        virtual void deleteWindow(void)=0;

        /* ------------------------------- RELATED TO EVENTS ------------------------------- */
        // handle events occuring in the window
        virtual bool events(void)=0;
        // closes the window in case of such an event
        virtual void closeWindowEvent(void)=0; 
};

#endif /* !ILIBS_HPP */
