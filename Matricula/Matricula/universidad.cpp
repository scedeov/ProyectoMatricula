#include "universidad.h"


Universidad::Universidad()
{
	nombre = "Undefined";
	numeroTelefono = "Undefined";
	direccion = "Undefined";

	controladorEscuelas = new ControladorEscuelas();
	controladorEstudiantes = new ControladorEstudiantes();
}

Universidad::Universidad(std::string unNombre, std::string xNumero, std::string unDireccion)
{
	nombre = unNombre;
	numeroTelefono = xNumero;
	direccion = unDireccion;

	controladorEscuelas = new ControladorEscuelas();
	controladorEstudiantes = new ControladorEstudiantes();
}

Universidad::~Universidad()
{
	std::cout << "Eliminando Universidad..." << std::endl;
	delete controladorEscuelas;
	delete controladorEstudiantes;
}

void Universidad::setTelefono(std::string unTelefono)
{
	numeroTelefono = unTelefono;
}

void Universidad::setDireccion(std::string unDireccion)
{
	direccion = unDireccion;
}

void Universidad::setNombre(std::string unNombre)
{
	nombre = unNombre;
}

std::string Universidad::getNombre()
{
	return nombre;
}

std::string Universidad::getNumero()
{
	return numeroTelefono;
}

std::string Universidad::getDireccion()
{
	return direccion;
}

std::string Universidad::toString()
{
	std::stringstream s;
	s << "Nombre Universidad: " << nombre << std::endl
		<< "Numero de Telefono: " << numeroTelefono << std::endl
		<< "Direccion: " << direccion << std::endl;

	return s.str();
}

ControladorEscuelas* Universidad::getControladorEscuelas() {
	return controladorEscuelas;
}

ControladorEstudiantes * Universidad::getContenedorEstudiantes()
{
	return controladorEstudiantes;
}

std::ostream& operator << (std::ostream &o, Universidad& U)
{
	return o << U.toString();
}
