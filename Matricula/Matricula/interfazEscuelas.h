#ifndef INTERFAZ_ESCUELAS
#define INTERFAZ_ESCUELAS



class ContenedorEscuelas;
class Interfaz_Escuelas
{
public:
	static char vMenuEscuelas();
	static char vAjustesEscuelas();
	static void vIngresaEscuela(ContenedorEscuelas*);
	static void vInfoEscuelas(Universidad*, ContenedorEscuelas*);
};
#endif // !INTERFAZ_ESCUELAS

