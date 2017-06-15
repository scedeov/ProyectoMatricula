#ifndef LISTA
#define LISTA

#include "nodo.h"

template <class TipoDato>
class Lista {
private:
	Nodo<TipoDato> *pinicio;
	Nodo<TipoDato> *paux;
public:
	inline Lista() {
		pinicio = nullptr;
		paux = nullptr;
	}

	inline Lista(const Lista& l) {
		paux = pinicio;
		Nodo<TipoDato>* cursor = l.paux;
		while (cursor != nullptr) {
			push_front(cursor->getDato());
			cursor = cursor->getNext()
		}
	}

	inline Lista& operator = (const Lista& l) {
		if (this != &l) {
			if (pinicio != nullptr) {
				wipe();
			}
			pinicio = nullptr;
			Nodo<TipoDato>* cursor = l.pinicio;
			while (cursor != nullptr) {
				push_front((cursor->getDato()));
				cursor = cursor->getNext();
			}
		}
		return *this;
	}

	inline Nodo<TipoDato>* begin() {
		return pinicio;
	}

	inline TipoDato* front() {
		return begin()->getDato();
	}

	inline TipoDato* back() {
		return end()->getDato();
	}

	inline Nodo<TipoDato>* end() {
		paux = pinicio;
		while (paux->getNext() != nullptr)
			paux = paux->getNext();
		return paux;
	}

	inline TipoDato* at(int index) {
		paux = pinicio;
		while (paux != nullptr) {
			if (index == 0)
				return paux->getDato();
			for (int i = 0; i < index; i++)
				paux = paux->getNext();
		}
		return paux->getDato();
	}

	inline void push_front(TipoDato* unDato) {
		TipoDato* dato = new TipoDato(*unDato);
		pinicio = new Nodo<TipoDato>(*dato, pinicio);
	}

	inline void push_back(TipoDato* unDato) {
		TipoDato* dato = new TipoDato(*unDato);
		if (empty())
			pinicio = new Nodo<TipoDato>(*dato, pinicio);
		else
			end()->setNext(new Nodo<TipoDato>(*unDato, nullptr));
	}

	inline TipoDato* pop_front() {
		if (!empty()) {
			Nodo<TipoDato>* actual = this->pinicio;
			TipoDato* dato = new TipoDato(*(pinicio->getDato()));
			pinicio = pinicio->getNext();
			delete actual;
			return dato;
		}
		return nullptr;
	}

	inline bool empty() {

		if (pinicio == nullptr)
			return true;
		return false;
	}

	inline int size() {
		int contador = 0;
		paux = pinicio;
		while (paux != nullptr) {
			contador++;
			paux = paux->getNext();
		}
		return contador;
	}

	inline void wipe() {
		TipoDato* ptr;
		while (ptr = pop_front())
			delete ptr;
		pinicio = nullptr;
	}

	inline ~Lista() {
		cout << "Eliminando Template..." << endl;
		wipe();
	}
};
#endif // !LISTA


