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
	static char vMenuPrincipal();
	static char vMenuAjustes();
	static void vIngresarNumero(Universidad*);
	static void vIngresarDireccion(Universidad*);
	static void vIngresarNombre(Universidad*);
	static char vInfoConfirmacion();
	
	static bool chequeaNumero(string);
	
	static void msjPerfecto();
	static void msjNoDatosIngresadosUni();
	static void vtoString(Universidad*);
};
#endif // !INTERFAZ

