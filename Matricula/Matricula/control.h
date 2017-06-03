#ifndef CONTROL
#define CONTROL

#include "contenedor.h"

class Universidad;
class Control
{
private:
	Universidad *universidad;
	ContenedorEscuelas *contenedorEscuelas;
	ContenedorCursos *contenedorCursos;
	ContenedorPersonas *contenedorPersonas;
public:
	void Inicializador();
	void MenuPrincipal();
	void MenuUniversidad();
	void AjustesUniversidad();
	void MenuEscuelas();
	void AjustesEscuelas();
	void MenuCursos();
	void AjustesCursos();
	void MenuProfesores();
	void AjustesProfesores();
	void MenuEstudiantes();
	void AjustesEstudiantes();
	void MenuMatricula();
	void AjustesMatricula();
};

#endif
