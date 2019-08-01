#include "CellObject.h"

CellObject::CellObject(sf::Sprite _sprite, bool _collidable) :
    sprite(_sprite),
    collidable(_collidable)
{}

CellObject::~CellObject()
{

}
