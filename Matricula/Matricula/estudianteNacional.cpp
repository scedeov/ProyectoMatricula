#include "estudianteNacional.h"


Estudiante_Nacional::Estudiante_Nacional(Estudiante* estudiante = NULL) :
	estudiante(estudiante) {
}

Estudiante_Nacional::~Estudiante_Nacional() {
	cout << "Eliminando Estudiante Nacional..." << endl;
}
