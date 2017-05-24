#ifndef INTERFAZ_ESTUDIANTES
#define INTERFAZ_ESTUDIANTES

#include "universidad.h"

class Interfaz_Estudiantes {
public:
	static char vMenuEstudiantes();
	static char vAjustesEstudiantes();
	static void vIngresarEstudiante(Universidad*);
	static void vConsultaEstudiante(Universidad*);
	static void vEditarEstudiante(Universidad*);
};
#endif // !INTERFAZ_ESTUDIANTES

