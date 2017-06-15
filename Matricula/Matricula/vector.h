#ifndef VECTOR
#define VECTOR

template <class T>
class Vector {
private:
	T** vector;
	int cantidad;
	int capacidad;
public:
	inline Vector(int xCapacidad) {
		vector = new T*[xCapacidad];
		this->cantidad = -1;
		this->capacidad = xCapacidad;
		for (int i = 0; i < capacidad; i++)
			vector[i] = nullptr;
	}

	inline ~Vector() {
		for (cantidad; cantidad != -1; cantidad--) {
			delete vector[cantidad];
		}
		delete[]vector;
	}

	inline T* getDato(int pos) {
		return vector[pos];
	}

	inline void eliminarPosicion(int pos) {
		for (int i = pos; i < cantidad - 1; i++)
			vector[i] = vector[i + 1];
		cantidad--;
	}

	inline int getCantidad() {
		return cantidad;
	}
	inline int getCapacidad() {
		return capacidad;
	}

	inline void setCapacidad(int x) {
		this->capacidad = x;
	}

	inline void push(T* dato) {
		if (cantidad < capacidad)
			this->vector[++cantidad] = dato;
	}

	inline T* pop() {
		T* aux;
		if (vector[cantidad] != nullptr) {
			aux = vec[cantidad];
			vec[cantidad] = nullptr;
			cantidad--;
			return aux;
		}
		else
			return nullptr;
	}

	class Iterador;
	friend class Iterador;
	class Iterador {
	private:
		Vector *ptr;
		int cursor;
	public:
		inline Iterador(Vector* ptr) {
			this->ptr = ptr;
		}
		inline void first() {
			this->cursor = 0;
		}
		inline void next() {
			this->cursor++;
		}
		inline T* getCurItem() {
			return ptr->vector[cursor];
		}
	};
};
#endif // !VECTOR

