#ifndef GRUPOPROFESORES
#define GRUPOPROFESORES

class Profesor;
const int MAXPROF = 5;

class GrupoProfesores {
private:
	Vector<Profesor> *profesores;
public:
	GrupoProfesores();
	void agregarProfesor(Profesor*);
	Profesor* getProfesor(int);
	bool eliminarProfesor(int);
	int getCantidad();
	~GrupoProfesores();
};
#endif // !GRUPO
