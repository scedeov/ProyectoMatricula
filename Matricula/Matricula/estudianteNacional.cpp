#include "estudianteNacional.h"
#include <string>
#include <iostream>
using namespace std;

Estudiante_Nacional::Estudiante_Nacional(int porcentajeBeca = 0) : Estudiante(), porcentajeBeca(porcentajeBeca)
{
	
}

Estudiante_Nacional::~Estudiante_Nacional()
{
	cout << "Eliminando Estudiante Nacional..." << endl;
}
