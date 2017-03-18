#include "control.h"

int Escuela::codigo = 0;

void Control::principal()
{
	U = new Universidad();
	CE = new Contenedor_Escuelas();

	Interfaz::vBienvenida();

	if (Interfaz::vDatosPrimeraVez(U) == 'S')
	{
		Interfaz::vIngresarNombre(U);
		Interfaz::vIngresarNumero(U);
		Interfaz::vIngresarDireccion(U);
	}

	Escuela* E1 = new Escuela("Ingles", U);
	Escuela* E2 = new Escuela("Matematicas", U);
	Escuela* E3 = new Escuela("Geologia", U);
	CE->insertaralInicio(E1);
	CE->insertaralInicio(E2);
	CE->insertaralInicio(E3);

		bool end = false;

	do
	{
		char ans = Interfaz::vMenuPrincipal();

		switch (ans)
		{
		case '1':
		{
			if (U->getNombre() == "Undefined" && U->getNumero() == "Undefined")
				Interfaz::msjNoDatosIngresadosUni();
			else
				Interfaz::vtoString(U);
			break;
		}
		case '2':
		{
			cout << CE->toString();
			system("pause");
			system("cls");
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
		char opcion = Interfaz::vMenuAjustes(U);


		if (U->getNombre() == "Undefined")
		{
			switch (opcion)
			{
			case '1':
			{
				Interfaz::vIngresarNombre(U);
				break;
			}
			case '2':
			{
				Interfaz::vIngresarNumero(U);
				break;
			}
			case '3':
			{
				Interfaz::vIngresarDireccion(U);
				break;
			}
			case '4':
			{
				end = true;
				break;
			}
			default: break;

			}
		}
		else
		{

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
		}

	} while (end == false);
}

