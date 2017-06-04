#ifndef INTERFAZ_MATRICULA
#define INTERFAZ_MATRICULA

#include "universidad.h"
#include "aranceles.h"

class Interfaz_Matricula {
public:
	static char vMenuMatricula();
	static bool vMatriculaEstudianteCurso(Universidad*);
	static void vMatriculaListaCursosEstudiante(Universidad*);
	static void vMatriculaListaEstudiantesCursos(Universidad*);
	static void vCobroMatricula(Universidad*);
};
#endif // !INTERFAZ_MATRICULA

