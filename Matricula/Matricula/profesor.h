#ifndef PROFESOR
#define PROFESOR

#include <iostream>
using namespace std;

#include "persona.h"

class Profesor: private Persona
{
private:
	bool esDirector;
public:
	Profesor();
	~Profesor();
};
#endif // !PROFESOR
