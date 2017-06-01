#include "interfazProfesores.h"
#include "interfazPrincipal.h"
#include "profesor.h"
#include "curso.h"
#include "contenedorProfesores.h"
#include "contenedorCursos.h"
#include "contenedorEscuelas.h"
#include "grupoProfesores.h"
#include "grupoEstudiantes.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

char Interfaz_Profesores::vMenuProfesores() {
	char ans;
	cout << "**************MENU PROFESORES**************" << endl;
	cout << "(1)--Consultar lista de Profesores por Escuela" << endl;
	cout << "(2)--Consultar lista de Profesores por Curso" << endl;
	cout << "(3)--Buscar Profesor por Cedula" << endl;
	cout << "(4)--Consulta de Cursos asignados a un Profesor" << endl;
	cout << "(5)--Ajustes" << endl;
	cout << "(6)--Salir" << endl;
	cout << "********************************************" << endl;
	Interfaz_Principal::msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '6')
	{
		cout << "Opcion Incorrecta. Intente de nuevo. " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

char Interfaz_Profesores::vAjustesProfesores() {
	char ans;
	cout << "***************AJUSTES PROFESORES***************" << endl;
	cout << "(1)--Agregar Profesor" << endl;
	cout << "(2)--Editar Profesor" << endl;
	cout << "(3)--Asignar Profesor a Curso" << endl;
	cout << "(4)--Salir" << endl;
	Interfaz_Principal::msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '4') {
		cout << "Opcion Incorrecta. Try again " << endl;
		ans = _getch();
	}
	system("cls");
	return ans;
}

void Interfaz_Profesores::vAgregarProfesor(Universidad* U) {
	cout << "Agregando profesor..." << endl;
	cout << "Ingrese el primer apellido: "; string primerApellido; cin >> primerApellido; cin.ignore(); cout << endl;
	cout << "Ingrese el segundo apellido: "; string segundoApellido; cin >> segundoApellido; cin.ignore(); cout << endl;
	cout << "Ingrese el nombre del profesor: "; string nombre; getline(cin, nombre); cout << endl;
	cout << "Ingrese el numero de cedula: "; int cedula; cin >> cedula; cin.ignore(); cout << endl;
	Profesor *P = new Profesor(nombre, primerApellido, segundoApellido, cedula);
	cout << U->getContenedorEscuelas()->toString('1') << endl;
	cout << "Ingrese la materia de la escuela a la cual desea asignar al nuevo profesor: "; string materia, sigla; cin >> materia; cin.ignore();


	sigla = Interfaz_Principal::convierteMayuscula(materia).substr(0, 3);

	while (!U->getContenedorEscuelas()->retornaEscuela(sigla)) {
		cout << "Escuela invalida. Favor digite una de las opciones dadas." << endl;
		cout << "-> ";
		cin >> sigla; cin.ignore();
		sigla = Interfaz_Principal::convierteMayuscula(sigla);
	}
	P->setEscuela(materia);
	U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorProfesores()->agregarInicio(P);
	Interfaz_Principal::msjPerfecto();
}

void Interfaz_Profesores::vConsultarProfesEscuela(Universidad* U) {
	cout << "Nombre de la Universidad: " << U->getNombre() << endl << endl;
	cout << U->getContenedorEscuelas()->toString('1') << endl;

	cout << "Digite las siglas de la Escuela a consultar la lista de Profesores -> ";
	string sigla; cin >> sigla; cin.ignore();
	sigla = Interfaz_Principal::convierteMayuscula(sigla);

	while (U->getContenedorEscuelas()->retornaEscuela(sigla) == nullptr) {
		cout << "Escuela invalida. Favor digite una de las opciones dadas." << endl;
		cout << "-> ";
		cin >> sigla; cin.ignore();

		sigla = Interfaz_Principal::convierteMayuscula(sigla);
	}

	string verifica = U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorProfesores()->toString();
	if (verifica == "")
		cout << "No hay profesores asignados a esta Escuela aun." << endl;
	else
		cout << verifica;

	Interfaz_Principal::msjPausa();
	system("cls");
}

