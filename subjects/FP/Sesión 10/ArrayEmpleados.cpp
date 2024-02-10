#include <iostream>
#include <iomanip>

using namespace std;

// Constantes globales y tipo enumerado

const char SEPARADOR_FECHAS = '/', SEPARADOR_DATOS = '|';

enum class TipoOrdenacion {salario, apellidos, fecha};

/****************************************************************************
	Devuelve la posici�n en la que se encuentra el primer caracter 
	especificado en la cadena especificada

  Par�metros: cadena, (donde se busca el caracter)
			  caracter (el caracter a buscar)

  Devuelve: la posici�n en la que se encuentra caracter dentro de cadena
  PRE: Dentro de cadena hay al menos un caracter igual a caracter

****************************************************************************/

int PosicionCaracter(string cadena, char caracter){

	int i = 0;

	while(i < cadena.length() && cadena.at(i) != caracter)
		i++;
	
	return i;
}

/****************************************************************************
	Elimina los espacios iniciales y finales de una cadena

  Par�metros: cadena
  Devuelve: La cadena tras eliminarle los espacios iniciales y finales

****************************************************************************/

string EliminaEspacios(string cadena){

	const char ESPACIO = ' ';

	int pos = 0;

	// Busca el primer caracter distinto de ESPACIO

	while(pos < cadena.length() && cadena.at(pos) == ESPACIO)
		pos++;
	
	// Se queda con la subcadena que hay a partir de ese caracter

	string cadena_mod = cadena.substr(pos);

	// Busca el primer caracter distinto de ESPACIO empezando por detr�s

	pos = cadena.length() - 1;

	while(pos > 0 && cadena.at(pos) == ESPACIO)
		pos--;

	// Se que da con la subcadena que hay hasta ese caracter

	cadena_mod = cadena_mod.substr(0, pos);

	return cadena_mod;
}

/****************************************************************************
	Determina si las cadenas est�n ordenadas alfab�ticamete, siendo la primra
	menor que la segunda en t�rminos de orden.

  Par�metros: cadena1, cadena2
  Devuelve: true si cadena1 < cadena2 si ordenamos las cadenas alfab�ticamente,
			false si no
  PRE: cadena1 y cadena2 no pueden estar vac�as

****************************************************************************/

bool OrdenadasAlfabeticamente(string cadena1, string cadena2){

	bool ordenadas;

	int pos = 0;

	char car1 = toupper(cadena1.at(pos));
	char car2 = toupper(cadena2.at(pos));

	// Mientas que las cadenas sean iguales, se busca el siguiente carcter

	while(car1 == car2 && pos < cadena1.length() && pos < cadena2.length()){
	
		car1 = toupper(cadena1.at(pos));
		car2 = toupper(cadena2.at(pos));

		pos++;
	}

	// Si se ha llegado al �ltimo caracter si �xito

	if(pos == cadena1.length() || pos == cadena2.length()){

		// Si la primera cadena tiene menos caracteres o los mismos

		if(cadena1.length() <= cadena2.length())
			ordenadas = true;

		else
			ordenadas = false;

	}

	// Si la diferencia de su c�digo ascii es negativo, car2 tendr� un c�digo
	// mayor que car1, por lo que estar� m�s cerca de 'Z' que car1

	else
		ordenadas = car1 - car2 <= 0;

	return ordenadas;
}

/****************************************************************************
	Pasa todos los caracteres de una cadena a may�scula

  Par�metro: cadena
  Devuelve: cadena con todos sus caracteres en may�scula

****************************************************************************/

string Mayusculas(string cadena){
	string cadena_mod;

	for(int i = 0; i < cadena.length(); i++){
		cadena_mod += toupper(cadena.at(i));
	}

	return cadena_mod;
}

/****************************************************************************
	Dado un string con las tres primeras letras de un mes, determina el n�mero
	del mes

  Par�metros: mes
  Devuelve: el n�mero del mes
  PRE: mes debe ser uno de los contemplados en el array MESES

****************************************************************************/

int NumeroMes(string mes){
	const int NUM_MESES = 12;

	const string MESES[NUM_MESES] = {"ENE", "FEB", "MAR", "ABR", "MAY", "JUN", 
									"JUL", "AGO", "SEP", "OCT", "NOV", "DIC"};

	mes = Mayusculas(mes);

	int i = 1;

	// Mientras que mes no est� en MESES, aumentamos i

	while(i < NUM_MESES && MESES[i-1] != mes){
		i++;
	}

	return i;
}

