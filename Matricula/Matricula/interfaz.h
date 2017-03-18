#ifndef INTERFAZ
#define INTERFAZ

#include "universidad.h"
#include "contenedorEscuelas.h"

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
	
	static void vIngresaEscuela(Contenedor_Escuelas*);

	static bool chequeaNumero(string);
	
	static void msjPerfecto();
	static void msjNoDatosIngresadosUni();

	static void vtoString(Universidad*);
	static void vtoStringEscuelas(Universidad*, Contenedor_Escuelas*);
};
#endif // !INTERFAZ

