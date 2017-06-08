#include "controladorEscuelas.h"
//#include "contenedorProfesores.h"



ControladorEscuelas::ControladorEscuelas()
{
	listaEscuelas = new Lista<Escuela>();
}

void ControladorEscuelas::insertarInicio(Escuela* unEscuela)
{
	listaEscuelas->push_front(unEscuela);
	/*paux = new Nodo_Escuelas(unEscuela, NULL);

	if (pinicio == NULL)
	{
		pinicio = paux;
	}
	else
	{
		paux->setNext(pinicio);
		pinicio = paux;
	}*/
}

Escuela * ControladorEscuelas::retornaEscuela(string sigla)
{
	Nodo<Escuela> *paux = listaEscuelas->begin();

	while (paux != NULL)
	{
		if (encuentraEscuela(paux->getDato(), sigla) == true)
			return paux->getDato();
		else
			paux = paux->getNext();
	}
	return nullptr;
}

Profesor * ControladorEscuelas::retornaProfesor(string cedula)
{
	Nodo<Escuela> *paux = listaEscuelas->begin();
	while (paux != NULL) {
		if (paux->getDato()->getContenedorProfesores()->retornaProfesor(cedula) != NULL)
			return paux->getDato()->getContenedorProfesores()->retornaProfesor(cedula);
		else
			paux = paux->getNext();
	}
	return nullptr;
}

bool ControladorEscuelas::encuentraEscuela(Escuela* e, string sigla)
{
	if (e->getSiglaEscuela() == sigla)
		return true;
	else
		return false;
}

string ControladorEscuelas::toStringEscuelas() 
{
	stringstream s;
	Nodo<Escuela> *paux = listaEscuelas->begin();
	while (paux != NULL) {
		s << paux->getDato()->toStringEscuela();
		paux = paux->getNext();
	}
	return s.str();
}

string ControladorEscuelas::toStringConCursos() // debido a este char no puedo hacer sobrecarga
{
	stringstream s;
	Nodo<Escuela> *paux = listaEscuelas->begin();
	while (paux != NULL) {
		s << paux->getDato()->toStringConCursos();
		paux = paux->getNext();
	}
	return s.str();
}

ControladorEscuelas::~ControladorEscuelas()
{
	cout << "Eliminando Controlador de Escuelas" << endl;
	listaEscuelas->wipe();
}
