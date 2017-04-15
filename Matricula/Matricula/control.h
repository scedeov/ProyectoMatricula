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
	void MenuEscuelas();
	void MenuCursos();
	void MenuAjustes();
	void MenuProfesores();
	void MenuEstudiante();
};

#endif
