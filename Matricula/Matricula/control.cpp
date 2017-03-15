#include "control.h"

void Control::intro()
{
	U = new Universidad();

	Interfaz::vBienvenida();

	system("cls");

	Interfaz::vIngresarNombre(U);

	Interfaz::vIngresarNumero(U);

	Interfaz::vIngresarDireccion(U);

	system("cls");
	cout << U->toString() << endl;
}

void Control::body()
{
	bool end = false;

	do
	{
		Sleep(500);
		system("cls");
		cout << U->toString() << endl;


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

		system("cls");

	} while (end == false);
}

