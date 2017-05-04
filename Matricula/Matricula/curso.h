#ifndef CURSO
#define CURSO

#include <iostream>
#include <sstream>

const int MAXPROF = 10;
using namespace std;

class Curso
{
private:
	string nombreCurso;
	string codigoCurso;
	static int variableCodigoCursos;
	int cantidadCreditos;
	int cantidadProfesores;
	int profesores[MAXPROF];
public:
	Curso();
	Curso(string, string);
	void setNombre(string);
	void setCodigoCurso(string);
	void setCantidadCreditos(int);
	void setProfesores(int);
	int getProfesores(int);
	string getNombre();
	string getCodigoCurso();
	int getCantidadCreditos();
	int getCantidadProfesores();
	string toString();
	friend ostream& operator << (ostream&, Curso&);
	bool operator == (const Curso&) const;
	~Curso();
};
#endif // !CURSO