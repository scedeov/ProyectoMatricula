#include "control.h"


void Control::principal()
{
	U = new Universidad();
	CE = new Contenedor_Escuelas();

	bool end = false;

	do
	{
		char ans = Interfaz::vMenuPrincipal();

		switch (ans)
		{
		case '1':
		{
			if (U->getNumero() == "Undefined")
				Interfaz::msjNoDatosIngresadosUni();
			else
				Interfaz::vtoString(U);
			break;
		}
		case '2':
		{
			CE->toString();
			break;
		}
		case '3':
		{
			ajustes();
			break;
		}
		case '4':
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

