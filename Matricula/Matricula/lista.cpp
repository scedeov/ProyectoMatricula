#include "lista.h"

template<class TipoDato>
Lista<TipoDato>::Lista() {
	pinicio = NULL;
	paux = NULL;
}

template<class TipoDato>
Lista<TipoDato>::Lista(const Lista &l) {
	paux = pinicio;
	Nodo<TipoDato>* cursor = l.paux;
	while (cursor != NULL) {
		push_front(cursor->getDato());
		cursor = cursor->getNext()
	}
}

template<class TipoDato>
Lista<TipoDato>& Lista<TipoDato>::operator = (const Lista &l) {
	if (this != &l) {
		if (pinicio != NULL) {
			wipe();
		}
		pinicio = NULL;
		Nodo<TipoDato>* cursor = l.pinicio;
		while (cursor != NULL) {
			push_front((cursor->getDato()));
			cursor = cursor->getNext();
		}
	}
	return *this;
}

template<class TipoDato>
Nodo<TipoDato>* Lista<TipoDato>::begin()
{
	return pinicio;
}

template<class TipoDato>
TipoDato* Lista<TipoDato>::front()
{
	return begin()->getDato();
}

template<class TipoDato>
TipoDato* Lista<TipoDato>::back()
{
	return end()->getDato();
}

template<class TipoDato>
Nodo<TipoDato>* Lista<TipoDato>::end() {
	paux = pinicio;
	while (paux->getNext() != NULL)
		paux = paux->getNext();
	return paux;
}

template<class TipoDato>
TipoDato * Lista<TipoDato>::at(int index)
{
	paux = pinicio;
	while (paux != NULL) {
		if (index == 0)
			return paux->getDato();
		for (int i = 0; i < index; i++)
			paux = paux->getNext();
	}
	return paux->getDato();
}

template<class TipoDato>
void Lista<TipoDato>::push_front(TipoDato *unDato) {
	TipoDato* dato = new TipoDato(*unDato);
	pinicio = new Nodo<TipoDato>(*dato, pinicio);
}

template<class TipoDato>
void Lista<TipoDato>::push_back(TipoDato *unDato)
{
	TipoDato* dato = new TipoDato(*unDato);
	if (empty())
		pinicio = new Nodo<TipoDato>(*dato, pinicio);
	else
		end()->setNext(new Nodo<TipoDato>(*unDato, NULL));
}

template<class TipoDato>
TipoDato * Lista<TipoDato>::pop_front() {
	if (!empty()) {
		Nodo<TipoDato>* actual = this->pinicio;
		TipoDato* dato = new TipoDato(*(pinicio->getDato()));
		pinicio = pinicio->getNext();
		delete actual;
		return dato;
	}
	return NULL;
}

template<class TipoDato>
bool Lista<TipoDato>::empty()
{
	if (pinicio == NULL)
		return true;
	return false;
}

template<class TipoDato>
int Lista<TipoDato>::size() {
	int contador = 0;
	paux = pinicio;
	while (paux != NULL) {
		contador++;
		paux = paux->getNext();
	}
	return contador;
}

template<class TipoDato>
void Lista<TipoDato>::wipe() {
	TipoDato* ptr;
	while (ptr = pop_front())
		delete ptr;
	pinicio = NULL;
}

template<class TipoDato>
Lista<TipoDato>::~Lista() {
	cout << "Eliminando Template..." << endl;
	wipe();
}
//// aqui se tienen que especializar las que se vayan a usar
//template class Lista<Curso>;
//template class Lista<Escuela>;
//template class Lista<Estudiante>;
//template class Lista<Profesor>;

