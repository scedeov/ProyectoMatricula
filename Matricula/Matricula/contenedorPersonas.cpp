#include "contenedorPersonas.h"
#include "persona.h"
#include <iostream>
#include <sstream>
using namespace std;

ContenedorPersonas::ContenedorPersonas() {
	personas = new Lista<Persona>();
}

int ContenedorPersonas::getCantidad() {
	return personas->getCantidad();
}

void ContenedorPersonas::agregarInicio(Persona *persona) {
	personas->agregarInicio(persona);
}

Persona * ContenedorPersonas::getPersona(int cedula) {
	for (int i = 0; i < personas->getCantidad(); i++)
		if ((personas->at(i)->getNumCedula() == cedula))
			return personas->at(i);
	return nullptr;
}

string ContenedorPersonas::toString() {
	stringstream s;
	for (int i = 0; i < personas->getCantidad(); i++)
		s << personas->at(i)->toString() << endl;
	return s.str();
}

ContenedorPersonas::~ContenedorPersonas()
{
	cout << "Eliminando Contenedor de Cursos" << endl;
	personas->limpiar();
}

ostream & operator<<(ostream &o, ContenedorPersonas &CEs) {
	return o << CEs.toString();
}
