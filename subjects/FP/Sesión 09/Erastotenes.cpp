#include <iostream>

using namespace std;

// Definici�n de structs

struct Pareja{
	int primo;
	int potencia;
};

/****************************************************************************
	Imprime un mensaje y lee un n�mero entero.
	Mientras que el n�mero introducido no est� entre los valores m�nimo y
	m�ximo, vuelve a solicitar el n�mero.

  Par�metros: mensaje, el mensaje que se muestra al solicitar el n�mero
			  minimo, maximo, los n�meros que definen el rango
  Devuelve: un entero positivo

****************************************************************************/

int LeerEnteroEnRango(string mensaje, int minimo, int maximo){

	int entrada;

	// Se repite mientras entrada no est� en [minimo, maximo]

	do{

		cout << mensaje;
		cin >> entrada;

	}while(entrada < minimo || entrada > maximo);

	return entrada;
}

/****************************************************************************/

int main(){
	
	//---------------------------------------------------------------------
	// C�lculo de todos los n�meros primos entre PRIMER_PRIMO y MAX_PRIMO

	const int MAX_PRIMO = 5000;
	const int PRIMER_PRIMO = 2;

	// Longitud del array que almacena los primos
	const int MAX_DATOS = MAX_PRIMO / 2;

	// N�mero de valores entre PRIMER_PRIMO y MAX_PRIMO
	const int LONG_ARRAYS = MAX_PRIMO - PRIMER_PRIMO + 1;

	// Donde almacenamos todos los n�meros entre PRIMER_PRIMO Y MAX_PRIMO

	int numeros[LONG_ARRAYS];
	bool es_primo[LONG_ARRAYS];

	int primos[MAX_DATOS];
	int pos_validas_primos = 0;

	// Rellena numeros con todos los n�meros entre PRIMER_PRIMO y MAX_PRIMO

	int numero = PRIMER_PRIMO;

	for(int i = 0; i < LONG_ARRAYS; i++){
	
		numeros[i] = numero;
		numero++;

		// Se presupone que un n�mero es primo hasta que no se "tache"
		es_primo[i] = true;
	}

	int primo = PRIMER_PRIMO;

	int posicion = 0;

	// Mientras que primo^2 no sea mayor que MAX_PRIMO

	while(primo * primo <= MAX_PRIMO){

		// Comprueba todos los n�meros a partir de primo (est� en posicion)

		for(int i = posicion + 1; i < LONG_ARRAYS; i++){

			// Si numeros[i] es m�ltiplo de primo
			if(numeros[i] % primo == 0)
				es_primo[i] = false;	// No es un n�mero primo (se "tacha")		

		}

		// Busca el siguiente n�mero primo

		posicion++;

		while(!es_primo[posicion])
			posicion++;

		primo = numeros[posicion];
	}

	// Guarda todos los n�meros primos en el array primos

	for(int i = 0; i < LONG_ARRAYS; i++){
		if(es_primo[i]){
			primos[pos_validas_primos] = numeros[i];
			pos_validas_primos++;
		}
	}

	// ---------------------------------------------------------------------
	// Entradas y c�lculos

	const int TERMINADOR = 0;
	const string MSG = "Numero (entre " + to_string(TERMINADOR+1) + " y " 
						+ to_string(MAX_PRIMO) + "): "; 

	const int CASILLAS_DESCOMPOSICION = 50;

	const char ELEVADO = '^';
	const string SEPARADOR = " * ";

	cout << "Para finalizar, introduzca " << TERMINADOR << endl << endl;

	int entrada = LeerEnteroEnRango(MSG, TERMINADOR, MAX_PRIMO);

	while(entrada != TERMINADOR){

		// Se trabaja con una copia de entrada

		int numero = entrada;

		// Las inicializamos todas en 0

		Pareja descomposicion[CASILLAS_DESCOMPOSICION] = {{0, 0}};
		
		int utilizados_descomposicion = 0;

		int i = 0;

		if(numero == 1){

			descomposicion[0].primo = 1;
			utilizados_descomposicion++;

		}else{

			// Mientas que haya primos o mientras que numero sea distinto de 1

			while(i < pos_validas_primos && numero != 1){
				int primo = primos[i];	// Se coge un primo del array
				int contador = 0;
	
				// Se cuentan las veces que el primo es divisor de numero
	
				while(numero % primo == 0){
					numero /= primo;
					contador++;
				}
		
				// Si lo divide al menos una vez, se almacena qu� primo
				// era y cuantas veces lo divid�a
	
				if(contador != 0){
					descomposicion[utilizados_descomposicion].primo = primo;
					descomposicion[utilizados_descomposicion].potencia = 
																	contador;
					
					utilizados_descomposicion++;
				}
				
				i++;	// Se comprueba el siguiente primo
			}
		}

		// Imprime la salida ----------------------------------------

		cout << entrada << " = ";

		// Recorre todos los valores �tiles del array descomposicion

		for(int i = 0; i < utilizados_descomposicion - 1; i++){

			// Imprime el primo y la potencia si es necesario

			cout << descomposicion[i].primo;

			if(descomposicion[i].potencia > 1)
				cout << ELEVADO << descomposicion[i].potencia;

			cout << SEPARADOR;
		}

		// Imprime el �ltimo primo de la descomposici�n con su potencia

		cout << descomposicion[utilizados_descomposicion - 1].primo;

		if(descomposicion[utilizados_descomposicion - 1].potencia > 1)
			cout << ELEVADO 
				 << descomposicion[utilizados_descomposicion - 1].potencia;

		// Solicita el siguiente n�mero -----------------------------

		cout << endl << endl;

		entrada = LeerEnteroEnRango(MSG, TERMINADOR, MAX_PRIMO);
	}

	return 0;
}
