#include "control.h"

int Curso::cantidad = 0;

void Control::Inicializador()
{
	U = new Universidad("Universidad de Costa Rica", "22334455", "San Pedro");

	Escuela* E1 = new Escuela("Ingles");
	Escuela* E2 = new Escuela("Matematicas");
	Escuela* E3 = new Escuela("Geologia");
	Escuela* E4 = new Escuela("Sociales");

	U->insertarEscuela(E1);
	U->insertarEscuela(E2);
	U->insertarEscuela(E3);
	U->insertarEscuela(E4);

	Curso* CU1 = new Curso("Programacion I", E1->getSiglaEscuela());
	Curso* CU2 = new Curso("Programacion II", E2->getSiglaEscuela());
	E1->insertarCurso(CU1);
	E2->insertarCurso(CU2);

	MenuPrincipal();
}

void Control::MenuPrincipal()
{
	Interfaz::vBienvenida();

	if (Interfaz::vDatosPrimeraVez(U) == 'S')
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
			MenuUniversidad();
			break;
		}
		case '2':
		{
			MenuEscuelas();
			break;
		}
		case '3':
		{
			MenuCursos();
			break;
		}
		case '4':
		{
			MenuAjustes();
			break;
		}
		case '5':
		{
			delete U;
			end = true;
			break;
		}
		default:
			break;
		}

	} while (end == false);
}

void Control::MenuUniversidad()
{
	bool end = false;

	do
	{
		char ans = Interfaz::vMenuUniversidad();

		switch (ans)
		{
		case '1':
		{
			Interfaz::vInfoUniversidad(U);
			break;
		}
		case '2': //Salir
		{
			end = true;
			break;
		}
		default:
			break;
		}

	} while (end == false);
}

void Control::MenuEscuelas()
{
	bool end = false;

	do
	{
		char ans = Interfaz::vMenuEscuelas();

		switch (ans)
		{
		case '1':
		{
			Interfaz::vInfoEscuelas(U, '1'); //Imprime solamente escuelas
			break;
		}
		case '2':
		{
			Interfaz::vInfoEscuelas(U, '2'); //Imprime escuelas con los cursos
			break;
		}
		case '3': // Salir
		{
			end = true;
			break;
		}
		default:
			break;
		}

	} while (end == false);
}

void Control::MenuCursos()
{
	bool end = false;

	do
	{
		char ans = Interfaz::vMenuCursos();

		switch (ans)
		{
		case '1':
		{
			Interfaz::vInfoCurso(U);
			break;
		}
		case '2':
		{
			Interfaz::vListaCursosEscuelaParticular(U);
			break;
		}
		case '3': //Salir
		{
			end = true;
			break;
		}
		default:
			break;
		}

	} while (end == false);
}

void Control::MenuAjustes()
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
				Interfaz::vIngresaEscuela(U);
				break;
			}
			case '4':
			{
				Interfaz::vIngresaCurso(U);
				break;
			}
			case '5':
			{
				Interfaz::vEditarCurso(U);
				break;
			}
			case '6':
			{
				Interfaz::vEliminaCurso(U);
				break;
			}
			case '7':
			{
				end = true;
				break;
			}
			default: break;

			}
		}

	} while (end == false);
}

void Control::MenuProfesores()
{
	bool end = false;

	do
	{
		char opcion = Interfaz::vMenuProfesores();
		switch (opcion)
		{
		case '1':
			{

	
			}

		}
	} while (end == false);
}

void Control::MenuEstudiante()
{
}

