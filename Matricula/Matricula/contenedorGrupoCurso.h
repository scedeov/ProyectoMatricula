#ifndef CONTENEDOR_GRUPOCURSO
#define CONTENEDOR_GRUPOCURSO

#include "vector.h"

const int MAXGRUPOSESTUDIANTES = 5;

class GrupoCurso;
class ContenedorGrupoCurso {
private:
	Vector<GrupoCurso> *contenedorGrupoCurso;
public:
	ContenedorGrupoCurso();
	GrupoCurso* getCursoGrupo(int);
	~ContenedorGrupoCurso();
};
#endif // !CONTENEDOR_GRUPOCURSO
