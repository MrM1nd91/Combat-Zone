#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <box2d/box2d.h>
//#include <iostream>
#include "Personaje.h"

int main()
{


    sf::RenderWindow window(sf::VideoMode(1000, 600), "Combat Zone Ver1");
    window.setFramerateLimit(60);

    Personaje character;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //CMD - Joy



        //Update - Actualiza los estados del juego
        character.update();

        window.clear();

        // Draw
        window.draw(character);

        //Display - Flip
        window.display();
    }

    return 0;
}
