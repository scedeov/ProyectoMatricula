#ifndef NODO
#define NODO

#include "objetoBase.h"

class Nodo {
private:
	objetoBase* dato;
	Nodo* next;
public:
	Nodo(objetoBase&, Nodo*);
	virtual void setNext(Nodo*);
	virtual Nodo* getNext() const;
	virtual void setDato(objetoBase*);
	virtual void linkNext(Nodo*);
	virtual objetoBase* getDato() const;
	virtual ~Nodo();
};
#endif // !NODO

inline Nodo::Nodo(objetoBase& dato, Nodo* next) : next(next), dato(&dato) {
}

inline void Nodo::setNext(Nodo* unNext) {
	next = unNext;
}

inline Nodo* Nodo::getNext() const {
	return next;
}

inline void Nodo::setDato(objetoBase* unDato) {
	dato = unDato;
}

inline void Nodo::linkNext (Nodo *n)
{
	this->next = n->getNext();
}

objetoBase* Nodo::getDato() const {
	return dato;
}

inline Nodo::~Nodo()
{
	cout << "Eliminando Nodo..." << endl;
}
