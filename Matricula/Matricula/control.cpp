#include "control.h"

Control::Control()
{

}

void Control::Inicio()
{
	bool end = false;

	cout << string("Bienvenido al Sistema de Matricula") << endl;
	Sleep(1500);
	cout << string("Ingrese los datos de la Universidad.....") << endl << endl; // Al incio del programa pregunta una vez por los datos de la Universidad (solo una)
	Sleep(1500);
	system("pause");

	system("cls");

	ingresarNombre();

	ingresarNumero();

	ingresarDireccion();

	system("cls");
	cout << U1.toString() << endl;
	cin.get();

	do
	{
		Sleep(500);
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
				ingresarNumero();
				break;

			}
			case '2':
			{
				ingresarDireccion();
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

bool Control::chequeaNumero(string num)
{
	bool esNumero;

	for (size_t x = 0; x < num.length(); x++)
	{
		if (isdigit(num[x]))
			esNumero = true;
		else
		{
			esNumero = false;
			return esNumero;
		}
	}
	return esNumero;
}

void Control::ingresarNumero()
{
	char ans;

	do
	{
		Sleep(500);
		cout << string("Ingrese el numero de telefono -> "); string numero;
		std::cin >> numero; cin.ignore();

		while (chequeaNumero(numero) == false) //No le permite al usuario ingresar un algo que no sean numeros
		{
			cout << string("Numero Invalido. Intente de nuevo");
			Sleep(800);
			system("cls");
			cout << string("Ingrese el numero de telefono -> "); cin.clear();
			std::cin >> numero; cin.ignore();
		}

		cout << endl << endl;
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
}

void Control::ingresarDireccion()
{
	char ans;

	do
	{
		Sleep(500);
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
}

void Control::ingresarNombre()
{
	char ans;
	do //Pide los datos al usuario y le da la opcion de cambiarlos las veces que quiera mientras no confirme su opcion
	{
		Sleep(500);
		cout << string("Ingrese el nombre de la Universidad -> "); string nombre; std::getline(std::cin, nombre); cout << endl << endl;
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
}

Control::~Control()
{
}


