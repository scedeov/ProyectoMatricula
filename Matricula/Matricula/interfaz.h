#ifndef INTERFAZ
#define INTERFAZ

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <sstream>
#include <string>

using namespace std;

#include "universidad.h"

class Interfaz
{
public:
	static void vBienvenida();
	static char vMenuPrincipal();
	static char vMenuUniversidad();
	static char vAjustesUniversidad(Universidad*);
	static char vMenuEscuelas();
	static char vAjustesEscuelas();
	static char vMenuCursos();
	static char vAjustesCursos();
	static char vDatosPrimeraVez(Universidad*);
	static void vIngresarNumero(Universidad*);
	static void vIngresarDireccion(Universidad*);
	static void vIngresarNombre(Universidad*);
	static char vInfoConfirmacion();
	static void vIngresaEscuela(Universidad*);
	static void vIngresaCurso(Universidad*);
	static void vEditarCurso(Universidad*);
	static void vEliminaCurso(Universidad*);
	static void vInfoCurso(Universidad*);
	static void vListaCursosEscuelaParticular(Universidad*);
	static bool chequeaNumero(string);
	static void msjPerfecto();
	static void msjPausa();
	static void msjIngreseOpcion();
	static string convierteMayuscula(string);
	static void vInfoUniversidad(Universidad*);
	static void vInfoEscuelas(Universidad*, char); // el char es para ver si imprime cursos o no
	static char vMenuProfesores();
	static char vAjustesProfesores();
	static void vAgregarProfesor(Universidad*);
	static void vConsultarProfesEscuela(Universidad*);
	static void vConsultarProfeCedula(Universidad*);
	static void vConsultarProfesCurso(Universidad*);
};
#endif // !INTERFAZ

