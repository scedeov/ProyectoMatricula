#ifndef PERSONA
#define PERSONA

#include <iostream>
#include <sstream>
using namespace std;

class Persona
{
private:
	string nombre;
	string primerApellido;
	string segundoApellido;
	string nombreCompleto;
	int numCedula;
	friend ostream& operator << (ostream&, Persona&);
public:
	Persona();
	virtual ~Persona();
	virtual string getNombreCompleto();
	virtual void setNombre(string);
	virtual string getNombre();
	virtual void setPrimerApellido(string);
	virtual void setSegundoApellido(string);
	virtual string getPrimerApellido();
	virtual string getSegundoApellido();
	virtual void setNumCedula(int);
	virtual int getNumCedula();
	virtual string toString();
};
#endif // !PERSONA
