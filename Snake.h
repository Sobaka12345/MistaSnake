#ifndef SNAKE_H
#define SNAKE_H


#include "SnakeHead.h"

class Snake
{

    std::vector<SnakePart> snake;
    sf::Sprite body, head;

public:
    explicit Snake(std::vector<Cell *> initialPoints, sf::Sprite _head, sf::Sprite _body);
    ~Snake();

    std::vector<sf::Sprite> getSnakeParts() const
    {
        std::vector<sf::Sprite> out;
        for(auto x : snake)
            out.push_back(x.getSprite());
        return out;
    }
};

#endif // SNAKE_H
