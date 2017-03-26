#ifndef ESCUELA
#define ESCUELA

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Escuela
{
private:
	string nombreEscuela;
	string codigoEscuela;
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

