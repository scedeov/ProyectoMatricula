#ifndef VECTOR
#define VECTOR


template <class T>
class Vector {
private:
	T** vector;
	int cantidad;
	int capacidad;
public:
	Vector(int);
	virtual ~Vector();
	virtual int getCantidad();
	virtual int getCapacidad();
	virtual void setCapacidad(int);
	virtual T* getPrimerObjeto();
	virtual T* getUltimoObjeto();
	T* operator [] (int);
	virtual void agregar(T*);
	virtual void eliminaEspecifico(int);
	virtual T* eliminaUltimo();

	class Iterador;
	friend class Iterador;
	class Iterador {
	private:
		Vector *ptr;
		int cursor;
	public:
		Iterador(Vector* ptr) {
			this->ptr = ptr;
		}
		void posicionaPrimerObjeto() {
			this->cursor = 0;
		}
		int getPosicionActual(){
			return cursor;
		}
		void posicionaSiguiente() {
			this->cursor++;
		}
		T* getObjectoCursorActual() {
			return ptr->vector[cursor];
		}
	};
};
#endif // !VECTOR

template<class T>
inline Vector<T>::Vector(int xCapacidad)
{
	vector = new T*[xCapacidad];
	this->cantidad = -1;
	this->capacidad = xCapacidad;
	for (int i = 0; i < capacidad; i++)
		vector[i] = nullptr;
}

template<class T>
inline Vector<T>::~Vector()
{
	cout << "Eliminando Vector..." << endl;
	for (cantidad; cantidad != -1; cantidad--) {
		delete vector[cantidad];
	}
	delete[]vector;
}

template<class T>
inline int Vector<T>::getCantidad()
{
	return cantidad + 1;
}

template<class T>
inline int Vector<T>::getCapacidad()
{
	return capacidad;
}

template<class T>
inline void Vector<T>::setCapacidad(int x)
{
	capacidad = x;
}

template<class T>
inline T * Vector<T>::getPrimerObjeto()
{
	return vector[0];
}

template<class T>
inline T * Vector<T>::getUltimoObjeto()
{
	return vector[cantidad];
}

template<class T>
inline T * Vector<T>::operator[](int pos)
{
	return vector[pos];
}

template<class T>
inline void Vector<T>::agregar(T *dato)
{
	if (cantidad < capacidad)
		this->vector[++cantidad] = dato;
}

template<class T>
inline void Vector<T>::eliminaEspecifico(int pos)
{
	for (int i = pos; i < cantidad - 1; i++)
		vector[i] = vector[i + 1];
	cantidad--;
}

template<class T>
inline T* Vector<T>::eliminaUltimo()
{
	T* aux;
	if (vector[cantidad] != NULL) {
		aux = vec[cantidad];
		vec[cantidad] = NULL;
		cantidad--;
		return aux;
	}
	else
		return NULL;
}
