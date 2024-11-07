#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>


class Item: public sf::Drawable
{private:
	sf::Sprite _item;
	sf::Texture _itemTexture;
public:
	Item();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void respawn();
};

