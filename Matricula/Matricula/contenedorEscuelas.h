#ifndef CONTENEDOR_ESCUELAS
#define CONTENEDOR_ESCUELAS

class Escuela;
class Profesor;

class contenedorEscuelas {
private:
	Lista<Escuela> *listaEscuelas;
public:
	contenedorEscuelas();
	void agregarInicio (Escuela*);
	Escuela* retornaEscuela(std::string) const ;
	bool encuentraEscuela(Escuela*, std::string) const ;
	Profesor* retornaProfesor(int);
	std::string toString(char) const;
	~contenedorEscuelas();
};

#endif // !CONTENEDOR_ESCUELAS

