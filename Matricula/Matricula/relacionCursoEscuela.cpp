#include "relacionCursoEscuela.h"
#include "escuela.h"
#include "curso.h"

RelacionCursoEscuela::RelacionCursoEscuela(Escuela& escuela, Curso& curso): 
	referenciaCurso(&curso), 
	referenciaEscuela(&escuela)
{
}

Escuela* RelacionCursoEscuela::getReferenciaEscuela()
{
	return referenciaEscuela;
}

Curso* RelacionCursoEscuela::getReferenciaCurso()
{
	return referenciaCurso;
}

void RelacionCursoEscuela::setReferenciaCurso(Curso &curso)
{
	referenciaCurso = &curso;
}

void RelacionCursoEscuela::setReferenciaEscuela(Escuela &escuela)
{
	referenciaEscuela = &escuela;
}

RelacionCursoEscuela::~RelacionCursoEscuela()
{
}
