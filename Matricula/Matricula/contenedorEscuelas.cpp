#include "contenedorEscuelas.h"

Contenedor_Escuelas::Contenedor_Escuelas()
{
	pinicio = NULL;
	paux = NULL;
}

void Contenedor_Escuelas::insertaralInicio(Escuela* unEscuela)
{
	paux = new Nodo_Escuelas(unEscuela, NULL);

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

string Contenedor_Escuelas::toString()
{
	stringstream s;
	paux = pinicio;
	while (paux != NULL)
	{
		s << paux->toStringNodo();
		paux = paux->getNext();
	}
	return s.str();
}

Contenedor_Escuelas::~Contenedor_Escuelas()
{
	cout << "Eliminando contenedor de escuelas" << endl;

	while (pinicio != NULL)
	{
		paux = pinicio;
		pinicio = pinicio->getNext();
		delete paux;
	}
}
