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
    fixtureBody.friction = 0.7f;
    

    BODY->CreateFixture(&fixtureBody);

    BODY->SetFixedRotation(true);


    _velocity = { 4,4 };
    _texture.loadFromFile("Wizard.png");
    _sprite.setTexture(_texture);


    sf::Vector2u textureSize = _texture.getSize();
    textureSize.x /= 8;
    textureSize.y /= 6;
   

    _sprite.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));

    //_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, 0);
    //_sprite.setOrigin(_texture.getSize().x / 2.0f, _texture.getSize().y / 2.0f);
    _sprite.setOrigin(textureSize.x/2.0f, textureSize.y/2.0f);

    //_sprite.setScale(width / _texture.getSize().x, height / _texture.getSize().y);

}



void Personaje::render(sf::RenderWindow& window)
{
    b2Vec2 position = BODY->GetPosition();
    float angle = BODY->GetAngle();


    _sprite.setPosition(position.x * Escale, window.getSize().y - position.y * Escale);
    _sprite.setRotation(angle * 180.0f / b2_pi);
}

void Personaje::update(sf::Event tecla)
{   
    float fuerzaMov = 5.0f;
    float fuerzaS = 50.0f;
    _velocity = { 0,0 };
    int xTexture = 0;
    sf::Vector2 textureSize = _texture.getSize();
    textureSize.x /= 8;
    textureSize.y /= 6;
    int caminaFrame = 1;
    int saltoFrame = 2;
    int agacharseFrame = 4;


    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        BODY->ApplyLinearImpulse(b2Vec2(0.0f, fuerzaS), BODY->GetWorldCenter(), true);
        _velocity.y = -4;
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        //BODY->ApplyLinearImpulse(b2Vec2(0.0f, -fuerzaS), BODY->GetWorldCenter(), true);
        _sprite.setTextureRect(sf::IntRect(xTexture, textureSize.y * agacharseFrame, textureSize.x, textureSize.y));
        //_velocity.y = 4;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        BODY->ApplyLinearImpulse(b2Vec2(fuerzaMov,0.0f), BODY->GetWorldCenter(), true);
        
        xTexture = (int)_sprite.getPosition().x / 40 % 7;
        xTexture = xTexture * textureSize.x;
        //std::cout << xTexture << std::endl;

        _sprite.setTextureRect(sf::IntRect(xTexture, textureSize.y * caminaFrame, textureSize.x, textureSize.y));
        _velocity.x = 4;
        

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

        BODY->ApplyLinearImpulse(b2Vec2(-fuerzaMov, 0.0f), BODY->GetWorldCenter(), true);

        int xTexture = 0;
        xTexture = (int)_sprite.getPosition().x / 40 % 7;
        xTexture = xTexture * textureSize.x;

        _sprite.setTextureRect(sf::IntRect(xTexture, textureSize.y * caminaFrame, textureSize.x, textureSize.y));
        //Mago.move(-4, 0);


        _velocity.x = -4;
    }

    if (tecla.type == sf::Event::KeyReleased)
    {
        BODY->ApplyLinearImpulse(b2Vec2(0.0f, -fuerzaS), BODY->GetWorldCenter(), true);
        _sprite.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));
       
    }
    
   


    _sprite.move(_velocity);

    if (_velocity.x < 0) {
        _sprite.setScale(-1, 1);
    }
    else if (_velocity.x > 0) {
        _sprite.setScale(1, 1);
    }

    //hay que agregar restricciones al cuerpo Box2d?
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
