#include "Snake.h"
#include <iostream>

Snake::Snake(Field * _field, std::vector<Cell *>& initialPoints, sf::Texture & _head, sf::Texture & _body, float head_size, float body_size) :
    s_body(_body),
    s_head(_head)
{
    field = _field;
    s_head.setScale(Cell::getSize() / head_size, Cell::getSize() / head_size);
    s_body.setScale(Cell::getSize() / body_size, Cell::getSize() / body_size);


    sf::Sprite temp(s_head);
    temp.setPosition(float(initialPoints.back()->getX() * Cell::getSize()),
                     float(initialPoints.back()->getY() * Cell::getSize()));

    snake.push_back(new SnakeHead(temp, initialPoints.back()));
    headPosition = initialPoints.back();
    initialPoints.pop_back();

    while(!initialPoints.empty())
    {
        temp = sf::Sprite(s_body);
        temp.setPosition(float(initialPoints.back()->getX() * Cell::getSize()),
                         float(initialPoints.back()->getY() * Cell::getSize()));
        snake.push_back(new SnakePart(temp, initialPoints.back()));
        initialPoints.pop_back();
    }

}

Snake::~Snake()
{
    for(auto x : snake)
        delete x;
}

void Snake::update(float dt)
{
    direction  = tick(dt);
    move(float(Cell::getSize()));
}

void Snake::move(float step)
{
    switch(direction)
    {
        case UP :
                moveParts(0, -1, step);
            break;
        case RIGHT :
                moveParts(1, 0, step);
            break;
        case DOWN :
                moveParts(0, 1, step);
            break;
        case LEFT :
                moveParts(-1, 0, step);
            break;
        case REVERSE :
                reverse();
            break;
        default: ;
    }
}

void Snake::moveParts(int _x, int _y, float & step)
{
    Cell * temp = nullptr;
    if(snake.front()->is_head())
    {
        for(auto x = snake.begin(); x != snake.end(); x++)
        {
            if(x == snake.begin()) {
                temp = (*x)->getPosition();
                (*x)->movePart(_x, _y, step, field);
            }
            else {
                int dx = int(temp->getX() - (*x)->getPosition()->getX());
                int dy = int(temp->getY() - (*x)->getPosition()->getY());
                temp = (*x)->getPosition();
                (*x)->movePart(dx, dy, step, field);
            }
        }
    } else {
        for(auto x = snake.rbegin(); x != snake.rend(); x++)
        {
            if(x == snake.rbegin()) {
                temp = (*x)->getPosition();
                (*x)->movePart(_x, _y, step, field);
            }
            else {
                int dx = int(temp->getX() - (*x)->getPosition()->getX());
                int dy = int(temp->getY() - (*x)->getPosition()->getY());
                temp = (*x)->getPosition();
                (*x)->movePart(dx, dy, step, field);
            }
        }
    }
}

void Snake::reverse()
{
    if(snake.front()->is_head())
    {
        Cell * pos = snake.front()->getPosition();
        delete snake.front();
        sf::Sprite temp(s_body);
        temp.setPosition(float(pos->getX() * Cell::getSize()),
                         float(pos->getY() * Cell::getSize()));
        snake.front() = new SnakePart(temp,pos);
        pos = snake.back()->getPosition();
        delete snake.back();
        temp = sf::Sprite(s_head);
        temp.setPosition(float(pos->getX() * Cell::getSize()),
                         float(pos->getY() * Cell::getSize()));
        snake.back() = new SnakeHead(temp, pos);
    } else
    {
        Cell * pos = snake.back()->getPosition();
        delete snake.back();
        sf::Sprite temp(s_body);
        temp.setPosition(float(pos->getX() * Cell::getSize()),
                         float(pos->getY() * Cell::getSize()));
        snake.back() = new SnakePart(temp,pos);
        pos = snake.front()->getPosition();
        delete snake.front();
        temp = sf::Sprite(s_head);
        temp.setPosition(float(pos->getX() * Cell::getSize()),
                         float(pos->getY() * Cell::getSize()));
        snake.front() = new SnakeHead(temp, pos);
    }
}


