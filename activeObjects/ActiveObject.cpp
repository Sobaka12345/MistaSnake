#include "ActiveObject.h"
#include "Cell.h"

ActiveObject::ActiveObject(sf::Sprite _sprite, bool _collidable , Cell * _position)
    : CellObject (_sprite, _collidable)
{
    position = _position;
}
