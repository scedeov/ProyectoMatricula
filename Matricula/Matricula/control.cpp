#include "control.h"
#include <conio.h>
#include <Windows.h>
#include "interfazPrincipal.h"

int Curso::variableCodigoCursos = 0; // variable que controla el codigo del curso

void Control::Inicializador()
{
	U = new Universidad("Universidad de Costa Rica", "22334455", "San Pedro");

	Escuela* E1 = new Escuela("Ingles");
	Escuela* E2 = new Escuela("Matematicas");
	Escuela* E3 = new Escuela("Geologia");
	Escuela* E4 = new Escuela("Sociales");

	U->getContenedorEscuelas()->insertarInicio(E1);
	U->getContenedorEscuelas()->insertarInicio(E2);
	U->getContenedorEscuelas()->insertarInicio(E3);
	U->getContenedorEscuelas()->insertarInicio(E4);


	Curso* CU1 = new Curso("Programacion I", E1->getSiglaEscuela());
	Curso* CU2 = new Curso("Programacion II", E2->getSiglaEscuela());

	E1->getContenedorCursos()->insertaInicio(CU1);
	E2->getContenedorCursos()->insertaInicio(CU2);

	Profesor* P1 = new Profesor("Carlos", "Bermudez", "Villagran", 115720401);
	P1->setEscuela("Ingles");
	Profesor* P2 = new Profesor("Manati", "Bolanos", "Oztia", 11576767);
	P2->setEscuela("Ingles");
	E1->getContenedorProfesores()->insertaInicio(P1);
	E1->getContenedorProfesores()->insertaInicio(P2);
	CU1->getGrupoProfesores()->agregarProfesor(P1);
	CU1->getGrupoProfesores()->agregarProfesor(P2);
	P1->setCursosImpartidos(CU1->getCodigoCurso());
	P2->setCursosImpartidos(CU1->getCodigoCurso());

	MenuPrincipal();
}

void Control::MenuPrincipal()
{
	Interfaz_Principal::vBienvenida();

	if (Interfaz_Principal::vDatosPrimeraVez(U) == 'S')
	{
		Interfaz_Principal::vIngresarNombre(U);
		Interfaz_Principal::vIngresarNumero(U);
		Interfaz_Principal::vIngresarDireccion(U);
	}

	bool end = false;

	do
	{
		char ans = Interfaz_Principal::vMenuPrincipal();

		switch (ans)
		{
		case '1':
		{
			MenuUniversidad();
			break;
		}
		case '2':
		{
			MenuEscuelas();
			break;
		}
		case '3':
		{
			MenuCursos();
			break;
		}
		case '4':
		{
			MenuProfesores();
			break;
		}
		case '5':
		{
			MenuEstudiantes();
			break;
		}
		case '6': {
			MenuMatricula();
			break;
		}
		case '7':
		{
			delete U;
			end = true;
			break;
		}
		default:
			break;
		}

	} while (end == false);
}

void Control::MenuUniversidad() {
	bool end = false;
	do {
		char ans = Interfaz_Principal::vMenuUniversidad();

		switch (ans) {
		case '1': {
			Interfaz_Principal::vInfoUniversidad(U);
			break;
		}
		case '2': {
			AjustesUniversidad();
			break;
		}
		case '3': {
			end = true;
			break;
		}
		default: break;
		}

	} while (end == false);
}

void Control::AjustesUniversidad() {

	bool end = false;

	do {
		char opcion = Interfaz_Principal::vAjustesUniversidad(U);

		if (U->getNombre() == "Undefined") {
			switch (opcion) {
			case '1': {
				Interfaz_Principal::vIngresarNombre(U);
				break;
			}
			case '2': {
				Interfaz_Principal::vIngresarNumero(U);
				break;
			}
			case '3': {
				Interfaz_Principal::vIngresarDireccion(U);
				break;
			}
			case '4': {
				end = true;
				break;
			}
			default: break;
			}
		}
		else {

			switch (opcion) {
			case '1': {
				Interfaz_Principal::vIngresarNumero(U);
				break;
			}
			case '2': {
				Interfaz_Principal::vIngresarDireccion(U);
				break;
			}
			case '3': {
				end = true;
				break;
			}
			default: break;
			}
		}

	} while (end == false);
}

void Control::MenuEscuelas()
{
	bool end = false;

	do
	{
		char ans = Interfaz_Principal::vMenuEscuelas();

		switch (ans)
		{
		case '1':
		{
			Interfaz_Principal::vInfoEscuelas(U, '1'); //Imprime solamente escuelas
			break;
		}
		case '2':
		{
			Interfaz_Principal::vInfoEscuelas(U, '2'); //Imprime escuelas con los cursos
			break;
		}
		case '3':
		{
			AjustesEscuelas();
			break;
		}
		case '4': // Salir
		{
			end = true;
			break;
		}
		default:
			break;
		}

	} while (end == false);
}

