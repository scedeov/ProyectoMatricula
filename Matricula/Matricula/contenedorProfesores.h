#ifndef CONTENEDOR_PROFESORES
#define CONTENEDOR_PROFESORES

#include "contenedor.h"
#include "lista.h"

class Profesor;
class ContenedorProfesores: public Contenedor {
private:
	Lista<Profesor> *listaProfesores;
public:
	ContenedorProfesores();
	void agregarInicio(Profesor*);
	Profesor* retornaProfesor(int);
	bool encuentraProfesor(Profesor*, int);
	int getCantidad();
	std::string toString();
	~ContenedorProfesores();
	friend std::ostream& operator << (std::ostream&, ContenedorProfesores&);
};
#endif // !CONTENEDOR_PROFESORES
