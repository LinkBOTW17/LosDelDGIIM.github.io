#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double numero;
	int digitos;

	// ENTRADAS
	
	cout << "Introduce un numero: ";
	cin >> numero;

	cout << "Cifras decimales: ";
	cin >> digitos;

	// Comprueba que digitos sea un n�mero natural o 0
	bool digitos_correctos = digitos >= 0;

	if(!digitos_correctos){
		cout << endl;
		cout << "Error: El numero de digitos a redondear debe ser un numero "
			 << "natural." << endl;
		cout << endl;
	}

	// C�LCULOS --------------------

	int parte_entera;
	double numero_truncado;

	// Realiza los c�lculos s�lo si digitos es un n�mero natural:

	if(digitos_correctos){
		// auxiliar contiene los dig�tos del n�mero truncado.
		int auxiliar = numero * pow(10, digitos);
	
		// Desplazamos la coma hasta la posici�n correcta, obteniendo
		// el n�mero numero truncado a digitos decimales.
		numero_truncado = auxiliar / pow(10, digitos);
	
		// Cuenta el n�mero de d�gitos en la parte entera:
		// (trunca numero a las unidades y cuenta el n�mero de caracteres)
		parte_entera = to_string((int)numero).length();
	}

	// SALIDA ----------------------

	if(digitos_correctos){
	
		// Formateamos la consola para mostrar n�meros decimales.
		cout.setf(ios::fixed);

		cout << endl;
		cout << "Su numero truncado: " << setw(parte_entera + 1 + digitos) 
			 << setprecision(digitos) << numero_truncado << endl;	
		cout << endl;
	}

	return 0;
}
