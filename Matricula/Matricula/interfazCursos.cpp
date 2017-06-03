#include "interfazCursos.h"
#include "interfazPrincipal.h"
#include "contenedorEscuelas.h"
#include "grupoProfesores.h"
#include "contenedorCursos.h"
#include "contenedorRelacionCursoEscuela.h"
#include "curso.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

char Interfaz_Cursos::vMenuCursos()
{
	char ans;
	cout << "**************MENU CURSOS**************" << endl;
	cout << "(1)--Consultar curso" << endl;
	cout << "(2)--Consultar lista de cursos de una Escuela" << endl;
	cout << "(3)--Ajustes" << endl;
	cout << "(4)--Salir" << endl;
	cout << "********************************************" << endl;
	Interfaz_Principal::msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '4') {
		cout << "Opcion Incorrecta. Intente de nuevo. " << endl;
		ans = _getch();
	}

	system("cls");
	return ans;
}

char Interfaz_Cursos::vAjustesCursos()
{
	char ans;
	cout << "***************AJUSTES CURSOS***************" << endl;
	cout << "-(1)-Ingresar Curso" << endl;
	cout << "-(2)-Editar Curso" << endl;
	cout << "-(3)-Eliminar Curso" << endl;
	cout << "-(4)-Salir" << endl;
	Interfaz_Principal::msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '4')
	{
		cout << "Opcion Incorrecta. Try again " << endl;
		ans = _getch();
	}
	system("cls");
	return ans;
}

void Interfaz_Cursos::vIngresaCurso(Universidad* universidad)
{

	cout << "Nombre de la Universidad: " << universidad->getNombre() << endl << endl;
	cout << universidad->getContenedorEscuelas()->toString('1') << endl;

	cout << "Digite las siglas de la Escuela a la que desea ingresar el curso -> ";
	string sigla; cin >> sigla; cin.ignore();

	sigla = Interfaz_Principal::convierteMayuscula(sigla);

	if (!universidad->getContenedorEscuelas()->retornaEscuela(sigla))
		cout << "No se ha encontrado la Escuela..." << endl;
	else {

		system("cls");
		string nombre;
		cout << "Ingrese el nombre del curso -> "; getline(cin, nombre); cout << endl;
		cout << "Curso: " << "\"" << nombre << "\" "; cout << "| es esta informacion correcta? ";

		char ans = Interfaz_Principal::vInfoConfirmacion();

		while (nombre == "Undefined" || nombre == " " || nombre == "") {
			cout << "Nombre Invalido. Intente de nuevo -> ";
			Sleep(800);
			system("cls");
			cout << "Ingrese el nombre del curso  -> "; std::getline(std::cin, nombre); cout << endl << endl;
		}

		Curso* cur = new Curso(nombre, sigla);

		universidad->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->agregarInicio(cur);

		Interfaz_Principal::msjPerfecto();
	}
	Interfaz_Principal::msjPausa();
	system("cls");
}

void Interfaz_Cursos::vEditarCurso(Universidad *universidad)
{
	cout << universidad->getContenedorEscuelas()->toString('2');
	cout << "Ingrese el codigo del curso que desea editar -> ";
	string codigo, sigla;

	cin >> codigo; cin.ignore();

	codigo = Interfaz_Principal::convierteMayuscula(codigo);
	sigla = codigo.substr(0, 3);
	if (universidad->getContenedorEscuelas() == nullptr || universidad->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos() == nullptr)
		cout << "No existe ningun curso con esa sigla..." << endl;
	else
		if (!universidad->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->getCursoEspecifico(codigo))
			cout << "El curso no ha sido encontrado..." << endl;
		else {
			string nombre;
			cout << "Ingrese el nuevo nombre del curso -> "; getline(cin, nombre); cout << endl;

			cout << "Curso: " << "\"" << nombre << "\" "; cout << "| es esta informacion correcta? ";

			char ans = Interfaz_Principal::vInfoConfirmacion();

			while (nombre == "Undefined" || nombre == " " || nombre == "") {
				cout << "Nombre Invalido. Intente de nuevo -> ";
				Sleep(800);
				system("cls");
				cout << "Ingrese el nuevo nombre del curso  -> "; std::getline(std::cin, nombre); cout << endl << endl;
			}

			universidad->getContenedorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->
				getCursoEspecifico(codigo)->setNombre(nombre);

			Interfaz_Principal::msjPerfecto();
		}

		Interfaz_Principal::msjPausa();
		system("cls");
}

