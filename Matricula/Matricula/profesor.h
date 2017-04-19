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
	Profesor(string, string, string, int);
	~Profesor();
};
#endif // !PROFESOR
