#include "interfazMatricula.h"


char Interfaz_Matricula::vMenuMatricula()
{
	char ans;
	cout << "**************MENU MATRICULA**************" << endl;
	cout << "(1)--Matricular Estudiante en Curso" << endl;
	cout << "(2)--Consultar lista de Estudiantes de un Curso" << endl;
	cout << "(3)--Consultar lista de Cursos de un Estudiante" << endl;
	cout << "(4)--Consulta de cobro de Matricula de Estudiante" << endl;
	cout << "(5)--Ajustes" << endl;
	cout << "(6)--Salir" << endl;
	cout << "********************************************" << endl;
	Interfaz_Principal::msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '6') {
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
		string cedula; cin >> cedula; cin.ignore();
		Estudiante* EST = U->getContenedorEstudiantes()->retornaEstudiante(cedula);
		if (EST == nullptr) throw 1;

		cout << U->getControladorEscuelas()->toStringConCursos();
		cout << "Digite el codigo del curso en el cual desea matricular a " << EST->getNombreCompleto() << endl;
		cout << "-> "; string codigo; cin >> codigo; codigo = Interfaz_Principal::convierteMayuscula(codigo); cin.ignore();
		Curso* C = U->getControladorEscuelas()->retornaEscuela(codigo.substr(0, 3))->getContenedorCursos()->retornaCursoEspecifico(codigo);
		if (C == nullptr) throw 2;

		for (int i = 0; i < 5; i++) {
			if (C->getGrupo(i)->getCantidad() < CUPOMAXIMO) {
				C->getGrupo(i)->agregarEstudiante(EST);
				/*	EST->agregaCurso(C);*/
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
	cout << "-> "; string cedula; cin >> cedula; cin.ignore();
	Estudiante *E = U->getContenedorEstudiantes()->retornaEstudiante(cedula);
	try {
		if (E == nullptr) throw 1;

		cout << E->getCursosMatriculados()->toString() << endl;
	}
	catch (int e) {
		if (e == 0) cout << "No hay estudiantes matriculados aun..." << endl << endl;
		if (e == 1) cout << "El estudiante no se encuentra..." << endl << endl;
	}
	Interfaz_Principal::msjPausa();
	system("cls");
}

void Interfaz_Matricula::vMatriculaListaEstudiantesCursos(Universidad *U) {
	cout << U->getControladorEscuelas()->toStringConCursos();
	try {
		cout << "Digite el codigo del curso a consultar la lista de Estudiantes Matriculados" << endl;
		cout << "-> "; string codigo; cin >> codigo; codigo = Interfaz_Principal::convierteMayuscula(codigo); cin.ignore();
		string sigla = codigo.substr(0, 3);
		cout << U->getControladorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->retornaCursoEspecifico(codigo)->imprimeEstudiantesMatriculados();
	}
	catch (...) {
		cout << "Error..." << endl;
	}
	Interfaz_Principal::msjPausa();
	system("cls");
}

void Interfaz_Matricula::vCobroMatricula(Universidad *U)
{
	cout << "Calculando cobro..." << endl;
	try {
		cout << "Ingrese el numero de cedula del Estudiante a consultar -> "; string cedula; cin >> cedula; cin.ignore();
		Estudiante *E = U->getContenedorEstudiantes()->retornaEstudiante(cedula);
		if (E == nullptr) throw 1;
		double cobro = 0.0;
		for (int i = 0; i < E->getCantidadCursosMatriculados(); i++)
			cobro += Aranceles::cobroMatricula(E->getCursosMatriculados()->getCursoporPos(i), E);
		cout << "El costo de la matricula del estudiante es de -> " << cobro << endl;
	}
	catch (int e) {
		if (e == 1) cout << "El estudiante no existe..." << endl << endl;
	}
}
