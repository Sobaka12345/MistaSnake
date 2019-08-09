#ifndef FOOD_H
#define FOOD_H

#include "Cell.h"
#include "ActiveObject.h"

class Food : public ActiveObject
{

public:
    Food(sf::Sprite _sprite, Cell * _position);
};

#endif // FOOD_H
