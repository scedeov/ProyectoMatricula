#include "contenedorEscuelas.h"

Contenedor_Escuelas::Contenedor_Escuelas()
{
	for (size_t i = 0; i < 30; i++)
	{
		VEC[i] = new Escuela();
	}
}

Contenedor_Escuelas::~Contenedor_Escuelas()
{
}
