#ifndef FOOD_H
#define FOOD_H

#include "Cell.h"
#include "objects/CellObject.h"

class Food : public CellObject
{
    Cell * position;
public:
    Food(sf::Sprite _sprite, Cell * _position);
};

#endif // FOOD_H
