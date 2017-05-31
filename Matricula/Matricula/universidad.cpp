#include "universidad.h"
#include "contenedorEscuelas.h"
#include "contenedorEstudiantes.h"
#include <iostream>
#include <sstream>

Universidad::Universidad (
	std::string unNombre = "Undefined", 
	std::string xNumero = "Undefined", 
	std::string unDireccion = "Undefined") :
	nombre(unNombre), numeroTelefono(xNumero), direccion(unDireccion) { 

	ContE = new Contenedor_Escuelas();
	ContEst = new Contenedor_Estudiantes();
}

Universidad::~Universidad() {
	std::cout << "Eliminando Universidad..." << std::endl;
	delete ContE;
	delete ContEst;
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

Contenedor_Escuelas* Universidad::getContenedorEscuelas() {
	return ContE;
}

Contenedor_Estudiantes * Universidad::getContenedorEstudiantes() {
	return ContEst;
}

std::ostream& operator << (std::ostream &o, Universidad& U) {
	return o << U.toString();
}
