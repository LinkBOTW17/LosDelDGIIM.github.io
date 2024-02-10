#include <iostream>
#include <iomanip>

using namespace std;

// Enumerado que determina el modo de pasar por las casills

enum class RecorrerMapa {Zigzag, Espiral};

// Definici�n de struct

struct Punto{
	int fila;
	int columna;
};

/****************************************************************************
	Determina si una cadena es un n�mero entero o si no.

  Par�metros: cadena
  Devuelve: true si cadena es un n�mero entero, false si no

****************************************************************************/

bool EsEntero(string cadena){

	// Incluir en SIGNOS todos los signos v�lidos

	const string SIGNOS = "+-";

	bool es_entero;

	// Si la cadena est� vac�a no es un entero
	if(cadena.length() == 0)
		es_entero = false;

	else{

		// Si el primer caracter es un signo y hay m�s caracteres se borra

		if(SIGNOS.find(cadena.at(0)) != string::npos && cadena.length() > 1)
			cadena.erase(0, 1);

		// Comprobamos que todos los caracteres sean d�gitos

		int i = 0;

		es_entero = true;

		while(i < cadena.length() && es_entero){

			if(!isdigit(cadena.at(i)))
				es_entero = false;

			else
				i++;

		}
	}

	return es_entero;
}

/****************************************************************************
	Imprime un mensaje en consola y lee el n�mero entero que introduce el 
	usuario. Repite la entrada mientras que el valor introducido no sea
	un n�mero entero.

  Par�metros: titulo, el mensaje que se muestra al usuario
  Devuelve: el n�mero entero que introduce el usuario

****************************************************************************/

int LeerEntero(string mensaje){
	string numero;

	// Se repite mientras que no sea un n�mero entero

	do{

		cout << mensaje;
		cin >> numero;

	}while(!EsEntero(numero));

	return stoi(numero);
}

/****************************************************************************
	Imprime un mensaje en consola y lee el n�mero entero que introduce el 
	usuario. Repite la entrada mientras que el valor introducido no sea
	un n�mero entero o mientras que el n�mero no est� en el intervalo
	[min, max]

  Par�metros: titulo, el mensaje que se muestra al usuario
			  min, el m�nimo valor v�lido
			  max, el m�ximo valor v�lido
  Devuelve: el n�mero entero que introduce el usuario

****************************************************************************/

int LeerEnteroEnRango(string mensaje, int min, int max){
	int numero;

	// Se repite mientras que no est� en el intervalo [min, max]

	do{

		numero = LeerEntero(mensaje);

	}while(numero < min || numero > max);

	return numero;
}

/****************************************************************************/

