#ifndef CONTROL
#define CONTROL

#include "interfazPrincipal.h"
#include "interfazCursos.h"
#include "interfazEscuelas.h"
#include "interfazEstudiantes.h"
#include "interfazProfesores.h"
#include "interfazUniversidad.h"
#include "interfazMatricula.h"
#include "universidad.h"
#include "lista.h"
#include "vector.h"

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
