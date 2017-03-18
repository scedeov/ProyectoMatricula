#ifndef ESCUELA
#define ESCUELA

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Escuela
{
private:
	string nombre;
	string codigoEscuela;
	string nombreU;
	static int codigo;
public:
	Escuela(string);
	~Escuela();
	
	void setNombre(string);
	string getNombre();
	void setCodigoEscuela(string);
	string getCodigoEscuela();

	string generaCodigo(string);

	string toString();


};
#endif // !ESCUELA

