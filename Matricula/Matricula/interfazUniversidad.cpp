#include "interfazUniversidad.h"
#include "interfazPrincipal.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

char Interfaz_Universidad::vMenuUniversidad()
{
	char ans;
	cout << "**************MENU UNIVERSIDAD**************" << endl;
	cout << "(1)--Informacion acerca de la Universidad" << endl;
	cout << "(2)--Ajustes" << endl;
	cout << "(3)--Salir" << endl;
	cout << "********************************************" << endl;
	Interfaz_Principal::msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '3') {
		cout << "Opcion Incorrecta. Intente de nuevo. " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

char Interfaz_Universidad::vAjustesUniversidad(Universidad *U) {
	char ans;

	cout << "**************AJUSTES UNIVERSIDAD*************************" << endl;
	if (U->getNombre() == "Undefined") {
		cout << "-(1)-Ingresar nombre de la Universidad" << endl;

		if (U->getNumero() == "Undefined")
			cout << "-(2)-Ingresar Numero de Telefono de la Universidad" << endl;
		else
			cout << "-(2)-Cambiar Numero de Telefono de la Universidad" << endl;
		if (U->getDireccion() == "Undefined")
			cout << "-(3)-Ingresar Direccion de la Universidad" << endl;
		else
			cout << "-(3)-Cambiar Direccion de la Universidad" << endl;

		cout << "-(4)-Salir" << endl;
		cout << "************************************************" << endl;
		Interfaz_Principal::msjIngreseOpcion();
		ans = _getch();

		while (ans < '1' || ans > '4')
		{
			cout << "Opcion Incorrecta. Try again " << endl;
			ans = _getch();
		}
	}
	else {
		if (U->getNumero() == "Undefined")
			cout << "-(1)-Ingresar Numero de Telefono de la Universidad" << endl;
		else
			cout << "-(1)-Cambiar Numero de Telefono de la Universidad" << endl;
		if (U->getDireccion() == "Undefined")
			cout << "-(2)-Ingresar Direccion de la Universidad" << endl;
		else
			cout << "-(2)-Cambiar Direccion de la Universidad" << endl;
		cout << "-(3)-Salir" << endl;
		cout << "************************************************" << endl;
		Interfaz_Principal::msjIngreseOpcion();
		ans = _getch();

		while (ans < '1' || ans > '3') {
			cout << "Opcion Incorrecta. Try again " << endl;
			ans = _getch();
		}
	}
	system("cls");
	return ans;
}

void Interfaz_Universidad::vIngresarNumero(Universidad* U)
{
	char ans;

	do
	{
		Sleep(500);
		cout << "Ingrese el numero de telefono -> "; string numero;
		cin >> numero; cin.ignore();

		while (Interfaz_Principal::chequeaNumero(numero) == false) //No le permite al usuario ingresar un algo que no sean numeros
		{
			cout << "Numero Invalido. Intente de nuevo";
			Sleep(800);
			system("cls");
			cout << string("Ingrese el numero de telefono -> ");
			std::cin >> numero; cin.ignore();
		}

		cout << endl << endl;
		cout << "Numero : " << "\"" << numero << "\" "; cout << "| es esta informacion correcta?";

		ans = Interfaz_Principal::vInfoConfirmacion();

		if (ans == 'S')
		{
			U->setTelefono(numero);
			Interfaz_Principal::msjPerfecto();
		}

	} while (ans == 'N');
}

void Interfaz_Universidad::vIngresarDireccion(Universidad* U)
{
	char ans;

	do
	{
		Sleep(500);
		cout << "Ingrese la direccion -> "; string direccion; getline(std::cin, direccion); cout << endl << endl;
		cout << "Direccion : " << "\"" << direccion << "\" "; cout << "| es esta informacion correcta?";

		ans = Interfaz_Principal::vInfoConfirmacion();

		if (ans == 'S')
		{
			U->setDireccion(direccion);
			Interfaz_Principal::msjPerfecto();
		}

	} while (ans == 'N');
}

void Interfaz_Universidad::vIngresarNombre(Universidad* U)
{
	char ans;
	do //Pide los datos al usuario y le da la opcion de cambiarlos las veces que quiera mientras no confirme su opcion
	{
		Sleep(500);
		cout << string("Ingrese el nombre de la Universidad -> "); string nombre; std::getline(std::cin, nombre); cout << endl << endl;

		cout << "Universidad : " << "\"" << nombre << "\" "; cout << "| es esta informacion correcta? (El nombre no se puede cambiar una vez confirmado)";

		ans = Interfaz_Principal::vInfoConfirmacion();

		while (nombre == "Undefined" || nombre == " " || nombre == "")
		{
			cout << "Nombre Invalido. Intente de nuevo -> ";
			Sleep(800);
			system("cls");
			cout << "Ingrese el nombre de la Universidad  -> "; std::getline(std::cin, nombre); cout << endl << endl;
		}



		if (ans == 'S') //Solo ingresa al nombre si el usuario confirma
		{
			U->setNombre(nombre);
			Interfaz_Principal::msjPerfecto();
		}

	} while (ans == 'N');
}

void Interfaz_Universidad::vInfoUniversidad(Universidad* U) //Modificar para que sirva de informacion actual del sistema de matricula
{
	if (U->getNombre() == "Undefined" && U->getNumero() == "Undefined")
		cout << "Ups... parece que no se han ingresado todos los datos de la Universidad. Ve a Ajustes para agregarlos." << endl;
	else
		cout << *U << endl;

	Interfaz_Principal::msjPausa();
	system("cls");
}