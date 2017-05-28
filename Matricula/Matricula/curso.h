#ifndef CURSO
#define CURSO


#include "vector.h"
#include <vector> // no tengo idea porque si elimino esto se caen cosas en .cpp, ni siquiera estan relacionadas

class GrupoEstudiantes;
class GrupoProfesores;

const int MAXGRUPOSESTUDIANTES = 5;

class Curso {
private:
	Vector<GrupoEstudiantes> *grupoEstu;
	GrupoProfesores* grupoProfes;
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
	GrupoEstudiantes* getGrupoEstudiantes(int);
	GrupoProfesores* getGrupoProfesores();
	std::string getNombre();
	std::string getCodigoCurso();
	int getCantidadCreditos();
	std::string imprimeEstudiantesMatriculados();
	std::string toString();
	friend std::ostream& operator << (std::ostream&, Curso&);
	bool operator == (const Curso&) const;
	~Curso();
};
#endif // !CURSO