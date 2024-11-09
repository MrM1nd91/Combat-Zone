#include "Renderizador.h"

Renderizador::Renderizador(sf::RenderTarget& target) : target(target)
{
}

void Renderizador::draw(const sf::Texture& textura, const sf::Vector2f& posicion, const sf::Vector2f& Tam)
{
	renderSprite.setTexture(textura);
	renderSprite.setOrigin((sf::Vector2f)textura.getSize()/ 2.0f);
	renderSprite.setPosition(posicion);
	renderSprite.setScale(sf::Vector2f(Tam.x / textura.getSize().x, Tam.y / textura.getSize().y));

	target.draw(renderSprite);
}
