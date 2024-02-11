#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Constantes globales

const double PI = 6 * asin(0.5);

const double RADIO_MINIMO = 0.5, INCREMENTO = 0.25;

// Definici�n de structs

struct Punto2D{
	double x;
	double y;
};

/****************************************************************************/

class Rectangulo{
	private:
	
	Punto2D vert_s_i;	// V�rtice superior izquierdo
	Punto2D vert_i_d;	// V�rtice inferior derecho

	// Longitudes de una base y de una altura

	double long_base;
	double long_altura;

	public:
	
	/****************************************************************/
	// M�todo constructor

	Rectangulo() :long_base(0), long_altura(0) {

		Punto2D punto;

		punto.x = 0;
		punto.y = 0;

		vert_s_i = punto;
		vert_i_d = punto;

	}

	Rectangulo(Punto2D punto1, Punto2D punto2) :vert_s_i(punto1),
											    vert_i_d(punto2) {
	
		// Calcula las longitudes de una base y de una altura

		long_base = abs(vert_s_i.x - vert_i_d.x);
		long_altura = abs(vert_s_i.y - vert_i_d.y);
	}

	/****************************************************************/
	// Devuelve el punto de corte de las dos diagoanales del rect�ngulo

	Punto2D ObtenerCentro(){
		Punto2D centro;

		// Calcula el centro del rect�ngulo, con las medias entre las 
		// coordenadas de dos v�rtices opuestos

		centro.x = (vert_s_i.x + vert_i_d.x) / 2;
		centro.y = (vert_s_i.y + vert_i_d.y) / 2;

		return centro;
	}

	/****************************************************************/
	// Devuelve el �rea del rect�ngulo

	double ObtenerArea(){
		return long_base * long_altura;		// base * altura
	}

	/****************************************************************/
	// Devuelve el m�ximo radio posible que puede tener una circunferencia 
	// inscrita en este rect�ngulo
	
	double RadioMaximoCircunferenciaInscrita(){
	
		// Devuelve la mitad del lado menor del rect�ngulo

		double minimo = (long_altura < long_base)? long_altura : long_base;

		return minimo / 2;

	}

};

/****************************************************************************/

class Circunferencia{
	private:
	
	Punto2D centro;
	double radio;

	public:
	
	/****************************************************************/
	// M�todos constructores

	Circunferencia(double r) :radio(r) {

		Punto2D c;

		c.x = 0;
		c.y = 0;

		centro = c;
	}

	Circunferencia(Punto2D punto, double r) :centro(punto), radio(r) {}

	/****************************************************************/
	// Devuelve el �rea de la circunferencia

	double ObtenerArea(){
		return PI * radio * radio;	// Devuelve pi * r^2
	}

	/****************************************************************/
	// Aumenta el radio de la circunferencia

	void AumentarRadio(double aumento){
		radio += aumento;
	}

	/****************************************************************/
	// Devuelve los datos de la circunferencia en formato texto

	string ToString(){
		return "Circunferencia de centro (" + to_string(centro.x) + ", " 
				+ to_string(centro.y) + ") y radio " + to_string(radio);
	}

	/****************************************************************/
	// Devuelve si la circunferencia tiene un radio v�lido para inscribirse 
	// en el rect�ngulo especificado

	bool PuedeInscribirse(Rectangulo rect){

		double radio_maximo = rect.RadioMaximoCircunferenciaInscrita();

		return radio <= radio_maximo;

	}

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

	punto.x = stod(abscisa);
	punto.y = stod(ordenada);

	return punto;
}

/****************************************************************************
	Cuenta el n�mero de circunferencias que se pueden inscribir en un 
	rect�ngulo

  Par�metros: rect
  Devuelve: El n�mero de circunferencias que se pueden inscribir en rect

****************************************************************************/

int ContarCircunferenciasInscritas(Rectangulo rect){

	int contador = 0;

	// Coge el radio de la circunferencia inicial

	Circunferencia circf(RADIO_MINIMO);

	// Mientras que el radio sea v�lido, se cuenta

	while(circf.PuedeInscribirse(rect)){

		contador++;
		circf.AumentarRadio(INCREMENTO);

	}

	return contador;
}

/****************************************************************************/

int main(){
	
	const int LONG_ARRAY = 100;

	Punto2D punto1, punto2;

	// ENTRADAS

	cout << "Parametros del rectangulo:" << endl;

	cout << endl;

	punto1 = LeePunto("El vertice superior izquierdo del rectangulo: ");

	cout << endl;

	punto2 = LeePunto("El vertice inferior derecho del rectangulo: ");

	// C�LCULOS

	// Creamos nuestro rect�ngulo

	Rectangulo rect(punto1, punto2);

	int numero_circfs = ContarCircunferenciasInscritas(rect);

	// SALIDAS

	cout << endl;

	if(numero_circfs == 0){

		cout << "No puede inscribirse ninguna circunferencia." << endl;

	}else{

		cout << "Pueden inscribirse " << numero_circfs << " circunferencias:" 
		 << endl;

		cout << endl;
	
		// Inicializa la primera circunferencia
	
		Circunferencia circf(rect.ObtenerCentro(), RADIO_MINIMO);
	
		for(int i = 0; i < numero_circfs; i++){
	
			cout << circf.ToString() << endl;
	
			circf.AumentarRadio(INCREMENTO);
	
		}

	}

	cout << endl;

	return 0;
}
