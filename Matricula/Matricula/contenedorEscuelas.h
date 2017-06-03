#ifndef CONTENEDOR_ESCUELAS
#define CONTENEDOR_ESCUELAS

#include "contenedor.h"

class Escuela;
class ContenedorEscuelas {
private:
	Lista<Escuela> *listaEscuelas;
public:
	ContenedorEscuelas();
	int getCantidad();
	void agregarInicio (Escuela*);
	Escuela* retornaEscuela(std::string) const ;
	bool encuentraEscuela(Escuela*, std::string) const ;
	std::string toString(/*char*/)/* const*/;
	~ContenedorEscuelas();
};

#endif // !CONTENEDOR_ESCUELAS

