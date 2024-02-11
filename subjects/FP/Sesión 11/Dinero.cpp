#include <iostream>

using namespace std;

class Dinero{

	/*****************************************************************/
	// Campos de clase	

	private:
	
	int euros;		// PRE: euros >= 0
	int centimos;	// PRE: centimos >= 0

	public:
	
	/*****************************************************************/
	// M�todos constructores

	Dinero() :euros(0), centimos(0) {}

	// PRE: e >= 0, c >= 0
	Dinero(int e, int c){
		Asignar(e, c);
	}

	/*****************************************************************/
	// Devuelve la informaci�n de los campos en un texto

	string ToString(){
		return to_string(euros) + " euros y " + to_string(centimos) 
				+ " centimos ";
	}

	/*****************************************************************/
	// Incrementa el saldo seg�n porc

	// PRE: porc >= 0

	void Incrementar(double porc){
	
		// Pasa el saldo a c�ntimos

		double dinero = euros * 100 + centimos;

		// Aplica el porcentaje redondeando los c�ntimos

		int dinero_final = (dinero + dinero * porc / 100) + 0.5;

		// Vuelve a ajustar el saldo en los campos de clase

		Asignar(0, dinero_final);

	}

	/*****************************************************************/

	private: 

	/*****************************************************************/
	// Asigna los euros y los c�ntimos especificados a los campos de clase
	// con un formato v�lido (100 cents = 1 e)

	// PRE: e >= 0, c >= 0

	void Asignar(int e, int c){
	
		// Calcula los euros que hay en los centimos
		int euros_en_c = c / 100;

		// Estos centimos ya no cuenta como c�ntimos
		c -= euros_en_c * 100;

		// Se asignan los euros y los c�ntimos

		euros = e + euros_en_c;

		centimos = c;
	}

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

	do{

		cout << mensaje;
		cin >> numero;

	}while(!EsEntero(numero));

	return stoi(numero);
}

/****************************************************************************
	Imprime un mensaje en consola y lee el n�mero entero que introduce el 
	usuario. Repite la entrada mientras que el valor introducido no sea
	un n�mero entero o mientras que este no sea mayor o igual que la referencia

  Par�metros: titulo, el mensaje que se muestra al usuario
			  referencia, valor m�nimo que acepta la funci�n
  Devuelve: el n�mero entero que introduce el usuario

****************************************************************************/

int LeerEnteroMayorOIgual(string mensaje, int referencia){

	int numero;

	do{

		numero = LeerEntero(mensaje);

	}while(numero < referencia);

	return numero;
}

/****************************************************************************
	Determina si cadena es un n�mero real o si no.

  Par�metros: cadena
  Devuelve: true si cadena es un n�mero real, false si no

****************************************************************************/

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
}

/****************************************************************************
	Imprime un mensaje en consola y lee un n�mero real. Mientras que el n�mero 
	introducido por el usuario no sea real, repite la lectura.

  Pr�metros: mensaje
  Devuelve: Un n�mero double introducido por el usuario

****************************************************************************/

double LeerReal(string mensaje){
	string numero;

	do{
		cout << mensaje;
		cin >> numero;
	}while(!EsReal(numero));

	return stod(numero);
}

/****************************************************************************
	Imprime un mensaje en consola y lee un n�mero real. Mientras que el n�mero 
	introducido por el usuario no sea real o mientras que el real no sea mayor 
	o igual que la refenrencia, repite la lectura.

  Pr�metros: mensaje, referencia
  Devuelve: Un n�mero double introducido por el usuario

****************************************************************************/

double LeerRealMayorOIgual(string mensaje, double referencia){
	double numero;

	do{
	
		numero = LeerReal(mensaje);

	}while(numero < referencia);

	return numero;
}

/****************************************************************************/

int main(){
	
	const int MIN_VALOR_DINERO = 0, MIN_VALOR_PORC = 0, MIN_VALOR_MES = 0;
	int euros, centimos;

	double incremento;

	int meses;

	// ENTRADAS

	// Solicita el saldo de la cuenta

	cout << "Saldo: " << endl;

	euros = LeerEnteroMayorOIgual("\tEuros: ", MIN_VALOR_DINERO);
	centimos = LeerEnteroMayorOIgual("\tCentimos: ", MIN_VALOR_DINERO);

	Dinero monedero(euros, centimos);

	cout << endl;

	// Solicita el porcentaje del incremento y el n�mero de meses

	incremento = LeerRealMayorOIgual("Incremento mensual: ", MIN_VALOR_PORC);

	meses = LeerEnteroMayorOIgual("Numero de meses: ", MIN_VALOR_MES);

	// C�LCULOS Y SALIDAS

	cout << endl;

	// Por cada mes incrementa el salario y lo imprime en consola

	for(int i = 1; i <= meses; i++){

		monedero.Incrementar(incremento);

		cout << "Mes " << i << ": " << monedero.ToString() << endl;

	}
	
	return 0;
}
