#include <iostream>

using namespace std;

/****************************************************************************
	Funci�n que comprueba si un caracter es un d�gito

  Par�metro: caracter
  Devuelve: true si el caracter est� comprendido en el intervalo [0, 9],
	false si no

****************************************************************************/

bool EsDigito(char caracter){

	const int ASCII_0 = '0', ASCII_9 = '9';

	// Comprueba si el c�digo ascii de caracter est� entre los c�digos
	// ascii del 0 y el 9

	return caracter >= ASCII_0 && caracter <= ASCII_9;

}

/****************************************************************************
	Funci�n que comprueba si todos los caracteres de una cadena son d�gitos

  Par�metros: cadena
  Devuelve: true si todos los caracteres de la cadena eran d�gitos, false si no

****************************************************************************/

bool CadenaSoloContieneDigitos(string cadena){
	
	// Suponemos que la cadena s�lo tiene d�gitos
	bool todo_digitos =  true;

	// Recorremos la cadena en busca de un caracter que no sea un d�gito
	// en caso de encontrarlo, se detiene la ejecuci�n del bucle

	int i = 0;

	while(todo_digitos && i < cadena.length()){

		if(!EsDigito(cadena.at(i)))
			todo_digitos = false;

		i++;
	}

	return todo_digitos;
}

/****************************************************************************
	Funci�n que comprueba si un string es un n�mero entero o no

  Par�metros: cadena
  Devuelve: true (si cadena era un entero), false si no

****************************************************************************/

bool EsEntero (string cadena){
	const char MENOS = '-';	

	bool es_entero;

	// Si la cadena est� vac�a, no es un n�mero entero

	if(cadena.length() == 0)
		es_entero = false;

	else{

		// Si es un n�mero negativo, se elimina el signo
		if(cadena.at(0) == MENOS)
			cadena.erase(0, 1);	// Elimina el primer caracter
		
		// Si al quitar el menos hay m�s caracteres
		if(cadena.length() != 0){
		
			// Hasta que no se encuentre un fallo es un entero
			es_entero = CadenaSoloContieneDigitos(cadena);
		
		}else	// Si no, no es un entero (habr�an introducido "-")
			es_entero = false;

	}

	return es_entero;
}

/****************************************************************************
	Funci�n que lee y devuelve un dato entero. Si el valor introducido
	no era un entero, vuelve a repetir la entrada hasta obtener un entero

  Par�metros: titulo (mensaje que muestra al pedir el entero)
  Devuelve: el entero

****************************************************************************/

int LeeEntero (string titulo){

	string entrada;	

	bool es_entero;

	// Repite la entrada mientras que no introduzcan un entero

	do{
		// Solicita el entero
		cout << titulo;
		getline(cin, entrada);
	
		// Se comprueba que sea un n�mero entero
		es_entero = EsEntero(entrada);

	}while(!es_entero);

	return stoi(entrada);	
}

/****************************************************************************
	Funci�n que lee y devuelve un dato entero dentro del rango establecido.
	Si el valor introducido no fuera un entero o estuviese fuera
	del rango establecido, se volver�a a repetir la entrada.

  Par�metros: titulo (mensaje a mostrar), 
			  menor, mayor (definen el rango de valores v�lidos)
  Devuelve: el entero dentro del intervalo [menor, mayor]
  PRE: menor <= mayor

****************************************************************************/

int LeeEnteroEnRango (string titulo, int menor, int mayor){
	
	string entrada;
	int entero;

	bool no_valido;

	// Se repite mientras que no sea un valor v�lido

	do{
		// Lee un dato entero
		entero = LeeEntero(titulo);

		// Es inv�lido si el dato no est� en el intervalo [menor, mayor]
		no_valido = entero < menor || entero > mayor;

	}while(no_valido);

	return entero;
}

/****************************************************************************
	Funci�n que lee y devuelve un dato entero mayor o igual que referencia.
	Si el valor introducido no fuera un entero o fuera menor que referencia, 
	se volver�a a repetir la entrada.

  Par�metros: titulo (mensaje a mostrar), referencia
  Devuelve: el entero mayor o igual que referencia

****************************************************************************/

int LeeEnteroMayorOIgual (string titulo, int referencia){
	
	string entrada;
	int entero;

	bool no_valido;

	// Se repite mientras que no sea un valor v�lido

	do{
		// Lee un dato entero
		entero = LeeEntero(titulo);

		// No es v�lido si es menor que referencia
		no_valido = entero < referencia;

	}while(no_valido);

	return entero;
}

/****************************************************************************/

int main(){
	
	const int MENOR = 0, MAYOR = 50, REFERENCIA = 10;

	const string MSG_ENTERO = "Introduzca un entero: ";

	const string MSG_RANGO = "Introduzca un entero entre " + to_string(MENOR) 
							+ " y " + to_string(MAYOR) + " : ";

	const string MSG_MAYOR_IGUAL = "Introduzca un entero mayor o igual que "
							+ to_string(REFERENCIA) + " : ";

	// ENTRADAS

	int entero = LeeEntero(MSG_ENTERO);

	cout << endl;

	int rango = LeeEnteroEnRango(MSG_RANGO, MENOR, MAYOR);

	cout << endl;

	int mayor_igual = LeeEnteroMayorOIgual(MSG_MAYOR_IGUAL, REFERENCIA);

	// SALIDAS

	cout << endl << endl;

	cout << "Un entero: " << entero << endl;

	cout << "Un entero entre " << MENOR << " y " << MAYOR << ": " 
		 << rango << endl;

	cout << "Un entero mayor o igual que " << REFERENCIA << ": " 
		 << mayor_igual << endl;	

	cout << endl;

	return 0;
}
