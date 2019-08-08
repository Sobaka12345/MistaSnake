#include "SnakeHead.h"

SnakeHead::SnakeHead(sf::Sprite _sprite, Cell * _position) :
    SnakePart (_sprite, _position)
{
    _is_head = true;
}
