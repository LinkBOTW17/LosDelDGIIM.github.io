#include <iostream>

using namespace std;

/***********************************************************/
//	Constantes que definen la longitud de un DNI, de un NIE y las letras
//  iniciales que puede contener el NIE

const int LONGITUD_DNI = 9, LONGITUD_NIE = 9;

const int DIGITOS_DNI = 8, DIGITOS_NIE = 7;

const int LETRA_NIE_1 = 'X', LETRA_NIE_2 = 'Y', LETRA_NIE_3 = 'Z';

/***********************************************************/

/****************************************************************************
	Funci�n que comprueba si un caracter es un d�gito.

  Par�metros: caracter
  Devuelve: true si caracter es un d�gito, false si no

****************************************************************************/

bool EsDigito(char caracter){
	const int ASCII_0 = '0', ASCII_9 = '9';

	// Devuelve si el c�digo ascii de caracter se encuentra entre los c�digos
	// ascii del 0 y del 9 (en resumen, si caracter es un d�gito)

	return caracter >= ASCII_0 && caracter <= ASCII_9;
}

/****************************************************************************
	Funci�n que comprueba si un caracter es un caracter alfab�tico.

  Par�metros: carracter
  Devuelve: true si caracter es un caracter alfab�tico, false si no

	*Nota: En este caso, no consideramos a la � como un dato alfab�tico

****************************************************************************/

bool EsAlfabetico(char caracter){
	const int ASCII_A = 'A', ASCII_Z = 'Z';

	// Pasamos caracter a mayuscula para facilitar la comprobaci�n

	caracter = toupper(caracter);

	// Devuelve si el c�digo ascii de caracter en may�scula se encuentra entre 
	// los c�digos ascii de A y de Z (es decir, si era un caracter alfab�tico)

	return caracter >= ASCII_A && caracter <= ASCII_Z;
}

/****************************************************************************
	Funci�n que determina si la cadena indicada ten�a numero n�mero de
	d�gitos a partir de la posici�n inicio.

  Par�metros: cadena, inicio, numero
  Devuele: true si cadena contiene numero d�gitos desde la posici�n inicio
  PRE: 0 <= inicio < cadena.length()
	   numero es un dato natural

****************************************************************************/

bool ContarDigitos(string cadena, int inicio, int numero){
	// Supone que los d�gitos son correctos
	bool digitos_correctos = true;

	// Recorre la cadena desde inicio, hasta procesar numero caracteres
	// si alguno no era un n�mero, digitos_correctos pasa a valer false
	// y se detiene la ejecuci�n del bucle

	int i = inicio;

	while(digitos_correctos && i < numero){
		if(!EsDigito(cadena.at(i)))
			digitos_correctos = false;

		i++;
	}	

	return digitos_correctos;
}

/****************************************************************************
	Funci�n que determina si el formato de un DNI es correcto o no
  
	Comprueba que el DNI sea del formato:
		NNNNNNNNC

	Donde N representa a cualquier d�gito y C a cualquier caracter alfab�tico

  Par�metros: dni
  Devuelve: true si el DNI ten�a formato correcto, false si no

	*Nota: Necesita valor de constantes globales LONGITUD_DNI y DIGITOS_DNI

****************************************************************************/

bool DNIFormatoCorrecto(string dni){

	bool digitos_correctos;
	bool letra_final;
	bool formato_correcto;

	// Si la longitud del DNI es la adecuada, comprueba que tenga un 
	// formato correcto

	if(dni.length() == LONGITUD_DNI){

		// Comprueba si el �ltimo caracter es alfab�tico

		letra_final = EsAlfabetico(dni.at(LONGITUD_DNI - 1));

		// Comprueba que todos los CANTIDAD_NUMEROS primeros caracteres
		// sean d�gitos 

		digitos_correctos = ContarDigitos(dni, 0, DIGITOS_DNI);

		// Si se verifican las dos condiciones, es un formato de DNI v�lido

		formato_correcto = letra_final && digitos_correctos;

	}else		// Si no, directamente no es un formato de DNI
		formato_correcto = false;

	return formato_correcto;
}

/****************************************************************************
	Funci�n que determina si el formato de un NIE es v�lido o no
  
	Comprueba que el NIE sea del formato:
		CNNNNNNNC

	Donde N representa a cualquier d�gito y C a cualqueir caracter alfab�tico

  Par�metros: nie
  Devuelve: true si el NIE ten�a formato correcto, false si no

	*Nota: necesita valor de constantes globales LONGITUD_NIE y DIGITOS_NIE

****************************************************************************/

