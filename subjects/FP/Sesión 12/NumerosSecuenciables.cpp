#include <iostream>
#include <cmath>

using namespace std;

/****************************************************************************/

class Lector{

	// Campo de clase

	private:
	string mensaje;

	// M�todos

	public:

	/**************************************************************/
	// M�todo constructor

	Lector(string msg) : mensaje(msg) {}

	/**************************************************************/	
	// Cambia el mensaje

	void SetTitulo(string msg){
		mensaje = msg;
	}

	/**************************************************************/	
	// Obtiene el mensaje

	string GetTitulo() {
		return mensaje;
	}

	/**************************************************************/
	// M�todos de enteros
	/**************************************************************/
	// Imprime el mensaje y se repite mientras que no sea un n�mero entero

	int LeeEntero(){
		string numero;
	
		do{
	
			cout << mensaje;
			cin >> numero;
	
		}while(!EsEntero(numero));
	
		return stoi(numero);
	}

	/**************************************************************/
	// Devuelve un entero mayor o igual que referencia, repitiendo 
	// la entrada al usuario si esto no se da

	int LeeEnteroMayorOIgual(int referencia){
		int numero;

		do{
			numero = LeeEntero();
		}while(numero < referencia);

		return numero;
	}

	/**************************************************************/
	// Devuelve un entero entre min y max, repitiendo la entrada al 
	// usuario si esto no se da
	// PRE: min <= max

	int LeeEnteroEnRango(int min, int max){
		int numero;

		do{
			numero = LeeEntero();
		}while(numero < min || numero > max);

		return numero;
	}

	/**************************************************************/
	// Devuelve un n�mero entero entre min y max o menor o igual que 
	// terminador, repitiendo la entrada si ninguna de estas condicioens se da
	// PRE: terminador <= min <= max

	int LeeEnteroEnRangoConTerminador(int min, int max, 
														int terminador){
		int numero;

		// Repite la entrada si numero no pertenece al intervalo
		// (-inf, terminador] U [min, max]

		do{
			numero = LeeEntero();
		}while(numero > max || (numero > terminador && numero < min));

		return numero;
	}

	/**************************************************************/
	// M�todos de reales
	/**************************************************************/
	// Imprime el mensaje y lee un n�mero real del usuario

	double LeeReal(){
		string numero;

		do{
	
			cout << mensaje;
			cin >> numero;

		}while(!EsReal(numero));
	
		return stod(numero);
	}

	/**************************************************************/
	// Devuelve un n�mero mayor o igual que referencia, repitiendo 
	// la entrada si esto no se da

	double LeeRealMayorOIgual(double referencia){
		double numero;
	
		do{
			numero = LeeReal();
		}while(numero < referencia);
	
		return numero;
	}

	/**************************************************************/
	// Devuelve un n�mero real entre min y max, repitiendo la entrada 
	// si esto no se da
	// PRE: min <= max

	double LeeRealEnRango(double min, double max){
		double numero;

		do{
			numero = LeeReal();
		}while(numero < min || numero > max);

		return numero;
	}

	/**************************************************************/
	// Devuelve un n�mero real entre min y max o menor o igual que terminador,
	// repitiendo la entrada si ninguna de estas condicioens se da
	// PRE: terminador <= min <= max

	double LeeRealEnRangoConTerminador(double min, double max, 
														double terminador){
		double numero;

		// Repite la entrada si numero no pertenece al intervalo
		// (-inf, terminador] U [min, max]

		do{
			numero = LeeReal();
		}while(numero > max || (numero > terminador && numero < min));

		return numero;
	}

	/**************************************************************/
	// M�todos que determinan si un n�mero es real o entero
	/**************************************************************/

	private:

	// Determina si un n�mero es entero o si no

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

	/**************************************************************/

	// Determina si un n�mero es real o si no

