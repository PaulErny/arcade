#ifndef IENTITY_HPP
#define IENTITY_HPP

#include "../lib/ILibs.hpp"

enum entityType {
    SHAPE,
    SPRITE,
};

class Entity
{
    public:
        Entity(entityType type); // creates an entity
        ~Entity();

        void move(int xOffset, int yOffset); // moves the entity from its current pos to (posX + xOffset, posY + yOffset)
        void addShape(int height, int width, int r=255, int g=255, int b=255); // adds a shape to the shapes vector
        void addImage(std::string file); // adds a sprite to the shapes vector
        void nextShape(); // explicit
        void prevShape();
        void changeColor(int r, int g, int b); // explicit
        void draw();

    private:
        int posX;
        int posY;

        int height;
        int width;

        int color_r;
        int color_g;
        int color_b;

        entityType type; // type of the shapes
        std::vector<int> shapes; // for sprite sheets or animations with shapes
        int currentShape;

        ILibs *graphics;
};

#endif
