#ifndef CONTENEDOR_ESCUELAS
#define CONTENEDOR_ESCUELAS

#include "lista.h"
#include "contenedor.h"

class Escuela;
class ContenedorEscuelas: public adaptadorContenedorEscuelas {
private:
	Lista<Escuela> *listaEscuelas;
public:
	ContenedorEscuelas();
	void agregarInicio (Escuela*);
	Escuela* retornaEscuela(std::string) const ;
	bool encuentraEscuela(Escuela*, std::string) const ;
	std::string toString(char) const;
	~ContenedorEscuelas();
};

#endif // !CONTENEDOR_ESCUELAS

