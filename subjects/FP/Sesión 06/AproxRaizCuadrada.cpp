#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	
	const double MIN = 0, MAX = 16;
	const double SALTO = 0.5;

	double numero;

	bool error_numero = false;

	// ENTRADA  *******************************************************

	do{
		// Muestra al usuario por qu� su entrada no es v�lida
		if(error_numero)
			cout << endl << "El numero debe ser un real positivo." << endl;

		cout << "Raiz cuadrada de: ";
		cin >> numero;

		error_numero = numero < 0;

	}while(error_numero);

	// C�LCULOS Y SALIDAS **********************************************

	// Para no repetir c�digo, dentro del bucle de la tabla que imprimimos al
	// final incluimos el c�lculo de la ra�z de numero por los tres m�todos,
	// de forma que la primera vuelta del bucle est� dedicada al c�lculo
	// de su ra�z y el resto del bucle est� dedicado a crear la tabla.

	// El bucle tiene tantas vueltas como debe tener para crear la tabla
	// mas una al inicio

	for(double i = MIN - SALTO; i <= MAX; i += SALTO){

		double x;		// Real al que se le hace la ra�z cuadrada

		// Si es la primera vuelta del bucle, le hacemos la ra�z a numero
		if(i == MIN - SALTO)
			x = numero;

		// Si no, calculamos la ra�z del correspondiente n�mero de la tabla
		else
			x = i;

		// Metodo 1:  ---------------------------------------------------

		// 1.- Buscamos el n�mero entero al cuadrado que m�s se aproxime a x:

		int cuadrado_superior = 1;
	
		// Buscamos el cuadrado superior
		while(cuadrado_superior * cuadrado_superior <= x){
			cuadrado_superior++;
		}
	
		// Calculamos el cuadrado inferior 
		int cuadrado_inferior = cuadrado_superior - 1;
	
		// Calculamos la distancia de cada uno a x
		double distancia_inferior = x - cuadrado_inferior * cuadrado_inferior;
	
		double distancia_superior = cuadrado_superior * cuadrado_superior - x;

		// El entero al cuadrado m�s proximo es aquel cuyo cuadrado guarda 
		// menor distancia con x
		int proximo = (distancia_inferior < distancia_superior)?
						cuadrado_inferior : cuadrado_superior;
	
		// 2.- Calculamos la raiz de x, aplicando la f�rmula del enunciado
		// (La f�rmula del v�deo)
	
		double raiz1;
	
		// proximo es el denominador
		if(proximo != 0)
			raiz1 = proximo + abs(x - proximo * proximo) / (2 * proximo);

		// Le damos un valor por defecto a aquellos n�meros a los que no se les 
		// puede aplicar el m�todo
		else	
			raiz1 = 0;	

		// Metodo 2:  -----------------------------------------------------

		// 1.- Buscamos los cuadrados exactos m�s cercanos, que ya obtuvimos
		// en el m�todo 1:
		// sqrt(cuadrado_inferior^2) <= sqrt(x) <= sqrt(cuadrado_superior^2)

		// Usamos nuevas variables para simplificar los c�lculos:

		int a = cuadrado_inferior;
		int b = cuadrado_superior;

		// 2.- Existe una relaci�n entre la distancia de a^2 y b^2 y entre
		// la distancia de a y b (calculamos las distancias):

		int distancia_a_b_2 = (b * b) - (a * a);

		int distancia_a_b = b - a;

		// Esta misma relaci�n es la que guarda la distancia de a^2 y x 
		// entre la distancia de a y la ra�z de x

		double distancia_a_2_x = x - (a * a);

		// Por una regla de tres, obtenemos que:
		// distancia_raiz_x_a = distancia_a_2_x * distancia_a_b 
		//								/ distancia_a_b_2 
		// Luego:
		// sqrt(x)-a = distancia_a_2_x * distancia_a_b / distancia_a_b_2
		// Despejando:

		double raiz2 = (distancia_a_2_x * distancia_a_b / distancia_a_b_2) + a;

		// Metodo 3:

		double raiz3 = sqrt(x);

		// SALIDAS   ------------------------------------------------------

		// Si es la primera vuelta del bucle, imprimimos los resultados de la 
		// raiz de numero:
		if(i == MIN - SALTO){

			// Formateo de la consola
	
			cout.setf(ios::fixed);
			cout.setf(ios::showpoint);
		
			cout << setw(5) << setprecision(3);
		
			cout << endl << "La raiz cuadrada de " << numero << " es:" << endl;
			cout << "\tMetodo 1: " << raiz1 << endl;
			cout << "\tMetodo 2: " << raiz2 << endl;
			cout << "\tMetodo 3: " << raiz3 << endl;

			// Despu�s de la primera vuelta del bulce se procesar� e imprimir�
			// La tabla, por lo que ya podemos mostrar su cabecera:

			cout << endl << endl;
		
			cout << "Raices desde " << MIN << " hasta " << MAX 
				 << " con saltos de " << SALTO << "." << endl;
		
			cout << endl;
		
			cout << "                |	Metodo 1 |	Metodo 2     |	Metodo 3 |" 
				 << endl;
			cout << "      Numero    |	Formula  |	Triangulos   |	sqrt(x)  |" 
				 << endl;
		
			cout << endl;
	
		}

		else{
	
			// SALIDAS TABLA

			cout << "	" << setprecision(1) << x << "		" 
				 << setprecision(3) << raiz1 << "		" << raiz2 << "		" 
				 << raiz3 << endl;
	
			cout << endl;

		}

	}

	// A partir de la tabla, podemos observar que el segundo m�todo es m�s 
	// exacto que el primero

	return 0;
}
