#ifndef CONTENEDOR
#define CONTENEDOR

#include <iostream>
#include "addBehavior.h"

class Contenedor {
private:
	AddBehavior *add;
public:
	virtual void setAddBehaviour(AddBehavior*);
	virtual void agregaInicio() = 0;
	virtual ~Contenedor() = 0;
};
#endif // !CONTENEDOR

inline void Contenedor::setAddBehaviour(AddBehavior* add) {
	this->add = add;
}
inline void Contenedor::agregaInicio() {
	add->agregarInicio();
}
inline Contenedor::~Contenedor() {
	std::cout << "Eliminando Contenedor (Interfaz) " << std::endl;
}
