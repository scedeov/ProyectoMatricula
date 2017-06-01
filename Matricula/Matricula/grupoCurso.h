#ifndef GRUPOCURSO
#define GRUPOCURSO

class Profesor;
class Estudiante;
class Curso;

#include <string>

const int MAXESTU = 30;

class GrupoCurso {
private:
	Curso *curso;
	Profesor *profesorEncargado;
	Vector<Estudiante> *estudiantesMatriculados;
public:
	GrupoCurso();
	int getCantidad();
	Curso* getCurso();
	void setCurso(Curso*);
	void setProfesorEncargado(Profesor*);
	Profesor* getProfesorEncargado();
	void matricularEstudiante(Estudiante*);
	bool desmatricularEstudiante(int);
	std::string toString() const;
	~GrupoCurso();
};
#endif // !GRUPOCURSO
