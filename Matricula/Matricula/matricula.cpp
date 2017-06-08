#include "matricula.h"
#include "curso.h"
#include "profesor.h"

void Matricula::asignarProfesor(Curso *curso, Profesor *profesor)
{
	curso->getGrupo((curso->getCantidadProfesoresEncargados() + 1))->setProfesorEncargado(profesor);
}
