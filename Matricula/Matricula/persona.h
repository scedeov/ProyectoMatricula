#ifndef PERSONA
#define PERSONA

#include <iostream>
#include <sstream>
using namespace std;

class Persona
{
private:
	string nombre;
	string apellido;
	int numCedula;
	int numTelefono;

public:
	Persona();
	virtual ~Persona();
	virtual void setNombre(string);
	virtual string getNombre();
	virtual void setApellido(string);
	virtual string getApellido();
	virtual void setNumCedula(int);
	virtual int getNumCedula();
	virtual void setNumTelefono(int);
	virtual int getNumTelefono();
	friend ostream& operator << (ostream&, const Persona&); // No puede ser heredado, ve vos
};
#endif // !PERSONA
