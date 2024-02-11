#include <iostream>
#include <iomanip>

using namespace std;

/****************************************************************************/
// Definici�n de structs

struct InfoIPC{
	int indice_pais;			// 0 <= indice_pais <= NUM_PAISES
	double valor_medio_IPC;		// Valor del IPC medio
	int anio_inicio;			// Primer a�o del periodo
	int num_anios;				// N�mero de a�os del periodo
};

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

/****************************************************************************/

class GestorIPC{
	
	// Constantes est�ticas

	public:

	static const int PRIMER_ANIO = 2001;
	static const int ULTIMO_ANIO = 2021;
	static const int NUM_ANIOS = ULTIMO_ANIO - PRIMER_ANIO + 1;
	static const int NUM_PAISES = 4;

	static const string PAISES[NUM_PAISES];				// Nombre de los pa�ses
	static const double IPC[NUM_PAISES][NUM_ANIOS];		// Registro de IPCS
	
	// M�todos

	public:
	
	/****************************************/
	// No es necesaria la creaci�n de un m�todo constructor al no disponer
	// de campos de clase

	/****************************************/
	// Devuelve el primer a�o del que se tienen registros

	int PrimerAnio(){
		return PRIMER_ANIO;
	}

	/****************************************/
	// Devuelve el �ltimo a�o del que se tienen registros

	int UltimoAnio(){
		return ULTIMO_ANIO;
	}

	/****************************************/
	// Devuelve el n�mero de a�os de los que se tienen registros

	int NumAnios(){
		return NUM_ANIOS;
	}
	
	/****************************************/
	// Devuelve el numero de pa�ses de los que se tienen registros

	int NumPaises(){
		return NUM_PAISES;
	}

	/****************************************/
	// Devuelve el nombre de un pa�s
	// PRE: 0 <= pais <= NUM_PAISES

	string NombrePais(int pais){
		return PAISES[pais];
	}

	/****************************************/
	// Devuelve el valor del IPC de un pa�s en el a�o especificado
	// PRE: 0 <= pais <= NUM_PAISES
	//      PRIMER_ANIO <= anio <= ULTIMO_ANIO

	double ValorIPC(int anio, int pais){
		return IPC[pais][anio - PRIMER_ANIO];
	}

	/****************************************/
	// Calcula el IPC medio de un pa�s entre los a�os:
	// [primer_anio, primer_anio + anios - 1]
	// 
	// PRE: 0 <= pais <= NUM_PAISES
	//      PRIMER_ANIO <= primer_anio <= ULTIMO_ANIO
	//		primer_anio + anios <= ULTIMO_ANIO

	double IPC_Medio_PaisPeriodo(int pais, int primer_anio, int anios){

		double sumatoria = 0;

		// Recorre anios a�os, comenzando por primer_anio

		for(int anio = primer_anio; anio < primer_anio + anios; anio++){

			sumatoria += ValorIPC(anio, pais);

		}		

		// Devuelve la media del IPC del pa�s pais entre los a�os primer_anio
		// y primer_anio + anios - 1

		return sumatoria / anios;
	}

	/****************************************/
	// Devuelve un objeto struct con la informaci�n de cual es el pa�s con
	// el menor IPC medio en num_anios a�os

	// PRE: 0 <= num_anios <= NUM_ANIOS

	InfoIPC Info_IPC_MinMedio_Periodo(int num_anios){
		
		// Se inicializa en valor imposible para que se cambie
		// Se establece el n�mero de a�os entre el que se calcula

		InfoIPC MenorIPCMedio;

		/* = (0, 9999, 0, num_anios)*/

		MenorIPCMedio.anio_inicio = 0;
		MenorIPCMedio.indice_pais = 0;
		MenorIPCMedio.valor_medio_IPC = 9999;
		MenorIPCMedio.num_anios = num_anios;

		// a�os entre los que se calcula el ipc medio

		int primer_anio = PRIMER_ANIO;

		int ultimo_anio = primer_anio + num_anios - 1;

		// Mientras que se puedan seguir considerando a�os

		while(ultimo_anio <= ULTIMO_ANIO){

			// Se repite por cada pa�s

			for(int pais = 0; pais < NUM_PAISES; pais++){

				// Calcula el IPC medio

				double IPC_medio = IPC_Medio_PaisPeriodo(pais, primer_anio, 
																	num_anios);

				// Si es menor que el menor, se establece como nuevo menor

				if(IPC_medio < MenorIPCMedio.valor_medio_IPC){

					MenorIPCMedio.anio_inicio = primer_anio;
					MenorIPCMedio.indice_pais = pais;
					MenorIPCMedio.valor_medio_IPC = IPC_medio;

				}

			}

			// Busca en el siguiente intervalo de a�os

			primer_anio++;
			ultimo_anio = primer_anio + num_anios - 1;

		}

		return MenorIPCMedio;
	}

	/****************************************/
	// Devuelve un objeto struct con la informaci�n de cual es el pa�s con
	// el mayor IPC medio en num_anios a�os

	// PRE: 0 <= num_anios <= NUM_ANIOS
	
