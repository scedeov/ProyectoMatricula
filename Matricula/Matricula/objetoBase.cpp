#include "objetoBase.h"
#include "contenedorCursos.h"
#include "contenedorEscuelas.h"
using namespace std;

T::~T() {
}

adaptadorCursos::adaptadorCursos(Contenedor_Cursos *C = NULL) :
	Cc(C) {
}

bool adaptadorCursos::eliminaEspecifico(string s) {
	Cc->eliminarEspecifico(s);
}

std::string adaptadorCursos::toString() {
	return std::string();
}

std::ostream & operator<<(std::ostream &o, const T &ob) {
	return o << ob.toString() << std::endl;
}

adaptadorEscuelas::adaptadorEscuelas(contenedorEscuelas *cE = NULL):
	Ce(cE) {
}

bool adaptadorEscuelas::eliminaEspecifico(string s) {
	Ce->eliminaEspecifico(s);
}
