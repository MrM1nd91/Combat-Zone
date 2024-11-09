#include "Camara.h"

Camara::Camara(float zoom) : zoom(zoom)
{	
}

sf::View Camara::Vista(sf::Vector2u ventanaTam)
{
	float aspect = (float)ventanaTam.x / (float)ventanaTam.y;
	sf::Vector2f Tam{};

	if (aspect < 1.0f)
	{
		Tam = sf::Vector2f(zoom, zoom / aspect);
	}
	else {
		Tam = sf::Vector2f(zoom * aspect, zoom);
	}

	return sf::View(sf::Vector2f(370,450), Tam);
	//return sf::View(sf::Vector2f(0, 0), Tam);
}
