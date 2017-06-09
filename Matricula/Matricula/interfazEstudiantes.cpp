#include "interfazEstudiantes.h"

char Interfaz_Estudiantes::vMenuEstudiantes() {
	char ans;
	cout << "***************MENU ESTUDIANTES***************" << endl;
	cout << "-(1)-Info Estudiantes" << endl;
	cout << "-(2)-Ajustes" << endl;
	cout << "-(3)-Salir" << endl;
	Interfaz_Principal::msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '3')
	{
		cout << "Opcion Incorrecta. Try again " << endl;
		ans = _getch();
	}
	system("cls");
	return ans;
}

char Interfaz_Estudiantes::vAjustesEstudiantes() {
	char ans;
	cout << "***************AJUSTES ESTUDIANTES***************" << endl;
	cout << "-(1)-Ingresar Estudiante" << endl;
	cout << "-(2)-Editar Estudiante" << endl;
	cout << "-(3)-Salir" << endl;
	Interfaz_Principal::msjIngreseOpcion();
	ans = _getch();

	while (ans < '1' || ans > '3')
	{
		cout << "Opcion Incorrecta. Try again " << endl;
		ans = _getch();
	}
	system("cls");
	return ans;
}

void Interfaz_Estudiantes::vIngresarEstudiante(Universidad *U) {
	Estudiante *E = new Estudiante();
	cout << "Agregando estudiante..." << endl; int porcentaje = 0;
	cout << "Ingrese el primer apellido: "; string primerApellido; cin >> primerApellido; cin.ignore(); cout << endl; E->setPrimerApellido(primerApellido);
	cout << "Ingrese el segundo apellido: "; string segundoApellido; cin >> segundoApellido; cin.ignore(); cout << endl; E->setSegundoApellido(segundoApellido);
	cout << "Ingrese el nombre del estudiante: "; string nombre; getline(cin, nombre); cout << endl; E->setNombre(nombre);
	cout << "Ingrese el numero de cedula: "; string cedula; cin >> cedula; cin.ignore(); cout << endl; E->setID(cedula);
	cout << "Es un estudiante de nacionalidad extranjera?: "; ;
	if (char ans = Interfaz_Principal::vInfoConfirmacion() == 'N') {
		cout << "Ingrese el porcentaje de beca (0-100): "; cin >> porcentaje; cin.ignore(); cout << endl;
		E = new Estudiante_Nacional(E);
	}
	else
		E = new Estudiante_Extranjero(E);

	U->getContenedorEstudiantes()->insertaInicio(E);
	Interfaz_Principal::msjPerfecto();
}

void Interfaz_Estudiantes::vConsultaEstudiante(Universidad *U)
{
	cout << "Digite la cedula del estudiante a consultar -> "; string cedula; cin >> cedula; cin.ignore();

	if (U->getContenedorEstudiantes()->retornaEstudiante(cedula) == NULL)
		cout << "El Estudiante no ha sido encontrado..." << endl;
	else
		cout << *(U->getContenedorEstudiantes()->retornaEstudiante(cedula)) << endl;

	Interfaz_Principal::msjPausa();
	system("cls");
}

void Interfaz_Estudiantes::vEditarEstudiante(Universidad *U) {


	string primerApellido, segundoApellido, nombre;
	cout << "Digite el numero de cedula del Estudiante -> ";
	string cedula; cin >> cedula; cin.ignore();
	if (U->getContenedorEstudiantes()->retornaEstudiante(cedula)) {
		Estudiante *E = U->getContenedorEstudiantes()->retornaEstudiante(cedula);
		cout << "Ingrese el primer apellido: "; cin >> primerApellido; cin.ignore(); cout << endl; E->setPrimerApellido(primerApellido);
		cout << "Ingrese el segundo apellido: "; cin >> segundoApellido; cin.ignore(); cout << endl; E->setSegundoApellido(segundoApellido);
		cout << "Ingrese el nombre del Estudiante: "; getline(cin, nombre); cout << endl; E->setNombre(nombre);
		cout << "Es un estudiante de nacionalidad extranjera?: ";
		if (char ans = Interfaz_Principal::vInfoConfirmacion() == 'N') {
			cout << "Ingrese el porcentaje de beca (0-100): "; int porcentaje; cin >> porcentaje; cin.ignore(); cout << endl;
			E = new Estudiante_Nacional(E);
			E->setPorcentajeBeca(porcentaje);
		}
		else {
			E = new Estudiante_Extranjero(E);
		}
		E->setNombre(nombre); E->setPrimerApellido(primerApellido); E->setSegundoApellido(segundoApellido); E->generaCarnet();
	}
	else
		cout << "No se ha encontrado el profesor con ese numero de cedula..." << endl;

	Interfaz_Principal::msjPausa();
	system("cls");
}