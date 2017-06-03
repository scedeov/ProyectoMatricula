#ifndef INTERFAZ_ESCUELAS
#define INTERFAZ_ESCUELAS

#include "contenedor.h"

class Interfaz_Escuelas
{
public:
	static char vMenuEscuelas();
	static char vAjustesEscuelas();
	static void vIngresaEscuela(Contenedor<Escuela>*);
	static void vInfoEscuelas(Contenedor<Escuela>*/*, char*/); // el char es para ver si imprime cursos o no
};
#endif // !INTERFAZ_ESCUELAS

