/**
 * \file iGames.hpp
 * \brief iGames
 */
#ifndef IGAMES_HPP
#define IGAMES_HPP

#include "../lib/ILibs.hpp"
/*! \class IGames
   * \brief class of IGames
   *
   */
class IGames
{
private:
    /* data */
public:
    virtual ~IGames()=default;
/**
 * \fn virtual void initGameData(std::string &pseudo)
 * \brief Function that init game data
 * 
 * \param pseudo It's the pseudo
 */
    virtual void initGameData(std::string &pseudo)=0;
    /**
 * \fn virtual void initGraphics()
 * \brief Function that init Graphics
 * 
 */
    virtual void initGraphics()=0;
    /**
 * \fn virtual void runGame(int &indexGame, int &indexLib)
 * \brief Function that start game
 * 
 * \param indexGame of vector game
 * \param indexLib of vector lib
 */
    virtual void runGame(int &indexGame, int &indexLib)=0;
    /**
 * \fn virtual void setLib(std::shared_ptr<ILibs> &graphics)
 * \brief Function that set the lib
 * 
 * \param graphics for the graphics
 */
    virtual void setLib(std::shared_ptr<ILibs> &graphics)=0;
};

#endif
