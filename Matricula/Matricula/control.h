#ifndef CONTROL
#define CONTROL

#include "universidad.h"
#include <conio.h>
#include <Windows.h>

#include "interfaz.h"

class Control
{
private:
	Universidad U1;
public:
	void Inicio();
	bool chequeaNumero(string);
	void ingresarNumero();
	void ingresarDireccion();
	void ingresarNombre();
};

#endif
