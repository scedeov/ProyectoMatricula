#ifndef RELACION_CURSO_ESCUELA
#define RELACION_CURSO_ESCUELA


class Escuela; 
class Curso;
class RelacionCursoEscuela {
private:
	Escuela *referenciaEscuela;
	Curso *referenciaCurso;
public:
	RelacionCursoEscuela(Escuela&, Curso&);
	Escuela* getReferenciaEscuela();
	Curso* getReferenciaCurso();
	void setReferenciaCurso(Curso&);
	void setReferenciaEscuela(Escuela&);
	~RelacionCursoEscuela();

};

#endif // !RELACION_CURSO_ESCUELA
