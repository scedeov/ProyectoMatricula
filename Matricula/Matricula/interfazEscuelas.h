#ifndef INTERFAZ_ESCUELAS
#define INTERFAZ_ESCUELAS

#include "universidad.h"

class Interfaz_Escuelas
{
public:
	static char vMenuEscuelas();
	static char vAjustesEscuelas();
	static void vIngresaEscuela(Universidad*);
	static void vInfoEscuelas(Universidad*, char); // el char es para ver si imprime cursos o no
};
#endif // !INTERFAZ_ESCUELAS

