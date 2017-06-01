#ifndef NODO
#define NODO

template<class T>
class Nodo {
private:
	T* dato;
	Nodo<T>* next;
public:
	Nodo(T&, Nodo*);
	virtual void setNext(Nodo<T>*);
	virtual Nodo<T>* getNext() const;
	virtual void setDato(T*);
	virtual void linkNext(Nodo<T>*);
	virtual T* getDato() const;
	virtual ~Nodo();
};
#endif // !NODO

template<class T>
inline Nodo<T>::Nodo(T& dato, Nodo<T>* next) : next(next), dato(&dato) {
}

template<class T>
inline void Nodo<T>::setNext(Nodo<T>* unNext) {
	next = unNext;
}

template<class T>
inline Nodo<T>* Nodo<T>::getNext() const {
	return next;
}

template<class T>
inline void Nodo<T>::setDato(T* unDato) {
	dato = unDato;
}

template<class T>
inline void Nodo<T>::linkNext (Nodo<T> *n)
{
	this->next = n->getNext();
}

template<class T>
T* Nodo<T>::getDato() const {
	return dato;
}

template<class T>
inline Nodo<T>::~Nodo()
{
	cout << "Eliminando Nodo..." << endl;
}
