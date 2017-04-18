#include "contenedorProfesores.h"

Contenedor_Profesores::Contenedor_Profesores()
{
	pinicio = NULL;
	paux = NULL;
}

void Contenedor_Profesores::insertaInicio(Profesor *P){ 
	paux = new Nodo_Profesores(P, NULL);
	if (pinicio == NULL)
		pinicio = paux;
	else {
		paux->setNext(pinicio);
		pinicio = paux;
	}
}

Contenedor_Profesores::~Contenedor_Profesores() {
	cout << "Eliminando Contenedor de Profesores" << endl;

	while (pinicio != NULL) {
		paux = pinicio;
		pinicio = pinicio->getNext();
		delete paux;
	}
}