int main(){
	
	// Determina en qu� modo recorrer� el robot el mapa *********************

	RecorrerMapa modo;

	// Para que el robot recorra el mapa en Zigzag:

	modo = RecorrerMapa::Zigzag;

	// Para que el robot recorra el mapa en Espiral:

	// modo = RecorrerMapa::Espiral;

	// **********************************************************************

	// Coordenadas m�nimas y m�ximas de las filas y columnas

	const int MIN_FILAS = 1, MIN_COLUMNAS = 1;
	const int MAX_FILAS = 10, MAX_COLUMNAS = 10;

	const int NUM_FILAS = MAX_FILAS - MIN_FILAS + 1;
	const int NUM_COLUMNAS = MAX_COLUMNAS - MIN_COLUMNAS + 1;

	const string MSG_INTERVALO_FILAS = "(entre " + to_string(MIN_FILAS) + " y " 
												+ to_string(MAX_FILAS) + ")";

	const string MSG_INTERVALO_COLUMNAS = "(entre " + to_string(MIN_COLUMNAS) 
									+ " y " + to_string(MAX_COLUMNAS) + ")";

	// Repertorio v�lido de instrucciones

	const char INS_IZQDA = 'I', INS_DCHA = 'D';
	const char INS_ARRIBA = 'A', INS_ABAJO = 'B';

	int mapa[NUM_FILAS][NUM_COLUMNAS] = {{0}};

	// ENTRADAS ************************************************************

	// Se solicita la posici�n inicial del robot

	cout << "Introduzca la posici�n inicial del robot: " << endl;

	int fila, columna;

	fila = LeerEnteroEnRango("\tFila " + MSG_INTERVALO_FILAS + ": ", 
												MIN_FILAS, MAX_FILAS);

	columna = LeerEnteroEnRango("\tColumna " + MSG_INTERVALO_COLUMNAS + ": ", 
												MIN_COLUMNAS, MAX_COLUMNAS);

	// Se almacena la posici�n en pos

	Punto pos = {fila, columna};

	// C�LCULOS *************************************************************

	// Generaci�n de la secuencia de instrucciones *************************

	// 1.- Calculamos el n�mero de instrucciones que usaremos ---------------
		
	// N�mero de instrucciones para recorrer el mapa a partir de (1, 1)

	int dimension_mapa = NUM_FILAS * NUM_COLUMNAS;

	// N�mero de instrucciones para llevar el robot a (1, 1)

	int desplazamiento_horiz = pos.fila - MIN_FILAS;

	int desplazamiento_vert = pos.columna - MIN_COLUMNAS;

	// Declara el array que usaremos para las instrucciones

	int lon = dimension_mapa + desplazamiento_horiz + desplazamiento_vert;

	char ord[lon];

	int posiciones_llenas = 0;

	// 2.- Genera la secuencia para llevar el robot a (1, 1)  ----------------

	// Lleva el robot a la columna 1

	for(int i = pos.columna; i > MIN_COLUMNAS; i--){

		ord[posiciones_llenas] = INS_IZQDA;

		posiciones_llenas++;

	}

	// Lleva el robot a la fila 1

	for(int i = pos.fila; i > MIN_FILAS; i--){
		
		ord[posiciones_llenas] = INS_ABAJO;

		posiciones_llenas++;

	}

	// 3.- Genera la secuencia para recorrer el mapa en funci�n del modo 

	switch(modo){
	
		// 3.- Genera la secuencia para recorrerlo en ZigZag ----------------

		case RecorrerMapa::Zigzag:{
			
			bool avanzar_dcha = true;

			// Rellena la primera fila
		
			char rellenar = (avanzar_dcha)? INS_DCHA : INS_IZQDA;
		
			for(int i = MIN_COLUMNAS; i < MAX_COLUMNAS; i++){
		
				// Avanza hacia la derecha o hacia la izquierda
		
				ord[posiciones_llenas] = rellenar;
		
				posiciones_llenas++;
		
			}
		
			// Recorre todas las filas a partir de la segunda
		
			for(int i = MIN_FILAS + 1; i <= MAX_FILAS; i++){
		
				// Avanza a la siguiente fila
		
				ord[posiciones_llenas] = INS_ARRIBA;
		
				posiciones_llenas++;
			
				// Invierte la direcci�n de avance
		
				avanzar_dcha = !avanzar_dcha;
		
				// Recorre toda la fila
		
				rellenar = (avanzar_dcha)? INS_DCHA : INS_IZQDA;
		
				for(int i = MIN_COLUMNAS; i < MAX_COLUMNAS; i++){
		
					// Avanza hacia la derecha o hacia la izquierda
		
					ord[posiciones_llenas] = rellenar;
		
					posiciones_llenas++;
		
				}
			}

			break;}

		// 3.2- Genera la secuencia para recorrerlo en Espiral ---------------

		case RecorrerMapa::Espiral:{
	
			// Recorre la primera fila

			for(int i = MIN_COLUMNAS; i < MAX_COLUMNAS; i++){
			
				// Avanza hacia la derecha
		
				ord[posiciones_llenas] = INS_DCHA;
		
				posiciones_llenas++;
		
			}
		
			// Indican el n�mero de caracteres que se colocan por cada fila o 
			// columna de la espiral
		
			int rellena_filas = NUM_FILAS - 1;
			int rellena_columnas = NUM_COLUMNAS - 1;
		
			// Indica si el robot tiene que ir a la derecha y arriba o no
		
			bool dcha_y_arriba = true;
		
			// Mientras que no se rellenen todas las casillas
		
			while(posiciones_llenas < lon - 1){
		
				// Se rellena una columna de la espiral
		
				char rellenar_espiral = (dcha_y_arriba)? INS_ARRIBA: INS_ABAJO;
		
				for(int i = 0; i < rellena_filas; i++){
					ord[posiciones_llenas] = rellenar_espiral;
			
					posiciones_llenas++;
				}
			
				// Se rellena una fila de la espiral
		
				rellenar_espiral = (dcha_y_arriba)? INS_IZQDA : INS_DCHA;
		
				for(int i = 0; i < rellena_columnas; i++){
					ord[posiciones_llenas] = rellenar_espiral;
		
					posiciones_llenas++;
				}
		
				// Se alternan las posiciones
		
				dcha_y_arriba = !dcha_y_arriba;
		
				// En la siguiente vuelta, las filas y las columnas tendr�n
				// una casilla menos a rellenar
		
				rellena_filas--;
				rellena_columnas--;
			}

			break;}
	}

	// Se ejecuta el repertorio de instrucciones en el robot *****************

	int instruccion = -1;	// Para que se aumente al entrar en el bucle

	bool dentro_mapa = true;

	while(instruccion < posiciones_llenas && dentro_mapa){
	
		// Se cuenta que el robot ha pasado por dicha posici�n del mapa

		mapa[pos.fila-1][pos.columna-1]++;

		// Aumenta el n�mero de instrucci�n

		instruccion++;	

		switch(ord[instruccion]){
			case INS_IZQDA:	// Izquierda
				pos.columna--;
				break;

			case INS_DCHA:	// Derecha
				pos.columna++;
				break;

			case INS_ARRIBA:	// Arriba
				pos.fila++;
				break;

			case INS_ABAJO:	// Abajo
				pos.fila--;
				break;
		}	

		// Eval�a si el robot sigue estando dentro del mapa

		dentro_mapa = pos.fila >= MIN_FILAS && pos.fila <= MAX_FILAS && 
				pos.columna >= MIN_COLUMNAS && pos.columna <= MAX_COLUMNAS;
	}

	// SALIDAS **************************************************************

	cout << setw(1);

	cout << endl;

	// Si se sali� del mapa, imprime el n�mero de �rdenes

	if(!dentro_mapa)
		cout << "Numero de ordenes: " << instruccion << endl;

	else{

		// Imprime por qu� m�todo se ha recorrido el mapa -----------------

		switch(modo){
			case RecorrerMapa::Zigzag:
				cout << "Se ha recorrido el mapa en forma de zig-zag." << endl;
				break;

			case RecorrerMapa::Espiral:
				cout << "Se ha recorrido el mapa en forma de espiral." << endl;
				break;
		}

		cout << endl;

		// Parte superior mapa --------------------------------------------

		cout << "   : ";

		// Se imprimen el n�mero de columnas

		for(int i = MIN_COLUMNAS; i <= MAX_COLUMNAS; i++){
			cout << i << " ";
		}

		cout << "   " << endl;

		cout << "   -----------------------   " << endl;

		// Parte central mapa --------------------------------------------

		// Se imprime el mapa

		for(int i = MAX_FILAS; i >= MIN_FILAS; i--){

			// Se imprime el n�mero de fila

			// Si tiene s�lo 1 cifra se introduce un espacio

			if(i < 10)
				cout << " ";

			cout << i << " : ";

			// Se imprimen todas las columnas de la fila

			for(int j = MIN_COLUMNAS; j <= MAX_COLUMNAS; j++){

				if(mapa[i-1][j-1] == 0)
					cout << ". ";

				else
					cout << mapa[i-1][j-1] << " ";

			}

			// Se vuelve a imprimir el n�mero de fila al final

			cout << ":  " << i << endl;

		}

		// Parte inferior mapa --------------------------------------------

		cout << "   -----------------------   " << endl;

		cout << "   : ";

		// Se imprime el n�mero de columnas

		for(int i = MIN_COLUMNAS; i <= MAX_COLUMNAS; i++){
			cout << i << " ";
		}

		cout << "   " << endl;

	}

	cout << endl;

	return 0;
}
