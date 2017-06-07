#include "interfazCursos.h"
#include "interfazPrincipal.h"
#include "controladorEscuelas.h"
#include "grupoProfesores.h"
#include "controladorCursos.h"
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

void Interfaz_Cursos::vIngresaCurso(Universidad* U)
{

	cout << "Nombre de la Universidad: " << U->getNombre() << endl << endl;
	cout << U->getControladorEscuelas()->toString('1') << endl;

	cout << "Digite las siglas de la Escuela a la que desea ingresar el curso -> ";
	string sigla; cin >> sigla; cin.ignore();

	sigla = Interfaz_Principal::convierteMayuscula(sigla);

	if (!U->getControladorEscuelas()->retornaEscuela(sigla))
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

		cout << "Ingrese la cantidad de creditos del Curso -> (1 - 5) -> "; int creditos; cin >> creditos; cin.ignore();
		Curso* cur = new Curso(nombre, sigla);
		cur->setCantidadCreditos(creditos);
		U->getControladorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->insertaInicio(cur);

		Interfaz_Principal::msjPerfecto();
	}
	Interfaz_Principal::msjPausa();
	system("cls");
}

void Interfaz_Cursos::vEditarCurso(Universidad *U)
{
	cout << U->getControladorEscuelas()->toString('2');
	cout << "Ingrese el codigo del curso que desea editar -> ";
	string codigo, sigla;

	cin >> codigo; cin.ignore();

	codigo = Interfaz_Principal::convierteMayuscula(codigo);
	sigla = codigo.substr(0, 3);
	if (U->getControladorEscuelas() == nullptr || U->getControladorEscuelas()->retornaEscuela(sigla)->getContenedorCursos() == nullptr)
		cout << "No existe ningun curso con esa sigla..." << endl;
	else
		if (!U->getControladorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->retornaCursoEspecifico(codigo))
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

			U->getControladorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->
				retornaCursoEspecifico(codigo)->setNombre(nombre);

			cout << "Ingrese la cantidad de creditos del Curso -> (1 - 5) -> "; int creditos; cin >> creditos; cin.ignore();

			U->getControladorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->
				retornaCursoEspecifico(codigo)->setCantidadCreditos(creditos);
			Interfaz_Principal::msjPerfecto();
		}

		Interfaz_Principal::msjPausa();
		system("cls");
}

void Interfaz_Cursos::vEliminaCurso(Universidad *U) //debe implementarse mejor
{
	cout << U->getControladorEscuelas()->toString('2') << endl;
	cout << "Ingrese el codigo del curso que desea eliminar -> ";
	string codigo, sigla, aux;
	cin >> aux; cin.ignore();

	codigo = Interfaz_Principal::convierteMayuscula(aux);
	sigla = codigo.substr(0, 3);
	try {
		Escuela *Esc = U->getControladorEscuelas()->retornaEscuela(sigla);
		if (Esc == nullptr) throw 1;
		if (Esc->getContenedorCursos()->eliminaCursoEspecifico(codigo))
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

void Interfaz_Cursos::vInfoCurso(Universidad *U) //necesita ser optimizado
{
	string codigo, sigla;
	cout << "Ingrese el codigo del curso que desea consultar -> ";
	cin >> codigo; cin.ignore();

	codigo = Interfaz_Principal::convierteMayuscula(codigo);
	sigla = codigo.substr(0, 3);

	if (U->getControladorEscuelas()->retornaEscuela(sigla) == nullptr)
		cout << "No existe ningun curso perteneciente a esa sigla..." << endl;
	else
		if (U->getControladorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->retornaCursoEspecifico(codigo) == NULL)
			cout << "El curso no ha sido encontrado..." << endl;
		else
			cout << *(U->getControladorEscuelas()->retornaEscuela(sigla)->getContenedorCursos()->retornaCursoEspecifico(codigo)) << endl;

	Interfaz_Principal::msjPausa();
	system("cls");
}

void Interfaz_Cursos::vListaCursosEscuelaParticular(Universidad *U) {
	cout << U->getControladorEscuelas()->toString('1'); //Imprime lista de Escuelas con sus codigos
	string sigla;
	cout << "Ingrese la sigla de la escuela que desea consultar la lista de cursos -> ";
	cin >> sigla; cin.ignore();
	sigla = Interfaz_Principal::convierteMayuscula(sigla);
	if (!U->getControladorEscuelas()->retornaEscuela(sigla))
		cout << "La escuela no ha sido encontrada..." << endl;
	else {
		Escuela *EE = U->getControladorEscuelas()->retornaEscuela(sigla);
		if (EE->getContenedorCursos()->getCantidad() == 0)
			cout << "No existen cursos aun en esta Escuela..." << endl;
		else
			for (int i = 0; i < EE->getContenedorCursos()->getCantidad(); i++) {  //algoritmo mortal xxxxxx
				cout << "Curso: " << EE->getContenedorCursos()->getCursoporPos(i)->getNombre() << endl;
				cout << "Profesores:" << endl;
				for (int x = 0; x < EE->getContenedorCursos()->getCursoporPos(i)->getGrupoProfesores()->getCantidadProfesores(); x++) {
					int cedulaProfe = EE->getContenedorCursos()->getCursoporPos(i)->getGrupoProfesores()->getProfesor(x)->getNumCedula();
					cout << EE->getContenedorProfesores()->getNombreCompleto() << endl;
				}
			}
	}
	Interfaz_Principal::msjPausa();
	system("cls");
}