#include "estudianteExtranjero.h"
#include <string>
#include <iostream>
using namespace std;

Estudiante_Extranjero::Estudiante_Extranjero(Estudiante* estudiante = NULL): 
	estudiante(estudiante) {
	this->estudiante->setPorcentajeBeca(0);
}

Estudiante_Extranjero::~Estudiante_Extranjero() {
	cout << "Eliminando Estudiante Extranjero" << endl;
}
