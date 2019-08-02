#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include "SnakePart.h"

class SnakeHead : public SnakePart
{

public:
    explicit SnakeHead(sf::Sprite _sprite, Cell * _position);
};

#endif // SNAKEHEAD_H
