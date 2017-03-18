#ifndef INTERFAZ
#define INTERFAZ

#include "universidad.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <sstream>
#include <string>

using namespace std;

class Interfaz
{
public:
	static void vBienvenida();
	static char vMenuPrincipal();
	static char vDatosPrimeraVez(Universidad*);
	static char vMenuAjustes(Universidad*);
	static void vIngresarNumero(Universidad*);
	static void vIngresarDireccion(Universidad*);
	static void vIngresarNombre(Universidad*);
	static char vInfoConfirmacion();
	
	static bool chequeaNumero(string);
	static string convierteaMayusculas(string);
	
	static void msjPerfecto();
	static void msjNoDatosIngresadosUni();
	static void vtoString(Universidad*);
};
#endif // !INTERFAZ

