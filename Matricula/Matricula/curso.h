#ifndef CURSO
#define CURSO

#include "grupoProfesores.h"
#include "grupoEstudiantes.h"
#include <vector>

class Curso
{
private:
	std::vector<GrupoEstudiantes*> grupoEstu;
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