#include "LavaSnake.h"

sf::Texture LavaSnake::t_head, LavaSnake::t_body;

LavaSnake::LavaSnake(Field * _field, std::vector<Cell *> & initialPoints, sf::Texture & _head,
                     sf::Texture & _body, float head_size, float body_size) :
    Snake(_field, initialPoints, _head, _body, head_size, body_size)
{

}

LavaSnake * LavaSnake::createLavaSnake(std::vector<Cell *> &initialPoints, Field * _field)
{

    t_head.loadFromFile("textures/head.bmp");
    t_body.loadFromFile("textures/body.JPG");

    LavaSnake * obj = new LavaSnake(_field, initialPoints, t_head, t_body, 128.0f, 128.0f);

    return obj;
}

LavaSnake::DIR LavaSnake::tick(float dt)
{
    (void)dt;
    int kek = rand()%5;
    return kek > 3 ? REVERSE : DIR(kek);
}
