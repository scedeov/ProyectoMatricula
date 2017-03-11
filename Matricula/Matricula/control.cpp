#include "control.h"

Control::Control()
{

}

void Control::Inicio()
{
	bool end = false;


	cout << string("Bienvenido al Sistema de Matricula") << endl;
	cout << string("Ingrese los datos de la Universidad.....") << endl << endl;

	cout << string("Ingrese el nombre de la Universidad -> "); string nombre; getline(std::cin, nombre); cout << endl;
	U1.setNombre(nombre);

	cout << string("Ingrese el numero de telefono -> "); string numero; std::cin >> numero; U1.setTelefono(numero); cout << endl << endl;

	cout << string("Ingrese la direccion -> "); string direccion; std::cin >> direccion; U1.setDireccion(direccion); cout << endl << endl;

	do
	{

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
