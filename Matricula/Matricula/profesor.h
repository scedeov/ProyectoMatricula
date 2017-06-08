#ifndef PROFESOR
#define PROFESOR


#include "persona.h"

const int MAXCURSOS = 10;
class Escuela;
class Profesor: public Persona
{
private:
	Escuela *escuela;
	/*std::string cursosImpartidos[MAXCURSOS];*/
	//int cantidadCursos;
	//bool esDirector;
	//std::string escuela;
	friend std::ostream& operator << (std::ostream&, Profesor&);
public:
	Profesor();
	//Profesor(std::string, std::string, std::string, int);
	//void setCursosImpartidos(std::string);
	void setEscuela(Escuela*);
	Escuela* getEscuela();
	//int getCantidadCursos();
	//int getMaxCursos();
	//std::string getCursosImpartidos();
	//bool eliminarCursoImpartido(std::string);
	//bool getEsDirector();
	std::string toString();
	~Profesor();
};
#endif // !PROFESOR
