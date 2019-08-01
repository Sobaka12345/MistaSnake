#ifndef CELL_H
#define CELL_H

#include "CellObject.h"

class Cell
{
    ///cell coordinates
    unsigned int x, y;
    CellObject * object;

public:
    explicit Cell();
    explicit Cell(unsigned int _x, unsigned int _y, CellObject * _type);
    ~Cell();



    unsigned int getX() const
    {
        return x;
    }

    unsigned int getY() const
    {
        return y;
    }

    CellObject * getObject() const
    {
        return object;
    }
};

#endif // CELL_H
