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

Escuela * Contenedor_Escuelas::retornaEscuelaEspecifica(string sigla)
{
	paux = pinicio;
	while (paux != NULL)
	{
		if (encuentraEscuela(paux->getEscuela(), sigla) == true)
			return paux->getEscuela();
		else
			paux = paux->getNext();
	}
	return nullptr;
}

bool Contenedor_Escuelas::encuentraEscuela(Escuela* e, string sigla)
{
	if (e->getSiglaEscuela() == sigla)
		return true;
	else
		return false;
}

//ostream& operator << (ostream& o, const Contenedor_Escuelas& CE)
//{
//	paux = pinicio;
//	while (paux != NULL)
//	{
//		o << paux->toStringNodo(op);
//		paux = paux->getNext();
//	}
//	return o;
//}

string Contenedor_Escuelas::toString(char op) // debido a este char no puedo hacer sobrecarga
{
	stringstream s;
	paux = pinicio;
	while (paux != NULL)
	{
		s << paux->toStringNodo(op);
		paux = paux->getNext();
	}
	return s.str();
}

Contenedor_Escuelas::~Contenedor_Escuelas()
{
	cout << "Eliminando Contenedor de Escuelas" << endl;

	while (pinicio != NULL)
	{
		paux = pinicio;
		pinicio = pinicio->getNext();
		delete paux;
	}
}
