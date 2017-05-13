#include "estudianteExtranjero.h"

Estudiante_Extranjero::Estudiante_Extranjero(string nombre, string primerApellido, string segundoApellido, int cedula)
{
	setNombre(nombre);
	setPrimerApellido(primerApellido);
	setSegundoApellido(segundoApellido);
	generaCarnet();
	setNumCedula(cedula);
	setPorcentajeBeca(0);
	setEsExtranjero(true);
}

Estudiante_Extranjero::~Estudiante_Extranjero()
{
}
