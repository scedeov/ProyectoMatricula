#ifndef PERSONA
#define PERSONA

#include <string>

class Persona: public T
{
private:
	std::string nombre;
	std::string primerApellido;
	std::string segundoApellido;
	std::string nombreCompleto;
	int numCedula;
	friend std::ostream& operator << (std::ostream&, Persona&);
public:
	Persona();
	virtual ~Persona();
	virtual std::string getNombreCompleto();
	virtual void setNombre(std::string);
	virtual std::string getNombre();
	virtual void setPrimerApellido(std::string);
	virtual void setSegundoApellido(std::string);
	virtual std::string getPrimerApellido();
	virtual std::string getSegundoApellido();
	virtual void setNumCedula(int);
	virtual int getNumCedula();
	virtual std::string toString();
};
#endif // !PERSONA
