#ifndef ESTUDIANTE_EXTRANJERO
#define ESTUDIANTE_EXTRANJERO

#include "estudiante.h"

class Estudiante_Extranjero: public Estudiante {
private:
	Estudiante* estudiante;
public:
	Estudiante_Extranjero(Estudiante*);
	~Estudiante_Extranjero();
};
#endif // !ESTUDIANTE_EXTRANJERO
