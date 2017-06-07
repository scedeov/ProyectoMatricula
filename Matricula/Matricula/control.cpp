#include "control.h"



int Curso::variableCodigoCursos = 0; // variable que controla el codigo del curso

void Control::Inicializador()
{
	U = new Universidad("Universidad de Costa Rica", "22334455", "San Pedro");
	MenuPrincipal();
}

void Control::MenuPrincipal()
{
	Interfaz_Principal::vBienvenida();

	if (Interfaz_Principal::vDatosPrimeraVez(U) == 'S')
	{
		Interfaz_Universidad::vIngresarNombre(U);
		Interfaz_Universidad::vIngresarNumero(U);
		Interfaz_Universidad::vIngresarDireccion(U);
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
		char ans = Interfaz_Universidad::vMenuUniversidad();

		switch (ans) {
		case '1': {
			Interfaz_Universidad::vInfoUniversidad(U);
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
		char opcion = Interfaz_Universidad::vAjustesUniversidad(U);

		if (U->getNombre() == "Undefined") {
			switch (opcion) {
			case '1': {
				Interfaz_Universidad::vIngresarNombre(U);
				break;
			}
			case '2': {
				Interfaz_Universidad::vIngresarNumero(U);
				break;
			}
			case '3': {
				Interfaz_Universidad::vIngresarDireccion(U);
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
				Interfaz_Universidad::vIngresarNumero(U);
				break;
			}
			case '2': {
				Interfaz_Universidad::vIngresarDireccion(U);
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
			Interfaz_Escuelas::vInfoEscuelas(U, '1'); //Imprime solamente escuelas
			break;
		}
		case '2':
		{
			Interfaz_Escuelas::vInfoEscuelas(U, '2'); //Imprime escuelas con los cursos
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
		char opcion = Interfaz_Escuelas::vAjustesEscuelas();

		switch (opcion) {
		case '1':
		{
			Interfaz_Escuelas::vIngresaEscuela(U);
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
			Interfaz_Cursos::vInfoCurso(U);
			break;
		}
		case '2':
		{
			Interfaz_Cursos::vListaCursosEscuelaParticular(U);
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
			Interfaz_Cursos::vIngresaCurso(U);
			break;
		}
		case '2':
		{
			Interfaz_Cursos::vEditarCurso(U);
			break;
		}
		case '3':
		{
			Interfaz_Cursos::vEliminaCurso(U);
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
			Interfaz_Profesores::vConsultarProfesEscuela(U);
			break;
		}
		case'2': {
			Interfaz_Profesores::vConsultarProfesCurso(U);
			break;
		}
		case '3': {
			Interfaz_Profesores::vConsultarProfeCedula(U);
			break;
		}
		case '4': {
			Interfaz_Profesores::vConsultaCursosAsignadosProfesor(U);
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
			Interfaz_Profesores::vAgregarProfesor(U);
			break;
		}
		case '2': {
			Interfaz_Profesores::vEditarProfesor(U);
			break;
		}
		case '3': {
			Interfaz_Profesores::vAsignarProfesorCurso(U);
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
			Interfaz_Estudiantes::vConsultaEstudiante(U);
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
			Interfaz_Estudiantes::vIngresarEstudiante(U);
			break;
		}
		case '2': {
			Interfaz_Estudiantes::vEditarEstudiante(U);
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
			Interfaz_Matricula::vMatriculaEstudianteCurso(U);
			break;
		}
		case '2': {
			Interfaz_Matricula::vMatriculaListaEstudiantesCursos(U);
			break;
		}
		case '3': {
			Interfaz_Matricula::vMatriculaListaCursosEstudiante(U);
			break;
		}
		case '4': {
			Interfaz_Matricula::vCobroMatricula(U);
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
