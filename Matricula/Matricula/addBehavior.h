#ifndef ADDBEHAVIOR
#define ADDBEHAVIOR

class Persona;
class AddBehavior {
public:
	virtual void agregarInicio(Persona*) = 0;
};

class Estudiante;
class AddEstudiante : public AddBehavior {
public:
	void agregarInicio(Persona*);
};

class Profesor;
class AddProfesor : public AddBehavior {
	void agregarInicio(Persona*);
};
#endif // !ADDBEHAVIOR
