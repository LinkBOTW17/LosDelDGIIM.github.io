#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	
	const int MIN = 1, MAX = 100;
	const int NUM_VALORES = MAX - MIN + 1;		// Valores entre MIN y MAX

	const int NUMERO_JUEGOS = 50;

	int juego = 0;
	int jugadas = 0;

	int sumatoria_jugadas = 0;

	// Para mostrar las jugadas que se han hecho por cada juego
	string info_jugadas; 

	// C�LCULOS   ********************************************************

	// Iniciamos el generador de n�meros aleatorios

	time_t t;
	srand(time(&t));

	// Se juegan NUMERO_JUEGOS juegos

	for(int i = 0 ; i < NUMERO_JUEGOS; i++){

		jugadas = 0;	// Reiniciamos el n�mero de jugadas

		juego++;	// Comenzamos un nuevo juego

		// 1.- Se genera el n�mero aleatorio a adivinar   ------------------

		// Almacenamos el n�mero aleatorio, modific�ndolo para que est� en el
		// intervalo [MIN, MAX]
		int adivinar = (rand() % NUM_VALORES) + MIN;

		// 2.- EL programa intenta adivinar el n�mero aleatoriamente -------

		int intento;

		// Se ejecuta hasta que lo adivine

		srand(5);

		do{

			// N�mero aleatorio que intenta adivinar la variable adivinar
			intento = (rand() % NUM_VALORES) + MIN;

			jugadas++;		// Aumentan las jugadas

		}while(intento != adivinar);

		// 3.- Se tiene en cuenta el n�mero de jugadas y se almacenan para
		// imprimirlas en consola.

		info_jugadas += "Juego " + to_string(juego) + ":	" 
					 + to_string(jugadas) + " jugadas.\n";

		sumatoria_jugadas += jugadas;

	}

	// Se calcula la media de jugadas por juegos:

	double media_intentos = ((double) sumatoria_jugadas) / NUMERO_JUEGOS;

	// SALIDAS ***********************************************************

	cout << info_jugadas << endl;

	cout << "La media de intentos por juego es de " << media_intentos 
		 << " jugadas/juego." << endl;
	cout << endl;

	return 0;
}
