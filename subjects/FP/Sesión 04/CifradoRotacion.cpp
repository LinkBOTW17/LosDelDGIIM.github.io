#include <iostream>

using namespace std;

int main()
{
	int clave;
	char caracter;

	// Constantes que nos ayudar�n en los c�lculos para que el c�racter
	// codificado no se salga del intervalo [A, Z].
	const int MIN = 'A', MAX = 'Z';
	const int RANGO = MAX - MIN + 1; 	//N�mero de letras en [A, Z].

	// ENTRADAS

	cout << "La clave: ";
	cin >> clave;

	cout << "El caracter (mayuscula): ";
	cin >> caracter;

	// C�LCULO
	
	char caracter_codificado = MIN + ((caracter - MIN + clave) % RANGO);

	/*
		Cualquier n�mero y = MIN + (x % RANGO) (Sea x cualquier n�mero)
		est� dentro del intervalo [MIN, MAX].

		caracter - MIN est� dentro del intervalo [MIN, MAX]
		Al sumarle la clave, puede que se salga, por lo que aplicamos
		la ecuaci�n explicada anteriormente.
	*/

	// SALIDA

	cout << endl;
	cout << "El caracter codificado: " << caracter_codificado << endl;
	cout << endl;

	return 0;
}
