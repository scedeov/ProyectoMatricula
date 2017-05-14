#ifndef CURSO
#define CURSO

#include <iostream>
#include <sstream>

#include "grupoProfesores.h"
#include "grupoEstudiantes.h"

using namespace std;

class Curso
{
private:
	GrupoEstudiantes* grupoEstu;
	GrupoProfesores* grupoProfes;
	string nombreCurso;
	string codigoCurso;
	static int variableCodigoCursos;
	int cantidadCreditos;
public:
	Curso();
	Curso(string, string);
	void setNombre(string);
	void setCodigoCurso(string);
	void setCantidadCreditos(int);
	GrupoEstudiantes* getGrupoEstudiantes();
	GrupoProfesores* getGrupoProfesores();
	string getNombre();
	string getCodigoCurso();
	int getCantidadCreditos();
	string toString();
	friend ostream& operator << (ostream&, Curso&);
	bool operator == (const Curso&) const;
	~Curso();
};
#endif // !CURSO