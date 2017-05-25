#include "interfazEscuelas.h"
#include "interfazPrincipal.h"
#include "escuela.h"
#include "contenedorEscuelas.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

char Interfaz_Escuelas::vMenuEscuelas()
{
	char ans;
	cout << "**************MENU ESCUELAS**************" << endl;
	cout << "(1)--Consulta de la lista de Escuelas" << endl;
	cout << "(2)--Consulta de la lista de Escuelas (+ Cursos)" << endl;
	cout << "(3)--Ajustes" << endl;
	cout << "(4)--Salir" << endl;
	cout << "********************************************" << endl;
	Interfaz_Principal::msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '4')
	{
		cout << "Opcion Incorrecta. Intente de nuevo. " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

char Interfaz_Escuelas::vAjustesEscuelas()
{
	char ans;
	cout << "***************AJUSTES ESCUELAS***************" << endl;
	cout << "(1)--Ingresar Escuela" << endl;
	cout << "(2)--Salir" << endl;
	Interfaz_Principal::msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '2')
	{
		cout << "Opcion Incorrecta. Try again " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

void Interfaz_Escuelas::vIngresaEscuela(Universidad* U)
{
	string nombre;
	cout << "Ingrese el nombre de la escuela -> "; getline(cin, nombre); cout << endl;

	cout << "Escuela de : " << "\"" << nombre << "\" "; cout << "| es esta informacion correcta? (El nombre no se puede cambiar una vez confirmado)";

	char ans = Interfaz_Principal::vInfoConfirmacion();

	while (nombre == "Undefined" || nombre == " " || nombre == "")
	{
		cout << "Nombre Invalido. Intente de nuevo -> ";
		Sleep(800);
		system("cls");
		cout << "Ingrese el nombre de la escuela  -> "; std::getline(std::cin, nombre); cout << endl << endl;
	}

	Escuela* escu = new Escuela(nombre);

	U->getContenedorEscuelas()->insertarInicio(escu);

	system("cls");
}

void Interfaz_Escuelas::vInfoEscuelas(Universidad* U, char op)
{
	if (U->getNombre() == "Undefined")
		cout << "No se ha ingresado el nombre de la Universidad. Vaya a Ajustes." << endl;
	else
	{
		cout << "Nombre de la Universidad: " << U->getNombre() << endl << endl;
		cout << U->getContenedorEscuelas()->toString(op) << endl;
	}
	Interfaz_Principal::msjPausa();
	system("cls");
}