#ifndef INTERFAZ_MATRICULA
#define INTERFAZ_MATRICULA

#include "universidad.h"

class Interfaz_Matricula {
public:
	static char vMenuMatricula();
	static bool vMatriculaEstudianteCurso(Universidad*);
	static void vMatriculaListaCursosEstudiante(Universidad*);
	static void vMatriculaListaEstudiantesCursos(Universidad*);
};
#endif // !INTERFAZ_MATRICULA

