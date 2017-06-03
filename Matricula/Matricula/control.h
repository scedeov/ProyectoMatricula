#ifndef CONTROL
#define CONTROL

class Universidad;
class Contenedor;
class Control
{
private:
	Universidad *universidad;
	Contenedor *contenedor;
public:
	void Inicializador();
	void MenuPrincipal();
	void MenuUniversidad();
	void AjustesUniversidad();
	void MenuEscuelas();
	void AjustesEscuelas();
	void MenuCursos();
	void AjustesCursos();
	void MenuProfesores();
	void AjustesProfesores();
	void MenuEstudiantes();
	void AjustesEstudiantes();
	void MenuMatricula();
	void AjustesMatricula();
};

#endif
