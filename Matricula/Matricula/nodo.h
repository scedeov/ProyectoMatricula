#ifndef NODO
#define NODO

template <class TipoDato>
class Nodo {
public:
	inline Nodo(TipoDato& unDato, Nodo* unNext): 
		next(unNext), 
		dato(&unDato){}

	inline void setNext(Nodo* unNext) {
		next = unNext;
	}

	inline Nodo* getNext() {
		return next;
	}

	inline void setDato(TipoDato* unDato) {
		dato = unDato;
	}

	inline void linkNext(Nodo* n) {
		this->next = n->getNext();
	}

	inline TipoDato* getDato() {
		return dato;
	}
	inline ~Nodo() {}
private:
	TipoDato* dato;
	Nodo* next;
};
#endif // !NODO

