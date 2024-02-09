#include <iostream>

using namespace std;

// Los tipos de ajustes contemplados

enum class TipoAjuste {izquierda, centro, derecha};

/****************************************************************************
	Funci�n que genera una cadena en la que hay veces veces el caracter
	caracter.

  Par�metros: veces (el n�mero que se repite el caracter)
			  caracter (el caracter a repetir)
  Devuelve: una cadena que contiene caracter veces veces
  PRE: veces >= 0

****************************************************************************/

string GenerarCaracteres (int veces, char caracter){
	string devuelta;	

	// Concatena caracter a devuelta veces n�mero de veces
	for(int i = 0; i < veces; i++)
		devuelta += caracter;

	return devuelta;
}

/****************************************************************************
	Funci�n que centra la cadena cadena mediante caracteres relleno:

	Los caracteres relleno se a�adir�n seg�n el tipo de ajuste seleccionado:
		Si se selecciona izquierda, los caracteres relleno se colocan a la 
			derecha para dejar cad alineado a la izquierda.
		Si se selecciona derecha, los caracteres relleno se colocan a la 
			izquierda para dejar cad alineado a la derecha.
		Si se selecciona centro, los caracteres relleno se dividen entre la
			izquierda y la derecha de cad, aline�ndolo al centro.

  Par�metros: cadena, numero_caracteres, ajuste, relleno
  Devuele: Una nueva cadena que contiene la cadena anterior centrada en el
	sitio indicado, con la ayuda de tantos caracteres como se especificaron
	del tipo especificado
  PRE: numero_caracteres >= 0

****************************************************************************/

string Centrar(string cadena, int numero_caracteres, TipoAjuste ajuste
												   , char relleno){

	string cadena_centrada;

	// Realiza un ajuste u otro dependiendo del tipo de ajuste

	switch(ajuste){
		case TipoAjuste::izquierda:
			
			// A�ade los caracteres relleno a la derecha

			cadena_centrada = cadena 
							+ GenerarCaracteres(numero_caracteres, relleno);
			
			break;

		case TipoAjuste::derecha:
			
			// A�ade los carcteres relleno a la izquierda

			cadena_centrada = GenerarCaracteres(numero_caracteres, relleno) 
							+ cadena;

			break;

		case TipoAjuste::centro:
	
			// Reparte el n�mero de caracteres entre delante y detr�s

			int caracteres_delante = numero_caracteres / 2;

			int caracteres_detras = numero_caracteres - caracteres_delante;

			// A�ade los caracteres relleno correspondientes a ambos lados

			cadena_centrada = GenerarCaracteres(caracteres_delante, relleno) 
					+ cadena + GenerarCaracteres(caracteres_detras, relleno);

			break;
	}

	return cadena_centrada;
}

/****************************************************************************
	Funci�n que transforma el contenido de cad a un nuevo string seg�n el
	formato indicado en los par�metros:

	La nueva cadena tendr� una longitud m�nima de num_casillas casillas:
		Si cad ten�a ya ese n�mero de casillas, no se modifica.
		Si la longitud de cad era menor a ese n�memro, se a�aden caracteres
			relleno hasta llegar a la longitud deseada.

	Se centrar� seg�n el criterio especificado en la funci�n
	Centrar(cadena, numero_caracteres, ajuste, relleno)

  Par�metros: cad, num_casillas, ajuste, relleno
  Devuelve: La cadena formateada seg�n los par�metros.
  PRE: num_casillas >= 0

****************************************************************************/

string FormateaString (string cad, int num_casillas, TipoAjuste ajuste, 
													char relleno = ' '){

	string devuelta;

	// Si cad ya ten�a la longitud m�nima, no se modifica
	if(num_casillas <= cad.length())
		devuelta = cad;

	else{		// Si no, se modifica: 
	
		// Se calcula el n�mero de caracteres de relleno que son necesarios
		// incluir para llegar a la longitud deseada

		int caracteres_necesarios = num_casillas - cad.length();

		// Se centra la cadena

		devuelta = Centrar(cad, caracteres_necesarios, ajuste, relleno);

	}

	return devuelta;
}

/****************************************************************************/

int main(){
	
	string cadena;
	int casillas;
	TipoAjuste ajuste;
	char relleno;

	// ENTRADAS

	// Cadena

	cout << "Cadena a formatear: ";
	getline(cin, cadena);

	// N�mero m�nimo de casillas

	bool casillas_validas;

	do{

		cout << "Numero minimo de casillas: ";
		cin >> casillas;

		casillas_validas = casillas >= 0;

	}while(!casillas_validas);

	// Ajuste

	bool entrada_valida;

	char caracter;

	do{
	
		cout << "Tipo de ajuste (i -> izquierda, c -> centro, d -> derecha): ";
		cin >> caracter;

		entrada_valida = caracter == 'i' || caracter == 'c' || caracter == 'd';

	}while(!entrada_valida);

	// Se asigna el tipo enumerado en funci�n del caracter introducido

	switch(caracter){
		case 'i':
			ajuste = TipoAjuste::izquierda;
			break;

		case 'c':
			ajuste = TipoAjuste::centro;
			break;

		case 'd':
			ajuste = TipoAjuste::derecha;
			break;
	}

	// Caracter relleno

	cout << "Caracter para rellenar: ";
	cin >> relleno;

	// SALIDAS

	cout << endl;

	cout << FormateaString(cadena, casillas, ajuste, relleno);

	cout << endl;

	return 0;
}
