#ifndef UNIVERSIDAD
#define UNIVERSIDAD

#include <string>
class Contenedor_Escuelas;
class Contenedor_Estudiantes;


class Universidad
{
private:
	Contenedor_Escuelas* ContE;
	Contenedor_Estudiantes* ContEst;
	std::string nombre;
	std::string numeroTelefono;
	std::string direccion;
	friend std::ostream& operator << (std::ostream&, Universidad&);
public:
	Universidad(std::string, std::string, std::string);
	~Universidad();
	void setTelefono(std::string);
	void setDireccion(std::string);
	void setNombre(std::string);
	std::string getNombre();
	std::string getNumero();
	std::string getDireccion();
	std::string toString();
	Contenedor_Escuelas* getContenedorEscuelas();
	Contenedor_Estudiantes* getContenedorEstudiantes();
};
#endif // !UNIVERSIDAD

