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

	// C�LCULOS --------------------

	// auxiliar contiene los dig�tos del n�mero truncado.
	int auxiliar = numero * pow(10, digitos);

	// Desplazamos la coma hasta la posici�n correcta, obteniendo
	// el n�mero numero truncado a digitos decimales.
	double numero_truncado = ((double)auxiliar) / pow(10, digitos);

	// Cuenta el n�mero de d�gitos en la parte entera:
	// (trunca numero a las unidades y cuenta el n�mero de caracteres)
	int parte_entera = to_string((int)numero).length();

	// SALIDA ----------------------

	// Formateamos la consola para mostrar n�meros decimales.
	cout.setf(ios::fixed);

	// Mostramos la salida, reservando un ancho para la parte entera,
	// los d�gitos decimales y el punto decimal.
	cout << endl;
	cout << "Su numero truncado: " << setw(parte_entera + 1 + digitos) 
		 << setprecision(digitos) << numero_truncado << endl;
	cout << endl;

	return 0;
}
