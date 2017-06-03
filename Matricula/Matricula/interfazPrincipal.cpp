#include "interfazPrincipal.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

void Interfaz_Principal::vBienvenida()
{
	cout << "!Bienvenido al Sistema de Matricula!";
	Sleep(2500);
	system("cls");
}

char Interfaz_Principal::vMenuPrincipal()
{
	char ans;
	cout << "**************MENU PRINCIPAL**************" << endl;
	cout << "(1)--Universidad" << endl;
	cout << "(2)--Escuelas" << endl;
	cout << "(3)--Cursos" << endl;
	cout << "(4)--Profesores" << endl;
	cout << "(5)--Estudiantes" << endl;
	cout << "(6)--Matricula" << endl;
	cout << "(7)--Salir" << endl;
	cout << "******************************************" << endl;

	msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '7') //cambiar cada vez que se agrega opcion
	{
		cout << "Opcion Incorrecta. Intente de nuevo. " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

char Interfaz_Principal::vDatosPrimeraVez(Universidad* U)
{
	if (U->getNombre() == "Undefined")
	{
		cout << "!Hola!" << endl;
		cout << "Parece que es la primera vez que ingresas al sistema." << endl;
		cout << "?Deseas ingresar ahora los datos de la Universidad?";
		return vInfoConfirmacion();
	}
	return 0;
}

char Interfaz_Principal::vInfoConfirmacion()
{
	char ans;

	cout << endl << string(" SI (S) NO (N)") << endl;

	ans = toupper(_getch());

	while (ans != 'S' && ans != 'N') //Impide ingresar un valor diferente a S o N
	{
		ans = toupper(_getch());
	}

	return ans;
}

bool Interfaz_Principal::chequeaNumero(string num)
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

void Interfaz_Principal::msjPerfecto()
{
	cout << endl << string("Perfecto!");
	Sleep(1500);
	system("cls");
}

void Interfaz_Principal::msjPausa()
{
	cout << "Presione cualquier tecla para continuar..." << endl;
	_getch();
}

void Interfaz_Principal::msjIngreseOpcion()
{
	cout << "Ingrese una opcion -> ";
}

string Interfaz_Principal::convierteMayuscula(string minuscula)
{
	string mayuscula;

	for (int i = 0; i < minuscula.length(); i++)
	{
		mayuscula += toupper(minuscula[i]);
	}

	return mayuscula;
}



