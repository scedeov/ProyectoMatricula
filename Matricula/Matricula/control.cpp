#include "control.h"

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
	Profesor* P2 = new Profesor("Manati", "Bolanos", "Oztia", 11576767);
	E1->getContenedorProfesores()->insertaInicio(P1);
	E1->getContenedorProfesores()->insertaInicio(P2);
	CU1->setProfesores(P1->getNumCedula());
	CU1->setProfesores(P2->getNumCedula());
	P1->setCursosImpartidos(CU1->getCodigoCurso());
	P2->setCursosImpartidos(CU1->getCodigoCurso());

	MenuPrincipal();
}

void Control::MenuPrincipal()
{
	Interfaz::vBienvenida();

	if (Interfaz::vDatosPrimeraVez(U) == 'S')
	{
		Interfaz::vIngresarNombre(U);
		Interfaz::vIngresarNumero(U);
		Interfaz::vIngresarDireccion(U);
	}

	bool end = false;

	do
	{
		char ans = Interfaz::vMenuPrincipal();

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
		case'5':
		{
			MenuEstudiantes();
			break;
		}
		case '6':
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
		char ans = Interfaz::vMenuUniversidad();

		switch (ans) {
		case '1': {
			Interfaz::vInfoUniversidad(U);
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
		char opcion = Interfaz::vAjustesUniversidad(U);

		if (U->getNombre() == "Undefined") {
			switch (opcion) {
			case '1': {
				Interfaz::vIngresarNombre(U);
				break;
			}
			case '2': {
				Interfaz::vIngresarNumero(U);
				break;
			}
			case '3': {
				Interfaz::vIngresarDireccion(U);
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
				Interfaz::vIngresarNumero(U);
				break;
			}
			case '2': {
				Interfaz::vIngresarDireccion(U);
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
		char ans = Interfaz::vMenuEscuelas();

		switch (ans)
		{
		case '1':
		{
			Interfaz::vInfoEscuelas(U, '1'); //Imprime solamente escuelas
			break;
		}
		case '2':
		{
			Interfaz::vInfoEscuelas(U, '2'); //Imprime escuelas con los cursos
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
		char opcion = Interfaz::vAjustesEscuelas();

		switch (opcion) {
		case '1':
		{
			Interfaz::vIngresaEscuela(U);
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
		char ans = Interfaz::vMenuCursos();

		switch (ans)
		{
		case '1':
		{
			Interfaz::vInfoCurso(U);
			break;
		}
		case '2':
		{
			Interfaz::vListaCursosEscuelaParticular(U);
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

		char opcion = Interfaz::vAjustesCursos();

		switch (opcion) {
		case '1':
		{
			Interfaz::vIngresaCurso(U);
			break;
		}
		case '2':
		{
			Interfaz::vEditarCurso(U);
			break;
		}
		case '3':
		{
			Interfaz::vEliminaCurso(U);
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
		char opcion = Interfaz::vMenuProfesores();
		switch (opcion) {
		case '1': {
			Interfaz::vConsultarProfesEscuela(U);
			break;
		}
		case'2': {
			Interfaz::vConsultarProfesCurso(U);
			break;
		}
		case '3': {
			Interfaz::vConsultarProfeCedula(U);
			break;
		}
		case '4': {
			AjustesProfesores();
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

void Control::AjustesProfesores() {
	bool end = false;
	do {
		char opcion = Interfaz::vAjustesProfesores();
		switch (opcion) {
		case '1': {
			Interfaz::vAgregarProfesor(U);
			break;
		}
		case '2': {
			Interfaz::vEditarProfesor(U);
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

void Control::MenuEstudiantes()
{
}

