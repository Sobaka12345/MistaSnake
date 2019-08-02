#ifndef SNAKEPART_H
#define SNAKEPART_H

#include "Cell.h"


class SnakePart
{
    Cell * position;
    sf::Sprite sprite;

public:
    explicit SnakePart(sf::Sprite _sprite, Cell * _position);

    sf::Sprite getSprite() const
    {
        return sprite;
    }
private:
    void setPosition(Cell * cell)
    {
        position = cell;
    }

};

#endif // SNAKEPART_H
