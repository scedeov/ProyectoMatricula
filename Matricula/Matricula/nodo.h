#ifndef NODO
#define NODO

template <class TipoDato>

class Nodo {
private:
	TipoDato* dato;
	Nodo* next;
public:
	Nodo(TipoDato&, Nodo*);
	virtual void setNext(Nodo*);
	virtual Nodo* getNext() const;
	virtual void setDato(TipoDato*);
	virtual void linkNext(Nodo*);
	virtual TipoDato* getDato() const;
	virtual ~Nodo();
};
#endif // !NODO

template<class TipoDato>
Nodo<TipoDato>::Nodo(TipoDato& dato, Nodo* next) : next(next), dato(&dato) {}

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
inline void Nodo<TipoDato>::linkNext (Nodo *n)
{
	this->next = n->getNext();
}

template<class TipoDato>
TipoDato* Nodo<TipoDato>::getDato() const {
	return dato;
}

template<class TipoDato>
Nodo<TipoDato>::~Nodo()
{
}
