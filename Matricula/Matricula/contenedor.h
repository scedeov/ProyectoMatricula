#ifndef CONTENEDOR
#define CONTENEDOR

class Contenedor: public T {
public:
	virtual void agregaInicio()
};
#endif // !CONTENEDOR

inline Contenedor::~Contenedor() {
	std::cout << "Eliminando Contenedor (Interfaz) " << std::endl;
}
