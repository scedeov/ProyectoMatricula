#ifndef OBJETO_BASE
#define OBJETO_BASE

#include <string>
#include <sstream>
#include <iostream>

class T {
public:
	virtual std::string toString() const = 0;
	virtual bool eliminaEspecifico (int) = 0;
	virtual bool eliminaEspecifico (std::string) = 0;
	virtual void agregarInicio() = 0;
	virtual ~T() = 0;
};
//---------------------------------------------------
class contenedorEscuelas;
class adaptadorEscuelas: public T {
protected:
	contenedorEscuelas *Ce;
public:
	adaptadorEscuelas(contenedorEscuelas*);
	virtual bool eliminaEspecifico(std::string);
};
//---------------------------------------------------
class Contenedor_Cursos;
class adaptadorCursos: public T {
protected:
	Contenedor_Cursos *Cc;
public:
	adaptadorCursos(Contenedor_Cursos*);
	virtual bool eliminaEspecifico(std::string);
	virtual std::string toString();
};
std::ostream& operator <<(std::ostream&, const T&);
#endif // !OBJETO_BASE