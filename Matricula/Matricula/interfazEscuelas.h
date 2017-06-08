#ifndef INTERFAZ_ESCUELAS
#define INTERFAZ_ESCUELAS

#include "interfazPrincipal.h"
#include "escuela.h"
#include "controladorEscuelas.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "universidad.h"
using namespace std;


class Interfaz_Escuelas
{
public:
	static char vMenuEscuelas();
	static char vAjustesEscuelas();
	static void vIngresaEscuela(Universidad*);
	static void vInfoEscuelasSinCursos(Universidad*); // el char es para ver si imprime cursos o no
	static void vInfoEscuelasConCursos(Universidad*);
};
#endif // !INTERFAZ_ESCUELAS

