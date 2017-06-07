#ifndef INTERFAZ_MATRICULA
#define INTERFAZ_MATRICULA

#include "interfazPrincipal.h"
#include "controladorEstudiantes.h"
#include "controladorEscuelas.h"
#include "controladorCursos.h"
#include "grupo.h"
#include "universidad.h"
#include "aranceles.h"
#include <conio.h>
#include <iostream>
using namespace std;

class Interfaz_Matricula {
public:
	static char vMenuMatricula();
	static bool vMatriculaEstudianteCurso(Universidad*);
	static void vMatriculaListaCursosEstudiante(Universidad*);
	static void vMatriculaListaEstudiantesCursos(Universidad*);
	static void vCobroMatricula(Universidad*);
};
#endif // !INTERFAZ_MATRICULA

