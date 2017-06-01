#ifndef CONTENEDOR_PROFESORES
#define CONTENEDOR_PROFESORES

#include "profesor.h"

class ContenedorProfesores
{
private:
	Lista<Profesor> *listaProfesores;
	friend std::ostream& operator << (std::ostream&, ContenedorProfesores&);
public:
	ContenedorProfesores();
	void agregarInicio(Profesor*);
	Profesor* retornaProfesor(int);
	bool encuentraProfesor(Profesor*, int);
	int contadorProfesores();
	std::string toString();
	~ContenedorProfesores();
};
#endif // !CONTENEDOR_PROFESORES
