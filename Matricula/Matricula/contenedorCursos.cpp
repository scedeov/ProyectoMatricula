#include "contenedorCursos.h"

Contenedor_Cursos::Contenedor_Cursos()
{
	pinicio = NULL;
	paux = NULL;
}

void Contenedor_Cursos::insertaInicio(Curso *unCurso)
{
	paux = new Nodo_Cursos(unCurso, NULL);

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

string Contenedor_Cursos::toString()
{
	stringstream s;
	paux = pinicio;
	while (paux != NULL)
	{
		s << paux->toStringNodo() << endl;
		paux = paux->getNext();
	}
	return s.str();
}

Contenedor_Cursos::~Contenedor_Cursos()
{
	cout << "Eliminando Contenedor de Cursos" << endl;

	while (pinicio != NULL)
	{
		paux = pinicio;
		pinicio = pinicio->getNext();
		delete paux;
	}
}
