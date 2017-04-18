#ifndef ESTUDIANTE
#define ESTUDIANTE

#include <iostream>
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
	~Estudiante();
};
#endif // !ESTUDIANTE