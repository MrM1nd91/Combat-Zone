#include "Item.h"


Item::Item()
{
	_itemTexture.loadFromFile("Moneda.png");
	_item.setTexture(_itemTexture);
	_item.setOrigin(_item.getGlobalBounds().width / 2, _item.getGlobalBounds().height/2);
}

void Item::update()
{
}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_item, states);
}
void Item::respawn()
{

	_item.setPosition(std::rand() % 700 +_item.getGlobalBounds().width, std::rand() % 500 + _item.getGlobalBounds().height);

}

 