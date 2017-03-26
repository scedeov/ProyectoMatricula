#ifndef CURSO
#define CURSO

#include <iostream>
#include <sstream>

using namespace std;

class Curso
{
private:
	string nombreCurso;
	string codigoCurso;
	static int codigo;
public:
	Curso();
	Curso(string, string);
	~Curso();

	void setNombre(string);
	void setCodigoCurso(string);

	string getNombre();
	string getCodigoCurso();

	string toStringCurso();
};
#endif // !CURSO