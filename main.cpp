#include <QCoreApplication>

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Field.h"

const int width = 50;
const int height = 30;
const int cellSize = 20;

int main()
{
    Field * field = Field::createField(width, height, cellSize);

    sf::RenderWindow window(sf::VideoMode(width * cellSize, height * cellSize), "MistaSnake");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (auto x: field->onDraw())
            window.draw(x);
        window.display();
    }

    delete field;
    return EXIT_SUCCESS;
}
