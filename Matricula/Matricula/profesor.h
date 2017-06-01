#ifndef PROFESOR
#define PROFESOR

#include "persona.h"

const int MAXCURSOS = 10;
class Curso;
class Profesor: public Persona
{
private:
	Vector<Curso> *cursosImpartidos;
	int cantidadCursos;
	bool esDirector;
	std::string escuela;
	friend std::ostream& operator << (std::ostream&, Profesor&);
public:
	Profesor();
	Profesor(std::string, std::string, std::string, int);
	void agregaNuevoCursoImpartido(Curso*);
	void setEscuela(std::string);
	std::string getEscuela();
	int getCantidadCursos();
	int getMaxCursos();
	std::string getCursosImpartidos();
	bool eliminarCursoImpartido(std::string);
	bool getEsDirector();
	std::string toString();
	~Profesor();
};
#endif // !PROFESOR
