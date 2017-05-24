#ifndef INTERFAZ_PRINCIPAL
#define INTERFAZ_PRINCIPAL

#include "universidad.h"

class Interfaz_Principal {
public:
	static void vBienvenida();
	static char vMenuPrincipal();
	static char vMenuUniversidad();
	static char vAjustesUniversidad(Universidad*);
	static char vMenuEstudiantes();
	static char vAjustesEstudiantes();
	static char vDatosPrimeraVez(Universidad*);
	static void vIngresarNumero(Universidad*);
	static void vIngresarDireccion(Universidad*);
	static void vIngresarNombre(Universidad*);
	static char vInfoConfirmacion();
	static bool chequeaNumero(std::string);
	static void msjPerfecto();
	static void msjPausa();
	static void msjIngreseOpcion();
	static std::string convierteMayuscula(std::string);
	static void vInfoUniversidad(Universidad*);
	static char vMenuProfesores();
	static char vAjustesProfesores();
	static void vAgregarProfesor(Universidad*);
	static void vConsultarProfesEscuela(Universidad*);
	static void vConsultarProfeCedula(Universidad*);
	static void vConsultarProfesCurso(Universidad*);
	static void vAsignarProfesorCurso(Universidad*);
	static void vDeasignarProfesorCurso(Universidad*);
	static void vEditarProfesor(Universidad*);
	static void vIngresarEstudiante(Universidad*);
	static void vConsultaEstudiante(Universidad*);
	static void vEditarEstudiante(Universidad*);
	static void vConsultaCursosAsignadosProfesor(Universidad*);
	static char vMenuMatricula();
	static bool vMatriculaEstudianteCurso(Universidad*);
	static void vMatriculaListaCursosEstudiante(Universidad*);
	static void vMatriculaListaEstudiantesCursos(Universidad*);
};
#endif // !INTERFAZ_PRINCIPAL

