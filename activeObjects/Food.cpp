#include "Food.h"

Food::Food(sf::Sprite _sprite, Cell * _position)
    : CellObject(_sprite, true),
      position(_position)
{

}
