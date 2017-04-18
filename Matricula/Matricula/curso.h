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
	static int cantidad;
	int cantidadCreditos;
public:
	Curso();
	Curso(string, string);
	void setNombre(string);
	void setCodigoCurso(string);
	void setCantidadCreditos(int);
	string getNombre();
	string getCodigoCurso();
	int getCantidadCreditos();
	string toString();
	friend ostream& operator << (ostream&, Curso&);
	bool operator == (const Curso&) const;
	~Curso();
};
#endif // !CURSO