/**
 * \file Entity.hpp
 * \brief Entity
 */
#ifndef IENTITY_HPP
#define IENTITY_HPP

#include <memory>
#include "../lib/ILibs.hpp"

/**
 * \enum entityType
 * \brief All entityType
 *
 * SHAPE and SPRITE
 */
enum entityType
{
    SHAPE,
    SPRITE,
};
/*! \class Entity
   * \brief class of Entity
   *
   */
class Entity
{
  public:
    /**
 * \fn Entity()
 * \brief Constructor
 * 
 * \param arg is the arguments
 */
    Entity(); // creates an entity
    /**
 * \fn ~Entity()
 * \brief Destructor
 */
    ~Entity();
/**
 * \fn void move(float xOffset, float yOffset);   
 * \brief moves the entity from its current pos to (posX + xOffset, posY + yOffset)
 * 
 * \param xOffset is the coordinate x
 * \param yOffset is the coordinate y
 *
 */
    void move(float xOffset, float yOffset);
    /**
 * \fn void addShape(int height, int width, int r, int g, int b)
 * \brief adds a shape to the shapes vector
 * 
 * \param height is for the height
 * \param width is for the width
 * \param r for the color
 * \param g for the color
 * \param b for the color
 *
 */
    void addShape(int height, int width, int r = 255, int g = 255, int b = 255);
   /**
 * \fn void addImage(std::string file);
 * \brief adds a sprite to the shapes vector
 * 
 * \param file is the path to the ressource
 *
 */
    void addImage(std::string file);
   /**
 * \fn void nextShape();
 * \brief Function that change Shape by incrementing
 *
 */
    void resetGraphics();
   /**
 * \fn void nextShape();
 * \brief Function that change Shape by incrementing
 *
 */
    void nextShape();
   /**
 * \fn void prevShape();
 * \brief Function that change Shape by decrementing
 *
 */
    void prevShape();
   /**
 * \fn void changeColor(int r, int g, int b);
 * \brief Function that change the color of the entity
 * 
 * \param r for the color
 * \param g for the color
 * \param b for the color
 *
 */
    void changeColor(int r, int g, int b);
   /**
 * \fn void setPosition(float x, float y);
 * \brief Function that set position of the entity
 * 
 * \param x for the coordonate
 * \param y for the coordonate
 *
 */
    void setPosition(float x, float y);
   /**
 * \fn void updatePosition();
 * \brief Function that update the position of the entity
 *
 */
    void updatePosition();
   /**
 * \fn const float &getXposition() const;
 * \brief Function that get position X of the entity
 * 
 * \return float
 */
    const float &getXposition() const;
   /**
 * \fn const float &getYposition() const;
 * \brief Function that get position Y of the entity
 * 
 * \return float
 */
    const float &getYposition() const;
   /**
 * \fn const std::vector<int> &getVectorOfShape() const;
 * \brief Function that get vector of shape
 * 
 * \return std::vector<int>
 *
 */
    const std::vector<int> &getVectorOfShape() const;
   /**
 * \fn void draw();
 * \brief Function that draw the entity
 *
 */
    void draw();
   /**
 * \fn void setLibPtr(std::shared_ptr<ILibs>);
 * \brief Function that set lib
 *
 */
    void setLibPtr(std::shared_ptr<ILibs>);
   /**
 * \fn void setType(entityType type);
 * \brief Function that set type
 *
 */
    void setType(entityType type);

  protected:
    int inVector;
    float posX = 0.0;
    float posY = 0.0;

    int height;
    int width;

    int color_r;
    int color_g;
    int color_b;

    entityType type;        /*!< type of the shapes */
    std::vector<int> shapes; // for sprite sheets or animations with shapes
    int currentShape;

    std::shared_ptr<ILibs> graphics;
};

#endif
