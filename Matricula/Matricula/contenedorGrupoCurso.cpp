#include "contenedorGrupoCurso.h"
#include "grupoCurso.h"


ContenedorGrupoCurso::ContenedorGrupoCurso()
{
	contenedorGrupoCurso = new Vector<GrupoCurso>(MAXGRUPOSESTUDIANTES);
	for (int i = 0; i < contenedorGrupoCurso->getCapacidad(); i++)
		contenedorGrupoCurso->agregarInicio(new GrupoCurso());
}

GrupoCurso * ContenedorGrupoCurso::getCursoGrupo(int pos)
{
	Vector<GrupoCurso>::Iterador it(contenedorGrupoCurso);
	it.posicionaPrimerObjeto();
	for (int i = 0; i < pos; i++)
		it.posicionaSiguiente();
	return it.getObjectoCursorActual();
}

ContenedorGrupoCurso::~ContenedorGrupoCurso()
{
	std::cout << "Eliminando Contenedor de Grupos de Curso..." << std::endl;
}
