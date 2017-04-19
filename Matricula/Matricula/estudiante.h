#ifndef ESTUDIANTE
#define ESTUDIANTE

#include <iostream>
#include <sstream>
using namespace std;

#include "persona.h"

class Estudiante: private Persona
{
private:
	string carnet;
	bool esExtranjero;
	int porcentajeBeca;
public:
	Estudiante();
	void setCarnet(string);
	string getCarnet();
	void setNacionalidad(bool);
	bool getNacionalidad();
	void setPorcentajeBeca(int);
	int getPorcentajeBeca();
	string toString();
	friend ostream& operator << (ostream&, Estudiante&);
	~Estudiante();
};
#endif // !ESTUDIANTE