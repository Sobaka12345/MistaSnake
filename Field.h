#ifndef FIELD_H
#define FIELD_H

#include <memory>

#include <SFML/Graphics/Texture.hpp>

#include "Stone.h"
#include "Wall.h"
#include "Ground.h"
#include "Cell.h"

class Field
{
    static Field * p_instance;
    unsigned int width, height, cellSize;
    Cell * field;
    std::allocator<Cell> fieldAllocator;

    sf::Texture t_ground, t_wall, t_stone;
    sf::Sprite s_ground, s_wall, s_stone;

    std::vector<Cell *> blocked, free, food;

    Field(unsigned int _width, unsigned int _height, unsigned int _size);
public:
    static Field * createField(unsigned int _width, unsigned int _height, unsigned int _size);

    ~Field();

    void generateBorders();
    void generateWorld();

    std::vector<sf::Sprite> onDraw() const
    {
        std::vector<sf::Sprite> out;
        for(auto x : blocked)
            out.push_back(x->getObject()->getSprite());
        for(auto x : free)
            out.push_back(x->getObject()->getSprite());

        return out;
    }


    void setGroundSprite(const char * filename, float picSize)
    {
        t_ground.loadFromFile(filename);
        s_ground.setTexture(t_ground);
        s_ground.setScale(cellSize / picSize, cellSize / picSize);
    }

    void setWallSprite(const char * filename, float picSize)
    {
        t_wall.loadFromFile(filename);
        s_wall.setTexture(t_wall);
        s_wall.setScale(cellSize / picSize, cellSize / picSize);
    }

    void setStoneSprite(const char * filename, float picSize)
    {
        t_stone.loadFromFile(filename);
        s_stone.setTexture(t_stone);
        s_stone.setScale(cellSize / picSize, cellSize / picSize);
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
