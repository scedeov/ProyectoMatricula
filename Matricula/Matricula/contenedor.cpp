#include "contenedor.h"
#include "contenedorEscuelas.h"
#include "contenedorCursos.h"
#include "contenedorPersonas.h"

adaptadorContenedorEscuelas::adaptadorContenedorEscuelas(ContenedorEscuelas *contenedorEscuelas) {
	this->contenedorEscuelas = contenedorEscuelas;
}

Escuela * adaptadorContenedorEscuelas::getDato(std::string sigla) {
	return contenedorEscuelas->retornaEscuela(sigla);
}

Escuela * adaptadorContenedorEscuelas::getDato(int)
{
	return nullptr;
}

void adaptadorContenedorEscuelas::agregarInicio(Escuela *escuela) {
	contenedorEscuelas->agregarInicio(escuela);
}

std::string adaptadorContenedorEscuelas::toString() {
	return contenedorEscuelas->toString();
}

adaptadorContenedorCursos::adaptadorContenedorCursos(ContenedorCursos *contenedorCursos) {
	this->contenedorCursos = contenedorCursos;
}

Curso * adaptadorContenedorCursos::getDato(std::string codigo) {
	this->contenedorCursos->getCursoEspecifico(codigo);
}

void adaptadorContenedorCursos::agregarInicio(Curso *curso) {
	contenedorCursos->agregarInicio(curso);
}

adaptadorContenedorPersonas::adaptadorContenedorPersonas(ContenedorPersonas *contenedorPersonas) {
	this->contenedorPersonas = contenedorPersonas;
}

Persona * adaptadorContenedorPersonas::getDato(int cedula) {
	contenedorPersonas->getPersona(cedula);
}

void adaptadorContenedorPersonas::agregarInicio(Persona *persona)
{
	contenedorPersonas->agregarInicio(persona);
}
