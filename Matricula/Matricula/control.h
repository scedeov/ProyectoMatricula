#ifndef CONTROL
#define CONTROL


#include <conio.h>
#include <Windows.h>

#include "universidad.h"
#include "interfaz.h"

class Control
{
private:
	Universidad* U;
public:
	void inicializador();
	void principal();
	void ajustes();
};

#endif
