#ifndef UNIVERSIDAD
#define UNIVERSIDAD

#include <iostream>
#include <sstream>
#include "contenedorEscuelas.h"
using namespace std;

class Universidad
{
private:
	Contenedor_Escuelas* ContE;
	string nombre;
	string numeroTelefono;
	string direccion;
	friend ostream& operator << (ostream&, Universidad&);
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
	string toString();
	Contenedor_Escuelas* getContenedorEscuelas();
};
#endif // !UNIVERSIDAD

