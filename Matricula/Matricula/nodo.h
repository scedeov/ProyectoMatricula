#ifndef NODO
#define NODO

template <class TipoDato>

class Nodo {
private:
	Nodo* next;
	TipoDato* dato;
public:
	Nodo(Nodo*, TipoDato*);
	virtual void setNext(Nodo*);
	virtual Nodo* getNext() const;
	virtual void setDato(TipoDato*);
	virtual TipoDato* getDato() const;
	virtual ~Nodo();
};
#endif // !NODO

template<class TipoDato>
Nodo<TipoDato>::Nodo(Nodo* unNodo, TipoDato* unDato) {
	next = unNodo;
	dato = unDato;
}

template<class TipoDato>
void Nodo<TipoDato>::setNext(Nodo* unNext) {
	next = unNext;
}

template<class TipoDato>
Nodo<TipoDato>* Nodo<TipoDato>::getNext() const {
	return next;
}

template<class TipoDato>
void Nodo<TipoDato>::setDato(TipoDato* unDato) {
	dato = unDato;
}

template<class TipoDato>
TipoDato * Nodo<TipoDato>::getDato() const {
	return dato;
}

template<class TipoDato>
Nodo<TipoDato>::~Nodo()
{
}
