#ifndef CONTROL
#define CONTROL


#include <conio.h>
#include <Windows.h>

#include "universidad.h"
#include "interfaz.h"
#include "contenedorEscuelas.h"

class Control
{
private:
	Universidad* U;
	Contenedor_Escuelas* CE;
public:
	void principal();
	void ajustes();
};

#endif
