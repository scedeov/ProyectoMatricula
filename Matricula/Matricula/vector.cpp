#include "vector.h"

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
	for (cantidad; cantidad != -1; cantidad--) {
		delete vector[cantidad];
	}
	delete[]vector;
}

template<class T>
inline T * Vector<T>::getDato(int pos)
{
	return vector[pos];
}

template<class T>
inline int Vector<T>::getCantidad()
{
	return cantidad;
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
inline void Vector<T>::push(T *dato)
{
	if (cantidad < capacidad)
		this->vector[++cantidad] = dato;
}

template<class T>
inline T* Vector<T>::pop()
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
