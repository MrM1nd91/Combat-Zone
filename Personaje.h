#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

const float Escale = 32.0f;

class Personaje : public sf::Drawable
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;
    sf::Event tecla;

    b2Body* BODY;

public:
    Personaje(b2World& mundo, float x, float y, float width, float height);
    void render(sf::RenderWindow& window);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

};
