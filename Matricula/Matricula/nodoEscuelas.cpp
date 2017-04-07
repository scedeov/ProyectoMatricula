#include "nodoEscuelas.h"

Nodo_Escuelas::Nodo_Escuelas(Escuela* unEscuela, Nodo_Escuelas* unNext)
{
	e = unEscuela;
	next = unNext;
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
	next = unNext;
}

Nodo_Escuelas * Nodo_Escuelas::getNext()
{
	return next;
}

string Nodo_Escuelas::toStringNodo(char op)
{
	return e->toStringEscuela(op);
}

Curso * Nodo_Escuelas::retornaCurso(string codigo)
{
	return e->retornaCurso(codigo);
}

Nodo_Escuelas::~Nodo_Escuelas()
{
	cout << "Eliminando Nodo de Escuelas" << endl;
	delete e;
}
