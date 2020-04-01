#ifndef IGAMES_HPP
#define IGAMES_HPP

#include "../lib/ILibs.hpp"

class IGames
{
private:
    /* data */
public:
    virtual ~IGames()=default;

    virtual void initGameData()=0;
    virtual void initGraphics()=0;
    virtual void runGame()=0;

    virtual void setLib(std::shared_ptr<ILibs> &graphics)=0;
};

#endif
