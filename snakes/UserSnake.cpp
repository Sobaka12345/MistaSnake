#include "UserSnake.h"

sf::Texture UserSnake::t_head, UserSnake::t_body;

UserSnake::UserSnake(Field * _field, std::vector<Cell *> & initialPoints, sf::Texture & _head,
                     sf::Texture & _body, float head_size, float body_size) :
    Snake(_field, initialPoints, _head, _body, head_size, body_size)
{

}

UserSnake * UserSnake::createUserSnake(std::vector<Cell *> &initialPoints, Field * _field)
{
    t_head.loadFromFile("textures/head.bmp");
    t_body.loadFromFile("textures/body.JPG");

    UserSnake * obj = new UserSnake(_field, initialPoints, t_head, t_body, 128.0f, 128.0f);

    return obj;
}

UserSnake::DIR UserSnake::tick(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        return LEFT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        return UP;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        return RIGHT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        return DOWN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        return REVERSE;
    }
    return NO;
}
