#ifndef ESTUDIANTE_NACIONAL
#define ESTUDIANTE_NACIONAL

#include "estudiante.h"

class Estudiante_Nacional : public Estudiante {
private:
	Estudiante* estudiante;
public:
	Estudiante_Nacional(Estudiante*);
	~Estudiante_Nacional();
};
#endif // !ESTUDIANTE_NACIONAL
