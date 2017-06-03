#ifndef CONTENEDOR_RELACIONCURSOESCUELA
#define CONTENEDOR_RELACIONCURSOESCUELA

#include "lista.h"
#include <string>

class RelacionCursoEscuela;
class ContenedorRelacionCursoEscuela {
private:
	Lista<RelacionCursoEscuela> *listaRelacionCursoEscuela;
public:
	ContenedorRelacionCursoEscuela();
	Lista<RelacionCursoEscuela>* getLista();
	int getCursosNescuelas(std::string, std::string);
	~ContenedorRelacionCursoEscuela();
};
#endif // !CONTENEDOR_RELACIONCURSOESCUELA
