#include "Cell.h"


Cell::Cell() : x(0), y(0)
{}

Cell::Cell(unsigned int _x, unsigned int _y, CellObject * _type)
{
    x = _x;
    y = _y;
    object = _type;
    activeObject = nullptr;
}

Cell::~Cell()
{
    delete object;
    delete activeObject;
}
