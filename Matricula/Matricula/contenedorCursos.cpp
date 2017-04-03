#include "contenedorCursos.h"

Contenedor_Cursos::Contenedor_Cursos()
{
	pinicio = NULL;
	paux = NULL;
}

void Contenedor_Cursos::insertaInicio(Curso *unCurso)
{
	paux = new Nodo_Cursos(unCurso, NULL);

	if (pinicio == NULL)
	{
		pinicio = paux;
	}
	else
	{
		paux->setNext(pinicio);
		pinicio = paux;
	}
}

bool Contenedor_Cursos::eliminaCursoEspecifico(string codigo)
{
	Nodo_Cursos* anterior = NULL;
	paux = pinicio;

	if (paux == NULL)
	{
		return false;
	}

	if (paux->getCurso()->getCodigoCurso() == codigo)
	{
		paux = paux->getNext();
		delete pinicio;
		pinicio = paux;
		return true;
	}

	while (paux != NULL &&   paux->getCurso()->getCodigoCurso() != codigo) {
		anterior = paux;
		paux = paux->getNext();
	}

	if (paux == NULL)
	{
		return false;
	}

	else
	{
		anterior->setNext(paux->getNext());
		delete paux;
		return true;
	}

}

Curso * Contenedor_Cursos::retornaCursoEspecifico(string codigo)
{
	paux = pinicio;
	while (paux != NULL)
	{
		if (encuentraCurso(paux->getCurso(), codigo) == true)
			return paux->getCurso();
		else
			paux = paux->getNext();
	}
	return nullptr;
}

bool Contenedor_Cursos::encuentraCurso(Curso* C, string codigo)
{
	if (C->getCodigoCurso() == codigo)
		return true;
	else
		return false;
}


//string Contenedor_Cursos::toString()
//{
//	stringstream s;
//	paux = pinicio;
//	while (paux != NULL)
//	{
//		s << *(paux->getCurso()) << endl;
//		paux = paux->getNext();
//	}
//	return s.str();
//}

Contenedor_Cursos::~Contenedor_Cursos()
{
	cout << "Eliminando Contenedor de Cursos" << endl;

	while (pinicio != NULL)
	{
		paux = pinicio;
		pinicio = pinicio->getNext();
		delete paux;
	}
}

ostream & operator<<(ostream &o, Contenedor_Cursos &CC)
{
	CC.paux = CC.pinicio;

	while (CC.paux != NULL)
	{
		o << *(CC.paux->getCurso()) << endl;
		CC.paux = CC.paux->getNext();
	}

	return o;
}
