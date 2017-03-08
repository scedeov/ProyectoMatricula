#ifndef UNIVERSIDAD
#define UNIVERSIDAD

#include <iostream>
#include <sstream>

using namespace std;

class Universidad
{
private:
	string nombre;
	string numeroTelefono;
	string direccion;
public:
	Universidad();
	Universidad(string, string, string);
	~Universidad();
	void setTelefono(string);
	void setDireccion(string);
	string getNombre();
	string getNumero();
	string getDireccion();

	string toString();


};
#endif // !UNIVERSIDAD

