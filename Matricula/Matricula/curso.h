#ifndef CURSO
#define CURSO

#include "grupo.h"
#include <sstream>
#include <iostream>
#include "vector.h"
#include <string>
using namespace std;

#include "grupo.h"
//class GrupoProfesores;

const int MAXGRUPOSESTUDIANTES = 5;

class Curso {
private:
	Vector<Grupo> *grupo;
	std::string nombreCurso;
	std::string codigoCurso;
	static int variableCodigoCursos;
	int cantidadCreditos;
public:
	Curso();
	Curso(std::string, std::string);
	void setNombre(std::string);
	void setCodigoCurso(std::string);
	void setCantidadCreditos(int);
	Grupo* getGrupoEstudiantes(int);
	/*GrupoProfesores* getGrupoProfesores();*/
	std::string getNombre();
	std::string getCodigoCurso();
	int getCantidadCreditos();
	std::string imprimeEstudiantesMatriculados();
	std::string toString();
	friend std::ostream& operator << (std::ostream&, Curso&);
	bool operator == (const Curso&) const;
	~Curso();
};
#endif // !CURSO