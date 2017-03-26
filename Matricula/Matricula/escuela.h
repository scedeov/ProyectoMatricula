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
	string siglaEscuela;
public:
	Escuela(string);
	~Escuela();
	
	void setNombre(string);
	string getNombre();
	void setSiglaEscuela(string);
	string getCodigoEscuela();

	string generaSigla(string);

	string toString();


};
#endif // !ESCUELA

