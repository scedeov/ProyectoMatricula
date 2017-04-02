#include "nodoCursos.h"

Nodo_Cursos::Nodo_Cursos(Curso *unCurso, Nodo_Cursos *unNext)
{
	c = unCurso;
	next = unNext;
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
	next = unNext;
}

Nodo_Cursos * Nodo_Cursos::getNext()
{
	return next;
}

//string Nodo_Cursos::toStringNodo()
//{
//	return c->toStringCurso();
//}

Nodo_Cursos::~Nodo_Cursos()
{
	cout << "Eliminando Nodo de Cursos" << endl;
	delete c;
}
