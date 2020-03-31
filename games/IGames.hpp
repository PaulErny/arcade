#ifndef IGAMES_HPP
#define IGAMES_HPP

class Igames
{
private:
    /* data */
public:
    virtual ~Igames()=0;

    virtual void initGameData()=0;
    virtual void initGraphics()=0;
    virtual void runGame()=0;
};

#endif
