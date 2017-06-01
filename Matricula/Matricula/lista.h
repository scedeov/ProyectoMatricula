#ifndef LISTA
#define LISTA

#include "nodo.h"
#include <string>
#include <sstream>

template<class T>
class Lista {
private:
	Nodo<T> *pinicio;
	Nodo<T> *paux;
public:
	Lista();
	Lista(const Lista&);
	virtual Lista& operator = (const Lista&);
	virtual  Nodo<T>* getPrimerNodo();
	virtual T* getPrimerDato();
	virtual T* getUltimoDato();
	virtual Nodo<T>* getUltimoNodo();
	virtual T* at(int);
	virtual void agregarInicio(const T*);
	virtual bool eliminaEspecifico(string);
	virtual bool eliminaEspecifico(int);
	virtual void agregarFinal(T*);
	virtual T* eliminarInicio();
	virtual bool estaVacia();
	virtual int getCantidad();
	virtual void limpiar();
	virtual std::string toString() const;
	virtual ~Lista();
};
#endif // !LISTA

inline Lista<T>::Lista() {
	pinicio = NULL;
	paux = NULL;
}

inline Lista<T>::Lista(const Lista &l) {
	paux = pinicio;
	Nodo<T>* cursor = l.paux;
	while (cursor != NULL) {
		agregarInicio(cursor->getDato());
		cursor = cursor->getNext();
	}
}

inline Lista<T>& Lista<T>::operator = (const Lista &l) {
	if (this != &l) {
		if (pinicio != NULL) {
			limpiar();
		}
		pinicio = NULL;
		Nodo<T>* cursor = l.pinicio;
		while (cursor != NULL) {
			agregarInicio((cursor->getDato()));
			cursor = cursor->getNext();
		}
	}
	return *this;
}

inline Nodo<T>* Lista<T>::getPrimerNodo() {
	return pinicio;
}

inline T* Lista<T>::getPrimerDato() {
	return getPrimerNodo()->getDato();
}

inline T* Lista<T>::getUltimoDato() {
	return getUltimoNodo()->getDato();
}

inline Nodo<T>* Lista<T>::getUltimoNodo() {
	paux = pinicio;
	while (paux->getNext() != NULL)
		paux = paux->getNext();
	return paux;
}

inline T* Lista<T>::at(int index) {
	paux = pinicio;
	while (paux != NULL) {
		if (index == 0)
			return paux->getDato();
		for (int i = 0; i < index; i++)
			paux = paux->getNext();
	}
	return paux->getDato();
}

inline void Lista<T>::agregarInicio(const T *unDato) {
	pinicio = new Nodo<T>(*unDato, pinicio);
}

inline bool Lista<T>::eliminaEspecifico(string s)
{
	return false;
}

inline bool Lista<T>::eliminaEspecifico(int)
{
	return false;
}

inline void Lista<T>::agregarFinal(T *unDato) {
	if (estaVacia())
		pinicio = new Nodo<T>(*unDato, pinicio);
	else
		getUltimoNodo()->setNext(new Nodo<T>(*unDato, NULL));
}

inline T * Lista<T>::eliminarInicio() {
	if (!estaVacia()) {
		Nodo<T>* actual = this->pinicio;
		T *dato = NULL;
		dato = pinicio->getDato();
		pinicio = pinicio->getNext();
		delete actual;
		return dato;
	}
	return NULL;
}

inline bool Lista<T>::estaVacia()
{
	if (pinicio == NULL)
		return true;
	return false;
}

inline int Lista<T>::getCantidad() {
	int contador = 0;
	paux = pinicio;
	while (paux != NULL) {
		contador++;
		paux = paux->getNext();
	}
	return contador;
}

inline void Lista<T>::limpiar() {
	T* ptr;
	while (ptr = eliminarInicio())
		delete ptr;
	pinicio = NULL;
}

inline std::string Lista<T>::toString() const {
	std::stringstream s;
	Nodo<T>* aux = pinicio;
	if (pinicio != NULL) {
		aux = pinicio;
		while (paux != NULL) {
			s << *(paux->getDato()) << endl;
			aux = paux->getNext();
		}
	}
	return s.str();
}

inline Lista<T>::~Lista() {
	cout << "Eliminando Lista..." << endl;
	limpiar();
}
