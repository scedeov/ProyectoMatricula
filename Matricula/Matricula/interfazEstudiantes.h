#ifndef INTERFAZ_ESTUDIANTES
#define INTERFAZ_ESTUDIANTES

#include "interfazPrincipal.h"
#include "controladorEstudiantes.h"
#include "estudianteExtranjero.h"
#include "estudianteNacional.h"
#include "universidad.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Interfaz_Estudiantes {
public:
	static char vMenuEstudiantes();
	static char vAjustesEstudiantes();
	static void vIngresarEstudiante(Universidad*);
	static void vConsultaEstudiante(Universidad*);
	static void vEditarEstudiante(Universidad*);
};
#endif // !INTERFAZ_ESTUDIANTES

