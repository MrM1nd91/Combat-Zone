#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>

const float Escale = 32.0f;

class Personaje : public sf::Drawable
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;
    

    b2Body* BODY;

public:
    Personaje(b2World& mundo, float x, float y, float width, float height);
   // ~Personaje();
    void render(sf::RenderWindow& window);
    void update(sf::Event tecla);
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

};
