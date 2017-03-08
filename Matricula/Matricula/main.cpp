#include "universidad.h"
#include <conio.h>

int main()
{
	bool end = false;

	Universidad U1;

	cout << string("----------------PROBANDO---------------") << endl;
	cout << string("-------------SIN PARAMETROS-------------") << endl;
	cout << U1.toString() << endl;
	cout << string("-------------CON PARAMETROS-------------") << endl;
	Universidad U2("Universidad Undefined", "22123456", "Heredia");

	do
	{

		cout << U2.toString() << endl;
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
				string nuevoNumero; cin >> nuevoNumero;
				U2.setTelefono(nuevoNumero);
				break;

			}
			case '2':
			{
				cout << string("Ingrese la nueva direccion -> ");
				string direccion; cin >> direccion;
				U2.setDireccion(direccion);
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

	cin.get();
	cin.get();
	return 0;
}