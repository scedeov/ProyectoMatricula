#ifndef LISTA
#define LISTA

#include "nodo.h"

template <class TipoDato>
class Lista {
private:
	Nodo<TipoDato> *pinicio;
	Nodo<TipoDato> *paux;
public:
	Lista();
	Lista(const Lista&);
	virtual Lista& operator = (const Lista&);
	//virtual Nodo<TipoDato>& operator [] (const int);
	virtual  Nodo<TipoDato>* begin();
	virtual TipoDato* front();
	virtual TipoDato* back();
	virtual Nodo<TipoDato>* end();
	virtual TipoDato* at(int);
	virtual void push_front(TipoDato*);
	virtual void push_back(TipoDato*);
	virtual TipoDato* pop_front();
	virtual bool empty();
	virtual int size();
	virtual void wipe();
	~Lista();
};

//class Curso; typedef Lista<Curso> ListaCursos;
//class Escuela; typedef Lista<Escuela> ListaEscuelas;
//class Estudiante; typedef Lista<Estudiante> ListaEstudiantes;
//class Profesor; typedef Lista<Profesor> ListaProfesores;

#endif // !LISTA


