#ifndef CONTENEDOR_PERSONAS
#define CONTENEDOR_PERSONAS	

#include "contenedor.h"
#include "lista.h"

class Persona;
class ContenedorPersonas: public adaptadorContenedorPersonas {
private:
	Lista<Persona> *personas;
public:
	ContenedorPersonas();
	int getCantidad();
	void agregarInicio(Persona*);
	Persona* getPersona(int);
	std::string toString();
	~ContenedorPersonas();
	friend std::ostream& operator << (std::ostream&, ContenedorPersonas&);
};
#endif // !CONTENEDOR_PERSONAS

