#ifndef LISTA
#define LISTA


#include "nodo.h"
#include <string>
#include <sstream>

template <class TipoDato>
class Lista {
private:
	Nodo<TipoDato> *pinicio;
public:
	Lista();
	Lista(const Lista&);
	virtual Lista& operator = (const Lista&);
	virtual void agregaInicio(TipoDato&);
	virtual int tamano();
	virtual TipoDato* eliminar();
	virtual bool eliminaTodos();
	virtual std::string toString();
	~Lista();
};
#endif // !LISTA


template<class TipoDato>
inline Lista<TipoDato>::Lista() {
	pinicio = NULL;
}

template<class TipoDato>
inline Lista<TipoDato>::Lista(const Lista &l) {
	pinicio = NULL;
	Nodo<T>* cursor = l.pinicio;
	while (cursor != NULL) {
		agregaInicio(*(cursor->getDato());
		cursor = cursor->getNext()
	}
}

template<class TipoDato>
inline Lista<TipoDato>& Lista<TipoDato>::operator = (const Lista &l)
{
	if (this != &l) {
		if (pinicio != NULL) {
			eliminaTodos();
		}
		pinicio = NULL;
		Nodo<TipoDato>* cursor = l.pinicio;
		while (cursor != NULL) {
			agregaInicio((cursor->getDato()); // averiguar xq quito el asterisco
			cursor = cursor->getNext();
		}
	}
	return *this;
}

template<class TipoDato>
inline void Lista<TipoDato>::agregaInicio(TipoDato& unDato) {
	TipoDato* dato = new TipoDato(*unDato);
	primerNodo = new Nodo<T>(primerNodo, *dato);
}

template<class TipoDato>
inline int Lista<TipoDato>::tamano() {
	int contador = 0;
	while (pinicio != NULL) {
		contador++;
		pinicio = pinicio->getNext();
	}
	return contador;
}

template<class TipoDato>
inline TipoDato * Lista<TipoDato>::eliminar() {
	if (pinicio != NULL) {
		Nodo<TipoDato>* actual = this->pinicio;
		TipoDato* dato = new TipoDato (*(pinicio->getDato()));
		pinicio = pinicio->getNext();
		delete actual;
		return dato;
	}
	return NULL;
}

template<class TipoDato>
inline bool Lista<TipoDato>::eliminaTodos() {
	TipoDato* ptr;
	while (ptr = eliminar())
		delete ptr;
	pinicio = NULL;
}

template<class TipoDato>
inline std::string Lista<TipoDato>::toString() {
	std::stringstream s;
	if (pinicio != NULL) {
		Nodo<T>* paux = pinicio;
		while (paux != NULL) {
			s << *(paux->getDato()) << endl;
			paux = paux->getNext();
		}
	}
	return s.str();
}

template<class TipoDato>
inline Lista<TipoDato>::~Lista() {
	cout << "Eliminando Template..." << endl;
	eliminaTodos();
}
