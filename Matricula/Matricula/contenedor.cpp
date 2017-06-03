#include "contenedor.h"
#include "contenedorEscuelas.h"
#include "contenedorCursos.h"
#include "contenedorPersonas.h"
#include "contenedorGrupoCurso.h"

adaptadorContenedorEscuelas::adaptadorContenedorEscuelas()
{
}

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

adaptadorContenedorCursos::adaptadorContenedorCursos()
{
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

adaptadorContenedorPersonas::adaptadorContenedorPersonas()
{
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

adaptadorContenedorGrupoCurso::adaptadorContenedorGrupoCurso()
{
}

adaptadorContenedorGrupoCurso::adaptadorContenedorGrupoCurso(ContenedorGrupoCurso *contenedorGrupoCurso)
{
	this->contenedorGrupoCurso = contenedorGrupoCurso;
}

GrupoCurso * adaptadorContenedorGrupoCurso::getDato(int pos)
{
	return contenedorGrupoCurso->getDato(pos);
}
