#pragma once
#include <vector>
#include "Renderizador.h"

class Mapa
{
private:
	//por el momento no hay

public:
	//Mapa(float tamanioCeldas= 32.0f);

	void crearTablero(size_t width, size_t height);
	//void crearApdeImg(const sf::Image& imagen);
	//void draw(Renderizador& render);
	std::vector<std::vector<int>> cuadricula;
};

