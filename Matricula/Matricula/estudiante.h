#ifndef ESTUDIANTE
#define ESTUDIANTE

#include "persona.h"
#include <time.h>
#include <sstream>
#include <iostream>
using namespace std;

class Curso;

class Estudiante: public Persona {
private:
	std::string carnet;
	int porcentajeBeca;
public:
	Estudiante();
	Estudiante(int, string);
	virtual std::string getCarnet();
	virtual void setPorcentajeBeca(int);
	virtual int getPorcentajeBeca();
	virtual void generaCarnet();
	virtual std::string toString();
	friend std::ostream& operator << (std::ostream&, Estudiante&);
	virtual ~Estudiante();
};
#endif // !ESTUDIANTE