#include "control.h"

int Curso::codigo = 0;

void Control::inicializador()
{
	U = new Universidad();
	CE = new Contenedor_Escuelas();
	CC = new Contenedor_Cursos();

	Escuela* E1 = new Escuela("Ingles");
	Escuela* E2 = new Escuela("Matematicas");
	Escuela* E3 = new Escuela("Geologia");
	Escuela* E4 = new Escuela("Sociales");
	CE->insertaralInicio(E1);
	CE->insertaralInicio(E2);
	CE->insertaralInicio(E3);
	CE->insertaralInicio(E4);

	Curso* CU1 = new Curso("Programacion I", E1->getSiglaEscuela());
	Curso* CU2 = new Curso("Programacion II", E2->getSiglaEscuela());

	E1->insertarCurso(CU1);
	E2->insertarCurso(CU2);

	principal();
}

void Control::principal()
{
	Interfaz::vBienvenida();

	if (Interfaz::vDatosPrimeraVez(U) == 'S') //Esto me funciona para luego en caso de que ya se hayan ingresado los datos
	{
		Interfaz::vIngresarNombre(U);
		Interfaz::vIngresarNumero(U);
		Interfaz::vIngresarDireccion(U);
	}

	bool end = false;

	do
	{
		char ans = Interfaz::vMenuPrincipal();

		switch (ans)
		{
		case '1':
		{
			Interfaz::vtoString(U);
			break;
		}
		case '2':
		{
			Interfaz::vtoStringEscuelas(U, CE, '1');
			break;
		}
		case '3':
		{
			Interfaz::vtoStringEscuelas(U, CE, '2');
			break;
		}
		case '4':
		{
			ajustes();
			break;
		}
		case '5':
		{
			delete CC;
			delete CE; //se encarga de eliminar donde estan alojadas las escuelas (composicion)
			delete U;
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
				Interfaz::vIngresaEscuela(CE);
			}
			case '4':
			{
				end = true;
				break;
			}
			default: break;

			}
		}

	} while (end == false);
}