void Interfaz_Profesores::vConsultarProfeCedula(Universidad *U)
{
	cout << "Digite la cedula del profesor a consultar -> "; int cedula; cin >> cedula; cin.ignore();

	if (!U->getContenedorEscuelas()->retornaProfesor(cedula))
		cout << "El Profesor no ha sido encontrado..." << endl;
	else
		cout << *(U->getContenedorEscuelas()->retornaProfesor(cedula)) << endl;

	Interfaz_Principal::msjPausa();
	system("cls");
}

void Interfaz_Profesores::vConsultarProfesCurso(Universidad *U) {
	cout << U->getContenedorEscuelas()->toString('2'); //Imprime la lista de escuelas con sus respectivos cursos
	string codigo, sigla;
	cout << "Ingrese el codigo de la curso del que desea consultar su lista de profesores -> ";
	cin >> codigo; cin.ignore();

	codigo = Interfaz_Principal::convierteMayuscula(codigo);
	sigla = codigo.substr(0, 3);

	Escuela* e = U->getContenedorEscuelas()->retornaEscuela(sigla);
	Curso* c = e->getContenedorCursos()->getCursoEspecifico(codigo);
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

		Interfaz_Principal::msjPausa();
		system("cls");
}

void Interfaz_Profesores::vAsignarProfesorCurso(Universidad *U)
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
			sigla = Interfaz_Principal::convierteMayuscula(sigla);

			cout << U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->toString() << endl;
			cout << "Digite el codigo del Curso al que desea asignar al Profesor " << P->getSegundoApellido() << " -> ";
			string codigo; cin >> codigo; cin.ignore();
			codigo = Interfaz_Principal::convierteMayuscula(codigo);

			Curso *C = U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->getCursoEspecifico(codigo);
			C->getGrupoProfesores()->agregarProfesor(P);
			C->getGrupoEstudiantes(0)->setProfesorEncargado(P); // hay que poner el grupo en el que va a dar clases
			P->agregaNuevoCursoImpartido(codigo);
			Interfaz_Principal::msjPerfecto();
		}
	}
	Interfaz_Principal::msjPausa();
	system("cls");
}

void Interfaz_Profesores::vDeasignarProfesorCurso(Universidad *U)
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
		codigo = Interfaz_Principal::convierteMayuscula(codigo);
		string sigla = codigo.substr(0, 3);

		if (P->eliminarCursoImpartido(codigo)) {
			Curso * C = U->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->getCursoEspecifico(codigo);
			C->getGrupoProfesores()->eliminarProfesor(P->getNumCedula());
			Interfaz_Principal::msjPerfecto();
		}
		else
			cout << "Ha ocurrido un error..." << endl;
	}
	Interfaz_Principal::msjPausa();
	system("cls");

}

void Interfaz_Profesores::vEditarProfesor(Universidad *U)
{
	cout << "Digite el numero de cedula del profesor -> ";
	int cedula = 0; cin >> cedula; cin.ignore();
	if (U->getContenedorEscuelas()->retornaProfesor(cedula)) {
		Profesor *P = U->getContenedorEscuelas()->retornaProfesor(cedula);
		cout << "Ingrese el primer apellido: "; string primerApellido; cin >> primerApellido; cin.ignore(); cout << endl;
		cout << "Ingrese el segundo apellido: "; string segundoApellido; cin >> segundoApellido; cin.ignore(); cout << endl;
		cout << "Ingrese el nombre del profesor: "; string nombre; getline(cin, nombre); cout << endl;
		P->setNombre(nombre); P->setPrimerApellido(primerApellido); P->setSegundoApellido(segundoApellido);
		Interfaz_Principal::msjPerfecto();

	}
	else
		cout << "No se ha encontrado el profesor con ese numero de cedula..." << endl;

	Interfaz_Principal::msjPausa();
	system("cls");
}

void Interfaz_Profesores::vConsultaCursosAsignadosProfesor(Universidad *U)
{
	cout << "Digite el numero de identificacion del profesor a consultar ->"; int cedula; cin >> cedula; cin.ignore();
	if (U->getContenedorEscuelas()->retornaProfesor(cedula)) {
		cout << "El profesor " << U->getContenedorEscuelas()->retornaProfesor(cedula)->getNombreCompleto() << " imparte los cursos: " << endl;
		cout << U->getContenedorEscuelas()->retornaProfesor(cedula)->getCursosImpartidos() << endl;
	}
	else
		cout << "El profesor con la cedula " << cedula << " no existe" << endl;

	Interfaz_Principal::msjPausa();
	system("cls");
}