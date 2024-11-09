#pragma once
#include <SFML/Graphics.hpp>

class Camara
{
private:


public:
	Camara(float zoom = 100.0f); 
	sf::View Vista(sf::Vector2u ventanaTam);

	float zoom;

};