void Control::AjustesEscuelas() {

	bool end = false;

	do {
		char opcion = Interfaz_Principal::vAjustesEscuelas();

		switch (opcion) {
		case '1':
		{
			Interfaz_Principal::vIngresaEscuela(U);
			break;
		}
		case '2':
		{
			end = true;
			break;
		}
		default: break;
		}
	} while (end == false);
}

void Control::MenuCursos()
{
	bool end = false;

	do
	{
		char ans = Interfaz_Principal::vMenuCursos();

		switch (ans)
		{
		case '1':
		{
			Interfaz_Principal::vInfoCurso(U);
			break;
		}
		case '2':
		{
			Interfaz_Principal::vListaCursosEscuelaParticular(U);
			break;
		}
		case '3': //Salir
		{
			AjustesCursos();
			break;
		}
		case '4': {
			end = true;
			break;
		}
		default: break;
		}

	} while (end == false);
}

void Control::AjustesCursos() {

	bool end = false;

	do {

		char opcion = Interfaz_Principal::vAjustesCursos();

		switch (opcion) {
		case '1':
		{
			Interfaz_Principal::vIngresaCurso(U);
			break;
		}
		case '2':
		{
			Interfaz_Principal::vEditarCurso(U);
			break;
		}
		case '3':
		{
			Interfaz_Principal::vEliminaCurso(U);
			break;
		}
		case '4': 
		{
			end = true;
			break;
		}
		default: break;
		}

	} while (end == false);

}

void Control::MenuProfesores()
{
	bool end = false;

	do {
		char opcion = Interfaz_Principal::vMenuProfesores();
		switch (opcion) {
		case '1': {
			Interfaz_Principal::vConsultarProfesEscuela(U);
			break;
		}
		case'2': {
			Interfaz_Principal::vConsultarProfesCurso(U);
			break;
		}
		case '3': {
			Interfaz_Principal::vConsultarProfeCedula(U);
			break;
		}
		case '4': {
			Interfaz_Principal::vConsultaCursosAsignadosProfesor(U);
			break;

		}
		case '5': {
			AjustesProfesores();
			break;
		}
		case '6': {
			end = true;
			break;
		}
		default: break;
		}
	} while (end == false);
}

void Control::AjustesProfesores() {
	bool end = false;
	do {
		char opcion = Interfaz_Principal::vAjustesProfesores();
		switch (opcion) {
		case '1': {
			Interfaz_Principal::vAgregarProfesor(U);
			break;
		}
		case '2': {
			Interfaz_Principal::vEditarProfesor(U);
			break;
		}
		case '3': {
			Interfaz_Principal::vAsignarProfesorCurso(U);
			break;
		}
		case '4': {
			end = true;
			break;
		}
		default: break;
		}
	} while (end == false);
}

void Control::MenuEstudiantes() {
	bool end = false;
	do {
		char opcion = Interfaz_Principal::vMenuEstudiantes();
		switch (opcion) {
		case '1': {
			Interfaz_Principal::vConsultaEstudiante(U);
			break;
		}
		case '2': {
			AjustesEstudiantes();
			break;
		}
		case '3': {
			end = true;
			break;
		}
		}
	} while (end == false);
}

void Control::AjustesEstudiantes() {
	bool end = false;
	do {
		char opcion = Interfaz_Principal::vAjustesEstudiantes();
		switch (opcion) {
		case '1': {
			Interfaz_Principal::vIngresarEstudiante(U);
			break;
		}
		case '2': {
			Interfaz_Principal::vEditarEstudiante(U);
			break;
		}
		case '3': {
			end = true;
			break;
		}
		}
	} while (end == false);
}

void Control::MenuMatricula() {
	bool end = false;
	do {
		char opcion = Interfaz_Principal::vMenuMatricula();
		switch (opcion) {
		case '1': {
			Interfaz_Principal::vMatriculaEstudianteCurso(U);
			break;
		}
		case '2': {
			Interfaz_Principal::vMatriculaListaEstudiantesCursos(U);
			break;
		}
		case '3': {
			Interfaz_Principal::vMatriculaListaCursosEstudiante(U);
		}
		case '4': {
			AjustesMatricula();
			break;
		}
		case '5': {
			end = true;
			break;
		}
		default: break;
		}
	} while (end == false);
}

void Control::AjustesMatricula()
{
}
