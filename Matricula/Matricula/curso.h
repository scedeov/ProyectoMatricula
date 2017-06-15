#ifndef CURSO
#define CURSO

#include "vector.h"
#include <string>

class Estudiante;
class Grupo;
class Profesor;
const int MAXGRUPOSESTUDIANTES = 5;
class Curso {
private:
	Vector<Grupo> *grupo;
	std::string nombreCurso;
	std::string codigoCurso;
	static int variableCodigoCursos;
	int cantidadCreditos;
public:
	Curso();
	Curso(std::string, std::string);
	void setNombre(std::string);
	void setCodigoCurso(std::string);
	void setCantidadCreditos(int);
	Grupo* getGrupo(int);
	Profesor* getProfesorEncargado(int); // con una posicion del vector de grupos
	int getCantidadGrupos();
	int getCantidadProfesoresEncargados();
	std::string getNombre();
	std::string getCodigoCurso();
	int getCantidadCreditos();
	bool estaEstudiante(Estudiante*);
	std::string imprimeEstudiantesMatriculados();
	std::string toString();
	friend std::ostream& operator << (std::ostream&, Curso&);
	bool operator == (const Curso&) const;
	~Curso();
};
#endif // !CURSO