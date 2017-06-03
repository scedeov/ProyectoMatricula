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
	virtual std::string toString() = 0;
};

class ContenedorEscuelas;
class Escuela;
class adaptadorContenedorEscuelas : public Contenedor<Escuela> {
private:
	ContenedorEscuelas* contenedorEscuelas;
public:
	adaptadorContenedorEscuelas();
	adaptadorContenedorEscuelas(ContenedorEscuelas*);
	Escuela* getDato(std::string);
	Escuela* getDato(int);
	void agregarInicio(Escuela*);
	std::string toString();
};

class ContenedorCursos;
class Curso;
class adaptadorContenedorCursos : public Contenedor<Curso> {
private:
	ContenedorCursos* contenedorCursos;
public:
	adaptadorContenedorCursos();
	adaptadorContenedorCursos(ContenedorCursos*);
	virtual Curso* getDato(std::string);
	virtual void agregarInicio(Curso*);
};

class ContenedorPersonas;
class Persona;
class adaptadorContenedorPersonas : public Contenedor<Persona> {
private:
	ContenedorPersonas* contenedorPersonas;
public:
	adaptadorContenedorPersonas();
	adaptadorContenedorPersonas(ContenedorPersonas*);
	virtual Persona* getDato(int);
	virtual void agregarInicio(Persona*);
	virtual int getCantidad() = 0;
	virtual std::string toString() = 0;
};

class GrupoCurso;
class ContenedorGrupoCurso;
class adaptadorContenedorGrupoCurso : public Contenedor<GrupoCurso> {
private:
	ContenedorGrupoCurso* contenedorGrupoCurso;
public:
	adaptadorContenedorGrupoCurso();
	adaptadorContenedorGrupoCurso(ContenedorGrupoCurso*);
	virtual GrupoCurso* getDato(int);
};
#endif
