#ifndef CONTROL
#define CONTROL


#include <conio.h>
#include <Windows.h>

#include "universidad.h"
#include "interfaz.h"

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
	/*void MenuAjustes();*/
	void MenuProfesores();
	void AjustesProfesores();
	void MenuEstudiantes();
	void AjustesEstudiantes();
};

#endif
