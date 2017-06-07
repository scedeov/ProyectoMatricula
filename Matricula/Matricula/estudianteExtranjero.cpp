#include "estudianteExtranjero.h"
#include <iostream>
using namespace std;

Estudiante_Extranjero::Estudiante_Extranjero(Estudiante* estudiante = NULL): 
	estudiante(estudiante) {
	estudiante->setPorcentajeBeca(0);
	estudiante->generaCarnet();
}

Estudiante_Extranjero::~Estudiante_Extranjero()
{
	cout << "Eliminando Estudiante Extranjero" << endl;
}
