#ifndef CONTROL
#define CONTROL

#include "universidad.h"

class Control
{
private:
	Universidad* U;
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
