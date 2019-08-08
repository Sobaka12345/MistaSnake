#ifndef FIELD_H
#define FIELD_H

#include <memory>

#include <SFML/Graphics/Texture.hpp>

#include "objects/Stone.h"
#include "objects/Wall.h"
#include "objects/Ground.h"
#include "snakes/LavaSnake.h"



class Field
{
    static Field * p_instance;
    unsigned int width, height, cellSize;
    Cell * field;
    std::allocator<Cell> fieldAllocator;

    sf::Texture t_ground, t_wall, t_stone;
    sf::Sprite s_ground, s_wall, s_stone;
    std::vector <Snake *> snakes;

    std::vector<Cell *> blocked, free, food;

    Field(unsigned int _width, unsigned int _height, unsigned int _size);
public:
    static Field * createField(unsigned int _width, unsigned int _height, unsigned int _size);
    void update(float dt);

    ~Field();

    void generateBorders();
    void generateWorld();
    void generateSnakes();
    void generateFood(unsigned int max);

    std::vector<sf::Sprite> onDraw() const
    {
        std::vector<sf::Sprite> out;
        for(auto x : blocked)
            out.push_back(x->getObject()->getSprite());
        for(auto x : free)
            out.push_back(x->getObject()->getSprite());
        for(auto x : snakes)
            for(auto y : x->getSnakeParts())
                out.push_back(y);

        return out;
    }


    void setSprite(const char * filename, float picSize, sf::Texture & _texture, sf::Sprite & _sprite)
    {
        _texture.loadFromFile(filename);
        _sprite.setTexture(_texture);
        _sprite.setScale(cellSize / picSize, cellSize / picSize);
    }

    Cell * getCell(unsigned int x, unsigned int y)
    {
        if(x >= width || y >= height)
            return nullptr;
        return &field[width * y + x];
    }

    unsigned int getWidth() const
    {
        return width;
    }

    unsigned int getHeight() const
    {
        return height;
    }
};

#endif // FIELD_H
