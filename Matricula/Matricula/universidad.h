#ifndef UNIVERSIDAD
#define UNIVERSIDAD

#include <string>
//class ControladorEscuelas;
//class Contenedor_Estudiantes;
//
#include "lista.h"

class Universidad
{
private:
	Lista<Escuela> *ContE;
	Lista<Estudiante> *ContEst;
	std::string nombre;
	std::string numeroTelefono;
	std::string direccion;
	friend std::ostream& operator << (std::ostream&, Universidad&);
public:
	Universidad();
	Universidad(std::string, std::string, std::string);
	~Universidad();
	void setTelefono(std::string);
	void setDireccion(std::string);
	void setNombre(std::string);
	std::string getNombre();
	std::string getNumero();
	std::string getDireccion();
	std::string toString();
	ControladorEscuelas* getContenedorEscuelas();
	Contenedor_Estudiantes* getContenedorEstudiantes();
};
#endif // !UNIVERSIDAD

