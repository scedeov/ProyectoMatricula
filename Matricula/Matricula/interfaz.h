#ifndef INTERFAZ
#define INTERFAZ

#include "universidad.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <sstream>

using namespace std;

class Interfaz
{
public:
	static void vBienvenida();
	static char vMenu();
	static void vIngresarNumero(Universidad*);
	static void vIngresarDireccion(Universidad*);
	static void vIngresarNombre(Universidad*);
	static bool chequeaNumero(string);
};
#endif // !INTERFAZ

