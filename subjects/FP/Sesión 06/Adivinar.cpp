#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	
	const int MIN = 1, MAX = 100;
	const int NUM_VALORES = MAX - MIN + 1; // Valores entre MIN y MAX
	const int TERMINADOR = -1;

	int numero;

	// ENTRADAS Y C�LCULOS

	const string MENSAJE = "Intente adivinar el numero: ";

	cout << "Si no quiere seguir jugando, introduzca \"" << TERMINADOR << "\"." << endl << endl;
	cout << MENSAJE << "(entre " << MIN << " y " << MAX << ") ";

	cin >> numero;

	// Generamos el n�mero aleatorio:

	time_t t;
	srand(time(&t));	// Inicia el generador de n�meros aleatorios

	// Almacenamos el n�mero aleatorio, modific�ndolo para que est� en el
	// intervalo [MIN, MAX]
	int adivinar;
	adivinar = (rand() % NUM_VALORES) + MIN;

	// Bucle que permite seguir jugando

	while(numero != TERMINADOR && numero != adivinar){
		
		cout << endl;

		// Imprime si el n�mero a adivinar es mayor o menor que el introducido

		if(numero > adivinar)
			cout << "El numero es menor que " << numero << "." << endl;

		else
			cout << "El numero es mayor que " << numero << "." << endl;

		// Solicita el siguiente n�mero del jugador

		cout << MENSAJE;
		cin >> numero;

	}

	// SALIDAS

	cout << endl << endl;

	// Si el jugador se ha rendido
	if(numero == TERMINADOR)
		cout << "El numero era " << adivinar << "." << endl;

	// Si no, es que ha acertado el n�mero
	else
		cout << "Felicidades, has acertado, el numero era " << adivinar << "." << endl;

	cout << endl;

	return 0;
}
