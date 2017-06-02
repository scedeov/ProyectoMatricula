#include "director.h"
#include <iostream>
#include <sstream>

Director::Director():
Profesor() {
}

Director::Director(Profesor* profesor = NULL): 
	profesor(profesor){
}

std::string Director::toString()
{
	std::stringstream s;
	s << profesor->toString() << std::endl;
	s << "Es el director..." << std::endl;
	return profesor->toString();
}

Director::~Director()
{
	std::cout << "Eliminando Director" << std::endl;
}
