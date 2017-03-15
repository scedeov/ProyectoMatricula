#ifndef ESCUELA
#define ESCUELA

#include <iostream>
#include <sstream>

using namespace std;

class Escuela
{
private:
	string nombre;
	string codigoEscuela;
public:
	Escuela();
	~Escuela();
	
	void setNombre(string);
	string getNombre();
	void setCodigoEscuela(string);
	string getCodigoEscuela();

	string toString();


};
#endif // !ESCUELA

