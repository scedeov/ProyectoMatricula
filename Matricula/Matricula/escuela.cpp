#include "escuela.h"

Escuela::Escuela(string unNombre = "Undefined"):
	nombreEscuela(unNombre)
{
	siglaEscuela = generaSigla(nombreEscuela);

	if (nombreEscuela != "Undefined")
		nombreEscuela = "Escuela de " + nombreEscuela;

	CC = new Contenedor_Cursos();
}

Escuela::~Escuela()
{
	cout << "Eliminando Escuela" << endl;
	delete CC;
}

void Escuela::setNombre(string unNombre)
{
	nombreEscuela = unNombre;
}

string Escuela::getNombre()
{
	return nombreEscuela;
}

void Escuela::setSiglaEscuela(string unSiglaEscuela)
{
	siglaEscuela = unSiglaEscuela;
}

string Escuela::getSiglaEscuela()
{
	return siglaEscuela;
}

string Escuela::generaSigla(string unNombre)
{
	siglaEscuela = unNombre.substr(0, 3);
	string aux;
	for (int i = 0; i < siglaEscuela.length(); i++)
	{
		aux += toupper(siglaEscuela[i]);
	}

	siglaEscuela = aux;

	return siglaEscuela;
}


void Escuela::insertarCurso(Curso* unCurso)
{
	CC->insertaInicio(unCurso);
}

Contenedor_Cursos * Escuela::retornaContenedorCursos()
{
	return CC;
}

Curso * Escuela::retornaCurso(string codigo)
{
	return CC->retornaCurso(codigo);
}

string Escuela::toStringEscuela(char op)
{
	stringstream s;
	s << "Nombre de la Escuela: " << nombreEscuela;
	s << "| Codigo: " << siglaEscuela << endl;

	if (op == '2')
	{
		s << "Cursos Impartidos: " << endl;
		s << *CC << endl;
	}

	return s.str();
}
