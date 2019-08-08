#ifndef CELL_H
#define CELL_H

#include "objects/CellObject.h"

class Cell
{
    static unsigned int Size;
    unsigned int x, y;

    CellObject * object, * activeObject;

public:
    explicit Cell();
    explicit Cell(unsigned int _x, unsigned int _y, CellObject * _type);
    ~Cell();

    static void setSize(unsigned int _size)
    {
        Size = _size;
    }

    static unsigned int getSize()
    {
        return Size;
    }

    unsigned int getX() const
    {
        return x;
    }

    unsigned int getY() const
    {
        return y;
    }

    CellObject * getActiveObject()
    {
        return activeObject;
    }


    CellObject * getObject() const
    {
        return object;
    }

    void destroyActiveObject()
    {
        activeObject = nullptr;
    }

    template<typename T>
    void setActiveObject(T * obj)
    {
        activeObject = obj;
    }

    template<typename T>
    void setObject(T * obj)
    {
        object = obj;
    }

    bool operator == (Cell * obj)
    {
        return (obj->getX() == this->getX()) && (obj->getY() == this->getY());
    }
};

#endif // CELL_H
