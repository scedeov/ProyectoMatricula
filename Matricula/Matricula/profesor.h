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
	int cantidadCursos;
	bool esDirector;
	friend ostream& operator << (ostream&, Profesor&);
public:
	void setNombre(string);
	void setPrimerApellido(string);
	void setSegundoApellido(string);
	Profesor(string, string, string, int);
	void setCursosImpartidos(string);
	string getCursosImpartidos();
	int getNumCedula();
	string getNombreCompleto();
	bool getEsDirector();
	/*void generaCodigoProfesor();*/
	string toString();
	~Profesor();
};
#endif // !PROFESOR
