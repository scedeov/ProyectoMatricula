#ifndef CONTENEDOR_PROFESORES
#define CONTENEDOR_PROFESORES

#include "profesor.h"
#include "lista.h"

class contenedorProfesores
{
private:
	Lista<Profesor> *listaProfesores;
	friend std::ostream& operator << (std::ostream&, contenedorProfesores&);
public:
	contenedorProfesores();
	void agregarInicio(Profesor*);
	Profesor* retornaProfesor(int);
	bool encuentraProfesor(Profesor*, int);
	int contadorProfesores();
	std::string toString();
	~contenedorProfesores();
};
#endif // !CONTENEDOR_PROFESORES
