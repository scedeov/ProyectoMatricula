#ifndef CURSO
#define CURSO

#include <string>

class GrupoCurso;
class GrupoProfesores;
class ContenedorGrupoCurso;

class Curso {
private:
	std::string nombreCurso;
	std::string codigoCurso;
	static int variableCodigoCursos;
	int cantidadCreditos;
	ContenedorGrupoCurso *contenedorGrupoCurso;
	GrupoProfesores* grupoProfesores;
public:
	Curso(std::string, std::string, int);
	void setNombre(std::string);
	void setCodigoCurso(std::string);
	void setCantidadCreditos(int);
	std::string getNombre();
	std::string getCodigoCurso();
	int getCantidadCreditos();
	std::string imprimeEstudiantesMatriculados();
	std::string toString();
	friend std::ostream& operator << (std::ostream&, Curso&);
	bool operator == (const Curso&) const;
	ContenedorGrupoCurso* getContenedorGrupoCurso();
	GrupoProfesores* getGrupoProfesores();
	~Curso();
};
#endif // !CURSO