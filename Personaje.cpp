#include "Personaje.h"

Personaje::Personaje(b2World& mundo, float x, float y, float width, float height)
{

    b2BodyDef bodyCorpse;
    bodyCorpse.type = b2_dynamicBody;
    bodyCorpse.position.Set(x, y);
    BODY = mundo.CreateBody(&bodyCorpse);

    b2PolygonShape bodyS;
    bodyS.SetAsBox(width/Escale/2.0f, height/Escale/2.0f);

    b2FixtureDef fixtureBody;
    fixtureBody.shape = &bodyS;
    fixtureBody.density = 1.0f;
    fixtureBody.friction = 0.3f;

    BODY->CreateFixture(&fixtureBody);


    _velocity = { 4,4 };
    _texture.loadFromFile("Character.png");
    _sprite.setTexture(_texture);
    //_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, 0);
    _sprite.setOrigin(_texture.getSize().x / 2.0f, _texture.getSize().y / 2.0f);
    _sprite.setScale(width / _texture.getSize().x, height / _texture.getSize().y);

}

void Personaje::render(sf::RenderWindow& window)
{
    b2Vec2 position = BODY->GetPosition();
    float angle = BODY->GetAngle();


    _sprite.setPosition(position.x * Escale, window.getSize().y - position.y * Escale);
    _sprite.setRotation(angle * 180.0f / b2_pi);
}

void Personaje::update()
{   
    float fuerzaMov = 100.0f;
    //float fuerzaS = 50.0f;
    _velocity = { 0,0 };

    b2Vec2 XLREIGHT(0.0f, 1.0f);

    //LE MODIFIQUE LA VELOCIDAD A 8 para hacer tests
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _velocity.y = -4;
       //BODY->ApplyLinearImpulse(b2Vec2(0.0f, fuerzaS), BODY->GetWorldCenter(), true);
       b2Vec2 Accel = BODY->GetLinearVelocity() + XLREIGHT;

       BODY->SetLinearVelocity(Accel);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _velocity.x = -4;
        BODY->ApplyForceToCenter(b2Vec2(-fuerzaMov, 0.0f), true);
    }
    // Que se detenga al dejar de presionar
   /* if (tecla.type == sf::Event::KeyReleased) {

        if (tecla.key.code == sf::Keyboard::Left)
        {
            BODY->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
        }


    }*/

    //Down - Puede ser necesaria para alguna animacion
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _velocity.y = 4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _velocity.x = 4;
        BODY->ApplyForceToCenter(b2Vec2(fuerzaMov, 0.0f), true);
    }


    _sprite.move(_velocity);

    if (_velocity.x < 0) {
        _sprite.setScale(-1, 1);
    }
    else if (_velocity.x > 0) {
        _sprite.setScale(1, 1);
    }

    //hay que agregar restricciones al cuerpo Box2d
    if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
        
    }

    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
    }

    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 1000) {
        _sprite.setPosition(1000 - (_sprite.getGlobalBounds().width - _sprite.getOrigin().x), _sprite.getPosition().y);
    }

    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height > 600) {
        _sprite.setPosition(_sprite.getPosition().x, 600 - _sprite.getGlobalBounds().height);
    }
    
}

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
