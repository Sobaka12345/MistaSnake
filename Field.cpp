#include "Field.h"

unsigned int Cell::Size;
Field * Field::p_instance = nullptr;


Field * Field::createField(unsigned int _width, unsigned int _height, unsigned int _size)
{
    if(p_instance != nullptr)
        return nullptr;

    Cell::setSize(_size);
    p_instance = new Field(_width, _height, _size);

    p_instance->setSprite("textures/wood_13.jpg", 100.0f, p_instance->t_ground, p_instance->s_ground);
    p_instance->setSprite("textures/wall.png", 360.0f,  p_instance->t_wall, p_instance->s_wall);
    p_instance->setSprite("textures/stone.bmp", 128.0f,  p_instance->t_stone, p_instance->s_stone);
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

void Field::generateWorld()///for KISA
{
    for(unsigned int i = 1; i < height - 1; i++)
        for(unsigned int j = 1; j < width - 1; j++)
        {
            if(rand() % 10 >= 2)
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



void Field::generateSnakes()///for KISA
{
    std::vector<Cell*> in;

    in.push_back(getCell(2,2));
    in.push_back(getCell(2,3));
    in.push_back(getCell(2,4));

    snakes.push_back(LavaSnake::createLavaSnake(in, this));

    in.push_back(getCell(5,2));
    in.push_back(getCell(5,3));
    in.push_back(getCell(5,4));

    snakes.push_back(LavaSnake::createLavaSnake(in, this));
}

void Field::update(float dt)
{
    for(auto x: snakes)
        x->update(dt);
}
