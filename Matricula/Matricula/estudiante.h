#ifndef ESTUDIANTE
#define ESTUDIANTE

#include <iostream>
#include "persona.h"

using namespace std;

class Estudiante: public Persona {
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