/****************************************************************************
	Determina si las dos fechas est�n ordenadas cronol�gicamente

  Par�metros: fecha1, fecha2
  Devuelve: true si fecha1 sucede antes que fecha2
  PRE: fecha1 y fecha2 deben tener el formato:

	dd/mmm/aaaa

	Con _ = SEPARADOR_FECHAS
	Y mmm las tres primeras letras del mes

****************************************************************************/

bool OrdenadasCronologicamente(string fecha1, string fecha2){

	// Obtenemos el d�a

	int pos_dia = PosicionCaracter(fecha1, SEPARADOR_FECHAS);

	int dia1 = stoi(fecha1.substr(0, pos_dia));
	int dia2 = stoi(fecha2.substr());

	// Acortamos fecha1 y fecha2

	fecha1 = fecha1.substr(pos_dia + 1);
	fecha2 = fecha2.substr(pos_dia + 1);

	// Obtenemos el mes

	int pos_mes = PosicionCaracter(fecha1, SEPARADOR_FECHAS);

	int mes1 = NumeroMes(fecha1.substr(0, pos_mes));
	int mes2 = NumeroMes(fecha2.substr(0, pos_mes));

	// Acortamos fecha 1 y fecha2

	fecha1 = fecha1.substr(pos_mes + 1);
	fecha2 = fecha2.substr(pos_mes + 1);

	// Obtenemos los a�os

	int anio1 = stoi(fecha1);
	int anio2 = stoi(fecha2);

	// Comprobamos si fecha1 sucede antes que fecha2

	bool ordenados;

	if(anio1 < anio2){
		ordenados = true;
	
	}else{

		if(anio1 > anio2)		// fecha2 sucede antes
			ordenados = false;

		else{	// Son iguales => vemos los meses
		
			if(mes1 < mes2)
				ordenados = true;
	
			else{	

				if(mes1 > mes2)		// fecha2 sucede antes
					ordenados = false;

				else{ // Son iguales => vemos los d�as

					// Si los d�as son iguales, dia1 sucede antes
					ordenados = dia1 <= dia2;

				}

			}

		}
	}

	return ordenados;
}

/****************************************************************************
	Determina si dos datos est�n ordenados en funci�n del criterio especificado

  Pr�metros: dato1, dato2, criterio
  Devuelve: true si dato1 < dato2, false si no

****************************************************************************/

bool EstanOrdenados(string dato1, string dato2, TipoOrdenacion criterio){
	
	bool ordenados;
	
	// Seg�n el criterio, compara dato1 y dato2 de diferentes formas

	switch(criterio){
		case TipoOrdenacion::apellidos:
	
			ordenados = OrdenadasAlfabeticamente(dato1, dato2);
			break;

		case TipoOrdenacion::fecha:
	
			ordenados = OrdenadasCronologicamente(dato1, dato2);
			break;

		case TipoOrdenacion::salario:
		
			ordenados = stod(dato1) < stod(dato2);
			break;
	}

	return ordenados;
}

/****************************************************************************/

