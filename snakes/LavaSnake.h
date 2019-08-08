#ifndef LAVASNAKE_H
#define LAVASNAKE_H

#include "Snake.h"

class LavaSnake : public Snake
{
    static sf::Texture t_head, t_body;
protected:
    LavaSnake(Field * _field, std::vector<Cell *> & initialPoints, sf::Texture & _head,
              sf::Texture & _body, float head_size, float body_size);
public:
    static LavaSnake * createLavaSnake(std::vector<Cell *> & initialPoints, Field * _field);
    virtual DIR tick(float dt) override;

};

#endif // LAVASNAKE_H