bool NIEFormatoCorrecto(string nie){

	bool digitos_correctos;
	bool letra_inicial;
	bool letra_final;
	bool formato_correcto;

	// Comprueba que la longitud del NIE sea v�lida

	if(nie.length() == LONGITUD_NIE){

		// Comprueba que tenga CANTIDAD_NUMEROS n�mero de d�gitos a partir
		// de la posici�n 1

		digitos_correctos = ContarDigitos(nie, 1, DIGITOS_NIE);

		// Comprueba que el primer caracter del NIE sea alfab�tico

		letra_inicial = EsAlfabetico(nie.at(0));

		// Comprueba que el �ltio caracter del NIE sea alfab�tico

		letra_final = EsAlfabetico(nie.at(LONGITUD_NIE - 1));

		// Si se dan las tres, el formato es v�lido

		formato_correcto = digitos_correctos && letra_inicial && letra_final;

	}else	// Si no, ten�a un formato equivocado
		formato_correcto = false;

	return formato_correcto;
}

/****************************************************************************
	Funci�n que devuelve la letra correspondiente a un DNI

	Para ello, se calcula el m�dulo del n�mero del DNI entre DIVISOR y 
	dependiendo del valor se asigna una letra u otra.

  Par�metros: dni (n�mero del DNI)
  Devuelve: El caracter que le corresonde al DNI

****************************************************************************/

char ObtenerLetraDNI(long dni){

	const int DIVISOR = 23;

	// Contiene todas las letras que se pueden asignar a un DNI, ordenadas
	// seg�n los posibles valores de resto (del 0 al 22)

	const string LETRAS = "TRWAGMYFPDXBNJZSQVHLCKE";

	// Se calcula el resto y se devuelve el caracter correspondiente

	int resto = dni % DIVISOR;

	return LETRAS.at(resto);
}

/****************************************************************************
	Funci�n que determina si la letra de un DNI es correcta o no
  
	Para ello, se extrae el n�mero del DNI y se comprueba que la letra
	especificada coincida con la letra que debe tener el n�mero del DNI

  Par�metros: dni
  Devuelve: true si la letra del DNI era v�lida, false si no
  PRE: dni debe tener un formato v�lido, debe filtrarse por la funci�n
	DNIFormatoCorrecto(dni)

	*Nota: Necesita valor de constante global DIGITOS_DNI

****************************************************************************/

bool DNILetraCorrecta(string dni){

	// Nos quedamos con el n�mero del DNI y con la letra

	long numero_DNI = stol(dni.substr(0, DIGITOS_DNI));

	char letra = toupper(dni.at(dni.length() - 1));

	// Devolvemos el resultado de comparar la letra del DNI que introdujo
	// el usuario y la letra que deber�a tener ese n�mero de DNI

	return letra == ObtenerLetraDNI(numero_DNI);
}

/****************************************************************************
	Funci�n que determina si la primera letra de un NIE es correcta o no.
	Para ser correcta, debe ser igual a X, Y o Z.

  Par�metros: nie
  Devuelve: true si la primera letra es correcta, false si no
  PRE: nie no puede estar vac�o

	*Nota: necesita los valores de las constantes globales LETRA_NIE_1,
	LETRA_NIE_2 y LETRA_NIE_3

****************************************************************************/

bool PrimeraLetraCorrectaNIE(string nie){
	char primera_letra = toupper(nie.at(0));

	return primera_letra == LETRA_NIE_1 || primera_letra == LETRA_NIE_2 
							|| primera_letra == LETRA_NIE_3;
}

/****************************************************************************
	Funci�n que determina si las letras de un NIE son correctas o no
  
	Para ello, el primer caracter debe ser X, Y o Z

	Posteniormente se calcula la letra final, que se obtiene de la misma
	forma que la del DNI. La letra inicial se sustituye por un n�mero
	para obtener un n�mero similar al DNI:
		X --> 0
		Y --> 1
		Z --> 2

  Par�metros: nie
  Devuelve: true si el NIE era v�lido, false si no
  PRE: nie debe tener un formato correcto, debe filtrarse mediante la funci�n
	NIEFormatoCorrecto(nie)

	*Nota: Necesita los valores de las constantes globales DIGITOS_NIE 
		   y LETRA_NIE_1

****************************************************************************/

