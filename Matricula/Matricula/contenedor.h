#ifndef CONTENEDOR
#define CONTENEDOR

#include <string>
#include "lista.h"
#include "vector.h"

template<class T>
class Contenedor {
	virtual T* getDato(std::string) = 0;
	virtual T* getDato(int) = 0;
	virtual void agregarInicio(T*) = 0;
	virtual int getCantidad() = 0;
	virtual std::string toString() = 0;
};

class ContenedorEscuelas;
class Escuela;
class adaptadorContenedorEscuelas : public Contenedor<Escuela> {
private:
	ContenedorEscuelas* contenedorEscuelas;
public:
	adaptadorContenedorEscuelas(ContenedorEscuelas*);
	virtual Escuela* getDato(std::string);
	virtual void agregarInicio(Escuela*);
	virtual int getCantidad() = 0;
	virtual std::string toString() = 0;
	virtual ~adaptadorContenedorEscuelas() = 0;
};

class ContenedorCursos;
class Curso;
class adaptadorContenedorCursos : public Contenedor<Curso> {
private:
	ContenedorCursos* contenedorCursos;
public:
	adaptadorContenedorCursos(ContenedorCursos*);
	virtual Curso* getDato(std::string);
	virtual void agregarInicio(Curso*);
	virtual int getCantidad() = 0;
	virtual std::string toString() = 0;
	virtual ~adaptadorContenedorCursos() = 0;
};

class ContenedorPersonas;
class Persona;
class adaptadorContenedorPersonas : public Contenedor<Persona> {
private:
	ContenedorPersonas* contenedorPersonas;
public:
	adaptadorContenedorPersonas(ContenedorPersonas*);
	virtual Persona* getDato(int);
	virtual void agregarInicio(Persona*);
	virtual int getCantidad() = 0;
	virtual std::string toString() = 0;
	virtual ~adaptadorContenedorPersonas() = 0;
};
#endif
