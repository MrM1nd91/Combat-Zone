#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <box2d/box2d.h>
//#include <iostream>
#include "Personaje.h"
#include "Plataforma.h"

int main()
{
    int32 velIt = 8;
    int32 posIt = 3;

    sf::RenderWindow window(sf::VideoMode(1000, 600), "Combat Zone Ver1");
    window.setFramerateLimit(60);

    b2Vec2 gravedad(0.0f, -5.0f);
    b2World mundo(gravedad);

    Plataforma Suelo(mundo, 10.0f, 2.0f, 2000.0f, 100.0f);
    Personaje character(mundo,13.0f, 15.0f, 50.0f, 100.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        mundo.Step(1 / 60.0f, velIt, posIt);
        //CMD - Joy



        //Update - Actualiza los estados del juego
        character.update();

        window.clear();
        
        Suelo.render(window);
        character.render(window);

        // Draw
        window.draw(character);
        window.draw(Suelo);

        //Display - Flip
        window.display();
    }

    return 0;
}
