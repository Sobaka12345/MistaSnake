#ifndef SNAKEPART_H
#define SNAKEPART_H

class Field;
#include "Cell.h"
#include "ActiveObject.h"

class SnakePart : public ActiveObject
{
protected:
    bool _is_head;

public:

    explicit SnakePart(sf::Sprite _sprite, Cell * _position);



    Cell * getPosition()
    {
        return position;
    }

    bool is_head() const
    {
        return _is_head;
    }

    void movePart(int dx, int dy, float step, Field * field);


private:
    void setPosition(Cell * cell)
    {
        position = cell;
    }


};

#endif // SNAKEPART_H