	InfoIPC Info_IPC_MaxMedio_Periodo(int num_anios){
		
		// Se inicializa en valor imposible para que se cambie
		// Se establece el n�mero de a�os entre el que se calcula

		InfoIPC MayorIPCMedio;

		/* = (0, -9999, 0, num_anios)*/

		MayorIPCMedio.anio_inicio = 0;
		MayorIPCMedio.indice_pais = 0;
		MayorIPCMedio.valor_medio_IPC = -9999;
		MayorIPCMedio.num_anios = num_anios;

		// a�os entre los que se calcula el ipc medio

		int primer_anio = PRIMER_ANIO;

		int ultimo_anio = primer_anio + num_anios - 1;

		// Mientras que se puedan seguir considerando a�os

		while(ultimo_anio <= ULTIMO_ANIO){

			// Se repite por cada pa�s

			for(int pais = 0; pais < NUM_PAISES; pais++){

				// Calcula el IPC medio

				double IPC_medio = IPC_Medio_PaisPeriodo(pais, primer_anio, 
																	num_anios);

				// Si es mayor que el mayor, se establece como nuevo mayor

				if(IPC_medio > MayorIPCMedio.valor_medio_IPC){

					MayorIPCMedio.anio_inicio = primer_anio;
					MayorIPCMedio.indice_pais = pais;
					MayorIPCMedio.valor_medio_IPC = IPC_medio;

				}

			}

			// Busca en el siguiente intervalo de a�os

			primer_anio++;
			ultimo_anio = primer_anio + num_anios - 1;

		}

		return MayorIPCMedio;
	}


};	// clase GestorIPC

const string GestorIPC::PAISES[NUM_PAISES] = {"Espania", "Reino Unido", 
										"Estados Unidos", "Zona Euro"};	

const double GestorIPC::IPC[NUM_PAISES][NUM_ANIOS] = 
				{{2.7, 4, 2.6, 3.2, 3.7, 2.7, 4.2, 1.4, 0.8, 3, 2.4, 2.9, 0.3, 
				-1, 0, 1.6, 1.1, 1.2, 0.8, -0.5, 6.5}, 

				{1.07, 1.69, 1.25, 1.64, 1.92, 2.97, 2.12, 3.11, 2.83, 3.73, 
				4.2, 2.71, 2, 0.55, 0.23, 1.6, 2.9, 2.1, 1.3, 0.6, 5.4}, 

				{1.6, 2.4, 1.9, 3.3, 3.4, 2.5, 4.1, 0.1, 2.7, 1.5, 3, 1.7, 1.5, 
				0.8, 0.7, 2.1, 2.1, 1.9, 2.3, 1.4, 7}, 
			
				{2.1, 2.3, 2, 2.4, 2.2, 1.9, 3.1, 1.6, 0.9, 2.2, 2.8, 2.2, 0.8, 
				-0.2, 0.2, 1.1, 1.3, 1.5, 1.3, -0.3, 5}};

/****************************************************************************/

int main(){
	
	const int MIN_NUM_ANIOS = 2;
	const int MAX_NUM_ANIOS = 5;
	const int TERMINADOR_MAXIMO = -1;

	const string MSG_INTERVALO_N = "(entre " + to_string(MIN_NUM_ANIOS) 
								+ " y " + to_string(MAX_NUM_ANIOS) + ")";

	int num_anios;

	// ENTRADAS

	cout << "Introduzca un numero de anios negativo para finalizar." << endl;

	Lector leer("Numero de anios " + MSG_INTERVALO_N + ": ");

	cout << "------------------------------------" << endl;

	// Lee un n�mero menor o igual que TERMIANDOR_MAXIMO o en el intervalo
	// [MIN_NUM_ANIOS, MAX_NUM_ANIOS]

	num_anios = leer.LeeEnteroEnRangoConTerminador(MIN_NUM_ANIOS, 
										MAX_NUM_ANIOS, TERMINADOR_MAXIMO);

	// C�LCULOS Y SALIDAS

	GestorIPC gestor;

	InfoIPC MayorIPCMedio, MenorIPCMedio;

	// Formatea la consola

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);

	cout << setw(4) << setprecision(2);

	// Mientras que no se introduzca un terminador

	while(num_anios > TERMINADOR_MAXIMO){

		// C�LCULOS

		MayorIPCMedio = gestor.Info_IPC_MaxMedio_Periodo(num_anios);

		MenorIPCMedio = gestor.Info_IPC_MinMedio_Periodo(num_anios);

		// SALIDAS

		// Imprime el pa�s con mayor IPC

		cout << endl;

		cout << "El pais con mayor IPC medio es " << endl;
		cout << "\t" << gestor.NombrePais(MayorIPCMedio.indice_pais) << endl;
		cout << "\tCon un IPC medio del " << MayorIPCMedio.valor_medio_IPC 
			 << "%" << endl;
		cout << "\tEntre " << MayorIPCMedio.anio_inicio << " y " 
			 << (MayorIPCMedio.anio_inicio + MayorIPCMedio.num_anios - 1) 
			 << endl;
		cout << endl;

		// Imprime el pa�s con menor IPC
		
		cout << "El pais con menor IPC medio es " << endl;
		cout << "\t" << gestor.NombrePais(MenorIPCMedio.indice_pais) << endl;
		cout << "\tCon un IPC medio del " << MenorIPCMedio.valor_medio_IPC 
			 << "%" << endl;
		cout << "\tEntre " << MenorIPCMedio.anio_inicio << " y " 
			 << (MenorIPCMedio.anio_inicio + MenorIPCMedio.num_anios - 1) 
			 << endl;
		cout << endl;

		cout << endl;

		// Solicita el siguiente n�mero de a�os

		cout << "------------------------------------" << endl;

		num_anios = leer.LeeEnteroEnRangoConTerminador(MIN_NUM_ANIOS, 
										MAX_NUM_ANIOS, TERMINADOR_MAXIMO);
	}

	return 0;
}
