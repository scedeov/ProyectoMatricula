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
	static int codigo;
public:
	Escuela();
	~Escuela();
	
	void setNombre(string);
	string getNombre();
	void setCodigoEscuela(string);
	string getCodigoEscuela();

	void generaCodigo(string);

	string toString();


};
#endif // !ESCUELA

