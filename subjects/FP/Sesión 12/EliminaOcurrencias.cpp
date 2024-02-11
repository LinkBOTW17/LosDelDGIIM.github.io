#include <iostream>

using namespace std;

/***************************************************************************/

class SecuenciaCaracteres {

private:

    static const int TAMANIO = 50; // N�m.casillas disponibles
    char vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // N�m.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaCaracteres (void) : total_utilizados (0)
    {}
    
	/***********************************************************************/
    // Constructor con argumento string.
    // "Copia" el contenido del string en la secuencia 

    SecuenciaCaracteres (string cad) 
    {
    	int num_caracteres;
    	
    	int long_cad = cad.length();
    	
		if (long_cad > TAMANIO) num_caracteres = TAMANIO;
		else num_caracteres = long_cad;
		
		for (int pos=0; pos<num_caracteres; pos++) 
			vector_privado[pos] = cad.at(pos);
			
		total_utilizados = num_caracteres;	
	}
	
    /***********************************************************************/
    // Constructor con char e int.
    // Rellena la secuencia con "n" caracteres "c".

	SecuenciaCaracteres (char c, int n)
	{
		int num_caracteres;

		if (n > TAMANIO) num_caracteres = TAMANIO;
		else num_caracteres = n;
			
		for (int pos=0; pos<num_caracteres; pos++) 
			vector_privado[pos] = c;		

		total_utilizados = num_caracteres;		
	}

    /***********************************************************************/
    // Devuelve el n�mero de casillas ocupadas

    int TotalUtilizados (void)
    {
        return (total_utilizados);
    }

    /***********************************************************************/
    // Devuelve el n�mero de casillas disponibles

    int Capacidad (void)
    {
        return (TAMANIO);
    }

    /***********************************************************************/
    // A�ade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adici�n se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void Aniade (char nuevo)
    {
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }

    /***********************************************************************/
    // Devuelve el elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados

    char Elemento (int indice)
    {
        return (vector_privado[indice]);
    }

    /***********************************************************************/
    // Eliminar el car�cter de la posici�n dada por "indice".
    // Realiza un borrado f�sico (desplazamiento y sustituci�n).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice)
    {
        if ((indice >= 0) && (indice < total_utilizados)) {

            int tope = total_utilizados-1; // posic. del �ltimo

            for (int i = indice ; i < tope ; i++)
                vector_privado[i] = vector_privado[i+1];

            total_utilizados--;
        }
    }
 
    /***********************************************************************/
    // Compone un string con todos los caracteres que est�n
    // almacenados en la secuencia y lo devuelve.

    string ToString()
    {
        string cadena;

        for (int i=0; i<total_utilizados; i++)
            cadena = cadena + vector_privado[i];

        return (cadena);
    }
 
	/***********************************************************************/
	// Elimina todas las apariciones del caracter car en la secuencia

	void EliminaOcurrencias(char car){
		
		int buscar_ocurrencia = -1;		// Para que comience el bucle en 0

		int almacenar;	// Guarda la posici�n donde va almaenando los valores
	
		bool encuentra_ocurrencia = false;

		int casillas = total_utilizados;

		// Busca la primera ocurrencia

		while(buscar_ocurrencia < total_utilizados && !encuentra_ocurrencia){

			buscar_ocurrencia++;

			encuentra_ocurrencia = vector_privado[buscar_ocurrencia] == car;

		}

		// Disminuye el n�mero de casillas utilizadas e inicializa almacenar

		if(encuentra_ocurrencia){
			total_utilizados--;
			almacenar = buscar_ocurrencia;
		}

		// Recorre todas las casillas del array hasta la �ltima casilla

		while(buscar_ocurrencia < casillas){

			buscar_ocurrencia++;

			// Si no es el caracter buscado, va moviendo los caracteres

			if(vector_privado[buscar_ocurrencia] != car){

				vector_privado[almacenar] = vector_privado[buscar_ocurrencia];

				almacenar++;

			// Si no, elimina otra casilla

			}else{

				total_utilizados--;

			}

		}
	
	}

};	// Clase SecuenciaCaracateres

/***************************************************************************
	Imprime mensaje en consola y lee la entrada del usuario.
	Mientras que la entrada no sea un caracter repite la entrada.

  Par�metro: mensaje
  Devuelve: un caracter

***************************************************************************/

char LeeCaracter(string mensaje){
	string lectura;

	// Es un caracter si es un string de longitud 1

	do{

		cout << mensaje;
		cin >> lectura;

	}while(lectura.length() != 1);

	return lectura.at(0);
}

/***************************************************************************/

int main(){
	
	string cad;
	char car;

	// ENTRADAS

	cout << "Introduzca la cadena: " << endl;
	getline(cin, cad);

	cout << endl;
	car = LeeCaracter("Introduzca el caracter que desea eliminar: ");
	
	// C�LCULOS - Elimina las ocurrencias de car en cad

	SecuenciaCaracteres secuencia(cad);

	secuencia.EliminaOcurrencias(car);

	// SALIDAS

	cout << endl;

	cout << "Su cadena: " << endl;
	cout << secuencia.ToString();

	cout << endl;
	
	return 0;
}
