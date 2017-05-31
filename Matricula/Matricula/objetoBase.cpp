#include "objetoBase.h"
#include "contenedorCursos.h"

adaptadorCursos::adaptadorCursos(Contenedor_Cursos *C) {
	this->C = C;
}

void adaptadorCursos::eliminaEspecifico()
{
	C->eliminarEspecifico(string);
}

std::string adaptadorCursos::toString()
{
	return std::string();
}

std::ostream & operator<<(std::ostream &o, const objetoBase &ob)
{
	return o << ob.toString() << std::endl;
}
