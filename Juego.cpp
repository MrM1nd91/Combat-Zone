#include "Juego.h"


sf::Texture renderText;


void Start(const sf::Window& window)
{
    renderText.loadFromFile("grass_block.png");
    //hay que agregar el if
}

void Update()
{
    //Colisiones, eventos, etc
}

void Render(Renderizador& render)
{

    render.draw(renderText,sf::Vector2f(), sf::Vector2f(2, 2));
    
}
