#include "interfazMatricula.h"
#include "interfazPrincipal.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

char Interfaz_Matricula::vMenuMatricula()
{
	char ans;
	cout << "**************MENU MATRICULA**************" << endl;
	cout << "(1)--Matricular Estudiante en Curso" << endl;
	cout << "(2)--Consultar lista de Estudiantes de un Curso" << endl;
	cout << "(3)--Consultar lista de Cursos de un Estudiante" << endl;
	cout << "(4)--Ajustes" << endl;
	cout << "(5)--Salir" << endl;
	cout << "********************************************" << endl;
	Interfaz_Principal::msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '5') {
		cout << "Opcion Incorrecta. Intente de nuevo. " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

bool Interfaz_Matricula::vMatriculaEstudianteCurso(Universidad *U)
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
		cout << "-> "; string codigo; cin >> codigo; codigo = Interfaz_Principal::convierteMayuscula(codigo); cin.ignore();
		Curso* C = U->getContenedorEscuelas()->retornaEscuela(codigo.substr(0, 3))->getContenedorCursos()->retornaCursoEspecifico(codigo);
		if (C == nullptr) throw 2;

		for (int i = 0; i < 5; i++) {
			if (C->getGrupoEstudiantes(i)->getCantidad() < MAXESTU) {
				C->getGrupoEstudiantes(i)->agregarEstudiante(EST);
				EST->agregaCurso(codigo);
				Interfaz_Principal::msjPerfecto();
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
	Interfaz_Principal::msjPausa();
	system("cls");
	return false;
}

void Interfaz_Matricula::vMatriculaListaCursosEstudiante(Universidad *U) {
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
	Interfaz_Principal::msjPausa();
	system("cls");
}

void Interfaz_Matricula::vMatriculaListaEstudiantesCursos(Universidad *U) {
	cout << U->getContenedorEscuelas()->toString('2');
	try {
		cout << "Digite el codigo del curso a consultar la lista de Estudiantes Matriculados" << endl;
		cout << "-> "; string codigo; cin >> codigo; codigo = Interfaz_Principal::convierteMayuscula(codigo); cin.ignore();
		string sigla = codigo.substr(0, 3);
		cout << U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->retornaCursoEspecifico(codigo)->imprimeEstudiantesMatriculados();
	}
	catch (...) {
		cout << "Error..." << endl;
	}
	Interfaz_Principal::msjPausa();
	system("cls");
}