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



