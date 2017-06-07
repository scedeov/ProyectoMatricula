#include "nodoEscuelas.h"
#include <iostream>
using namespace std;

Nodo_Escuelas::Nodo_Escuelas(Escuela* unEscuela, Nodo_Escuelas* unNext)
{
	e = unEscuela;
	Next = unNext;
}

void Nodo_Escuelas::setEscuela(Escuela* unEscuela)
{
	e = unEscuela;
}

Escuela * Nodo_Escuelas::getEscuela()
{
	return e;
}

void Nodo_Escuelas::setNext(Nodo_Escuelas* unNext)
{
	Next = unNext;
}

Nodo_Escuelas * Nodo_Escuelas::getNext()
{
	return Next;
}

string Nodo_Escuelas::toStringNodoEscuelas() {
	return e->toStringEscuela();
}

string Nodo_Escuelas::toStringNodoConCursos() {
	return e->toStringConCursos();
}

Nodo_Escuelas::~Nodo_Escuelas()
{
	cout << "Eliminando Nodo de Escuelas" << endl;
	delete e;
}
