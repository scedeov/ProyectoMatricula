#ifndef LISTA
#define LISTA

#include "contenedor.h"
#include "nodo.h"
#include <string>
#include <sstream>

class Lista: public Contenedor {
private:
	Nodo *pinicio;
	Nodo *paux;
public:
	Lista();
	Lista(const Lista&);
	virtual Lista& operator = (const Lista&);
	virtual  Nodo* getPrimerNodo();
	virtual objetoBase* getPrimerDato();
	virtual objetoBase* getUltimoDato();
	virtual Nodo* end();
	virtual objetoBase* at(int);
	virtual void agregarInicio(objetoBase*);
	virtual void agregarFinal(objetoBase*);
	virtual objetoBase* eliminarInicio();
	virtual bool estaVacia();
	virtual int getCantidad();
	virtual void limpiar();
	virtual std::string toString() const;
	virtual ~Lista();
};
#endif // !LISTA

inline Lista::Lista() {
	pinicio = NULL;
	paux = NULL;
}

inline Lista::Lista(const Lista &l) {
	paux = pinicio;
	Nodo* cursor = l.paux;
	while (cursor != NULL) {
		agregarInicio(cursor->getDato());
		cursor = cursor->getNext();
	}
}

inline Lista& Lista::operator = (const Lista &l) {
	if (this != &l) {
		if (pinicio != NULL) {
			limpiar();
		}
		pinicio = NULL;
		Nodo* cursor = l.pinicio;
		while (cursor != NULL) {
			agregarInicio((cursor->getDato()));
			cursor = cursor->getNext();
		}
	}
	return *this;
}

inline Nodo* Lista::getPrimerNodo() {
	return pinicio;
}

inline objetoBase* Lista::getPrimerDato() {
	return getPrimerNodo()->getDato();
}

inline objetoBase* Lista::getUltimoDato() {
	return end()->getDato();
}

inline Nodo* Lista::end() {
	paux = pinicio;
	while (paux->getNext() != NULL)
		paux = paux->getNext();
	return paux;
}

inline objetoBase* Lista::at(int index) {
	paux = pinicio;
	while (paux != NULL) {
		if (index == 0)
			return paux->getDato();
		for (int i = 0; i < index; i++)
			paux = paux->getNext();
	}
	return paux->getDato();
}

inline void Lista::agregarInicio(objetoBase *unDato) {
	pinicio = new Nodo(*unDato, pinicio);
}

inline void Lista::agregarFinal(objetoBase *unDato) {
	if (estaVacia())
		pinicio = new Nodo(*unDato, pinicio);
	else
		end()->setNext(new Nodo(*unDato, NULL));
}

inline objetoBase * Lista::eliminarInicio() {
	if (!estaVacia()) {
		Nodo* actual = this->pinicio;
		objetoBase *dato = NULL;
		dato = pinicio->getDato();
		pinicio = pinicio->getNext();
		delete actual;
		return dato;
	}
	return NULL;
}

inline bool Lista::estaVacia()
{
	if (pinicio == NULL)
		return true;
	return false;
}

inline int Lista::getCantidad() {
	int contador = 0;
	paux = pinicio;
	while (paux != NULL) {
		contador++;
		paux = paux->getNext();
	}
	return contador;
}

inline void Lista::limpiar() {
	objetoBase* ptr;
	while (ptr = eliminarInicio())
		delete ptr;
	pinicio = NULL;
}

inline std::string Lista::toString() const {
	std::stringstream s;
	Nodo* aux = pinicio;
	if (pinicio != NULL) {
		aux = pinicio;
		while (paux != NULL) {
			s << *(paux->getDato()) << endl;
			aux = paux->getNext();
		}
	}
	return s.str();
}

inline Lista::~Lista() {
	cout << "Eliminando Lista..." << endl;
	limpiar();
}
