#ifndef ESTUDIANTE
#define ESTUDIANTE

#include <iostream>
#include <sstream>
#include <time.h>

using namespace std;

#include "persona.h"

class Estudiante: public Persona
{
private:
	string carnet;
	int porcentajeBeca;
	bool esExtranjero;
public:
	Estudiante();
	Estudiante(string, string, string, int, int);
	virtual string getCarnet();
	virtual void setEsExtranjero(bool);
	virtual bool getEsExtranjero();
	virtual void setPorcentajeBeca(int);
	virtual int getPorcentajeBeca();
	virtual void generaCarnet();
	virtual string toString();
	friend ostream& operator << (ostream&, Estudiante&);
	virtual ~Estudiante();
};
#endif // !ESTUDIANTE