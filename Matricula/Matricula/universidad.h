#ifndef UNIVERSIDAD
#define UNIVERSIDAD

#include <string>
#include "lista.h"
#include "vector.h"

class ContenedorEscuelas;
class ContenedorPersonas;

class Universidad {
private:
	ContenedorEscuelas* escuelas;
	ContenedorPersonas* personas;
	//---------------------------------------
	std::string nombre;
	std::string numeroTelefono;
	std::string direccion;
	//---------------------------------------
	friend std::ostream& operator << (std::ostream&, Universidad&);
public:
	Universidad(std::string, std::string, std::string);
	void setTelefono(std::string);
	void setDireccion(std::string);
	void setNombre(std::string);
	std::string getNombre();
	std::string getNumero();
	std::string getDireccion();
	std::string toString();
	ContenedorEscuelas* getContenedorEscuelas();
	ContenedorPersonas* getContenedorPersonas();
	~Universidad();
};
#endif // !UNIVERSIDAD

