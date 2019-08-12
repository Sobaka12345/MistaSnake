#ifndef SNAKE_H
#define SNAKE_H

#include "activeObjects/SnakeHead.h"


class Snake
{
protected:
    typedef enum Direction
    {
        UP = 0,
        RIGHT,
        DOWN,
        LEFT,
        REVERSE = 360,
        NO = -1
    } DIR;

    float time;
    Field * field;
    std::vector<SnakePart *> snake;
    ActiveObject * head;
    sf::Sprite s_body, s_head;
    unsigned int food, foodCounter;

    explicit Snake(Field * _field, std::vector<Cell *> & initialPoints, sf::Texture & _body, sf::Texture & _head, float head_size, float body_size);
    void move(float step);
    void moveParts(int _x, int _y, float & step);
    void reverse();
    bool addPart();

    virtual DIR tick(float dt)
    {
        (void)(dt);
        return static_cast<DIR>(rand() % 5 - 1);
    }
public:
    virtual ~Snake();
    void update(float dt);


    std::vector<sf::Sprite> getSnakeParts() const
    {
        std::vector<sf::Sprite> out;
        for(auto x : snake)
            out.push_back(x->getSprite());
        return out;
    }
private:
    std::vector<DIR> direction;
};

#endif // SNAKE_H
