#include <iostream>
#include <iomanip>

using namespace std;

/****************************************************************************/
// Constantes globales

const int ANIO_INICIAL = 2001, ANIO_FINAL = 2021;
const int NUM_ANIOS = ANIO_FINAL - ANIO_INICIAL + 1;

const int PAISES = 4;

const string NOMBRES_PAISES[PAISES] = {"Espania", "Reino Unido", 
										"Estados Unidos", "Zona euro"};

enum class Pais {Espana, UK, USA, Euro};

// IPC de Espa�a, Inglaterra, USA y la Zona Euro

const double IPC[PAISES][NUM_ANIOS] = 
				{{2.7, 4, 2.6, 3.2, 3.7, 2.7, 4.2, 1.4, 0.8, 3, 2.4, 2.9, 0.3, 
				-1, 0, 1.6, 1.1, 1.2, 0.8, -0.5, 6.5}, 

				{1.07, 1.69, 1.25, 1.64, 1.92, 2.97, 2.12, 3.11, 2.83, 3.73, 
				4.2, 2.71, 2, 0.55, 0.23, 1.6, 2.9, 2.1, 1.3, 0.6, 5.4}, 

				{1.6, 2.4, 1.9, 3.3, 3.4, 2.5, 4.1, 0.1, 2.7, 1.5, 3, 1.7, 1.5, 
				0.8, 0.7, 2.1, 2.1, 1.9, 2.3, 1.4, 7}, 
			
				{2.1, 2.3, 2, 2.4, 2.2, 1.9, 3.1, 1.6, 0.9, 2.2, 2.8, 2.2, 0.8, 
				-0.2, 0.2, 1.1, 1.3, 1.5, 1.3, -0.3, 5}};

/****************************************************************************/
// Definici�n de structs

// Almacena un valor de IPC medio

struct IPCMedio{
	double ipc;		// Valor del IPC medio
	Pais pais;		// Indica de que pa�s es el IPC
	int anio_inicial;		// Indica el a�o inicial de c�lculo
	int anio_final;			// Indica el a�o final
};

/****************************************************************************
	Imprime en consola el IPC medio, indicando el pa�s, el valor del ipc
	y los a�os entre los que se ha calculado con el siguiente formato:

		pais
		ipc%
		Entre anio_inicial y anio_final

  Par�metros: ipc_medio

****************************************************************************/

void cout_IPCMedio(IPCMedio ipc_medio){

	cout << "\t" << NOMBRES_PAISES[(int)ipc_medio.pais] << endl;

	cout << "\t" << ipc_medio.ipc << "%" << endl;

	cout << "\tEntre " << ipc_medio.anio_inicial << " y " 
		 << ipc_medio.anio_final << endl;
}

/****************************************************************************
	Devuelve el IPC del a�o especificado y del pa�s especificado

  Par�metros: anio, pais
  Devuelve: El IPC del anio especificado

  PRE: ANIO_INICIAL <= anio <= ANIO_FINAL

	*Necesita a la cte global IPC[][]

****************************************************************************/

double Obtener_IPC(int anio, Pais pais){
	
	return IPC[(int) pais][anio - ANIO_INICIAL];
}

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

	// Se repite mientas que no sea entero

	do{

		cout << mensaje;
		cin >> numero;

	}while(!EsEntero(numero));

	return stoi(numero);
}

/****************************************************************************/

int main(){

	const int MIN_N_ANIOS = 2, MAX_N_ANIOS = 5;
	const int TERMINADOR_MAXIMO = -1;

	const string MSG_INTERVALO_N = "(entre " + to_string(MIN_N_ANIOS) 
									+ " y " + to_string(MAX_N_ANIOS) + ")";

	// Se formatea la consola para mostrar de forma correcta los porcentajes
	
	cout.setf(ios::fixed);

	cout << setw(4) << setprecision(2);

	// Se comienza con la entrada de datos

	cout << "Introduzca un numero de anios negativo para finalizar." << endl;

	cout << endl;

	// Solicita un n�mero de a�os 
	// MIN_N_ANIOS <= n <= MAX_N_ANIOS � n <= TERMINADOR_MAXIMO

	int n;

	cout << "--------------------------------" << endl;

	do{
		
		n = LeerEntero("Numero de anios " + MSG_INTERVALO_N + ": ");

	}while(n > TERMINADOR_MAXIMO && (n < MIN_N_ANIOS || n > MAX_N_ANIOS));

	// Mientras que n no sea negativo

	while(n > TERMINADOR_MAXIMO){

		// Calcula el IPC medio mayor y menor en n a�os --------------------

		// Los a�os entre los que se van calculando los ipc medios

		int primer_anio = ANIO_INICIAL;

		int ultimo_anio = primer_anio + n - 1;

		// Almacena cuales y donde son los maximos y minimo ipcs

		// Inicializamos su valor en unos valores imposibles para que se 
		// se alteren en el bucle

		IPCMedio mayor_ipc = {-100, Pais::Espana, 2001, 2021};

		IPCMedio menor_ipc = {100, Pais::Espana, 2001, 2021};

		IPCMedio actual;	// ALmacena el IPC que se est� calculando ahora

		// Mientras que se pueddan seguir considerando a�os

		while(ultimo_anio <= ANIO_FINAL){

			// Se guardan los a�os en los que se calcula el IPC medio

			actual.anio_inicial = primer_anio;

			actual.anio_final = ultimo_anio;

			// Lo repite por cada pa�s

			for(int pais = 0; pais < PAISES; pais++){

				// Guarda la informaci�n del ipc medio que se calcula

				actual.pais = (Pais) pais;

				// Se calcula el IPC medio entre primer_anio y ultimo_anio
				// del pa�s pais

				double sumatoria = 0;

				for(int anio = primer_anio; anio <= ultimo_anio; anio++){

					sumatoria += Obtener_IPC(anio, actual.pais);

				}

				actual.ipc = sumatoria / n;

				// Si es mayor que el mayor o menor que el menor se guarda

				if(actual.ipc > mayor_ipc.ipc)
					mayor_ipc = actual;

				if(actual.ipc < menor_ipc.ipc)
					menor_ipc = actual;

			}

			// Busca en el siguiente intervalo de a�os

			primer_anio++;
			ultimo_anio = primer_anio + n - 1;			
		}

		// Imprime cual ha sido el resultado ------------------------------

		cout << endl;

		// Imprime cual es el mayor IPC medio en n a�os

		cout << "Mayor IPC medio en " << n << " anios: " << endl;

		cout_IPCMedio(mayor_ipc);

		cout << endl;

		// Imprime cual es el menor IPC medio en n a�os

		cout << "Menor IPC medio en " << n << " anios: " << endl;

		cout_IPCMedio(menor_ipc);

		cout << endl;

		// Solicita el siguiente n�mero de anios --------------------------
		// MIN_N_ANIOS <= n <= MAX_N_ANIOS � n <= TERMINADOR_MAXIMO
	
		cout << "--------------------------------" << endl;

		do{
		
		n = LeerEntero("Numero de anios " + MSG_INTERVALO_N + ": ");

		}while(n > TERMINADOR_MAXIMO && (n < MIN_N_ANIOS || n > MAX_N_ANIOS));

	}

	return 0;
}