bool NIELetrasCorrectas(string nie){

	bool letras_correctas;

	// Nos quedamos con la �ltima y la primera letra

	char letra_inicial = toupper(nie.at(0));

	char letra_final = toupper(nie.at(nie.length() - 1));

	// Comprobamos si la letra inicial era v�lida:

	bool letra_inicial_valida = PrimeraLetraCorrectaNIE(nie);

	// Si la primera letra no era v�lida, las letras no son correctas

	if (!letra_inicial_valida)
		letras_correctas = false;

	else{		// letra_inicial es la contemplada

		// Restamos el c�digo ascii de letra_inicial menos el c�digo ascii
		// de la primera letra v�lida del NIE, obteniendo el primer n�emro
		// del NIE

		int primer_numero = letra_inicial - LETRA_NIE_1;

		// Se obtiene el n�mero del NIE, una vez sustituida la letra inicial
		// por el d�gito corresondiente
		
		long numero_nie = 
				stol(to_string(primer_numero) + nie.substr(1, DIGITOS_NIE));

		// Se comprueba si la letra final es la correcta

		letras_correctas = letra_final == ObtenerLetraDNI(numero_nie);

	}

	return letras_correctas;
}

/***************************************************************************
	Funci�n que comprueba si un DNI es v�lido o no

  Par�metros: dni
  Devuelve: true si el DNI es v�lido (si tiene un formato adecuado y la letra 
	adecuada al n�mero), false si no

****************************************************************************/

bool DNIValido(string dni){
	bool dni_valido;

	// Filtramos que el formato sea v�lido antes de comprobar la letra

	if(DNIFormatoCorrecto(dni)){
	
		if(DNILetraCorrecta(dni))
			dni_valido = true;

		else
			dni_valido = false;

	}else
		dni_valido = false;

	return dni_valido;
}

/****************************************************************************
	Funci�n que comprueba si un NIE es v�lido o no

  Par�metros: nie
  Devuelve: true si el NIE es v�lido (si tiene un formato adecuado, si
	las letras iniciales son las contempladas y si la letra final se 
	corresponde con el n�mero y la letra inicial), false si no

****************************************************************************/

bool NIEValido(string nie){
	bool nie_valido;

	// Filtramos que el formato sea v�lido antes de comprobar las letras

	if(NIEFormatoCorrecto(nie)){

		if(NIELetrasCorrectas(nie))
			nie_valido = true;

		else
			nie_valido = false;

	}else
		nie_valido = false;

	return nie_valido;
}

/****************************************************************************
	Funci�n que pasa una cadena entera a may�sculas

  Par�metros: cadena
  Devuele: la cadena en may�sculas

****************************************************************************/

string CadenaAMayuscula(string cadena){
	string cadena_en_mayusculas;	

	// Recorre cadena en todos los caracteres, pas�ndolos a may�scula
	// y concaten�ndolos en cadena_en_mayusculas

	for(int i = 0; i < cadena.length(); i++)
		cadena_en_mayusculas += toupper(cadena.at(i));

	return cadena_en_mayusculas;
}

/****************************************************************************
	Funci�n que imprime mensaje en consola, lee una cadena de caracteres
	y la devuelve toda en may�sculas

  Par�metros: mensaje
  Devuele: La lectura en may�sculas

****************************************************************************/

string LeerEnMayuscula (string mensaje){
	string lectura;

	cout << mensaje;
	getline(cin, lectura);

	return CadenaAMayuscula(lectura);
}

/****************************************************************************/

int main(){
	
	const string TERMINADOR = "FIN";

	// Lectura y comprobaci�n de DNIs

	string entrada_dni;

	cout << "Introduzca los DNIs a comprobar (FIN para terminar): " << endl;
	entrada_dni = LeerEnMayuscula("DNI: ");

	// Mientras que no se introduzca TERINADOR

	while(entrada_dni != TERMINADOR){
	
		// Comprueba si el DNI es v�lido

		if(DNIValido(entrada_dni))
			cout << "DNI valido." << endl;
	
		else
			cout << "DNI invalido." << endl;

		cout << endl;

		// Lee el siguiente DNI

		entrada_dni = LeerEnMayuscula("DNI: ");
	}
	
	cout << endl << endl;

	// Lectura y comprobaci�n de NIEs

	string entrada_nie;

	cout << "----------------------------------------------------" << endl;
	cout << "Introduzca los NIEs a comprobar (FIN para terminar): " << endl;
	entrada_nie = LeerEnMayuscula("NIE: ");

	// Mientras que no se introuduzca TERMINADOR

	while(entrada_nie != TERMINADOR){

		// Comprueba que el NIE sea v�lido

		if(NIEValido(entrada_nie))
			cout << "NIE valido." << endl;
	
		else
			cout << "NIE invalido." << endl;

		cout << endl;

		// Lee el siguiente NIE

		entrada_nie = LeerEnMayuscula("NIE: ");
	}

	return 0;
}