int main(){

	// Selecciona por qu� criterio se ordenan los empleados *****************	

	TipoOrdenacion criterio;

	// Ordena a los empleados seg�n el sueldo bruto ---------------------

	criterio = TipoOrdenacion::salario;

	// Ordena a los empleados por apellidos -----------------------------

	// criterio = TipoOrdenacion::apellidos;

	// Ordena los empleados por su fecha de nacimiento ------------------

	// criterio = TipoOrdenacion::fecha;

	// ***********************************************************************

	// Ctes para el array info_empleados

	const int MAX_FILAS = 100, COLUMNAS = 4;

	const int COLUMNA_APELLIDOS = 0, COLUMNA_NOMBRES = 1, COLUMNA_FECHAS = 2
			, COLUMNA_SALARIOS = 3;

	string info_empleados[MAX_FILAS][COLUMNAS];

	int filas_validas = 0;

	// ENTRADAS ***************************************************************

	string entrada;

	// Solicita los datos del primer empleado

	getline(cin, entrada);

	// Elimina los espacios iniciales y finales de la entrada

	entrada = EliminaEspacios(entrada);

	// Mientras que haya empleados por leer y huecos libres en info_empleados

	while(entrada.length() != 0 && filas_validas < MAX_FILAS - 1){

		// Se repite COLUMNAS - 1 veces

		for(int i = 0; i < COLUMNAS - 1; i++){

			// Obtiene la posici�n del primer SEPARADOR_DATOS

			int posicion_corte = PosicionCaracter(entrada, SEPARADOR_DATOS);

			// Almacena el valor hasta el separador

			info_empleados[filas_validas][i] = 
											entrada.substr(0, posicion_corte);

			// Acorta la entrada

			entrada = entrada.substr(posicion_corte + 1);

		}

		// Almacena el �ltimo dato

		info_empleados[filas_validas][COLUMNA_SALARIOS] = 
									entrada.substr(0, entrada.length());

		filas_validas++;

		// Solicita los datos del siguiente empleado

		getline(cin, entrada);

		entrada = EliminaEspacios(entrada);
	}

	// info_empleados est� apunto de llenarse, se guarda el �ltimo empleado

	if(entrada.length() != 0){

		// Se repite COLUMNAS - 1 veces

		for(int i = 0; i < COLUMNAS - 1; i++){

			// Obtiene la posici�n del primer SEPARADOR_DATOS

			int posicion_corte = PosicionCaracter(entrada, SEPARADOR_DATOS);

			// Almacena el valor hasta el separador

			info_empleados[filas_validas][i] = 
											entrada.substr(0, posicion_corte);

			// Acorta la entrada

			entrada = entrada.substr(posicion_corte + 1);

		}

		// Almacena el �ltimo dato

		info_empleados[filas_validas][COLUMNA_SALARIOS] = 
									entrada.substr(0, entrada.length());

		filas_validas++;

		// Imprime que no se admiten m�s emleados por estar info_emleados lleno

		cout << endl;
		cout << "Maximo de empleados alcanzado." << endl;
		cout << endl;
	}

	// C�LCULOS **********************************************************

	// Ordena seg�n el ajuste especificado usando selection sort ----------

	int posiciones_ordenadas = 0;

	int columna;

	// Selecciona la columna en funci�n del criterio

	switch(criterio){
		case TipoOrdenacion::apellidos: 
			columna = COLUMNA_APELLIDOS;
			break;

		case TipoOrdenacion::fecha: 
			columna = COLUMNA_FECHAS;
			break;

		case TipoOrdenacion::salario:
		default: 
			columna = COLUMNA_SALARIOS;
			break;
	}

	// Se ejecuta tantas veces como empleados haya menos uno

	for(int vuelta = 0; vuelta < filas_validas - 1; vuelta++){

		// Busca el m�nimo del array -------------------------

		// Inicializa minimo en el dato del primer empleado

		int posicion_minimo = posiciones_ordenadas;
		string minimo = info_empleados[posicion_minimo][columna];

		// Recorre todas las posiciones en b�squeda del m�nimo

		for(int i = posicion_minimo + 1; i < filas_validas; i++){

			string dato = info_empleados[i][columna];

			// Comprueba si dato < minimo en funci�n de criterio

			if(EstanOrdenados(dato, minimo, criterio)){

				minimo = dato;
				posicion_minimo = i;

			}

		}

		// Si el m�nimo no estaba en la primera posici�n del array ordenado

		if(posiciones_ordenadas != posicion_minimo){

		   // Intercambia el elemento de posicion_minimo y posiciones_ordenadas

			for(int i = 0; i < COLUMNAS; i++){

				string auxiliar = info_empleados[posiciones_ordenadas][i];
				info_empleados[posiciones_ordenadas][i] = 
										info_empleados[posicion_minimo][i];
				info_empleados[posicion_minimo][i] = auxiliar;

			}

		}

		// Tenemos una nueva posici�n ordenada

		posiciones_ordenadas++;	

	}

	// SALIDAS

	cout << endl;

	// Imprime el criterio por el que se han ordenado

	switch(criterio){
		case TipoOrdenacion::apellidos:
			cout << "Ordenados por apellidos:" << endl;
			break;

		case TipoOrdenacion::fecha:
			cout << "Ordenados por fecha de nacimiento:" << endl;
			break;

		case TipoOrdenacion::salario:
		default:
			cout << "Ordenados por sueldo: " << endl;
			break;
	}

	cout << endl;

	// Imprime la cabecera de una tabla

	cout << setw(20) << "APELLIDOS		";
	cout << setw(20) << "NOMBRE		";
	cout << setw(20) << "NACIMIENTO		";
	cout << setw(20) << "SUELDO		" << endl;

	// Imprime los datos de todos los empleados, ordenados por el criterio
	// seleccionado

	for(int i = 0; i < filas_validas; i++){

		// Imprime el apellido del empleado, adem�s de una coma

		cout << setw(20) << info_empleados[i][COLUMNA_APELLIDOS] << ",";

		for(int j = 1; j < COLUMNAS; j++){

			cout << "		" << setw(20) << info_empleados[i][j];

		}

		cout << endl;

	}

	cout << endl;

	return 0;
}
