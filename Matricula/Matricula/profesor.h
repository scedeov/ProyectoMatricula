#ifndef PROFESOR
#define PROFESOR
#include <sstream>
#include <iostream>
#include "persona.h"

using namespace std;
const int MAXCURSOS = 10;

class Profesor: public Persona
{
private:
	/*std::string cursosImpartidos[MAXCURSOS];*/
	//int cantidadCursos;
	//bool esDirector;
	//std::string escuela;
	friend std::ostream& operator << (std::ostream&, Profesor&);
public:
	Profesor();
	//Profesor(std::string, std::string, std::string, int);
	//void setCursosImpartidos(std::string);
	//void setEscuela(std::string);
	//std::string getEscuela();
	//int getCantidadCursos();
	//int getMaxCursos();
	//std::string getCursosImpartidos();
	//bool eliminarCursoImpartido(std::string);
	//bool getEsDirector();
	std::string toString();
	~Profesor();
};
#endif // !PROFESOR
