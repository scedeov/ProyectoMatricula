#ifndef PROFESOR
#define PROFESOR

#include <iostream>
using namespace std;

#include "persona.h"

class Profesor: private Persona
{
private:
	bool esDirector;
	friend ostream& operator << (ostream&, Profesor&);
public:
	Profesor(string, string, string, int);
	string toString();
	~Profesor();
};
#endif // !PROFESOR
