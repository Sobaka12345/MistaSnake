#ifndef ACTIVEOBJECT_H
#define ACTIVEOBJECT_H

#include "objects/CellObject.h"

class Cell;

class ActiveObject : public CellObject
{
protected:
    Cell * position;
    bool _is_food;
public:
    ActiveObject(sf::Sprite _sprite, bool _collidable , Cell * _position);

    bool is_food() const
    {
        return _is_food;
    }
};

#endif // ACTIVEOBJECT_H
