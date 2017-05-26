#ifndef LISTA
#define LISTA

#include "nodo.h"

template <class TipoDato>

class Lista {
private:
	Nodo<TipoDato>* pinicio;
public:
	Lista();
	virtual void agregaInicio(TipoDato*);
	virtual int tamano();
	virtual bool eliminaTodos();
	~Lista();

};
#endif // !LISTA

template<class TipoDato>
Lista<TipoDato>::Lista() {
	pinicio = NULL;
}

template<class TipoDato>
inline void Lista<TipoDato>::agregaInicio(TipoDato* unDato) {
	TipoDato* dato = new TipoDato(*unDato);
	primerNodo = new Nodo<T>(primerNodo, *dato);
}

template<class TipoDato>
inline int Lista<TipoDato>::tamano()
{
	int contador = 0;
	while (pinicio != NULL) {
		contador++;
		pinicio = pinicio->getNext();
	}
	return contador;
}

template<class TipoDato>
Lista<TipoDato>::~Lista() {
	cout << "Eliminando Template..." << endl;
}
