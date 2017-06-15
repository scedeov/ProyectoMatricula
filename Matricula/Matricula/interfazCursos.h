#ifndef INTERFAZ_CURSOS
#define INTERFAZ_CURSOS

class Universidad;
class Interfaz_Cursos {
public:
	static char vMenuCursos();
	static char vAjustesCursos();
	static void vIngresaCurso(Universidad*);
	static void vEditarCurso(Universidad*);
	static void vEliminaCurso(Universidad*);
	static void vInfoCurso(Universidad*);
	static void vListaCursosEscuelaParticular(Universidad*);
};
#endif // !INTERFAZ_CURSOS