	bool EsReal(string cadena){
	
		const string SIGNOS = "+-";
	
		const char PUNTO_DECIMAL = '.';
	
		bool es_real;
	
		// Si cadena est� vac�a no es un n�mero real
		if(cadena.length() == 0)
			es_real = false;
	
		else{
		
			// Si el primer caracter es un signo y hay m�s caracteres se borra
	
			if(SIGNOS.find(cadena.at(0)) != string::npos && cadena.length() > 1)
				cadena.erase(0, 1);
	
			int i = 0;
	
			es_real = true;
	
			bool hay_punto = false;
	
			// Comprobamos todos los caracteres
	
			while(es_real && i < cadena.length()){
	
				// Si no es un d�gito
	
				if(!isdigit(cadena.at(i))){
		
					// Se comprueba que sea un punto y que haya m�s caracteres
	
					if(cadena.at(i) == PUNTO_DECIMAL && cadena.length() > 1){
		
						// Si ya hab�a un punto, hay 2 puntos => no es un real
	
						if(hay_punto) 
							es_real = false;
	
						// Si no hab�a ninguno, lo tenemos en cuenta ahora
	
						else{
							hay_punto = true;
							i++;
						}
	
					}else	// No es un real
						es_real = false;
		
				}else	// Es un d�gito
					i++;
	
			}
	
		}
	
		return es_real;

	}	// EsReal(string cadena)

};	// Clase Lector

/****************************************************************************
	Determina si un n�mero es potencia de dos

  Par�metro: numero
  Devuelve: true si numero es potencia de dos, false si no

****************************************************************************/

bool EsPotencia_2(int numero){	

	double log = log2(numero);

	int truncado = log;

	// Devuelve true si el logatitmo en base dos de numero es entero

	return log == truncado;
}

/****************************************************************************/

class Secuencia{
	
	// Campos de clase

	private:

	int primer_sumando;
	int ultimo_sumando;		// PRE: ultimo_sumando > primer_sumando
	
	// M�todos

	public:

	/******************************************************************/
	// M�todos constructores

	// El constructor por defecto otorga valores imposibles

	Secuencia() :primer_sumando(-1), ultimo_sumando(-1) {}

	// PRE: primer < ultimo

	Secuencia(int primer, int ultimo) :primer_sumando(primer), 
												ultimo_sumando(ultimo) {}

	/******************************************************************/
	// GETTERS y SETTERS

	int GetPrimerSumando(){
		return primer_sumando;
	}

	int GetUltimoSumando(){
		return ultimo_sumando;
	}

	// PRE: primer < ultimo_sumando

	void SetPrimerSumando(int primer){
		primer_sumando = primer;
	}

	// PRE: ultimo > primer_sumando

	void SetUltimoSumando(int ultimo){
		ultimo_sumando = ultimo;
	}

	// PRE: primer < ultimo

	void SetSecuencia(int primer, int ultimo){
		primer_sumando = primer;
		ultimo_sumando = ultimo;
	}

	/******************************************************************/
	// Devuelve la Secuencia en texto, con el siguiente formato:
	// primer_sumando + primer_sumando+1 + ... + ultimo_sumando

	string ToString(){

		string cad;

		for(int i = primer_sumando; i < ultimo_sumando; i++){
			cad += to_string(i) + " + ";
		}

		cad += to_string(ultimo_sumando);

		return cad;

	}

};

/****************************************************************************/

class GestorNumerosSecuenciables{
	
	// Campos de clase

	private:

	int numero;		// PRE: 1 <= numero
	
	// M�todos

	public:

	/******************************************************************/
	// Constructores

	GestorNumerosSecuenciables() :numero(1) {}

	// PRE: 1 <= n

	GestorNumerosSecuenciables(int n) :numero(n) {}

	/******************************************************************/
	// GETTERS / SETTERS

	int GetNumero(){
		return numero;
	}	

	// PRE: 1 <= n

	void SetNumero(int n){
		numero = n;
	}

	/******************************************************************/
	// Devuelve true si numero es secuenciable, false si no

	bool EsSecuenciable(){

		// Los �nicos n�meros con 0 descomoposiciones (los no secuenciables) 
		// son las potencias de 2

		return !EsPotencia_2(numero);
	}

	/******************************************************************/
	// Devuelve el n�mero de secuencias que admite numero

