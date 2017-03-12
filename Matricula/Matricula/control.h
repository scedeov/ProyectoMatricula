#ifndef CONTROL
#define CONTROL

#include "universidad.h"
#include <conio.h>
#include <Windows.h>


class Control
{
private:
	Universidad U1;
public:
	Control();
	void Inicio();
	bool chequeaNumero(string);
	~Control();
};

#endif
