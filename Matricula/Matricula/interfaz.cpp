#include "interfaz.h"

void Interfaz::vBienvenida()
{
	cout << "Bienvenido al Sistema de Matricula" << endl;
	Sleep(1500);
	cout << "Ingrese los datos de la Universidad....." << endl << endl; // Al inicio del programa pregunta una vez por los datos de la Universidad (solo una)
	Sleep(1500);
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
