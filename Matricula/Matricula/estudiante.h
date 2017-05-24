#ifndef ESTUDIANTE
#define ESTUDIANTE

#include "persona.h"
#include <vector>

class Estudiante: public Persona {
private:
	std::string carnet;
	int porcentajeBeca;
	bool esExtranjero;
	std::vector<std::string> listaCursos;
public:
	Estudiante();
	Estudiante(std::string, std::string, std::string, int, int);
	virtual std::string getCarnet();
	virtual void agregaCurso(std::string);
	virtual std::string imprimeCursos();
	virtual void setEsExtranjero(bool);
	virtual bool getEsExtranjero();
	virtual void setPorcentajeBeca(int);
	virtual int getPorcentajeBeca();
	virtual void generaCarnet();
	virtual std::string toString();
	friend std::ostream& operator << (std::ostream&, Estudiante&);
	virtual ~Estudiante();
};
#endif // !ESTUDIANTE