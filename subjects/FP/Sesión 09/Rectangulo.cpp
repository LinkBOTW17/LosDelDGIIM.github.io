#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Constantes

const double PI = 6 * asin(0.5);

/****************************************************************************/
// Definiciones de structs

// Punto en un plano

struct Punto2D{
	double abscisa;
	double ordenada;
};

// Circunferencia

struct Circunferencia{
	Punto2D centro;
	double radio;
};

// Rect�ngulo

struct Rectangulo{
	Punto2D punto_si;	// V�rtice superior izquierdo
	Punto2D punto_id;	// V�rtice inferior derecho
};

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
	Calcula el centro del rect�ngulo (donde se cortan las dos diagonales).

  Par�metros: rect, el rect�ngulo
  Devuelve: El centro del rect�ngulo

****************************************************************************/

Punto2D CentroRectangulo(Rectangulo rect){

	Punto2D centro;

	// El centro del rect�ngulo es igual que el punto medio de la recta
	// que une el punto superior izquierda con el punto inferior derecha

	centro.abscisa = (rect.punto_si.abscisa + rect.punto_id.abscisa) / 2;

	centro.ordenada = (rect.punto_si.ordenada + rect.punto_id.ordenada) / 2;

	return centro;
}

/****************************************************************************
	Dada una circunferencia, calcula su �rea.

  Par�metros: circf, la circunferencia.
  Devuelve: El �rea de la circunferencia.

****************************************************************************/

double Area(Circunferencia circf){
	return PI * circf.radio * circf.radio;		// Area = pi * r^2
}

/****************************************************************************
	Dado un rect�ngulo, calcula su �rea.

  Par�metros: rect, el rect�ngulo
  Devuelve: El �rea del rect�ngulo

****************************************************************************/

double Area(Rectangulo rect){

	// Calculamos los lados del rect�ngulo

	double lado_vert = abs(rect.punto_si.ordenada - rect.punto_id.ordenada);

	double lado_horiz = abs(rect.punto_si.abscisa - rect.punto_id.abscisa);

	return lado_horiz * lado_vert;		// Area = base * altura
}

/****************************************************************************
	Dado un rect�ngulo, devuelve la circunferencia centrada en el punto de
	corte de las diagonales del rect�ngulo cuya superficie es la menor
	que todas las superficies de �rea mayor que el rect�ngulo

  Par�metros: rect, el rect�ngulo en el que centramos la circunferencia
  Devuelve: La circunferencia

****************************************************************************/

Circunferencia CircunferenciaCentrada(Rectangulo rect){

	// Valores especificados en el enunciado
	const double RADIO_INICIAL = 0.5;
	const double INCREMENTO = 0.25;

	Circunferencia circf;

	// La circunferencia est� centrada en el rect�ngulo
	circf.centro = CentroRectangulo(rect);

	circf.radio = RADIO_INICIAL;

	// Si el �rea de la circunferencia es menor o igual que la del rect�ngulo, 
	// incrementamos su radio en INCREMENTO

	while(Area(circf) <= Area(rect))
		circf.radio += INCREMENTO;

	return circf;
}

/****************************************************************************
	Imprime un mensaje en consola y solicita la ordenada y la abscisa de
	un punto, devolviendo el punto introducido.

  Par�metros: titulo, el mensaje que se imprime al usuario
  Devuelve: El punto que el usuario introdujo

****************************************************************************/

Punto2D LeePunto(string titulo){

	string abscisa, ordenada;

	cout << titulo << endl;

	// Solicita la abscisa

	do{

		cout << "\tLa abscisa: ";
		cin >> abscisa;

	}while(!EsReal(abscisa));

	// Solicita la ordenada

	do{

		cout << "\tLa ordenada: ";
		cin >> ordenada;

	}while(!EsReal(ordenada));

	// Crea el objeto punto a partir de la abscisa y de la ordenada

	Punto2D punto;

	punto.abscisa = stod(abscisa);
	punto.ordenada = stod(ordenada);

	return punto;
}

/****************************************************************************/

int main(){
	
	Punto2D punto1, punto2;

	// ENTRADAS

	punto1 = LeePunto("El vertice superior izquierdo del rectangulo: ");

	cout << endl;

	punto2 = LeePunto("El vertice inferior derecho: ");

	// C�LCULOS

	Rectangulo rect = {punto1, punto2};

	Circunferencia circf = CircunferenciaCentrada(rect);

	// SALIDAS

	cout.setf(ios::fixed);

	cout << endl;

	cout << "La circunferencia sera: " << endl;
	cout << "\tLa de centro el punto: (" << setw(4) << setprecision(2) 
		 << circf.centro.abscisa << ", " << circf.centro.ordenada << ")" << endl;
	cout << "\tY que tenga " << setw(4) << setprecision(2) << circf.radio 
		 << " de radio." << endl;

	cout << endl;

	return 0;
}
