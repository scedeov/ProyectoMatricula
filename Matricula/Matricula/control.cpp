#include "control.h"

Control::Control()
{

}

void Control::Inicio()
{
	bool end = false;

	char ans;
	cout << string("Bienvenido al Sistema de Matricula") << endl;
	cout << string("Ingrese los datos de la Universidad.....") << endl << endl; // Al incio del programa pregunta una vez por los datos de la Universidad (solo una)

	do //Pide los datos al usuario y le da la opcion de cambiarlos las veces que quiera mientras no confirme su opcion
	{
		cout << string("Ingrese el nombre de la Universidad -> "); string nombre; getline(std::cin, nombre); cout << endl << endl;
		cout << "Universidad : " << "\"" << nombre << "\" "; cout << string("| es esta informacion correcta? SI (S) NO (N)") << endl;

		ans = toupper(_getch());

		while (ans != 'S' && ans != 'N') //Impide ingresar un valor diferente a S o N
		{
			ans = toupper(_getch());
		}

		if (ans == 'S') //Solo ingresa al nombre si el usuario confirma
		{
			U1.setNombre(nombre);
			cout << string("Perfecto!"); Sleep(1500); system("cls");
		}

	} while (ans == 'N');


	do // igual que el anterior
	{
		cout << string("Ingrese el numero de telefono -> "); string numero; std::cin >> numero;  cout << endl << endl;
		cout << "Numero : " << "\"" << numero << "\" "; cout << string("| es esta informacion correcta? SI (S) NO (N)") << endl;

		ans = toupper(_getch());

		while (ans != 'S' && ans != 'N') //Impide ingresar un valor diferente a S o N
		{
			ans = toupper(_getch());
		}

		if (ans == 'S')
		{
			U1.setTelefono(numero);
			cout << string("Perfecto!"); Sleep(1500); system("cls");
		}

	} while (ans == 'N');

	do
	{
		cout << string("Ingrese la direccion -> "); string direccion; getline(std::cin, direccion); cout << endl << endl;
		cout << "Direccion : " << "\"" << direccion << "\" "; cout << string("| es esta informacion correcta? SI (S) NO (N)") << endl;

		ans = toupper(_getch());

		while (ans != 'S' && ans != 'N') //Impide ingresar un valor diferente a S o N
		{
			ans = toupper(_getch());
		}

		if (ans == 'S')
		{
			U1.setDireccion(direccion);
			cout << string("Perfecto!"); Sleep(1500); system("cls");
		}

	} while (ans == 'N');

	system("cls");
	cout << U1.toString() << endl;
	cin.get();

	do
	{
		system("cls");
		cout << U1.toString() << endl;

		cout << string("Cambiar numero de telefono (1) Cambiar Direccion (2) Salir (3)") << endl;
		char ans;
		ans = _getch();
		while (ans != '1' && ans != '2' && ans != '3')
		{
			cout << string("Opcion Incorrecta. Try again ") << endl;
			ans = _getch();
		}
		{
			switch (ans)
			{
			case '1':
			{
				cout << string("Ingrese el nuevo numero de telefono -> ");
				string nuevoNumero; std::cin >> nuevoNumero;
				U1.setTelefono(nuevoNumero);
				break;

			}
			case '2':
			{
				cout << string("Ingrese la nueva direccion -> ");
				string direccion; std::cin >> direccion;
				U1.setDireccion(direccion);
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
		system("cls");
	} while (end == false);
}

Control::~Control()
{
}
