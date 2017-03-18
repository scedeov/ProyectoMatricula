#include "interfaz.h"


void Interfaz::vBienvenida()
{
	cout << "!Bienvenido al Sistema de Matricula!";
	Sleep(2500);
	system("cls");
}

char Interfaz::vMenuPrincipal()
{
	char ans;
	cout << "**************MENU PRINCIPAL**************" << endl;
	cout << "(1)--Informacion acerca de la Universidad" << endl;
	cout << "(2)--Lista de Escuelas" << endl;
	cout << "(3)--Ajustes" << endl;
	cout << "(4)--Salir" << endl;
	cout << "******************************************" << endl;

	ans = _getch();

	while (ans != '1' && ans != '2' && ans != '3' && ans != '4')
	{
		cout << "Opcion Incorrecta. Try again " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

char Interfaz::vDatosPrimeraVez(Universidad* U)
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

char Interfaz::vMenuAjustes(Universidad* U) //Estoy seguro que puede mejorarse mil veces
{
	char ans;

	if (U->getNombre() == "Undefined")
	{
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

		ans = _getch();

		while (ans != '1' && ans != '2' && ans != '3' && ans != '4')
		{
			cout << "Opcion Incorrecta. Try again " << endl;
			ans = _getch();
		}
	}
	else
	{
		if (U->getNumero() == "Undefined")
			cout << "-(1)-Ingresar Numero de Telefono de la Universidad" << endl;
		else
			cout << "-(1)-Cambiar Numero de Telefono de la Universidad" << endl;
		if (U->getDireccion() == "Undefined")
			cout << "-(2)-Ingresar Direccion de la Universidad" << endl;
		else
			cout << "-(2)-Cambiar Direccion de la Universidad" << endl;

		cout << "-(3)-Ingresar Escuela" << endl;
		cout << "-(4)-Salir" << endl;

		ans = _getch();

		while (ans != '1' && ans != '2' && ans != '3' && ans != '4')
		{
			cout << "Opcion Incorrecta. Try again " << endl;
			ans = _getch();
		}
	}

	system("cls");
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
		cout << "Numero : " << "\"" << numero << "\" "; cout << "| es esta informacion correcta?";

		ans = vInfoConfirmacion();

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
		cout << "Direccion : " << "\"" << direccion << "\" "; cout << "| es esta informacion correcta?";

		ans = vInfoConfirmacion();

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

		cout << "Universidad : " << "\"" << nombre << "\" "; cout << "| es esta informacion correcta? (El nombre no se puede cambiar una vez confirmado)";

		ans = vInfoConfirmacion();

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
			msjPerfecto();
		}

	} while (ans == 'N');
}

char Interfaz::vInfoConfirmacion()
{
	char ans;

	cout << endl << string(" SI (S) NO (N)") << endl;

	ans = toupper(_getch());

	while (ans != 'S' && ans != 'N') //Impide ingresar un valor diferente a S o N
	{
		ans = toupper(_getch());
	}

	system("cls");

	return ans;
}

void Interfaz::vIngresaEscuela(Contenedor_Escuelas* CE)
{
	string nombre;
	cout << "Ingrese el nombre de la escuela -> "; getline(cin, nombre); cout << endl;

	cout << "Escuela de : " << "\"" << nombre << "\" "; cout << "| es esta informacion correcta? (El nombre no se puede cambiar una vez confirmado)";

	char ans = vInfoConfirmacion();

	while (nombre == "Undefined" || nombre == " " || nombre == "")
	{
		cout << "Nombre Invalido. Intente de nuevo -> ";
		Sleep(800);
		system("cls");
		cout << "Ingrese el nombre de la Universidad  -> "; std::getline(std::cin, nombre); cout << endl << endl;
	}

	Escuela* escu = new Escuela(nombre);

	CE->insertaralInicio(escu);
	system("cls");
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
	cout << endl << string("Perfecto!");
	Sleep(1500);
	system("cls");
}

void Interfaz::msjPausa()
{
	cout << "Presione cualquier tecla para continuar..." << endl;
	_getch();
}

void Interfaz::vtoString(Universidad* U) //Modificar para que sirva de informacion actual del sistema de matricula
{
	if (U->getNombre() == "Undefined" && U->getNumero() == "Undefined")
		cout << "Ups... parece que no se han ingresado todos los datos de la Universidad. Ve a Ajustes para agregarlos." << endl;
	else
		cout << U->toString() << endl;

	msjPausa();
	system("cls");
}

void Interfaz::vtoStringEscuelas(Universidad* U, Contenedor_Escuelas* CE)
{
	if (U->getNombre() == "Undefined")
		cout << "No se ha ingresado el nombre de la Universidad. Vaya a Ajustes." << endl;
	else
	{
		cout << "Nombre de la Universidad: " << U->getNombre() << endl << endl;
		cout << CE->toString() << endl;
	}
	msjPausa();
	system("cls");
}


