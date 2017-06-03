#include "contenedorRelacionCursoEscuela.h"
#include "nodo.h"

ContenedorRelacionCursoEscuela::ContenedorRelacionCursoEscuela()
{
	listaRelacionCursoEscuela = new Lista<RelacionCursoEscuela>();
}

Lista<RelacionCursoEscuela>* ContenedorRelacionCursoEscuela::getLista()
{
	return listaRelacionCursoEscuela;
}

int ContenedorRelacionCursoEscuela::getCursosNescuelas(std::string codigo, std::string sigla)
{
	Nodo<RelacionCursoEscuela> *ptr = listaRelacionCursoEscuela->getPrimerNodo();
	while (ptr != NULL) {
		if(ptr->getDato()) 
		ptr = ptr->getNext();
	}
}

ContenedorRelacionCursoEscuela::~ContenedorRelacionCursoEscuela()
{
	listaRelacionCursoEscuela->limpiar();
}
