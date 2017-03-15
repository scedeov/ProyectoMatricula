#include "control.h"

void Control::intro()
{
	U = new Universidad();

	Interfaz::vBienvenida();

	Interfaz::vIngresarNombre(U);

	Interfaz::vIngresarNumero(U);

	Interfaz::vIngresarDireccion(U);

	Interfaz::vtoString(U);
}

void Control::body()
{
	bool end = false;

	do
	{
		char opcion = Interfaz::vMenu();

		switch (opcion)
		{
		case '1':
		{
			Interfaz::vIngresarNumero(U);
			break;

		}
		case '2':
		{
			Interfaz::vIngresarDireccion(U);
			break;
		}
		case '3':
		{
			end = true;
			break;
		}
		default: break;

		}

	} while (end == false);
}

