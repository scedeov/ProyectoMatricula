#ifndef UNIVERSIDAD
#define UNIVERSIDAD
#include <iostream>
#include <sstream>
#include <string>

#include "controladorEscuelas.h"
#include "controladorEstudiantes.h"
//class ControladorEscuelas;
//class ControladorEstudiantes;
class Universidad {
private:
	ControladorEscuelas *controladorEscuelas;
	ControladorEstudiantes *controladorEstudiantes;
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
	ControladorEscuelas* getControladorEscuelas();
	ControladorEstudiantes* getContenedorEstudiantes();
};
#endif // !UNIVERSIDAD

