#ifndef ESTUDIANTE_EXTRANJERO
#define ESTUDIANTE_EXTRANJERO

#include "estudiante.h"

class Estudiante_Extranjero: public Estudiante {
private:
public:
	Estudiante_Extranjero(string, string, string, int);
	~Estudiante_Extranjero();
};
#endif // !ESTUDIANTE_EXTRANJERO
