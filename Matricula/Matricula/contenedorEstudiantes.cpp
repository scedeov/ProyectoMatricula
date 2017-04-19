#include "contenedorEstudiantes.h"

Contenedor_Estudiantes::Contenedor_Estudiantes()
{
	pinicio = NULL;
	paux = NULL;
}

void Contenedor_Estudiantes::insertaInicio(Estudiante *unEstudiante)
{
	paux = new Nodo_Estudiantes(unEstudiante, NULL);

	if (pinicio == NULL)
	{
		pinicio = paux;
	}
	else
	{
		paux->setNext(pinicio);
		pinicio = paux;
	}
}

string Contenedor_Estudiantes::toString()
{
	paux = pinicio;
	stringstream s;
	while (paux != NULL) {
		s << paux->toStringNodo() << endl;
		paux = paux->getNext();
	}
	return s.str();
}

Contenedor_Estudiantes::~Contenedor_Estudiantes()
{
	cout << "Eliminando Contenedor de Cursos" << endl;

	while (pinicio != NULL)
	{
		paux = pinicio;
		pinicio = pinicio->getNext();
		delete paux;
	}
}

ostream & operator<<(ostream &o, Contenedor_Estudiantes &CEs) {
	return o << CEs.toString();
}
