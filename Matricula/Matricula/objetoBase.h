#ifndef OBJETO_BASE
#define OBJETO_BASE

#include <string>
#include <sstream>
#include <iostream>

class objetoBase {
public:
	virtual std::string toString() const = 0;
	virtual void eliminaEspecifico() = 0;
	virtual void agregar() = 0;
};

class Contenedor_Cursos;
class adaptadorCursos : public objetoBase {
protected:
	Contenedor_Cursos* C;
public:
	adaptadorCursos(Contenedor_Cursos*);
	virtual void eliminaEspecifico();
	virtual std::string toString();
};
std::ostream& operator <<(std::ostream&, const objetoBase&);
#endif // !OBJETO_BASE