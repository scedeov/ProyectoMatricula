#ifndef INTERFAZ_PRINCIPAL
#define INTERFAZ_PRINCIPAL

#include "universidad.h"

class Interfaz_Principal {
public:
	static void vBienvenida();
	static char vMenuPrincipal();
	static char vDatosPrimeraVez(Universidad*);
	static char vInfoConfirmacion();
	static bool chequeaNumero(std::string);
	static void msjPerfecto();
	static void msjPausa();
	static void msjIngreseOpcion();
	static std::string convierteMayuscula(std::string);
	static char vMenuMatricula();
	static bool vMatriculaEstudianteCurso(Universidad*);
	static void vMatriculaListaCursosEstudiante(Universidad*);
	static void vMatriculaListaEstudiantesCursos(Universidad*);
};
#endif // !INTERFAZ_PRINCIPAL

