#ifndef WALL_H
#define WALL_H

#include "CellObject.h"

class Wall : public CellObject
{
public:
    Wall(sf::Sprite _sprite);
};

#endif // WALL_H
