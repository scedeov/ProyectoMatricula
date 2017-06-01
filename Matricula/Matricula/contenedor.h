#ifndef CONTENEDOR
#define CONTENEDOR

#include "objetoBase.h"

class Contenedor: public T {
public:
	virtual void agregarInicio(T*) = 0;
	virtual std::string toString() const = 0;
	virtual ~Contenedor() = 0;
};
#endif // !CONTENEDOR

inline Contenedor::~Contenedor() {
	std::cout << "Eliminando Contenedor (Interfaz) " << std::endl;
}
