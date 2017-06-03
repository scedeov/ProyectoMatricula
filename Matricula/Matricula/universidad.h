#ifndef UNIVERSIDAD
#define UNIVERSIDAD

#include <string>

class Universidad {
private:
	std::string nombre;
	std::string numeroTelefono;
	std::string direccion;
public:
	Universidad(std::string, std::string, std::string);
	void setTelefono(std::string);
	void setDireccion(std::string);
	void setNombre(std::string);
	std::string getNombre();
	std::string getNumero();
	std::string getDireccion();
	std::string toString();
	friend std::ostream& operator << (std::ostream&, Universidad&);
	~Universidad();
};
#endif // !UNIVERSIDAD

