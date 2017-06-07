#include "estudianteNacional.h"
#include <string>
#include <iostream>
using namespace std;

Estudiante_Nacional::Estudiante_Nacional(Estudiante* estudiante = NULL) :
	estudiante(estudiante) {
}

Estudiante_Nacional::~Estudiante_Nacional() {
	cout << "Eliminando Estudiante Nacional..." << endl;
}
