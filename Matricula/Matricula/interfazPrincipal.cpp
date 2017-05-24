#include "interfazPrincipal.h"
#include <Windows.h>
#include <conio.h>
#include <sstream>
#include <string>
#include <iostream>
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

char Interfaz_Principal::vMenuUniversidad()
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

char Interfaz_Principal::vAjustesUniversidad(Universidad *U) {
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

char Interfaz_Principal::vMenuEstudiantes() {
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

char Interfaz_Principal::vAjustesEstudiantes() {
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

void Interfaz_Principal::vIngresarNumero(Universidad* U)
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

void Interfaz_Principal::vIngresarDireccion(Universidad* U)
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

void Interfaz_Principal::vIngresarNombre(Universidad* U)
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

void Interfaz_Principal::vInfoUniversidad(Universidad* U) //Modificar para que sirva de informacion actual del sistema de matricula
{
	if (U->getNombre() == "Undefined" && U->getNumero() == "Undefined")
		cout << "Ups... parece que no se han ingresado todos los datos de la Universidad. Ve a Ajustes para agregarlos." << endl;
	else
		cout << *U << endl;

	msjPausa();
	system("cls");
}

char Interfaz_Principal::vMenuProfesores() {
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

char Interfaz_Principal::vAjustesProfesores() {
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

void Interfaz_Principal::vAgregarProfesor(Universidad* U) {
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

void Interfaz_Principal::vConsultarProfesEscuela(Universidad* U) {
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

void Interfaz_Principal::vConsultarProfeCedula(Universidad *U)
{
	cout << "Digite la cedula del profesor a consultar -> "; int cedula; cin >> cedula; cin.ignore();

	if (!U->getContenedorEscuelas()->retornaProfesor(cedula))
		cout << "El Profesor no ha sido encontrado..." << endl;
	else
		cout << *(U->getContenedorEscuelas()->retornaProfesor(cedula)) << endl;

	msjPausa();
	system("cls");
}

void Interfaz_Principal::vConsultarProfesCurso(Universidad *U) {
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

void Interfaz_Principal::vAsignarProfesorCurso(Universidad *U)
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

void Interfaz_Principal::vDeasignarProfesorCurso(Universidad *U)
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

void Interfaz_Principal::vEditarProfesor(Universidad *U)
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

void Interfaz_Principal::vIngresarEstudiante(Universidad *U) {
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

void Interfaz_Principal::vConsultaEstudiante(Universidad *U)
{
	cout << "Digite la cedula del estudiante a consultar -> "; int cedula; cin >> cedula; cin.ignore();

	if (U->getContenedorEstudiantes()->retornaEstudiante(cedula) == NULL)
		cout << "El Estudiante no ha sido encontrado..." << endl;
	else
		cout << *(U->getContenedorEstudiantes()->retornaEstudiante(cedula)) << endl;

	msjPausa();
	system("cls");
}

void Interfaz_Principal::vEditarEstudiante(Universidad *U) {


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

void Interfaz_Principal::vConsultaCursosAsignadosProfesor(Universidad *U)
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

char Interfaz_Principal::vMenuMatricula()
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

bool Interfaz_Principal::vMatriculaEstudianteCurso(Universidad *U)
{
	

	try {
		if (U->getContenedorEstudiantes()->getCantidadEstudiantes() == 0)
			throw 0;
		cout << "Digite el numero de cedula del estudiante que desea matricular un curso..." << endl;
		int cedula; cin >> cedula; cin.ignore();
		Estudiante* EST = U->getContenedorEstudiantes()->retornaEstudiante(cedula);
		if (EST == nullptr) throw 1;

		cout << U->getContenedorEscuelas()->toString('2');
		cout << "Digite el codigo del curso en el cual desea matricular a " << EST->getNombreCompleto() << endl;
		cout << "-> "; string codigo; cin >> codigo; codigo = convierteMayuscula(codigo); cin.ignore();
		Curso* C = U->getContenedorEscuelas()->retornaEscuela(codigo.substr(0, 3))->getContenedorCursos()->retornaCursoEspecifico(codigo);
		if (C == nullptr) throw 2;

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
		if (e == 0)
			cout << "No hay estudiantes matriculados aun..." << endl << endl;
		if (e == 1)
			cout << "No existe el Estudiante con esa cedula " << endl << endl;
		if (e == 2)
			cout << "No existe el curso con ese codigo " << endl << endl;
		if (e == 3)
			cout << "No hay espacio en este curso" << endl << endl;
	}
	catch (...) {
		cout << "Error desconocido..." << endl << endl;
	}
	msjPausa();
	system("cls");
	return false;
}

void Interfaz_Principal::vMatriculaListaCursosEstudiante(Universidad *U) {
	if (U->getContenedorEstudiantes()->getCantidadEstudiantes() == 0)
		throw 0;
	cout << "Digite el numero de cedula del Estudiante a consultar lista de Cursos Matriculados..." << endl;
	cout << "-> "; int cedula; cin >> cedula; cin.ignore();
	Estudiante *E = U->getContenedorEstudiantes()->retornaEstudiante(cedula);
	try {
		if (E == nullptr) throw 1;

		cout << U->getContenedorEstudiantes()->retornaEstudiante(cedula)->imprimeCursos();
	}
	catch (int e) {
		if (e == 0) cout << "No hay estudiantes matriculados aun..." << endl << endl;
		if (e == 1) cout << "El estudiante no se encuentra..." << endl << endl;
	}
	msjPausa();
	system("cls");
}

void Interfaz_Principal::vMatriculaListaEstudiantesCursos(Universidad *U) {
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



