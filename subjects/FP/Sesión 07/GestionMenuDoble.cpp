#include <iostream>

using namespace std;

int main(){
	
	// Para saber el men� que hay que mostrar o si hay que salir del programa

	enum class Menu {Principal, Adicion, Producto, Salir};

	Menu estado = Menu::Principal;

	// Variables con las que se realizan los c�lculos

	int numero1, numero2, salida;

	// Variables para la selecci�n en cada men�

	char entrada;
	bool entrada_invalida;

	// true si hay que mostrar una salida de un resultado, false si no

	bool mostrar_salida;

	// Mientras que el usuario no seleccione Salir en el men� principal

	while(estado != Menu::Salir){

		switch(estado){

			// Si debemos mostrar el men� principal	

			case Menu::Principal:

				// Muestra el men� principal y lee la entrada, filtr�ndola

				do{

					cout << "----------------------" << endl;
					cout << "A->Calcular adici�n." << endl;
					cout << "P->Calcular producto." << endl;
					cout << "X->Salir." << endl;
					cout << endl;
					cout << "> ";
				
					cin >> entrada;

					cout << endl;

					entrada = tolower(entrada);

					entrada_invalida = entrada != 'a' && entrada != 'p' 
										&& entrada != 'x';

				}while(entrada_invalida);

				// Dependiendo de la entrada, asigna a estado un valor
				// u otro

				if(entrada == 'a')
					estado = Menu::Adicion;

				else if(entrada == 'p')
					estado = Menu::Producto;

				else
					estado = Menu::Salir;

				// No es necesario imprimir ning�n c�lculo

				mostrar_salida = false;

				break;		// De case Menu::Principal:

			// Si debemos mostrar el men� de adici�n

			case Menu::Adicion:
	
				// Muestra el men� de adici�n y lee la entrada, filtr�ndola

				do{

					cout << "-------------------" << endl;
					cout << "S->Calcular suma." << endl;
					cout << "R->Calcular resta." << endl;
					cout << "X->Salir." << endl;
					cout << endl;
					cout << "> ";
				
					cin >> entrada;

					cout << endl;

					entrada = tolower(entrada);

					entrada_invalida = entrada != 's' && entrada != 'r' 
										&& entrada != 'x';

				}while(entrada_invalida);

				// Si hay que volver al men� principal, se cambia estado
				// (No hay que mostrar resultados del c�lculos)

				if(entrada == 'x'){
					estado = Menu::Principal;
					mostrar_salida = false;
				}

				// Si no, el programa solicita dos n�meros enteros

				else {

					cout << "Introduce el primer entero: ";
					cin >> numero1;

					cout << "Introduce el segundo entero: ";
					cin >> numero2;

					// Dependiendo de la selecci�n los suma o resta

					if(entrada == 's')
						salida = numero1 + numero2;

					else
						salida = numero1 - numero2;

					// Hay que mostrar el resultado al final

					mostrar_salida = true;
				}

				break;		// De case Menu::Adicion:

			// Si hay que mostrar el men� del producto

			case Menu::Producto:

				// Muestra el men� y lee la entrada, filtr�ndola

				do{
	
					cout << "---------------------------" << endl;
					cout << "M->Calcular multiplicacion." << endl;
					cout << "D->Calcular division entera." << endl;
					cout << "R->Calcular resto." << endl;
					cout << "X->Salir." << endl;
					cout << endl;
					cout << "> ";

					cin >> entrada;

					cout << endl;

					entrada = tolower(entrada);
		
					entrada_invalida = entrada != 'm' && entrada != 'd' 
									&& entrada != 'r' && entrada != 'x';

				}while(entrada_invalida);

				// Si se selecciona salir, se cambia estado
				// (no hay que mostrar ning�n resultado de c�lculo)

				if(entrada == 'x'){
					estado = Menu::Principal;
					mostrar_salida = false;
				}

				// Si no, se solicitan dos n�meros

				else{

					cout << "Introduce el primer entero: ";
					cin >> numero1;

					// true si hay que realizar una divisi�n

					bool division = entrada == 'd' || entrada == 'r';

					// Si hay que hacer una divisi�n y el divisor es 0,
					// se vuelve a solicitar

					do{

						cout << "Introduce el segundo entero: ";
						cin >> numero2;

					}while(division && numero2 == 0);

					// salida_negativa == true si un numero es positivo
					// y otro negativo

					bool salida_negativa = (numero1 < 0 && numero2 >= 0) 
						|| (numero2 < 0 && numero1 >=0);

					// Calculamos el opuesto de los n�meros 
					// en el caso de ser negativos (su valor absoluto)

					if(numero1 < 0)
						numero1 = -numero1;

					if(numero2 < 0)
						numero2 = -numero2;

					// Si hay que multiplicarlos

					if(entrada == 'm'){

						// Realizamos una sumatoria de numero1 numero2 veces

						// Para reducir peso computacional, gracias a la 
						// conmutatividad del producto, podemos hacer
						// que el m�nimo n�mero sea el que defina
						// las vueltas del for

						// numero2 ser� el m�nimo de ambos:

						if(numero1 < numero2){
							int auxiliar = numero1;
							numero1 = numero2;
							numero2 = auxiliar;
						}

						// Se suma numero1 numero2 veces, obteniendo
						// numero1 * numero2

						salida = 0;

						for(int i = 0; i < numero2; i++)
							salida += numero1;

						// Si un n�mero era positivo y otro negativo, el
						// resultado debe ser negativo

						if(salida_negativa)
							salida = -salida;

					// Si hay que dividirlos (de forma entera) o hacer el resto

					}else{

						// Se trabaja con una copia de numero1

						int auxiliar = numero1;

						// Se cuenta el n�mero de veces que hay que 
						// sustraer numero2 a numero1 para que 
						// numero1 sea menor a numero2

						int contador = 0;

						while(auxiliar >= numero2){
							auxiliar -= numero2;
							contador++;
						}

						// Dicha cuenta es el resultado de la divisi�n
						// entera numero1 / numero2

						if(entrada == 'd'){	// Si hab�a que dividirlos

							salida = contador;

						}else{	// if(entrada == 'r') , salida = resto

							// El valor restante en auxiliar es el resto

							salida = auxiliar;

						}

						// Si un n�mero era positivo y otro negativo, el
						// resultado debe ser negativo

						if(salida_negativa)
							salida = -salida;

					}	// Cierre if(entrada != 'm')

					// Se muestra al final la salida de los c�lculos
		
					mostrar_salida = true;

				} // Cierre if(entrada != 'x')

				break;		// De case Menu::Producto:

		}	// Cierre switch(estado)

		// SALIDAS DE C�LCULOS

		if(mostrar_salida){
			cout << endl;
			cout << "El resultado es " << salida << "." << endl;
			cout << endl;
		}

		// Se deja espacio entre cada vez que se vuelve a mostrar un men�

		cout << endl << endl << endl << endl;

	}	// Cierre while(estado != Menu::Salir)
	

	return 0;
}
