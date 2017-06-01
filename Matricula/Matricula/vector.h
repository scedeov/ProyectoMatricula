#ifndef VECTOR
#define VECTOR

template<class T>
class Vector{
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
	T* getPrimerDato();
	T* getUltimoDato();
	T* operator [] (int);
	virtual void agregarInicio(const T*);
	virtual bool eliminaPosicion(int);
	virtual bool eliminaEspecifico(int);
	virtual bool eliminaEspecifico(std::string);
	 T* eliminaUltimo();
	 void limpiar();

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
	std::cout << "Eliminando Vector..." << std::endl;
	limpiar();
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
inline void Vector<T>::setCapacidad(int x) {
	capacidad = x;
}

template<class T>
inline T * Vector<T>::getPrimerDato()
{
	return vector[0];
}

template<class T>
inline T * Vector<T>::getUltimoDato()
{
	return vector[cantidad];
}

template<class T>
inline T * Vector<T>::operator[](int pos)
{
	return vector[pos];
}

template<class T>
inline void Vector<T>::agregarInicio(const T *dato) {
	if (cantidad < capacidad)
		this->vector[++cantidad] = dato;
}

template<class T>
inline bool Vector<T>::eliminaPosicion(int pos)
{
	for (int i = pos; i < cantidad - 1; i++)
		vector[i] = vector[i + 1];
	cantidad--;
}

template<class T>
inline bool Vector<T>::eliminaEspecifico(int cedula)
{/*
	for (int i = 0; i < cantidad; i++)
		if (dynamic_cast<typeidT*>(ptr->)-> == cedula) {
			for (int x = i; x < cantidadProfesores; x++)
				profesores[x] = profesores[i + 1];
			cantidadProfesores--;*/
	return false;
}

template<class T>
inline bool Vector<T>::eliminaEspecifico(std::string s)
{
	return false;
}

template<class T>
inline T* Vector<T>::eliminaUltimo() {
	T* aux;
	if (vector[cantidad] != NULL) {
		aux = vector[cantidad];
		vector[cantidad] = NULL;
		cantidad--;
		return aux;
	}
	else
		return NULL;
}

template<class T>
inline void Vector<T>::limpiar() {
	for (cantidad; cantidad != -1; cantidad--) {
		delete vector[cantidad];
	}
	delete[]vector;
}
