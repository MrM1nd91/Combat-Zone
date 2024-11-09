#include "Mapa.h"

void Mapa::crearTablero(size_t width, size_t height)
{
	cuadricula = std::vector(width, std::vector(height, 0));

	int final = 0;

	//columnas
	for (auto& columnas : cuadricula)
	{
		//celdas
		for (auto& celda : columnas)
		{
			//alternar
			celda = !final;
			final = celda;
		}
	}
}
