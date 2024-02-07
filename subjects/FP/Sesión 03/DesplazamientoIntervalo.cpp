#include <iostream>

using namespace std;

int main()
{
	// Declaraciones
	int minimo, maximo, a_desplazar, desplazamiento;

	// Entradas
	cout << endl;
	cout << "Introduzca el valor minimo del intervalo cerrado (dato entero): ";
	cin >> minimo;

	cout << "Introduzca el valor maximo del intervalo abierto (dato entero): ";
	cin >> maximo;

	cout << "Introduzca el numero de posiciones que ha de desplazarse el "
		<< "numero entero (dato entero entre 0 y " << (maximo-minimo) << "): ";
	cin >> desplazamiento;

	cout << "Introduzca el valor del numero entero que se desplazara " <<
		desplazamiento << " posiciones (dato entero entre " << minimo << " y " << maximo << "): ";
	cin >> a_desplazar;

	// C�lculos
	// Suma la posici�n del entero m�s las unidades a desplazarlo
    
	int desplazado = a_desplazar + desplazamiento;

	// Si el resultado se sale del intervalo (desplazdo > maximo), el programa
	// calcula por cuanto se ha pasado del m�ximo y se lo suma al m�nimo.
	// Esta cuenta se vuelve a almacenar en la variable desplazado.
	// Si no se pas�, la variable no se altera.
    
	desplazado = (desplazado > maximo)? (minimo-1 + (desplazado - maximo)) : desplazado;

	// Salida
	cout << endl;
	cout << "El entero " << a_desplazar << " desplazado " << desplazamiento
		<< " unidades a lo largo del intervalo [" << minimo << ", " << maximo << "] es: " << desplazado << endl;
	cout << endl;

	return 0;
}
