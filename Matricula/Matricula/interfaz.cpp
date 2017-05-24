#include "interfaz.h"
#include <Windows.h>
#include <conio.h>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

enum errores { NOENCONTRADO = 1, DATOERRONEO };

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

char Interfaz::vMenuUniversidad()
{
	char ans;
	cout << "**************MENU UNIVERSIDAD**************" << endl;
	cout << "(1)--Informacion acerca de la Universidad" << endl;
	cout << "(2)--Ajustes" << endl;
	cout << "(3)--Salir" << endl;
	cout << "********************************************" << endl;
	msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '3') {
		cout << "Opcion Incorrecta. Intente de nuevo. " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

char Interfaz::vAjustesUniversidad(Universidad *U) {
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
		msjIngreseOpcion();
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
		msjIngreseOpcion();
		ans = _getch();

		while (ans < '1' || ans > '3') {
			cout << "Opcion Incorrecta. Try again " << endl;
			ans = _getch();
		}
	}
	system("cls");
	return ans;
}

char Interfaz::vMenuEscuelas()
{
	char ans;
	cout << "**************MENU ESCUELAS**************" << endl;
	cout << "(1)--Consulta de la lista de Escuelas" << endl;
	cout << "(2)--Consulta de la lista de Escuelas (+ Cursos)" << endl;
	cout << "(3)--Ajustes" << endl;
	cout << "(4)--Salir" << endl;
	cout << "********************************************" << endl;
	msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '4')
	{
		cout << "Opcion Incorrecta. Intente de nuevo. " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

char Interfaz::vAjustesEscuelas()
{
	char ans;
	cout << "***************AJUSTES ESCUELAS***************" << endl;
	cout << "(1)--Ingresar Escuela" << endl;
	cout << "(2)--Salir" << endl;
	msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '2')
	{
		cout << "Opcion Incorrecta. Try again " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

char Interfaz::vMenuCursos()
{
	char ans;
	cout << "**************MENU CURSOS**************" << endl;
	cout << "(1)--Consultar curso" << endl;
	cout << "(2)--Consultar lista de cursos de una Escuela" << endl;
	cout << "(3)--Ajustes" << endl;
	cout << "(4)--Salir" << endl;
	cout << "********************************************" << endl;
	msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '4')
	{
		cout << "Opcion Incorrecta. Intente de nuevo. " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

char Interfaz::vAjustesCursos()
{
	char ans;
	cout << "***************AJUSTES CURSOS***************" << endl;
	cout << "-(1)-Ingresar Curso" << endl;
	cout << "-(2)-Editar Curso" << endl;
	cout << "-(3)-Eliminar Curso" << endl;
	cout << "-(4)-Salir" << endl;
	msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '4')
	{
		cout << "Opcion Incorrecta. Try again " << endl;
		ans = _getch();
	}
	system("cls");
	return ans;
}

char Interfaz::vMenuEstudiantes() {
	char ans;
	cout << "***************MENU ESTUDIANTES***************" << endl;
	cout << "-(1)-Info Estudiantes" << endl;
	cout << "-(2)-Ajustes" << endl;
	cout << "-(3)-Salir" << endl;
	msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '3')
	{
		cout << "Opcion Incorrecta. Try again " << endl;
		ans = _getch();
	}
	system("cls");
	return ans;
}

char Interfaz::vAjustesEstudiantes() {
	char ans;
	cout << "***************AJUSTES ESTUDIANTES***************" << endl;
	cout << "-(1)-Ingresar Estudiante" << endl;
	cout << "-(2)-Editar Estudiante" << endl;
	cout << "-(3)-Salir" << endl;
	msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '3')
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

void Interfaz::vIngresarNumero(Universidad* U)
{
	char ans;

	do
	{
		Sleep(500);
		cout << "Ingrese el numero de telefono -> "; string numero;
		cin >> numero; cin.ignore();

		while (chequeaNumero(numero) == false) //No le permite al usuario ingresar un algo que no sean numeros
		{
			cout << "Numero Invalido. Intente de nuevo";
			Sleep(800);
			system("cls");
			cout << string("Ingrese el numero de telefono -> ");
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

	U->getContenedorEscuelas()->insertarInicio(escu);

	system("cls");
}

void Interfaz::vIngresaCurso(Universidad* U)
{

	cout << "Nombre de la Universidad: " << U->getNombre() << endl << endl;
	cout << U->getContenedorEscuelas()->toString('1') << endl;

	cout << "Digite las siglas de la Escuela a la que desea ingresar el curso -> ";
	string sigla; cin >> sigla; cin.ignore();

	sigla = convierteMayuscula(sigla);

	while (!U->getContenedorEscuelas()->retornaEscuela(sigla)) {
		cout << "Escuela invalida. Favor digite una de las opciones dadas." << endl;
		cout << "-> ";
		cin >> sigla; cin.ignore();

		sigla = convierteMayuscula(sigla);
	}

	system("cls");
	string nombre;
	cout << "Ingrese el nombre del curso -> "; getline(cin, nombre); cout << endl;
	cout << "Curso: " << "\"" << nombre << "\" "; cout << "| es esta informacion correcta? ";

	char ans = vInfoConfirmacion();

	while (nombre == "Undefined" || nombre == " " || nombre == "") {
		cout << "Nombre Invalido. Intente de nuevo -> ";
		Sleep(800);
		system("cls");
		cout << "Ingrese el nombre del curso  -> "; std::getline(std::cin, nombre); cout << endl << endl;
	}

	Curso* cur = new Curso(nombre, sigla);

	U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->insertaInicio(cur);

	msjPerfecto();
	system("cls");
}

void Interfaz::vEditarCurso(Universidad *U)
{
	cout << U->getContenedorEscuelas()->toString('2');
	cout << "Ingrese el codigo del curso que desea editar -> ";
	string codigo, sigla;

	cin >> codigo; cin.ignore();

	codigo = convierteMayuscula(codigo);
	sigla = codigo.substr(0, 3);

	if (!U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->retornaCursoEspecifico(codigo))
		cout << "El curso no ha sido encontrado..." << endl;
	else {
		string nombre;
		cout << "Ingrese el nuevo nombre del curso -> "; getline(cin, nombre); cout << endl;

		cout << "Curso: " << "\"" << nombre << "\" "; cout << "| es esta informacion correcta? ";

		char ans = vInfoConfirmacion();

		while (nombre == "Undefined" || nombre == " " || nombre == "") {
			cout << "Nombre Invalido. Intente de nuevo -> ";
			Sleep(800);
			system("cls");
			cout << "Ingrese el nuevo nombre del curso  -> "; std::getline(std::cin, nombre); cout << endl << endl;
		}

		U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->
			retornaCursoEspecifico(codigo)->setNombre(nombre);

		msjPerfecto();
	}

	msjPausa();
	system("cls");
}

void Interfaz::vEliminaCurso(Universidad *U) //debe implementarse mejor
{
	cout << U->getContenedorEscuelas()->toString('2') << endl;
	cout << "Ingrese el codigo del curso que desea eliminar -> ";
	string codigo, sigla, aux;
	cin >> aux; cin.ignore();

	codigo = convierteMayuscula(aux);
	sigla = codigo.substr(0, 3);

	if (U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->eliminaCursoEspecifico(codigo))
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

	if (U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->retornaCursoEspecifico(codigo) == nullptr)
		cout << "El curso no ha sido encontrado..." << endl;
	else
		cout << *(U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->retornaCursoEspecifico(codigo)) << endl;

	msjPausa();
	system("cls");
}

void Interfaz::vListaCursosEscuelaParticular(Universidad *U) {
	cout << U->getContenedorEscuelas()->toString('1'); //Imprime lista de Escuelas con sus respectivos cursos
	string sigla;
	cout << "Ingrese la sigla de la escuela que desea consultar la lista de cursos -> ";
	cin >> sigla; cin.ignore();
	sigla = convierteMayuscula(sigla);
	if (!U->getContenedorEscuelas()->retornaEscuela(sigla))
		cout << "La escuela no ha sido encontrada..." << endl;
	else {
		Escuela *EE = U->getContenedorEscuelas()->retornaEscuela(sigla);
		for (int i = 0; i < EE->getContenedorCursos()->getCantidad(); i++) {  //algoritmo mortal xxxxxx
			cout << "Curso: " << EE->getContenedorCursos()->getCursoporPos(i)->getNombre() << endl;
			cout << "Profesores:" << endl;
			for (int x = 0; x < EE->getContenedorCursos()->getCursoporPos(i)->getGrupoProfesores()->getCantidadProfesores(); x++) {
				int cedulaProfe = EE->getContenedorCursos()->getCursoporPos(i)->getGrupoProfesores()->getProfesor(x)->getNumCedula();
				cout << U->getContenedorEscuelas()->retornaProfesor(cedulaProfe)->getNombreCompleto() << endl;
			}
		}
	}
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

void Interfaz::msjIngreseOpcion()
{
	cout << "Ingrese una opcion -> ";
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

char Interfaz::vMenuProfesores() {
	char ans;
	cout << "**************MENU PROFESORES**************" << endl;
	cout << "(1)--Consultar lista de Profesores por Escuela" << endl;
	cout << "(2)--Consultar lista de Profesores por Curso" << endl;
	cout << "(3)--Buscar Profesor por Cedula" << endl;
	cout << "(4)--Consulta de Cursos asignados a un Profesor" << endl;
	cout << "(5)--Ajustes" << endl;
	cout << "(6)--Salir" << endl;
	cout << "********************************************" << endl;
	msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '6')
	{
		cout << "Opcion Incorrecta. Intente de nuevo. " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

char Interfaz::vAjustesProfesores() {
	char ans;
	cout << "***************AJUSTES PROFESORES***************" << endl;
	cout << "(1)--Agregar Profesor" << endl;
	cout << "(2)--Editar Profesor" << endl;
	cout << "(3)--Asignar Profesor a Curso" << endl;
	cout << "(4)--Salir" << endl;
	msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '4') {
		cout << "Opcion Incorrecta. Try again " << endl;
		ans = _getch();
	}
	system("cls");
	return ans;
}

void Interfaz::vAgregarProfesor(Universidad* U) {
	cout << "Agregando profesor..." << endl;
	cout << "Ingrese el primer apellido: "; string primerApellido; cin >> primerApellido; cin.ignore(); cout << endl;
	cout << "Ingrese el segundo apellido: "; string segundoApellido; cin >> segundoApellido; cin.ignore(); cout << endl;
	cout << "Ingrese el nombre del profesor: "; string nombre; getline(cin, nombre); cout << endl;
	cout << "Ingrese el numero de cedula: "; int cedula; cin >> cedula; cin.ignore(); cout << endl;
	Profesor *P = new Profesor(nombre, primerApellido, segundoApellido, cedula);
	cout << U->getContenedorEscuelas()->toString('1') << endl;
	cout << "Ingrese la materia de la escuela a la cual desea asignar al nuevo profesor: "; string materia, sigla; cin >> materia; cin.ignore();


	sigla = convierteMayuscula(materia).substr(0, 3);

	while (!U->getContenedorEscuelas()->retornaEscuela(sigla)) {
		cout << "Escuela invalida. Favor digite una de las opciones dadas." << endl;
		cout << "-> ";
		cin >> sigla; cin.ignore();
		sigla = convierteMayuscula(sigla);
	}
	P->setEscuela(materia);
	U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorProfesores()->insertaInicio(P);
	msjPerfecto();
}

void Interfaz::vConsultarProfesEscuela(Universidad* U) {
	cout << "Nombre de la Universidad: " << U->getNombre() << endl << endl;
	cout << U->getContenedorEscuelas()->toString('1') << endl;

	cout << "Digite las siglas de la Escuela a consultar la lista de Profesores -> ";
	string sigla; cin >> sigla; cin.ignore();
	sigla = convierteMayuscula(sigla);

	while (U->getContenedorEscuelas()->retornaEscuela(sigla) == nullptr) {
		cout << "Escuela invalida. Favor digite una de las opciones dadas." << endl;
		cout << "-> ";
		cin >> sigla; cin.ignore();

		sigla = convierteMayuscula(sigla);
	}

	string verifica = U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorProfesores()->toString();
	if (verifica == "")
		cout << "No hay profesores asignados a esta Escuela aun.";
	else
		cout << verifica;

	msjPausa();
	system("cls");
}

void Interfaz::vConsultarProfeCedula(Universidad *U)
{
	cout << "Digite la cedula del profesor a consultar -> "; int cedula; cin >> cedula; cin.ignore();

	if (!U->getContenedorEscuelas()->retornaProfesor(cedula))
		cout << "El Profesor no ha sido encontrado..." << endl;
	else
		cout << *(U->getContenedorEscuelas()->retornaProfesor(cedula)) << endl;

	msjPausa();
	system("cls");
}

void Interfaz::vConsultarProfesCurso(Universidad *U) {
	cout << U->getContenedorEscuelas()->toString('2'); //Imprime la lista de escuelas con sus respectivos cursos
	string codigo, sigla;
	cout << "Ingrese el codigo de la curso del que desea consultar su lista de profesores -> ";
	cin >> codigo; cin.ignore();

	codigo = convierteMayuscula(codigo);
	sigla = codigo.substr(0, 3);

	Escuela* e = U->getContenedorEscuelas()->retornaEscuela(sigla);
	Curso* c = e->getContenedorCursos()->retornaCursoEspecifico(codigo);
	int contador = c->getGrupoProfesores()->getCantidadProfesores();
	if (!e)
		cout << "La escuela no ha sido encontrada..." << endl;
	else
		if (contador == 0)
			cout << "El curso no tiene profesores asignados..." << endl;
		else {
			cout << "El curso: " << c->getNombre() << " es impartido por los profesores: " << endl;
			for (int i = 0; i < contador; i++) {
				if (e->getContenedorProfesores()->retornaProfesor(c->getGrupoProfesores()->getProfesor(i)->getNumCedula()))
					cout << e->getContenedorProfesores()->retornaProfesor(c->getGrupoProfesores()->getProfesor(i)->getNumCedula())->getNombreCompleto() << endl;;

			}
		}

		msjPausa();
		system("cls");
}

void Interfaz::vAsignarProfesorCurso(Universidad *U)
{
	cout << "Asignando profesor a un curso..." << endl;
	cout << "Digite el numero de identificacion del profesor al cual desea asignar un curso -> "; int cedula; cin >> cedula; cin.ignore();
	Profesor *P = U->getContenedorEscuelas()->retornaProfesor(cedula);
	if (!P)
		cout << "El profesor con el numero de cedula" << cedula << " no existe." << endl;
	else {
		cout << "El profesor " << P->getNombreCompleto() << " | " << P->getEscuela() << endl;
		cout << "Imparte actualmente " << P->getCantidadCursos() << " | " << "Max Cursos/Profesor: " << P->getMaxCursos() << endl;
		if (P->getCantidadCursos() > P->getMaxCursos())
			cout << "No se pueden asignar mas cursos a este profesor." << endl;
		else {
			string sigla = P->getEscuela().substr(0, 3);
			sigla = convierteMayuscula(sigla);

			cout << U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->toString() << endl;
			cout << "Digite el codigo del Curso al que desea asignar al Profesor " << P->getSegundoApellido() << " -> ";
			string codigo; cin >> codigo; cin.ignore();
			codigo = convierteMayuscula(codigo);

			Curso * C = U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->retornaCursoEspecifico(codigo);
			C->getGrupoProfesores()->agregarProfesor(P);
			C->getGrupoEstudiantes(0)->setProfesorEncargado(P); // hay que poner el grupo en el que va a dar clases
			P->setCursosImpartidos(codigo);
			msjPerfecto();
		}
	}
	msjPausa();
	system("cls");
}

void Interfaz::vDeasignarProfesorCurso(Universidad *U)
{
	cout << "Desasignando profesor de un curso..." << endl;
	cout << "Digite el numero de identificacion del profesor al cual desea desasignar de un curso -> "; int cedula; cin >> cedula; cin.ignore();
	Profesor *P = U->getContenedorEscuelas()->retornaProfesor(cedula);
	if (!P)
		cout << "El profesor con el numero de cedula" << cedula << " no existe." << endl;
	else {
		cout << "El profesor " << P->getNombreCompleto() << " | " << P->getEscuela() << endl;
		cout << "Imparte actualmente " << endl;
		cout << U->getContenedorEscuelas()->retornaEscuela(P->getEscuela().substr(0, 3))->getContenedorCursos()->toString() << endl;
		cout << "Digite el codigo del Curso al que desea desasignar al Profesor " << P->getSegundoApellido() << " -> ";
		string codigo; cin >> codigo; cin.ignore();
		codigo = convierteMayuscula(codigo);
		string sigla = codigo.substr(0, 3);

		if (P->eliminarCursoImpartido(codigo)) {
			Curso * C = U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->retornaCursoEspecifico(codigo);
			C->getGrupoProfesores()->eliminarProfesor(P->getNumCedula());
			msjPerfecto();
		}
		else
			cout << "Ha ocurrido un error..." << endl;
	}
	msjPausa();
	system("cls");

}

void Interfaz::vEditarProfesor(Universidad *U)
{
	cout << "Digite el numero de cedula del profesor -> ";
	int cedula = 0; cin >> cedula; cin.ignore();
	if (U->getContenedorEscuelas()->retornaProfesor(cedula)) {
		Profesor *P = U->getContenedorEscuelas()->retornaProfesor(cedula);
		cout << "Ingrese el primer apellido: "; string primerApellido; cin >> primerApellido; cin.ignore(); cout << endl;
		cout << "Ingrese el segundo apellido: "; string segundoApellido; cin >> segundoApellido; cin.ignore(); cout << endl;
		cout << "Ingrese el nombre del profesor: "; string nombre; getline(cin, nombre); cout << endl;
		P->setNombre(nombre); P->setPrimerApellido(primerApellido); P->setSegundoApellido(segundoApellido);
		msjPerfecto();

	}
	else
		cout << "No se ha encontrado el profesor con ese numero de cedula..." << endl;

	msjPausa();
	system("cls");
}

void Interfaz::vIngresarEstudiante(Universidad *U) {
	cout << "Agregando estudiante..." << endl; int porcentaje = 0;
	cout << "Ingrese el primer apellido: "; string primerApellido; cin >> primerApellido; cin.ignore(); cout << endl;
	cout << "Ingrese el segundo apellido: "; string segundoApellido; cin >> segundoApellido; cin.ignore(); cout << endl;
	cout << "Ingrese el nombre del estudiante: "; string nombre; getline(cin, nombre); cout << endl;
	cout << "Ingrese el numero de cedula: "; int cedula; cin >> cedula; cin.ignore(); cout << endl;
	cout << "Es un estudiante de nacionalidad extranjera?: "; Estudiante *E;
	if (char ans = vInfoConfirmacion() == 'N') {
		cout << "Ingrese el porcentaje de beca (0-100): "; cin >> porcentaje; cin.ignore(); cout << endl;
		E = new Estudiante_Nacional(nombre, primerApellido, segundoApellido, cedula, porcentaje);
	}
	else
		E = new Estudiante_Extranjero(nombre, primerApellido, segundoApellido, cedula);

	U->getContenedorEstudiantes()->insertaInicio(E);
	msjPerfecto();
}

void Interfaz::vConsultaEstudiante(Universidad *U)
{
	cout << "Digite la cedula del estudiante a consultar -> "; int cedula; cin >> cedula; cin.ignore();

	if (U->getContenedorEstudiantes()->retornaEstudiante(cedula) == NULL)
		cout << "El Estudiante no ha sido encontrado..." << endl;
	else
		cout << *(U->getContenedorEstudiantes()->retornaEstudiante(cedula)) << endl;

	msjPausa();
	system("cls");
}

void Interfaz::vEditarEstudiante(Universidad *U) {


	string primerApellido, segundoApellido, nombre;
	cout << "Digite el numero de cedula del Estudiante -> ";
	int cedula; cin >> cedula; cin.ignore();
	if (U->getContenedorEstudiantes()->retornaEstudiante(cedula)) {
		Estudiante *E = U->getContenedorEstudiantes()->retornaEstudiante(cedula);
		cout << "Ingrese el primer apellido: "; cin >> primerApellido; cin.ignore(); cout << endl;
		cout << "Ingrese el segundo apellido: "; cin >> segundoApellido; cin.ignore(); cout << endl;
		cout << "Ingrese el nombre del Estudiante: "; getline(cin, nombre); cout << endl;
		cout << "Es un estudiante de nacionalidad extranjera?: ";
		if (char ans = vInfoConfirmacion() == 'N') {
			cout << "Ingrese el porcentaje de beca (0-100): "; int porcentaje; cin >> porcentaje; cin.ignore(); cout << endl;
			E->setEsExtranjero(false);
			E->setPorcentajeBeca(porcentaje);
		}
		else {
			E->setEsExtranjero(true);
			E->setPorcentajeBeca(0);
		}
		E->setNombre(nombre); E->setPrimerApellido(primerApellido); E->setSegundoApellido(segundoApellido); E->generaCarnet();
	}
	else
		cout << "No se ha encontrado el profesor con ese numero de cedula..." << endl;

	msjPausa();
	system("cls");
}

void Interfaz::vConsultaCursosAsignadosProfesor(Universidad *U)
{
	cout << "Digite el numero de identificacion del profesor a consultar ->"; int cedula; cin >> cedula; cin.ignore();
	if (U->getContenedorEscuelas()->retornaProfesor(cedula)) {
		cout << "El profesor " << U->getContenedorEscuelas()->retornaProfesor(cedula)->getNombreCompleto() << " imparte los cursos: " << endl;
		cout << U->getContenedorEscuelas()->retornaProfesor(cedula)->getCursosImpartidos() << endl;
	}
	else
		cout << "El profesor con la cedula " << cedula << " no existe" << endl;

	msjPausa();
	system("cls");
}

char Interfaz::vMenuMatricula()
{
	char ans;
	cout << "**************MENU MATRICULA**************" << endl;
	cout << "(1)--Matricular Estudiante en Curso" << endl;
	cout << "(2)--Consultar lista de Estudiantes de un Curso" << endl;
	cout << "(3)--Consultar lista de Cursos de un Estudiante" << endl;
	cout << "(4)--Ajustes" << endl;
	cout << "(5)--Salir" << endl;
	cout << "********************************************" << endl;
	msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '5') {
		cout << "Opcion Incorrecta. Intente de nuevo. " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

bool Interfaz::vMatriculaEstudianteCurso(Universidad *U)
{
	cout << "Digite el numero de cedula del estudiante que desea matricular un curso..." << endl;

	try {
		int cedula; cin >> cedula; cin.ignore();
		Estudiante* EST = U->getContenedorEstudiantes()->retornaEstudiante(cedula);
		if (EST == nullptr)
			throw 1;
		cout << U->getContenedorEscuelas()->toString('2');
		cout << "Digite el codigo del curso en el cual desea matricular a " << EST->getNombreCompleto() << endl;
		cout << "-> "; string codigo; cin >> codigo; codigo = convierteMayuscula(codigo); cin.ignore();
		Curso* C = U->getContenedorEscuelas()->retornaEscuela(codigo.substr(0, 3))->getContenedorCursos()->retornaCursoEspecifico(codigo);
		if (C == nullptr)
			throw 2;

		for (int i = 0; i < 5; i++) {
			if (C->getGrupoEstudiantes(i)->getCantidad() < MAXESTU) {
				C->getGrupoEstudiantes(i)->agregarEstudiante(EST);
				EST->agregaCurso(codigo);
				msjPerfecto();
				return true;
			}
			throw 3;
		}
	}
	catch (int e) {
		if (e == 1)
			cout << "No existe el Estudiante con esa cedula " << endl;
		if (e == 2)
			cout << "No existe el curso con ese codigo " << endl;
		if (e == 3)
			cout << "No hay espacio en este curso" << endl;
	}
	catch (...) {
		cout << "Error desconocido..." << endl;
	}
	msjPausa();
	system("cls");
	return false;
}

void Interfaz::vMatriculaListaCursosEstudiante(Universidad *U) {
	cout << "Digite el numero de cedula del Estudiante a consultar lista de Cursos Matriculados..." << endl;
	cout << "-> "; int cedula; cin >> cedula; cin.ignore();
	try {
		cout << U->getContenedorEstudiantes()->retornaEstudiante(cedula)->imprimeCursos();
		throw;
	}
	catch (...) {
		cout << "El estudiante no se encuentra..." << endl;
	}
	msjPausa();
	system("cls");
}

void Interfaz::vMatriculaListaEstudiantesCursos(Universidad *U) {
	cout << U->getContenedorEscuelas()->toString('2');
	try {
		cout << "Digite el codigo del curso a consultar la lista de Estudiantes Matriculados" << endl;
		cout << "-> "; string codigo; cin >> codigo; codigo = convierteMayuscula(codigo); cin.ignore();
		string sigla = codigo.substr(0, 3);
		cout << U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->retornaCursoEspecifico(codigo)->imprimeEstudiantesMatriculados();
	}
	catch (...) {
		cout << "Error..." << endl;
	}
	msjPausa();
	system("cls");
}



