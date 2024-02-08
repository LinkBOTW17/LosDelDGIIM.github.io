#include <iostream>

using namespace std;

int main()
{	
	// Numero de posiciones que hay que retroceder en la tabla ASCII
	// para pasar de min�scula a may�scula.
	const int POSICIONES_ASCII = 'a' - 'A';
	const int MINUSCULA_MIN = 'a';
	const int MINUSCULA_MAX = 'z';

	char caracter_in, caracter_out;

	// ENTRADA

	cout << "Un caracter en minuscula: ";
	cin >> caracter_in;

	// Comprobamos si caracter_in es una letra min�scula:

	bool caracter_in_minuscula = caracter_in >= MINUSCULA_MIN && caracter_in <= MINUSCULA_MAX;

	if(!caracter_in_minuscula){
		cout << endl;
		cout << "Error: el dato introducido debe ser un caracter en minuscula." 
			 << endl;
		cout << endl;
	}

	// C�LCULO

	// Si es una letra min�scula, la pasamos a may�scula:

	if(caracter_in_minuscula)

		// Retrocede las posicinoes indicadas en la tabla ASCII.
		caracter_out = caracter_in - POSICIONES_ASCII;

	// SALIDA

	if(caracter_in_minuscula){
		cout << endl;
		cout << "Su caracter: " << caracter_out << endl;
		cout << endl;
	}

	return 0;
}
