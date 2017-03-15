#include "interfaz.h"

void Interfaz::vBienvenida()
{
	cout << "Bienvenido al Sistema de Matricula" << endl << endl;
	Sleep(1500);
	cout << "Ingrese los datos de la Universidad....." << endl << endl; // Al inicio del programa pregunta una vez por los datos de la Universidad (solo una)
	Sleep(1500);
	system("cls");
}

char Interfaz::vMenu()
{
	char ans;
	cout << "Cambiar numero de telefono (1) Cambiar Direccion (2) Salir (3)" << endl;
	ans = _getch();

	while (ans != '1' && ans != '2' && ans != '3')
	{
		cout << "Opcion Incorrecta. Try again " << endl;
		ans = _getch();
	}

	return ans;
}

void Interfaz::vIngresarNumero(Universidad* U)
{
	char ans;

	do
	{
		Sleep(500);
		cout << "Ingrese el numero de telefono -> "; string numero;
		std::cin >> numero; cin.ignore();

		while (chequeaNumero(numero) == false) //No le permite al usuario ingresar un algo que no sean numeros
		{
			cout << "Numero Invalido. Intente de nuevo";
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
			U->setTelefono(numero);
			msjPerfecto();
		}

	} while (ans == 'N');
}

void Interfaz::vIngresarDireccion(Universidad* U)
{
	char ans;

	do
	{
		Sleep(500);
		cout << "Ingrese la direccion -> "; string direccion; getline(std::cin, direccion); cout << endl << endl;
		cout << "Direccion : " << "\"" << direccion << "\" "; cout << "| es esta informacion correcta? SI (S) NO (N)" << endl;

		ans = toupper(_getch());

		while (ans != 'S' && ans != 'N') //Impide ingresar un valor diferente a S o N
		{
			ans = toupper(_getch());
		}

		if (ans == 'S')
		{
			U->setDireccion(direccion);
			msjPerfecto();
		}

	} while (ans == 'N');
}

void Interfaz::vIngresarNombre(Universidad* U)
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
			U->setNombre(nombre);
			msjPerfecto();
		}

	} while (ans == 'N');
}

bool Interfaz::chequeaNumero(string num)
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

void Interfaz::msjPerfecto()
{
	cout << string("Perfecto!"); 
	Sleep(1500); 
	system("cls");
}

void Interfaz::vtoString(Universidad* U)
{
	Sleep(500);
	system("cls");
	cout << U->toString() << endl;
}
