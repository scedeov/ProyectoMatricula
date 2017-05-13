#ifndef PROFESOR
#define PROFESOR

#include <iostream>
#include "persona.h"

using namespace std;
const int MAXCURSOS = 10;

class Profesor: public Persona
{
private:
	string cursosImpartidos[MAXCURSOS];
	int cantidadCursos;
	bool esDirector;
	friend ostream& operator << (ostream&, Profesor&);
public:
	Profesor();
	Profesor(string, string, string, int);
	void setCursosImpartidos(string);
	string getCursosImpartidos();
	bool getEsDirector();
	string toString();
	~Profesor();
};
#endif // !PROFESOR
