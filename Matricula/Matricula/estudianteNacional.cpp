#include "estudianteNacional.h"
#include <string>
#include <iostream>
using namespace std;

Estudiante_Nacional::Estudiante_Nacional(string nombre, string primerApellido, string segundoApellido, int cedula, int porcentajeBeca)
{
	setNombre(nombre);
	setPrimerApellido(primerApellido);
	setSegundoApellido(segundoApellido);
	generaCarnet();
	setNumCedula(cedula);
	setPorcentajeBeca(porcentajeBeca);
	setEsExtranjero(false);
}

Estudiante_Nacional::~Estudiante_Nacional()
{
	cout << "Eliminando Estudiante Nacional..." << endl;
}
