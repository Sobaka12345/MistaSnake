#include "Food.h"

Food::Food(sf::Sprite _sprite, Cell * _position)
    : ActiveObject(_sprite, true , _position)
{
    _is_food = true;
}
