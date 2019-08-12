#include "SnakePart.h"
#include "Field.h"

SnakePart::SnakePart(sf::Sprite _sprite, Cell * _position) :
    ActiveObject(_sprite, true, _position),
    _is_head(false)
{
    position->setActiveObject(this);
}

void SnakePart::movePart(int dx, int dy, float step, Field * field)
{
    unsigned int x = position->getX();
    unsigned int y = position->getY();

    Cell * temp = field->getCell(x + dx, y + dy);

    if((temp->getActiveObject() != nullptr && (temp->getActiveObject()->isCollidable() || temp->getActiveObject()->is_food()))
            || temp->getObject()->isCollidable())
            return;

    position->destroyActiveObject();
    position = temp;
    temp->setActiveObject(this);
    sprite.move(dx*step, dy*step);
}
