#include "escuela.h"

Escuela::Escuela(string unNombre = "Undefined") :
	nombreEscuela(unNombre)
{
	siglaEscuela = generaSigla(nombreEscuela);

	if (nombreEscuela != "Undefined")
		nombreEscuela = "Escuela de " + nombreEscuela;

	ContP = new Contenedor_Profesores();
	ConC = new Contenedor_Cursos();

}

Escuela::~Escuela()
{
	cout << "Eliminando Escuela" << endl;
	delete ConC;
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
	ConC->insertaInicio(unCurso);
}

Contenedor_Cursos * Escuela::retornaContenedorCursos()
{
	return ConC;
}

Curso * Escuela::retornaCurso(string codigo)
{
	return ConC->retornaCurso(codigo);
}

void Escuela::insertarProfesor(Profesor *P)
{
	ContP->insertaInicio(P);
}

string Escuela::toStringEscuela(char op)
{
	stringstream s;
	s << "Nombre de la Escuela: " << nombreEscuela;
	s << "| Codigo: " << siglaEscuela << endl;

	if (op == '2')
	{
		s << "Cursos Impartidos: " << endl;
		s << *ConC << endl;
	}

	return s.str();
}
