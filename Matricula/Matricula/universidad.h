#ifndef UNIVERSIDAD
#define UNIVERSIDAD

#include <iostream>
#include <sstream>

using namespace std;

#include "contenedorEscuelas.h"

class Universidad
{
private:
	string nombre;
	string numeroTelefono;
	string direccion;
	int a;
	Contenedor_Escuelas* CE;

public:
	Universidad();
	Universidad(string, string, string);
	~Universidad();
	void setTelefono(string);
	void setDireccion(string);
	void setNombre(string);
	string getNombre();
	string getNumero();
	string getDireccion();
	Contenedor_Escuelas* getContenedorEscuelas();
	Curso* retornaCurso(string);
	Escuela* retornaEscuela(string);
	void insertarEscuela(Escuela*);
	void insertarCurso(string, Curso*);
	string toString();
	friend ostream& operator << (ostream&, Universidad&);
};
#endif // !UNIVERSIDAD

