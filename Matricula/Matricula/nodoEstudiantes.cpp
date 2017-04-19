#include "nodoEstudiantes.h"

Nodo_Estudiantes::Nodo_Estudiantes(Estudiante* unEstudiante, Nodo_Estudiantes* unNext)
{
	E = unEstudiante;
	Next = unNext;
}

void Nodo_Estudiantes::setEstudiante(Estudiante* unEstudiante)
{
	E = unEstudiante;
}

Estudiante * Nodo_Estudiantes::getEstudiante()
{
	return E;
}

void Nodo_Estudiantes::setNext(Nodo_Estudiantes* unNext)
{
	Next = unNext;
}

Nodo_Estudiantes * Nodo_Estudiantes::getNext()
{
	return Next;
}

string Nodo_Estudiantes::toStringNodo()
{
	return E->toString();
}

Nodo_Estudiantes::~Nodo_Estudiantes()
{
	cout << "Eliminando Nodo de Escuelas" << endl;
	delete E;
}
