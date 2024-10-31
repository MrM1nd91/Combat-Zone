#include "Plataforma.h"

Plataforma::Plataforma(b2World& world, float x, float y, float with, float height)
{

	b2BodyDef bodyFloor;
	bodyFloor.type = b2_staticBody;
	bodyFloor.position.Set(x,y);
	FLOOR = world.CreateBody(&bodyFloor);

	b2PolygonShape floorS;
	floorS.SetAsBox(with / Escala / 2.0f, height / Escala / 2.0f);

	b2FixtureDef fixtureFloor;
	fixtureFloor.shape = &floorS;
	fixtureFloor.density = 3.0f;
	fixtureFloor.friction = 0.03f;

	FLOOR->CreateFixture(&floorS, 0.0f);

	shapeFloor.setSize(sf::Vector2f(with, height));//Se puede probar la escala
	shapeFloor.setOrigin(with / 2.0, height / 2.0);
	shapeFloor.setFillColor(sf::Color::Green);

}

void Plataforma::render(sf::RenderWindow& window)
{
	b2Vec2 posicion = FLOOR->GetPosition();
	float angu = FLOOR->GetAngle();

	shapeFloor.setPosition(posicion.x * Escala,window.getSize().y - posicion.y * Escala);
	shapeFloor.setRotation(angu * 180 / b2_pi);

}

void Plataforma::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(shapeFloor, states);

}