#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <vector>
#include "Global.h"

class Renderizador 
{
private:
	
	sf::Sprite renderSprite;
	sf::RenderTarget& target;
	
 	
public:
	Renderizador(sf::RenderTarget& target);
	void draw(const sf::Texture& textura, const sf::Vector2f& posicion, const sf::Vector2f& Tam);


};

