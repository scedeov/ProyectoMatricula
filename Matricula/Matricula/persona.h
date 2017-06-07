#ifndef PERSONA
#define PERSONA


#include "objetoBase.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Persona: public objetoBase {
protected:
	std::string nombre;
	std::string primerApellido;
	std::string segundoApellido;
	std::string nombreCompleto;
	std::string cedula;
	friend std::ostream& operator << (std::ostream&, Persona&);
public:
	Persona();
	virtual ~Persona();
	virtual std::string getNombreCompleto();
	virtual void setNombre(std::string);
	virtual std::string getNombre();
	virtual void setPrimerApellido(std::string);
	virtual void setSegundoApellido(std::string);
	virtual std::string getPrimerApellido();
	virtual std::string getSegundoApellido();
	virtual void setNumCedula(std::string);
	virtual std::string getNumCedula();
	virtual std::string toString();
};
#endif // !PERSONA
