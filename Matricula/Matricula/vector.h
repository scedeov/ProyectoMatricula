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
	~Vector();
	int getCantidad();
	int getCapacidad();
	void setCapacidad(int);
	T* first();
	T* last();
	T* operator [] (int);
	void push(T*);
	void eliminaEspecifico(int);
	T* eliminaUltimo();

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
		void first() {
			this->cursor = 0;
		}
		int getPosActual(){
			return cursor;
		}
		void next() {
			this->cursor++;
		}
		T* getCurItem() {
			return ptr->vector[cursor];
		}
		//No estoy seguro sobre el destructor
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
inline T * Vector<T>::first()
{
	return vector[0];
}

template<class T>
inline T * Vector<T>::last()
{
	return vector[cantidad];
}

template<class T>
inline T * Vector<T>::operator[](int pos)
{
	return vector[pos];
}

template<class T>
inline void Vector<T>::push(T *dato)
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
