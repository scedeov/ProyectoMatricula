#ifndef VECTOR
#define VECTOR

#include "contenedor.h"
#include "objetoBase.h"

class Vector {
private:
	objetoBase** vector;
	int cantidad;
	int capacidad;
public:
	Vector(int);
	~Vector();
	int getCantidad();
	int getCapacidad();
	void setCapacidad(int);
	objetoBase* getPrimerDato();
	objetoBase* getUltimoDato();
	objetoBase* operator [] (int);
	void agregarInicio(objetoBase*);
	void eliminaEspecifico(int);
	 objetoBase* eliminaUltimo();
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
		objetoBase* getObjectoCursorActual() {
			return ptr->vector[cursor];
		}
	};
};
#endif // !VECTOR

inline Vector::Vector(int xCapacidad)
{
	vector = new objetoBase*[xCapacidad];
	this->cantidad = -1;
	this->capacidad = xCapacidad;
	for (int i = 0; i < capacidad; i++)
		vector[i] = nullptr;
}

inline Vector::~Vector()
{
	std::cout << "Eliminando Vector..." << std::endl;
	limpiar();
}

inline int Vector::getCantidad()
{
	return cantidad + 1;
}

inline int Vector::getCapacidad()
{
	return capacidad;
}

inline void Vector::setCapacidad(int x) {
	capacidad = x;
}

inline objetoBase * Vector::getPrimerDato()
{
	return vector[0];
}

inline objetoBase * Vector::getUltimoDato()
{
	return vector[cantidad];
}

inline objetoBase * Vector::operator[](int pos)
{
	return vector[pos];
}

inline void Vector::agregarInicio(objetoBase *dato)
{
	if (cantidad < capacidad)
		this->vector[++cantidad] = dato;
}

inline void Vector::eliminaEspecifico(int pos)
{
	for (int i = pos; i < cantidad - 1; i++)
		vector[i] = vector[i + 1];
	cantidad--;
}

inline objetoBase* Vector::eliminaUltimo() {
	objetoBase* aux;
	if (vector[cantidad] != NULL) {
		aux = vector[cantidad];
		vector[cantidad] = NULL;
		cantidad--;
		return aux;
	}
	else
		return NULL;
}

inline void Vector::limpiar() {
	for (cantidad; cantidad != -1; cantidad--) {
		delete vector[cantidad];
	}
	delete[]vector;
}
