#include "nodoProfesores.h"

Nodo_Profesores::Nodo_Profesores(Profesor *P, Nodo_Profesores *Next)
{
	this->P = P;
	this->Next = Next;
}

void Nodo_Profesores::setNext(Nodo_Profesores *Next)
{
	this->Next = Next;
}

Nodo_Profesores * Nodo_Profesores::getNext()
{
	return Next;
}

void Nodo_Profesores::setProfesor(Profesor *P)
{
	this->P = P;
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
