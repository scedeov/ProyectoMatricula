#include "contenedorProfesores.h"

Contenedor_Profesores::Contenedor_Profesores()
{
	pinicio = NULL;
	paux = NULL;
}

void Contenedor_Profesores::insertaInicio(Profesor *P) {
	paux = new Nodo_Profesores(P, NULL);
	if (pinicio == NULL)
		pinicio = paux;
	else {
		paux->setNext(pinicio);
		pinicio = paux;
	}
}

Profesor * Contenedor_Profesores::retornaProfesor(int cedula) {
	paux = pinicio;
	while (paux != NULL)
	{
		if (encuentraProfesor(paux->getProfesor(), cedula) == true)
			return paux->getProfesor();
		else
			paux = paux->getNext();
	}
	return nullptr;
}

bool Contenedor_Profesores::encuentraProfesor(Profesor *P, int cedula) {
	if (P->getNumCedulaProfe() == cedula)
		return true;
	else
		return false;
}


string Contenedor_Profesores::toString()
{
	stringstream s;
	paux = pinicio;
	while (paux != NULL) {
		s << *paux;
		paux = paux->getNext();
	}
	return s.str();
}

Contenedor_Profesores::~Contenedor_Profesores() {
	cout << "Eliminando Contenedor de Profesores" << endl;

	while (pinicio != NULL) {
		paux = pinicio;
		pinicio = pinicio->getNext();
		delete paux;
	}
}

ostream & operator<<(ostream &o, Contenedor_Profesores &ContP) {
	return o << ContP.toString();
}
