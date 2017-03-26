#ifndef CONTROL
#define CONTROL


#include <conio.h>
#include <Windows.h>

#include "universidad.h"
#include "contenedorCursos.h"
#include "interfaz.h"
#include "contenedorEscuelas.h"

class Control
{
private:
	Universidad* U;
	Contenedor_Escuelas* CE;
	Contenedor_Cursos* CC;
public:
	void inicializador();
	void principal();
	void ajustes();
};

#endif
