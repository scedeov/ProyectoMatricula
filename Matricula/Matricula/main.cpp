#include "universidad.h"

int main()
{
	Universidad U1;

	cout << string("----------------PROBANDO---------------") << endl;
	cout << string("-------------SIN PARAMETROS-------------") << endl;
	cout << U1.toString() << endl;
	cout << string("-------------CON PARAMETROS-------------") << endl;
	Universidad U2("Universidad Undefined", "22123456", "Heredia");
	cout << U2.toString() << endl;

	cin.get();
	cin.get();
	return 0;
}