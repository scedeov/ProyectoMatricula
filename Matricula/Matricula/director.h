#ifndef DIRECTOR
#define DIRECTOR

#include "profesor.h"

class Director: public Profesor {
private:
	Profesor* profesor;
public:
	Director();
	Director(Profesor*);
	std::string toString();
	~Director();
};
#endif // !DIRECTOR
