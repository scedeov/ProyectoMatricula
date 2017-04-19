#include "nodoProfesores.h"

Nodo_Profesores::Nodo_Profesores(Profesor *unP, Nodo_Profesores *unNext)
{
	P = unP;
	Next = unNext;
}

void Nodo_Profesores::setNext(Nodo_Profesores *unNext)
{
	Next = unNext;
}

Nodo_Profesores * Nodo_Profesores::getNext()
{
	return Next;
}

void Nodo_Profesores::setProfesor(Profesor *unP)
{
	P = unP;
}

Profesor * Nodo_Profesores::getProfesor()
{
	return P;
}

Nodo_Profesores::~Nodo_Profesores()
{
	cout << "Eliminando Nodo Profesores..." << endl;
	delete P;
}
