#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	
    const char CHAR_SEGUIR = 's', CHAR_SALIR = 'n';
	const int MIN = 1, MAX = 100;
	const int NUM_VALORES = MAX - MIN + 1; // Valores entre MIN y MAX
	const int TERMINADOR = -1;

	int numero;

	char entrada;		// (S/N) de desea seguir jugando

	bool seguir;		// true para seguir jugando

	int juegos = 0; 	// N�mero de juegos

	// ENTRADAS Y C�LCULOS

	const string MENSAJE = "Intente adivinar el numero: ";

	// Iniciamos el generador de n�meros aleatorios
	time_t t;
	srand(time(&t));

	do{

		// Generamos el n�mero aleatorio
	
		// Almacenamos el n�mero aleatorio, modific�ndolo para que est� en el
		// intervalo [MIN, MAX]
		int adivinar;
		adivinar = (rand() % NUM_VALORES) + MIN;

		// Primera salida (informaci�n del TERMINADOR)

		cout << "Si se rinde, introduzca \"" << TERMINADOR << "\"." 
				 << endl << endl;

		// Lectura anticipada

		// Se asegura que el n�mero introducido est� en [MIN, MAX]

		bool fuera_rango;

		do{
	
			cout << MENSAJE << "(entre " << MIN << " y " << MAX << ") ";

			cin >> numero;

			fuera_rango = numero != TERMINADOR 
							&& (numero < MIN || numero > MAX);

		}while(fuera_rango);
	
		// Bucle que permite seguir jugando
	
		while(numero != TERMINADOR && numero != adivinar){
			
			cout << endl;
	
			// Imprime si adivinar es mayor o menor que el introducido
	
			if(numero > adivinar)
				cout << "El numero es menor que " << numero << "." << endl;
	
			else
				cout << "El numero es mayor que " << numero << "." << endl;
	
			// Solicita el siguiente n�mero del jugador
			// Se asegura que el n�mero introducido est� en [MIN, MAX]
	
			do{

				cout << MENSAJE;
				cin >> numero;

				fuera_rango = numero != TERMINADOR 
							&& (numero < MIN || numero > MAX);

			}while(fuera_rango);

		}
	
		// SALIDAS
	
		cout << endl << endl;
	
		// Si el jugador se ha rendido
		if(numero == TERMINADOR)
			cout << "El numero era " << adivinar << "." << endl;
	
		// Si no, es que ha acertado el n�mero
		else
			cout << "Felicidades, has acertado, el numero era " << adivinar 
				 << "." << endl;
	
		cout << endl;

		// SEGUIR JUGANDO

		do{

			cout << endl;
			cout << "Quiere seguir jugando? (S/N): ";
	
			cin >> entrada;
	
			cout << endl << endl;

			// Pasamos entrada a min�scula para simplificar las comparaciones
			entrada = tolower(entrada);

			// Si no es igual a s/n la entrada es inv�lida, se repite

		}while(entrada != CHAR_SEGUIR && entrada != CHAR_SALIR);

		seguir = entrada == CHAR_SEGUIR;	// Si se introdujo s se sigue jugando

		juegos++;	// Se aumenta el contador del n�mero de juegos

	}while(seguir);

	// Se imprime el n�mero de juegos totales, contando tambi�n rendiciones 

	cout << "Se han jugado un total de " << juegos << " juegos." << endl;

	return 0;
}
