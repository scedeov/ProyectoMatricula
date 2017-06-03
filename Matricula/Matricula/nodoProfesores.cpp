#include "nodoProfesores.h"
#include <iostream>
using namespace std;

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

string Nodo_Profesores::toStringNodo()
{
	return P->toString();
}

Nodo_Profesores::~Nodo_Profesores()
{
	cout << "Eliminando Nodo Profesores..." << endl;
	delete P;
}

ostream & operator<<(ostream &o, Nodo_Profesores &NP)
{
	return o << NP.toStringNodo();
}
