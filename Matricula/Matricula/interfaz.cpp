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
	cout << "(3)--Lista de Escuelas con sus respectivos cursos" << endl;
	cout << "(4)--Consultar Curso" << endl;
	cout << "(5)--Consultar Lista de Cursos de una Escuela" << endl;
	cout << "(6)--Ajustes" << endl;
	cout << "(7)--Salir" << endl;
	cout << "******************************************" << endl;

	ans = _getch();

	while (ans < '1' || ans > '7')
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

		while (ans < '1' || ans > '4')
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
		cout << "-(4)-Ingresar Curso" << endl;
		cout << "-(5)-Eliminar Curso" << endl;
		cout << "-(6)-Salir" << endl;

		ans = _getch();

		while (ans < '1' || ans > '6')
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

void Interfaz::vIngresaEscuela(Universidad* U)
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
		cout << "Ingrese el nombre de la escuela  -> "; std::getline(std::cin, nombre); cout << endl << endl;
	}

	Escuela* escu = new Escuela(nombre);

	U->getContenedorEscuelas()->insertaralInicio(escu);
	system("cls");
}

void Interfaz::vIngresaCurso(Universidad* U)
{

	cout << "Nombre de la Universidad: " << U->getNombre() << endl << endl;
	cout << U->getContenedorEscuelas()->toString('1') << endl;

	cout << "Digite las siglas de la Escuela a la que desea ingresar el curso -> ";
	string sigla; cin >> sigla;

	sigla = convierteMayuscula(sigla);

	while (U->getContenedorEscuelas()->retornaEscuelaEspecifica(sigla) == nullptr)
	{
		cin.clear();
		cout << "Escuela invalida. Favor digite una de las opciones dadas." << endl;
		cout << "-> ";
		cin >> sigla;

		sigla = convierteMayuscula(sigla);
	}

	system("cls");
	cin.ignore();
	string nombre;
	cout << "Ingrese el nombre del curso -> "; getline(cin, nombre); cout << endl;

	cout << "Curso: " << "\"" << nombre << "\" "; cout << "| es esta informacion correcta? ";

	char ans = vInfoConfirmacion();

	while (nombre == "Undefined" || nombre == " " || nombre == "")
	{
		cout << "Nombre Invalido. Intente de nuevo -> ";
		Sleep(800);
		system("cls");
		cout << "Ingrese el nombre del curso  -> "; std::getline(std::cin, nombre); cout << endl << endl;
	}

	Curso* cur = new Curso(nombre, sigla);

	U->getContenedorEscuelas()->retornaEscuelaEspecifica(sigla)->insertarCurso(cur);

	msjPerfecto();

	system("cls");
}

void Interfaz::vEliminaCurso(Universidad *U) //debe implementarse mejor
{
	cout << U->getContenedorEscuelas()->toString('2') << endl;

	cout << "Ingrese el codigo del curso que desea eliminar -> ";
	string codigo, sigla, aux;

	cin >> aux;

	codigo = convierteMayuscula(aux);

	sigla = codigo.substr(0, 3);

	if (U->getContenedorEscuelas()->retornaEscuelaEspecifica(sigla)->retornaContenedorCursos()->eliminaCursoEspecifico(codigo))
		cout << "Curso eliminado con exito" << endl;
	else
		cout << "No se ha podido eliminar el curso." << endl;

	msjPausa();
	system("cls");
}

void Interfaz::vInfoCurso(Universidad *U) //necesita ser optimizado
{
	string codigo, sigla;
	cout << "Ingrese el codigo del curso que desea consultar -> ";
	cin >> codigo; cin.ignore();

	codigo = convierteMayuscula(codigo);
	sigla = codigo.substr(0, 3);

	if (U->getContenedorEscuelas()->retornaEscuelaEspecifica(sigla) == nullptr)
		cout << "El curso no ha sido encontrado..." << endl;
	else
		if (U->getContenedorEscuelas()->retornaEscuelaEspecifica(sigla)->retornaContenedorCursos()->retornaCursoEspecifico(codigo) == nullptr)
			cout << "El curso no ha sido encontrado..." << endl;
		else
			cout << *(U->getContenedorEscuelas()->retornaEscuelaEspecifica(sigla)->retornaContenedorCursos()->retornaCursoEspecifico(codigo)) << endl;

	msjPausa();
	system("cls");
}

void Interfaz::vListaCursosEscuelaParticular(Universidad *U)
{
	string sigla;
	cout << "Ingrese la sigla de la escuela que desea consultar la lista de cursos -> ";
	cin >> sigla;

	sigla = convierteMayuscula(sigla);

	if (U->getContenedorEscuelas()->retornaEscuelaEspecifica(sigla) == nullptr)
		cout << "La escuela no ha sido encontrada..." << endl;
	else
		cout << U->getContenedorEscuelas()->retornaEscuelaEspecifica(sigla)->toStringEscuela('2') << endl;

	msjPausa();
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

string Interfaz::convierteMayuscula(string minuscula)
{
	string mayuscula;

	for (int i = 0; i < minuscula.length(); i++)
	{
		mayuscula += toupper(minuscula[i]);
	}

	return mayuscula;
}

void Interfaz::vInfoUniversidad(Universidad* U) //Modificar para que sirva de informacion actual del sistema de matricula
{
	if (U->getNombre() == "Undefined" && U->getNumero() == "Undefined")
		cout << "Ups... parece que no se han ingresado todos los datos de la Universidad. Ve a Ajustes para agregarlos." << endl;
	else
		cout << *U << endl;

	msjPausa();
	system("cls");
}

void Interfaz::vInfoEscuelas(Universidad* U, char op)
{
	if (U->getNombre() == "Undefined")
		cout << "No se ha ingresado el nombre de la Universidad. Vaya a Ajustes." << endl;
	else
	{
		cout << "Nombre de la Universidad: " << U->getNombre() << endl << endl;
		cout << U->getContenedorEscuelas()->toString(op) << endl;
	}
	msjPausa();
	system("cls");
}




