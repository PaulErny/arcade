#ifndef IGAMES_HPP
#define IGAMES_HPP

class IGames
{
private:
    /* data */
public:
    virtual ~IGames()=0;

    virtual void initGameData()=0;
    virtual void initGraphics()=0;
    virtual void runGame()=0;
};

#endif
