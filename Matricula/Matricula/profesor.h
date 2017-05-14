#ifndef PROFESOR
#define PROFESOR

#include "persona.h"

const int MAXCURSOS = 10;
using namespace std;
class Profesor: public Persona
{
private:
	string cursosImpartidos[MAXCURSOS];
	int cantidadCursos;
	bool esDirector;
	string escuela;
	friend ostream& operator << (ostream&, Profesor&);
public:
	Profesor();
	Profesor(string, string, string, int);
	void setCursosImpartidos(string);
	void setEscuela(string);
	string getEscuela();
	int getCantidadCursos();
	int getMaxCursos();
	string getCursosImpartidos();
	bool eliminarCursoImpartido(string);
	bool getEsDirector();
	string toString();
	~Profesor();
};
#endif // !PROFESOR
