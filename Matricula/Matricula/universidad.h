#ifndef UNIVERSIDAD
#define UNIVERSIDAD

#include <iostream>
#include <sstream>

using namespace std;

#include "contenedorEscuelas.h"
#include "contenedorEstudiantes.h"

class Universidad
{
private:
	string nombre;
	string numeroTelefono;
	string direccion;
	Contenedor_Escuelas* CE;
	Contenedor_Estudiantes* CEs;
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
	Contenedor_Escuelas* getContenedorEscuelas();
	Curso* retornaCurso(string);
	Escuela* retornaEscuela(string);
	Profesor* retornaProfesor(int);
	void insertarEscuela(Escuela*);
	void insertarCurso(string, Curso*);
	void insertarProfesor(string, Profesor*);
	string toString();
	Contenedor_Profesores* retornaContenedorProfes(string);
};
#endif // !UNIVERSIDAD

