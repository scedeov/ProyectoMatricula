#ifndef INTERFAZ_PROFESORES
#define INTERFAZ_PROFESORES

#include "universidad.h"

class Interfaz_Profesores {
public:
	static char vMenuProfesores();
	static char vAjustesProfesores();
	static void vAgregarProfesor(Universidad*);
	static void vConsultarProfesEscuela(Universidad*);
	static void vConsultarProfeCedula(Universidad*);
	static void vConsultarProfesCurso(Universidad*);
	static void vAsignarProfesorCurso(Universidad*);
	static void vDeasignarProfesorCurso(Universidad*);
	static void vEditarProfesor(Universidad*);
	static void vConsultaCursosAsignadosProfesor(Universidad*);
};
#endif // !INTERFAZ_PROFESORES

