#include "Snake.h"


Snake::Snake(std::vector<Cell *> initialPoints, sf::Sprite _head, sf::Sprite _body) :
    body(_body),
    head(_head)
{
    snake.push_back(SnakePart(head, initialPoints.back()));
    initialPoints.pop_back();

    while(!initialPoints.empty())
    {
        snake.push_back(SnakePart(body, initialPoints.back()));
        initialPoints.pop_back();
    }

}

Snake::~Snake()
{

}
