#include "universidad.h"

Universidad::Universidad()
{
	nombre = "Undefined";
	numeroTelefono = "Undefined";
	direccion = "Undefined";

	CE = new Contenedor_Escuelas();
}

Universidad::Universidad(string unNombre, string xNumero, string unDireccion)
{
	nombre = unNombre;
	numeroTelefono = xNumero;
	direccion = unDireccion;

	CE = new Contenedor_Escuelas();
}

Universidad::~Universidad()
{
	cout << "Eliminando Universidad..." << endl;
	delete CE;
}

void Universidad::setTelefono(string unTelefono)
{
	numeroTelefono = unTelefono;
}

void Universidad::setDireccion(string unDireccion)
{
	direccion = unDireccion;
}

void Universidad::setNombre(string unNombre)
{
	nombre = unNombre;
}

string Universidad::getNombre()
{
	return nombre;
}

string Universidad::getNumero()
{
	return numeroTelefono;
}

string Universidad::getDireccion()
{
	return direccion;
}

Contenedor_Escuelas * Universidad::getContenedorEscuelas()
{
	return CE;
}

ostream& operator << (ostream &o, const Universidad& U)
{
	o	<< "Nombre Universidad: " << U.nombre << endl
		<< "Numero de Telefono: " << U.numeroTelefono << endl
		<< "Direccion: " << U.direccion << endl;

	return o;

}


//string Universidad::toString()
//{
//	stringstream s;
//
//	s	<< string("Nombre Universidad: ") << nombre << endl
//		<< string("Numero de Telefono: ") << numeroTelefono << endl
//		<< string("Direccion: ") << direccion << endl;
//	return s.str();
//}
