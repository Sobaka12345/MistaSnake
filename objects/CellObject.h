#ifndef CELLOBJECT_H
#define CELLOBJECT_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>


class CellObject
{
protected:
    sf::Sprite sprite;
    bool collidable;

public:
    explicit CellObject(sf::Sprite _sprite, bool _collidable);
    ~CellObject();

    sf::Sprite & getSprite()
    {
        return sprite;
    }

    bool isCollidable() const
    {
        return collidable;
    }
};

#endif // CELLOBJECT_H
