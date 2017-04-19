#include "profesor.h"

Profesor::Profesor(string nombre, string primerApellido, string segundoApellido, int numCedula)
{
	setNombre(nombre);
	setPrimerApellido(primerApellido);
	setSegundoApellido(segundoApellido);
	setNumCedula(numCedula);
	esDirector = false;
}

Profesor::~Profesor()
{
	cout << "Eliminando Profesor... " << endl;
}
