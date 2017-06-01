#ifndef UNIVERSIDAD
#define UNIVERSIDAD

#include <string>
class contenedorEscuelas;
class contenedorEstudiantes;
class contenedorProfesores;


class Universidad {
private:
	contenedorEscuelas* escuelas;
	contenedorEstudiantes* estudiantes;
	contenedorProfesores* profesores;
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
	contenedorEscuelas* getContenedorEscuelas();
	contenedorEstudiantes* getContenedorEstudiantes();
	contenedorProfesores* getContenedorProfesores();
	~Universidad();
};
#endif // !UNIVERSIDAD

