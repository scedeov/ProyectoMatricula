#include "nodoEscuelas.h"

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

string Nodo_Escuelas::toStringNodo(char op)
{
	return e->toStringEscuela(op);
}

Curso * Nodo_Escuelas::retornaCurso(string codigo)
{
	return e->retornaCurso(codigo);
}

Profesor * Nodo_Escuelas::retornaProfesor(int cedula) {
	return e->retornaProfesor(cedula);
}

Nodo_Escuelas::~Nodo_Escuelas()
{
	cout << "Eliminando Nodo de Escuelas" << endl;
	delete e;
}
