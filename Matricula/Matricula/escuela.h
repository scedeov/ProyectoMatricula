#ifndef ESCUELA
#define ESCUELA

#include <string>

class Contenedor_Cursos;
class Contenedor_Profesores;

class Escuela
{
private:
	std::string nombreEscuela;
	std::string siglaEscuela;
	Contenedor_Cursos* ConC;
	Contenedor_Profesores* ContP;
public:
	Escuela(std::string);
	~Escuela();
	void setNombre(std::string);
	std::string getNombre();
	void setSiglaEscuela(std::string);
	std::string getSiglaEscuela();
	std::string generaSigla(std::string);
	Contenedor_Cursos* getContenedorCursos();
	Contenedor_Profesores* getContenedorProfesores();
	std::string toStringEscuela(char);
};
#endif // !ESCUELA

