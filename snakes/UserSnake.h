#ifndef USERSNAKE_H
#define USERSNAKE_H

#include "Snake.h"
#include <SFML/Window/Keyboard.hpp>

class UserSnake : public Snake
{
    static sf::Texture t_head, t_body;
protected:
    virtual DIR tick(float dt) override;
public:
    UserSnake(Field * _field, std::vector<Cell *> & initialPoints, sf::Texture & _head,
              sf::Texture & _body, float head_size, float body_size);

    static UserSnake * createUserSnake(std::vector<Cell *> &initialPoints, Field * _field);

};

#endif // USERSNAKE_H
