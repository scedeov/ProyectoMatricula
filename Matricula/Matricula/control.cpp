#include "control.h"

void Control::intro(Universidad* U)
{


	Interfaz::vBienvenida();

	Interfaz::vIngresarNombre(U);

	Interfaz::vIngresarNumero(U);

	Interfaz::vIngresarDireccion(U);

	Interfaz::vtoString(U);

}

void Control::principal()
{
	U = new Universidad();
	if (U->getNombre() != "Undefined") //cambiar luego para que pida los datos al inicio
		intro(U);

	bool end = false;

	do
	{
		char ans = Interfaz::vMenuPrincipal();

		switch (ans)
		{
		case '1':
		{
			ajustes();
			break;
		}
		case '2':
		{
			end = true;
			break;
		}
		default:
			break;
		}

	} while (end == false);
}

void Control::ajustes()
{
	bool end = false;

	do
	{
		char opcion = Interfaz::vMenuAjustes();

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

