#include "nodoCursos.h"
#include <sstream>
#include <iostream>
using namespace std;

Nodo_Cursos::Nodo_Cursos(Curso *unCurso, Nodo_Cursos *unNext)
{
	c = unCurso;
	Next = unNext;
}

void Nodo_Cursos::setCurso(Curso* unCurso)
{
	c = unCurso;
}

Curso * Nodo_Cursos::getCurso()
{
	return c;
}

void Nodo_Cursos::setNext(Nodo_Cursos *unNext)
{
	Next = unNext;
}

Nodo_Cursos * Nodo_Cursos::getNext()
{
	return Next;
}

string Nodo_Cursos::toStringNodo()
{
	std::stringstream s;
	s << c->toString();
	return s.str();
}

Nodo_Cursos::~Nodo_Cursos()
{
	std::cout << "Eliminando Nodo de Cursos" << std::endl;
	delete c;
}

ostream & operator <<(ostream &o, Nodo_Cursos &NC)
{
	return o << NC.toStringNodo();
}
