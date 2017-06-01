#include "grupoCurso.h"
#include "estudiante.h"
#include "curso.h"
#include "profesor.h"
#include <iostream>
#include <sstream>
using namespace std;

GrupoCurso::GrupoCurso() {
	curso = nullptr;
	profesorEncargado = nullptr;
	estudiantesMatriculados = new Vector<Estudiante>(MAXESTU);
}

int GrupoCurso::getCantidad() {
	return estudiantesMatriculados->getCantidad();
}

Curso * GrupoCurso::getCurso()
{
	return curso;
}

void GrupoCurso::setCurso(Curso *curso) {
	this->curso = curso;
}

void GrupoCurso::setProfesorEncargado(Profesor *P) {
	profesorEncargado = P;
}

Profesor * GrupoCurso::getProfesorEncargado() {
	return profesorEncargado;
}

void GrupoCurso::matricularEstudiante(Estudiante *E) {
	estudiantesMatriculados->agregarInicio(E);
}

bool GrupoCurso::desmatricularEstudiante(int cedula)
{
	Vector<Estudiante>::Iterador it(estudiantesMatriculados);
	it.posicionaPrimerObjeto();
	while (it.getPosicionActual() < estudiantesMatriculados->getCantidad()) {
		if (it.getObjectoCursorActual()->getNumCedula() == cedula) { // si es el primero
			estudiantesMatriculados->eliminaEspecifico(it.getPosicionActual());
			return true;
		}
		else
			it.posicionaSiguiente();
	}
	return false;
}

string GrupoCurso::toString() const {
	stringstream s;
	Vector<Estudiante>::Iterador it(estudiantesMatriculados);
	it.posicionaPrimerObjeto();
	for (int i = 0; i < estudiantesMatriculados->getCantidad(); i++) {
		s << it.getObjectoCursorActual()->getNombreCompleto() << endl;
		it.posicionaSiguiente();
	}
	return s.str();
}

GrupoCurso::~GrupoCurso()
{
	std::cout << "Eliminando grupo Estudiantes..." << std::endl;
	delete estudiantesMatriculados;
}
