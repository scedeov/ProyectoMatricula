#include "universidad.h"
#include "contenedorEscuelas.h"
#include "contenedorEstudiantes.h"
#include "contenedorProfesores.h"
#include <iostream>
#include <sstream>

Universidad::Universidad (
	std::string unNombre = "Undefined", 
	std::string xNumero = "Undefined", 
	std::string unDireccion = "Undefined") :
	nombre(unNombre), numeroTelefono(xNumero), direccion(unDireccion) { 

	//Se crean los componentes de la Universidad (Composicion)
	escuelas = new contenedorEscuelas();
	profesores = new contenedorProfesores();
	estudiantes = new contenedorEstudiantes();
}

Universidad::~Universidad() {
	std::cout << "Eliminando Universidad..." << std::endl;
	delete escuelas;
	delete profesores;
	delete estudiantes;
}

void Universidad::setTelefono(std::string unTelefono) {
	numeroTelefono = unTelefono;
}

void Universidad::setDireccion(std::string unDireccion) {
	direccion = unDireccion;
}

void Universidad::setNombre(std::string unNombre) {
	nombre = unNombre;
}

std::string Universidad::getNombre() {
	return nombre;
}

std::string Universidad::getNumero() {
	return numeroTelefono;
}

std::string Universidad::getDireccion() {
	return direccion;
}

std::string Universidad::toString() {
	std::stringstream s;
	s	<< "Nombre Universidad: " << nombre << std::endl
		<< "Numero de Telefono: " << numeroTelefono << std::endl
		<< "Direccion: " << direccion << std::endl;
	return s.str();
}

contenedorEscuelas* Universidad::getContenedorEscuelas() {
	return escuelas;
}

contenedorEstudiantes * Universidad::getContenedorEstudiantes() {
	return estudiantes;
}

contenedorProfesores * Universidad::getContenedorProfesores() {
	return profesores;
}

std::ostream& operator << (std::ostream &o, Universidad& U) {
	return o << U.toString();
}
