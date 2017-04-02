#ifndef CONTENEDOR_ESCUELAS
#define CONTENEDOR_ESCUELAS

#include "nodoEscuelas.h" 

class Contenedor_Escuelas
{
private:
	Nodo_Escuelas* pinicio;
	Nodo_Escuelas* paux;
	/*friend ostream& operator << (ostream&, const Contenedor_Escuelas&);*/
public:
	Contenedor_Escuelas();

	void insertaralInicio(Escuela*);
	Escuela* retornaEscuelaEspecifica(string);
	bool encuentraEscuela(string);

	string toString(char);

	~Contenedor_Escuelas();
};

#endif // !CONTENEDOR_ESCUELAS

