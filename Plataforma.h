#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include "Global.h"


class Plataforma : public sf::Drawable
{	private:
		b2Body* FLOOR;
		sf::RectangleShape shapeFloor;

	public:
		Plataforma(b2World& world, float x, float y, float with, float height);
		//~Plataforma();
		void render(sf::RenderWindow& window);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		

	
};

