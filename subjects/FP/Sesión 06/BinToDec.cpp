#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	string binario;
	int decimal = 0;

	bool error_lectura = false;

	// ENTRADAS CON FILTROS Y C�LCULOS

	do{
		// Imprime que se ha introducido un dato incorrecto, en dicho caso
		if(error_lectura)
			cout << endl << "Error: debe introducir un numero binario entero."
				 << endl;

		// Hasta que no se detecte que ha habido un error, no ha habido ninguno
		error_lectura = false;

		// Se solicita el n�mero binario al usuario
		cout << "Numero binario: ";
		cin >> binario;

		// INEFICIENTE: USAR WHILE

		// Se comprueba que la cadena introducida s�lo tenga '0' y '1'
		for(int i = 0; i < binario.length(); i++){

			// Si no se ha detectado ning�n error, se busca uno
			if(!error_lectura)

				// Si un caracter es distinto de 0 o 1, hay un error
				error_lectura = binario.at(i) != '0' && binario.at(i) != '1';

		}

	}while(error_lectura);

	// C�LCULOS

	int exponente = 0;
	
	// Recorre el n�mero binario, comenzando por su bit menos significativo
	for(int i = binario.length()-1; i>= 0; i--){

		// En caso de haber un 1 en dicha posici�n, se le suma al n�mero 
		// decimal 2^exponente
		if(binario.at(i) == '1')
			decimal += pow(2, exponente);

		// Aumentamos el exponente para analizar la siguiente cifra
		exponente++;

	}

	// SALIDA

	cout << endl;
	cout << binario << " en decimal es " << decimal << endl;
	cout << endl;

	return 0;
}
