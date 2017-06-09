#ifndef ESTUDIANTE
#define ESTUDIANTE

#include "persona.h"
#include <time.h>
#include <sstream>
#include <iostream>
using namespace std;

class Curso;
class ControladorCursos;
class Estudiante: public Persona {
private:
	std::string carnet;
	int porcentajeBeca;
	ControladorCursos* cursosMatriculados;
public:
	Estudiante();
	virtual std::string getCarnet();
	virtual void setPorcentajeBeca(int);
	virtual int getPorcentajeBeca();
	virtual void generaCarnet();
	virtual ControladorCursos* getCursosMatriculados();
	virtual int getCantidadCursosMatriculados();
	virtual std::string toString();
	friend std::ostream& operator << (std::ostream&, Estudiante&);
	virtual ~Estudiante();
};
#endif // !ESTUDIANTE