#include "control.h"
#include "interfazPrincipal.h"
#include "interfazCursos.h"
#include "interfazEscuelas.h"
#include "interfazEstudiantes.h"
#include "interfazProfesores.h"
#include "interfazUniversidad.h"
#include "interfazMatricula.h"


int Curso::variableCodigoCursos = 0; // variable que controla el codigo del curso

void Control::Inicializador()
{
	universidad = new Universidad("Universidad de Costa Rica", "22334455", "San Pedro");
	MenuPrincipal();
}

void Control::MenuPrincipal()
{
	Interfaz_Principal::vBienvenida();

	if (Interfaz_Principal::vDatosPrimeraVez(universidad) == 'S')
	{
		Interfaz_Universidad::vIngresarNombre(universidad);
		Interfaz_Universidad::vIngresarNumero(universidad);
		Interfaz_Universidad::vIngresarDireccion(universidad);
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
			delete universidad;
			end = true;
			break;
		}
		default:
			break;
		}

	} while (end == false);
}

void Control::MenuUniversidad() {
	bool end= false;
	do {
		char ans = Interfaz_Universidad::vMenuUniversidad();

		switch (ans) {
		case '1': {
			Interfaz_Universidad::vInfoUniversidad(universidad);
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
		char opcion = Interfaz_Universidad::vAjustesUniversidad(universidad);

		if (universidad->getNombre() == "Undefined") {
			switch (opcion) {
			case '1': {
				Interfaz_Universidad::vIngresarNombre(universidad);
				break;
			}
			case '2': {
				Interfaz_Universidad::vIngresarNumero(universidad);
				break;
			}
			case '3': {
				Interfaz_Universidad::vIngresarDireccion(universidad);
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
				Interfaz_Universidad::vIngresarNumero(universidad);
				break;
			}
			case '2': {
				Interfaz_Universidad::vIngresarDireccion(universidad);
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
		char ans = Interfaz_Escuelas::vMenuEscuelas();

		switch (ans)
		{
		case '1':
		{
			Interfaz_Escuelas::vInfoEscuelas(contenedor, '1'); //Imprime solamente escuelas
			break;
		}
		case '2':
		{
			Interfaz_Escuelas::vInfoEscuelas(contenedor, '2'); //Imprime escuelas con los cursos
			break;
		}
		case '3':
		{
			AjustesEscuelas();
			break;
		}
		case '4':
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
		char opcion = Interfaz_Escuelas::vAjustesEscuelas();

		switch (opcion) {
		case '1':
		{
			Interfaz_Escuelas::vIngresaEscuela(universidad);
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
		char ans = Interfaz_Cursos::vMenuCursos();

		switch (ans)
		{
		case '1':
		{
			Interfaz_Cursos::vInfoCurso(universidad);
			break;
		}
		case '2':
		{
			Interfaz_Cursos::vListaCursosEscuelaParticular(universidad);
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

		char opcion = Interfaz_Cursos::vAjustesCursos();

		switch (opcion) {
		case '1':
		{
			Interfaz_Cursos::vIngresaCurso(universidad);
			break;
		}
		case '2':
		{
			Interfaz_Cursos::vEditarCurso(universidad);
			break;
		}
		case '3':
		{
			Interfaz_Cursos::vEliminaCurso(universidad);
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
		char opcion = Interfaz_Profesores::vMenuProfesores();
		switch (opcion) {
		case '1': {
			Interfaz_Profesores::vConsultarProfesEscuela(universidad);
			break;
		}
		case'2': {
			Interfaz_Profesores::vConsultarProfesCurso(universidad);
			break;
		}
		case '3': {
			Interfaz_Profesores::vConsultarProfeCedula(universidad);
			break;
		}
		case '4': {
			Interfaz_Profesores::vConsultaCursosAsignadosProfesor(universidad);
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
		char opcion = Interfaz_Profesores::vAjustesProfesores();
		switch (opcion) {
		case '1': {
			Interfaz_Profesores::vAgregarProfesor(universidad);
			break;
		}
		case '2': {
			Interfaz_Profesores::vEditarProfesor(universidad);
			break;
		}
		case '3': {
			Interfaz_Profesores::vAsignarProfesorCurso(universidad);
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
		char opcion = Interfaz_Estudiantes::vMenuEstudiantes();
		switch (opcion) {
		case '1': {
			Interfaz_Estudiantes::vConsultaEstudiante(universidad);
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
		char opcion = Interfaz_Estudiantes::vAjustesEstudiantes();
		switch (opcion) {
		case '1': {
			Interfaz_Estudiantes::vIngresarEstudiante(universidad);
			break;
		}
		case '2': {
			Interfaz_Estudiantes::vEditarEstudiante(universidad);
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
		char opcion = Interfaz_Matricula::vMenuMatricula();
		switch (opcion) {
		case '1': {
			Interfaz_Matricula::vMatriculaEstudianteCurso(universidad);
			break;
		}
		case '2': {
			Interfaz_Matricula::vMatriculaListaEstudiantesCursos(universidad);
			break;
		}
		case '3': {
			Interfaz_Matricula::vMatriculaListaCursosEstudiante(universidad);
			break;
		}
		case '4': {
			Interfaz_Matricula::vCobroMatricula(universidad);
			break;
		}
		case '5': {
			AjustesMatricula();
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

void Control::AjustesMatricula()
{
}