	int NumeroSecuencias(){

		int ultimo_inicio = numero/2;   
		int cont_secuencias = 0; 
				
		for (int inicio = 1; inicio <= ultimo_inicio; inicio++) {
			
			int suma  = inicio;  // suma inicial (primer valor de la sec.)
			int nuevo = inicio+1; 	// segundo valor de la sec. 
	
			// Mientras que la suma de la secuencia sea menor que "valor", 
			// seguir a�adiendo t�rminos consecutivos. 
			 
			while (suma < numero) {
				suma += nuevo; // Nueva suma 
				nuevo++; // El nuevo t�rmino a considerar es el siguiente 
			}
			
			// Si "suma" es igual a "n" hemos encontrado una secuencia. 
			// Si no, la suma es necesariamente mayor.  
			if (suma == numero) cont_secuencias++;
		}
		
		return cont_secuencias;

	}

	/******************************************************************/
	// Devuelve la n-�sima secuencia del n�mero definida por un par de enteros 
	// (a, b) de forma que numero = a + a+1 + ... + b
	// Si dicha secuencia no existe, se devuelve (-1, -1)

	Secuencia CalculaSecuencia(int n){

		int ultimo_inicio = numero / 2;
		int cont_secuencias = 0;

		bool continuar = true;

		int inicio = 1;

		Secuencia secuencia;

		while(inicio <= ultimo_inicio && continuar){
			int suma  = inicio;  // suma inicial (primer valor de la sec.)
			int nuevo = inicio+1; 	// segundo valor de la sec. 
	
			// Mientras que la suma de la secuencia sea menor que "valor", 
			// seguir a�adiendo t�rminos consecutivos. 
			 
			while (suma < numero) {
				suma += nuevo; // Nueva suma 
				nuevo++; // El nuevo t�rmino a considerar es el siguiente 
			}
			
			// Si "suma" es igual a "n" hemos encontrado una secuencia. 

			if (suma == numero){
				cont_secuencias++;

				// Si no es el n�mero de secuencia especificada, sigue buscando

				continuar = cont_secuencias != n;

				// Si es la secuencia n-�sima, se guarda

				if(!continuar)
					secuencia.SetSecuencia(inicio, nuevo-1);
			}

			// Comienza a sumar por el siguiente entero

			inicio++;
		}

		return secuencia; 
	}

};

/****************************************************************************/

int main(){
	
	int num_inicial, num_final;
	int num_secuencias;

	// ENTRADAS

	// Lee el primer n�mero

	Lector leer("Numero inicial: ");

	num_inicial = leer.LeeEntero();

	cout << endl;

	// Lee el segundo n�mero

	leer.SetTitulo("Numero final (mayor que " + to_string(num_inicial) + "): ");
	
	num_final = leer.LeeEnteroMayorOIgual(num_inicial + 1);

	cout << endl;

	// Lee el n�mero de secuencias

	leer.SetTitulo("Numero de secuencias: ");

	num_secuencias = leer.LeeEntero();

	cout << endl;

	// C�LCULOS Y SALIDAS  ------------------------------------------------

	cout << "------------------------------------------------------" << endl;

	cout << "Numeros secuenciables con " << num_secuencias << " secuencias:" 
		 << endl;

	GestorNumerosSecuenciables gestor;

	int contador = 0;

	// Recorre el intervlo entero [num_inicial, num_final]

	for(int i = num_inicial; i <= num_final; i++){

		// Obtiene las secuencias de i

		gestor.SetNumero(i);

		int secuencias = gestor.NumeroSecuencias();

		// Si i tiene num_secuencias secuencias

		if(secuencias == num_secuencias){
	
			contador++;

			// SALIDA

			cout << endl;

			cout << i << " ( " << secuencias << " secuencias)" << endl;

			// Por cada secuencia de i

			for(int j = 1; j <= secuencias; j++){

				cout << "\t" << i << " = " 
					 << gestor.CalculaSecuencia(j).ToString() << endl;

			}

		}

	}

	cout << endl;

	cout << "Hay " << contador << " numeros con " << num_secuencias 
		 << " secuencias" << endl;

	cout << endl;

	return 0;
}
