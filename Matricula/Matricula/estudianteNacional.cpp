#include "estudianteNacional.h"
#include <iostream>
using namespace std;

Estudiante_Nacional::Estudiante_Nacional(Estudiante* estudiante = NULL) :
	estudiante(estudiante) {
	estudiante->generaCarnet();
}

Estudiante_Nacional::~Estudiante_Nacional() {
	cout << "Eliminando Estudiante Nacional..." << endl;
}
