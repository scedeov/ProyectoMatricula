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
	T* getDato(int);
	void eliminarPosicion(int);
	int getCantidad();
	int getCapacidad();
	void setCapacidad(int);
	void push(T*);
	T* pop();

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
		void next() {
			this->cursor++;
		}
		T* getCurItem() {
			return ptr->vector[cursor];
		}
	};
};
#endif // !VECTOR

