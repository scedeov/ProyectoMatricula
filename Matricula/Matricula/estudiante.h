#ifndef ESTUDIANTE
#define ESTUDIANTE

#include <iostream>
using namespace std;

#include "persona.h"

class Estudiante: private Persona
{
private:
	
public:
	Estudiante();
	~Estudiante();
};
#endif // !ESTUDIANTE