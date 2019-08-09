#ifndef ACTIVEOBJECT_H
#define ACTIVEOBJECT_H

#include "objects/CellObject.h"

class Cell;

class ActiveObject : public CellObject
{
protected:
    Cell * position;
public:
    ActiveObject(sf::Sprite _sprite, bool _collidable , Cell * _position);
};

#endif // ACTIVEOBJECT_H
