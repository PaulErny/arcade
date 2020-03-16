/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLib
*/

#ifndef SFMLLIB_HPP
#define SFMLLIB_HPP

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "../ILibs.hpp"

class SFMLLib : public ILibs {
    public:
        SFMLLib();
        ~SFMLLib();

        /* ------------------------------- RELATED TO SHAPES ------------------------------- */
        // explicit. if rectangle -> use $width and $height, if sphere -> $width = radius
        // returns the index of the newly created shape in a std::vector of shapes
        int createShape(ShapeType, int width, int height=0);
        // draws the shape contained at $index of the vector of shapes
        void drawShape(int index);
        // sets the position of the shape contained at $index of the vector of shapes
        void setShapePos(int index, int x, int y);
        // sets the color of the shape contained at $index of the vector of shapes
        void setShapeColor(int index, int r, int g, int b, int a=255);
        // deletes the shape contained at $index of the vector of shapes
        void deleteShape(int index);

        /* ------------------------------- RELATED TO SPRITES / TEXTURES ------------------------------- */
        // creates a texture from the image file given as parameter
        // returns the index of the newly created texture
        int createTextureFromFile(const std::string filename);
        // creates a sprite and assigns it the id of the texture returned by createTexture()
        // returns the index of the newly created sprite
        int createSprite(int textureId);
        // draws the sprite contained at $spriteId of the vector of shapes
        void drawSprite(int spriteId);
        // sets the position of the sprite contained at $spriteId of the vector of shapes
        void setSpritePos(int spriteId, int x, int y);
        // deletes the sprite contained at $spriteId of the vector of sprites
        void deleteSprite(int spriteId);
        // deletes the texture contained at $textureId of the vector of textures
        void deleteTexture(int spriteId);

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
        void setTextString(std::string str);
        // sets the position of the sprite contained at $spriteId of the vector of shapes
        void setTextPos(int textId, int x, int y);
        // sets the size of the text to $charSize
        void setTextCharSize(int textId, int charSize);
        // changes the color of the text
        void setTextColor(int textId, int r, int g, int b, int a=255);
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

    private:
        std::vector<std::shared_ptr<sf::Texture>> textures;
        std::vector<std::shared_ptr<sf::Sprite>> sprites;
        std::vector<std::shared_ptr<sf::Font>> fonts;
        std::vector<std::shared_ptr<sf::Text>> texts;
        std::vector<std::shared_ptr<sf::Shape>> shapes;
        std::shared_ptr<sf::RenderWindow> window;
        sf::Event event;
};

#endif /* !SFMLLIB_HPP_ */