void Interfaz_Cursos::vEliminaCurso(Universidad *universidad) //debe implementarse mejor
{
	cout << universidad->getContenedorEscuelas()->toString('2') << endl;
	cout << "Ingrese el codigo del curso que desea eliminar -> ";
	string codigo, sigla, aux;
	cin >> aux; cin.ignore();

	codigo = Interfaz_Principal::convierteMayuscula(aux);
	sigla = codigo.substr(0, 3);
	try {
		Escuela *Esc = universidad->getContenedorEscuelas()->retornaEscuela(sigla);
		if (Esc == nullptr) throw 1;
		if (Esc->getContenedorCursos()->eliminarEspecifico(codigo))
			cout << "Curso eliminado con exito" << endl;
		else
			cout << "No se ha podido eliminar el curso." << endl;

		Interfaz_Principal::msjPausa();
		system("cls");
	}
	catch (int e) {
		if (e == 1)
			cout << "No existe ningun curso con ese codigo" << endl;
	}
}

void Interfaz_Cursos::vInfoCurso(ContenedorEscuelas *contenedor) //necesita ser optimizado
{
	string codigo, sigla;
	cout << "Ingrese el codigo del curso que desea consultar -> ";
	cin >> codigo; cin.ignore();

	codigo = Interfaz_Principal::convierteMayuscula(codigo);
	sigla = codigo.substr(0, 3);

	if (contenedor->retornaEscuela(sigla) == nullptr)
		cout << "No existe ningun curso perteneciente a esa sigla..." << endl;
	else
		if (contenedor->retornaEscuela(sigla)->getContenedorCursos()->getCursoEspecifico(codigo) == NULL)
			cout << "El curso no ha sido encontrado..." << endl;
		else
			cout << *(contenedor->retornaEscuela(sigla)->getContenedorCursos()->getCursoEspecifico(codigo)) << endl;

	Interfaz_Principal::msjPausa();
	system("cls");
}

void Interfaz_Cursos::vListaCursosEscuelaParticular(ContenedorRelacionCursoEscuela* contenedor, ContenedorEscuelas* escuelas) {
	cout << escuelas->toString(); //Imprime lista de Escuelas con sus codigos
	string sigla;
	cout << "Ingrese la sigla de la escuela que desea consultar la lista de cursos -> ";
	cin >> sigla; cin.ignore();
	sigla = Interfaz_Principal::convierteMayuscula(sigla);
	if (!escuelas->retornaEscuela(sigla))
		cout << "La escuela no ha sido encontrada..." << endl;
	else {
		Escuela *EE = escuelas->retornaEscuela(sigla);
		if (contenedor->getCursosNescuelas(codigo, sigla) == 0)
			cout << "No existen cursos aun en esta Escuela..." << endl;
		else
			for (int i = 0; i < cursos->getCantidad(); i++) {  //algoritmo mortal xxxxxx
				cout << "Curso: " << cursos->getCurso(i)->getNombre() << endl;
				cout << "Profesores:" << endl;
				for (int x = 0; x < EE->getContenedorCursos()->getCurso(i)->getGrupoProfesores()->getCantidadProfesores(); x++) {
					int cedulaProfe = EE->getContenedorCursos()->getCurso(i)->getGrupoProfesores()->getProfesor(x)->getNumCedula();
					cout << universidad->getContenedorEscuelas()->retornaProfesor(cedulaProfe)->getNombreCompleto() << endl;
				}
			}
	}
	Interfaz_Principal::msjPausa();
	system("cls");
}