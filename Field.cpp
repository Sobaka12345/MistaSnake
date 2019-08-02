#include "Field.h"

Field * Field::p_instance = nullptr;


Field * Field::createField(unsigned int _width, unsigned int _height, unsigned int _size)
{
    if(p_instance != nullptr)
        return nullptr;

    p_instance = new Field(_width, _height, _size);

    p_instance->setGroundSprite("textures/wood.jpg", 50.0f);
    p_instance->setWallSprite("textures/wall.png", 360.0f);
    p_instance->setStoneSprite("textures/stone.bmp", 128.0f);
    p_instance->generateBorders();
    p_instance->generateWorld();

    p_instance->generateSnakes();
    return p_instance;
}

Field::Field(unsigned int _width, unsigned int _height, unsigned int _size)
{
    width = _width;
    height = _height;
    cellSize = _size;
    field = fieldAllocator.allocate(width * height);
}

Field::~Field()
{
    fieldAllocator.deallocate(field, width * height);
    for(auto x : snakes)
        delete x;
    p_instance = nullptr;
}

void Field::generateBorders()
{
    for(unsigned int i = 0; i < height; i++)
        for(unsigned int j = 0; j < width; j++)
        {
            if(i == (height - 1) || j == (width - 1) || i == 0 || j == 0)
            {
                sf::Sprite temp(s_wall);
                temp.setPosition(static_cast<float>(j * cellSize), static_cast<float>(i * cellSize));
                fieldAllocator.construct(field + width * i + j, j, i, new Wall(temp));
                blocked.push_back(field + width * i + j);
            }
        }
}

void Field::generateWorld()///testo
{
    for(unsigned int i = 1; i < height - 1; i++)
        for(unsigned int j = 1; j < width - 1; j++)
        {
            if(rand() % 10 > 1)
            {
                sf::Sprite temp(s_ground);
                temp.setPosition(static_cast<float>(j * cellSize), static_cast<float>(i * cellSize));
                fieldAllocator.construct(field + width * i + j, j, i, new Ground(temp));
                free.push_back(field + width * i + j);
            } else
            {
                sf::Sprite temp(s_stone);
                temp.setPosition(static_cast<float>(j * cellSize), static_cast<float>(i * cellSize));
                fieldAllocator.construct(field + width * i + j, j, i, new Stone(temp));
                blocked.push_back(field + width * i + j);
            }
        }
}

void Field::generateSnakes()
{
    std::vector<Cell*> in;
    sf::Sprite body(s_wall);
    sf::Sprite head(s_stone);
    in.push_back(getCell(2,2));
    in.push_back(getCell(2,3));
    body.setPosition(getCell(2, 2)->getX() * cellSize, getCell(2, 2)->getY() * cellSize);
    head.setPosition(getCell(2, 3)->getX() * cellSize, getCell(2, 3)->getY() * cellSize);
    snakes.push_back(new Snake(in, head, body));
}
