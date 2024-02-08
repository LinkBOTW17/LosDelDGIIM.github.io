#include <iostream>
#include <cmath>	//Para poder usar pow()

using namespace std;

int main(){
	
	int decimal;
	int n; 			//N�mero de bits

	bool error_n = false;
	bool error_decimal = false;

	// ENTRADAS CON FILTROS **************************************************

	do{
		// Si hubo un error, lo imprime
		if(error_n)
			cout << endl << "Error: el numero de bits debe de ser mayor que 0."
				 << endl;
			
		// Solicita el n�mero de bits
		cout << "Numero de bits: ";
		cin >> n;

		// Comprueba si es un n�mero v�lido de cifras binarias
		error_n = n <= 0;

	}while(error_n);

	// N�mero decimal m�ximo que se puede reprsentar con n bits
	int maximo = pow(2, n) - 1;

	do{
		// Si hubo un error, lo imprime
		if(error_decimal)
			cout << endl << "Error: el dato debe estar en el intervalo [0," 
				 << maximo << "]." << endl;

		// Solicita el n�mero decimal
		cout << "Numero entero positivo entre [0," << maximo << "]: ";
		cin >> decimal;

		// Comprueba si es v�lido o no
		error_decimal = decimal < 0 || decimal > maximo;

	}while(error_decimal);

	// C�LCULOS  **********************************************************

	// C�lculo del n�mero binario

	string n_binario;	// decimal en binario

	int auxiliar = decimal; // Trabajamos con una copia de decimal
	
	while(auxiliar != 0) {
		// Comparar �ltimo bit con 1  
		
		if (auxiliar & 1) 
			n_binario = "1" + n_binario;  	// Es 1
		else 
			n_binario = "0" + n_binario;	// Es 0
		
		auxiliar >>= 1; // Desplazar a la derecha el auxiliar
	}

	// Ajustar los bits para representar n bits

	if(n_binario.length() != n){		// Si el n�mero de bits no es igual

		// Se calcula cuantos ceros le faltan al n�mero binario delante
		int diferencia = n - n_binario.length();

		// Generamos un string de tantos ceros como bits le falten al
		// n�mero binario para llegar a n bits

		string str_ceros;

		for(int i = 0; i < diferencia; i++){

			str_ceros += '0';

		}

		// Cancatenamos a ese n�mero de ceros el string con el n�mero binario
		// obteniendo finalmente el valor deseado

		n_binario = str_ceros + n_binario;
	}

	// SALIDA  *************************************************************
	
	cout << endl;
	cout << decimal << " en binario con " << n << " bits es " << n_binario << "." << endl;
	cout << endl;

	return 0;
}
