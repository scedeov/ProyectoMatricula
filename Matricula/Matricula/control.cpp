#include "control.h"


void Control::principal()
{
	U = new Universidad();
	CE = new Contenedor_Escuelas();

	Escuela* E1 = new Escuela();
	Escuela* E2 = new Escuela();
	Escuela* E3 = new Escuela();
	E1->setNombre("Escuela de Ingles");
	E2->setNombre("Escuela de Matematicas");
	E3->setNombre("Escuela de Geologia");
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
			if ( U->getNombre() == "Undefined" && U->getNumero() == "Undefined")
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

