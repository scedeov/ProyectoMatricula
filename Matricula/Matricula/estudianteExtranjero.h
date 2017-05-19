#ifndef ESTUDIANTE_EXTRANJERO
#define ESTUDIANTE_EXTRANJERO

#include "estudiante.h"

class Estudiante_Extranjero: public Estudiante {
private:
public:
	Estudiante_Extranjero(std::string, std::string, std::string, int);
	~Estudiante_Extranjero();
};
#endif // !ESTUDIANTE_EXTRANJERO
