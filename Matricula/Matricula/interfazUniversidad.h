#ifndef INTERFAZ_UNIVERSIDAD
#define INTERFAZ_UNIVERSIDAD

#include "universidad.h"

class Interfaz_Universidad {
public:
	static char vMenuUniversidad();
	static char vAjustesUniversidad(Universidad*);
	static void vIngresarNumero(Universidad*);
	static void vIngresarDireccion(Universidad*);
	static void vIngresarNombre(Universidad*);
	static void vInfoUniversidad(Universidad*);
};
#endif // !INTERFAZ_UNIVERSIDAD

