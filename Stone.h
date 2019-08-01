#ifndef STONE_H
#define STONE_H

#include "CellObject.h"

class Stone : public CellObject
{
public:
    explicit Stone(sf::Sprite _sprite);
};

#endif // STONE_H
