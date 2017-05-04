#ifndef PROFESOR
#define PROFESOR

#include <iostream>
using namespace std;

const int MAXCURSOS = 10;
#include "persona.h"

class Profesor: private Persona
{
private:
	string cursosImpartidos[MAXCURSOS];
	string codigoProfesor;
	int cantidadCursos;
	bool esDirector;
	friend ostream& operator << (ostream&, Profesor&);
public:
	Profesor(string, string, string, int);
	void setCursosImpartidos(string);
	string getCursosImpartidos();
	int getNumCedulaProfe();
	bool getEsDirector();
	void generaCodigoProfesor();
	string getCodigoProfesor();
	string toString();
	~Profesor();
};
#endif // !PROFESOR
