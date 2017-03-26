#ifndef CONTENEDOR_ESCUELAS
#define CONTENEDOR_ESCUELAS

#include "nodoEscuelas.h" 

class Contenedor_Escuelas
{
private:
	Nodo_Escuelas* pinicio;
	Nodo_Escuelas* paux;

public:
	Contenedor_Escuelas();

	void insertaralInicio(Escuela*);
	string toString(char);

	~Contenedor_Escuelas();
};

#endif // !CONTENEDOR_ESCUELAS

