#include <iostream>

using namespace std;

/****************************************************************************
	Extrae una subcadena de otra, desde la posici�n indicada hasta encontrar 
	el caracter especificado

  Par�metros: cadena, posicion, caracter
  Devuelve: la subcadena especificada de cadena
  PRE: 0 <= posicion

****************************************************************************/

string ExtraeCadena(string cadena, int posicion, char caracter){

	string cad;

	bool seguir_leyendo = true;

	char car_actual = cadena.at(posicion);

	// Mientras que se pueda seguir leyendo

	while(seguir_leyendo && posicion < cadena.length()){
	
		cad += car_actual;

		posicion++;

		car_actual = cadena.at(posicion);

		// Lee hasta que no se encuentre caracter

		seguir_leyendo = car_actual != caracter;
	}

	return cad;
}

/****************************************************************************
	Pasa a may�sculas un string

  Par�metro: cad
  Devuelve: cad en may�sculas

****************************************************************************/

string Mayusculas(string cadena){
	string cad;

	for(int i = 0; i < cad.length(); i++){
		cad += toupper(cadena.at(i));
	}

	return cad;
}

/****************************************************************************
	Genera una cadena en la que hay veces veces el caracter caracter.

  Par�metros: veces (el n�mero que se repite el caracter)
			  caracter (el caracter a repetir)
  Devuelve: una cadena que contiene caracter veces veces
  PRE: veces >= 0

****************************************************************************/

string GenerarCaracteres (int veces, char caracter){
	string devuelta;	

	// Concatena caracter a devuelta veces n�mero de veces
	for(int i = 0; i < veces; i++)
		devuelta += caracter;

	return devuelta;
}

/****************************************************************************
	Formatea el string indicado de forma que contenga al menos el n�mero de
	caracteres especificado, rellenando con caracteres relleno

  Par�metros: cad, caracteres, relleno
  Devuelve: una cadena con cad alineado a la izquierda de al menos caracteres
	caracteres

****************************************************************************/

string Formatea(string cad, int caracteres, char relleno){

	string cadena;

	if(cad.length() < caracteres){

		int num_relleno = caracteres - cad.length();

		cadena = cad + GenerarCaracteres(num_relleno, relleno);

	}else
		cadena = cad;

	return cadena;
}

/****************************************************************************
	Devuelve en una cadena la representaci�n de un dato double con dos valores 
	decimales

  Par�metro: numero
  Devuelve: numero expresado como string, mostrando 2 decimales

****************************************************************************/

string FormateaNumero(double numero){
	
	string cadena = to_string(numero);

	string cad = cadena.substr(0, cadena.length() - 4);

	return cad;
}

/****************************************************************************/

class Fecha{

	// Campos de clase

	private:
		
	int dia;		// PRE: 0 < dia <= 31
	int mes;		// PRE: 0 < mes <= 12
	int anio;		// PRE: 1990 <= anio <= 2022

	// M�todos

	public:
	
	/*****************************************************************/
	// M�todos constructores

	Fecha() :dia(1), mes(1), anio(2000) {}

	// PRE: 0 < dia <= 31
	//		0 < mes <= 12
	//		1990 <= anio <= 2022

	Fecha(int d, int m, int a) :dia(d), mes(m), anio(a) {}

	// linea define una fecha con el siguiente formato:
	// dd/mm/aaaa

	Fecha(string linea){
		SetFecha(linea);
	}

	/*****************************************************************/
	// GETTERS y SETTERS

	int GetDia(){
		return dia;
	}

	int GetMes(){
		return mes;
	}

	int GetAnio(){
		return anio;
	}

	// PRE: 0 < d <= 31

	void SetDia(int d){
		dia = d;	
	}

	// PRE: 0 < m <= 12

	void SetMes(int m){
		mes = m;
	}

	// PRE: 1990 <= a <= 2022

	void SetAnio(int a){
		anio = a;
	}

	// PRE: 0 < dia <= 31
	//		0 < mes <= 12
	//		1990 <= anio <= 2022	

	void SetFecha(int d, int m, int a){
		dia = d;
		mes = m;
		anio = a;
	}

	// linea define una fecha con el siguiente formato:
	// dd/mm/aaaa

	void SetFecha(string linea){

		// Obtiene el d�a, el mes y el a�o

		string el_dia = linea.substr(0, 2);

		string el_mes = linea.substr(3, 2);

		string el_anio = linea.substr(6, 4);

		// Almacena cada uno en su campo correspondiente

		SetFecha(stoi(el_dia), stoi(el_mes), stoi(el_anio));
	}

	/*****************************************************************/
	// Obtiene las tres primeras letras del mes indicado

	string LetrasMes(int el_mes){
	
		const string MESES[] = {"Ene", "Feb", "Mar", "Abr", "May", 
							"Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"};	

		return MESES[el_mes - 1];
	}

	/*****************************************************************/
	// Devuelve en un string la informaci�n de la clase, en formato:
	//		dd MES aaaa

	string ToString(){
		
		const string CERO = to_string(0);
		const string SEPARADOR = " ";

		string cad;

		// Se a�aden los d�as

		if(dia < 10)
			cad += CERO;

		cad += to_string(dia) + SEPARADOR;

		// Se a�aden los meses

		cad += LetrasMes(mes) + SEPARADOR;

		// Se a�aden los a�os

		cad += to_string(anio);

		return cad;
	}	

	/*****************************************************************/
	// Devuelve en un string la informaci�n de la clase en el formato:
	// aaaammdd

	string ToString2(){

		const char CERO = '0';

		string meses, dias;

		// Se adaptan los meses para ocupar dos cifras

		if(mes < 10)
			meses += CERO;

		meses += to_string(mes);

		// Se adaptan los d�as para ocupar dos cifras

		if(dia < 10)
			dias += CERO;

		dias += to_string(dia);

		// Se construye la cadena

		string cad = to_string(anio) + meses + dias;

		return cad;
	}

	/*****************************************************************/
	// Devuelve true si la fecha indicada sucede despu�s que esta fecha

	bool SucedeDespues(Fecha fecha){
		return stoi(ToString2()) < stoi(fecha.ToString2());
	}

};

/****************************************************************************/

class Empleado{

	// Campos de clase

	private:

	string nombre;
	string apellidos;
	double salario;		// PRE: salario > 0
	Fecha fecha_nac;

	// M�todos

	public:

	/*****************************************************************/
	// M�todos constructores

	Empleado() :salario(0) {}

	// PRE: sueldo > 0

	Empleado(string nom, string ape, double sueldo, Fecha nacimiento)
		:nombre(nom), apellidos(ape), salario(sueldo), fecha_nac(nacimiento) {}

	// linea define un empleado con el siguiente formato:
	// Apellidos*Nombre*dd/mm/aaaa*salario*

	Empleado(string linea){
		SetDatos(linea);
	}

	/*****************************************************************/
	// GETTERS

	string GetNombre(){
		return nombre;
	}

	string GetApellidos(){
		return apellidos;
	}

	double GetSalario(){
		return salario;
	}

	Fecha GetFecha(){
		return fecha_nac;
	}

	/*****************************************************************/
	// SETTERS

	void SetNombre(string nom){
		nombre = nom;
	}

	void SetApellidos(string ape){
		apellidos = ape;
	}

	// PRE: sueldo > 0

	void SetSalario(double sueldo){
		salario = sueldo;
	}

	void SetFecha(Fecha nacimiento){
		fecha_nac = nacimiento;
	}

	// PRE: sueldo > 0

	void SetDatos(string nom, string ape, double sueldo, Fecha nacimiento){
		nombre = nom;
		apellidos = ape;
		salario = sueldo;
		fecha_nac = nacimiento;
	}

	void SetDatos(string linea){
	
		const char SEPARADOR = '|';

		int pos = 0;

		// Extrae los apellidos, el nombre, el salario y la fecha

		apellidos = ExtraeCadena(linea, pos, SEPARADOR);
		pos += apellidos.length() + 1;

		nombre = ExtraeCadena(linea, pos, SEPARADOR);
		pos += nombre.length() + 1;

		string fecha = ExtraeCadena(linea, pos, SEPARADOR);
		fecha_nac.SetFecha(fecha);
		pos += fecha.length() + 1;

		string sueldo = ExtraeCadena(linea, pos, SEPARADOR);
		salario = stod(sueldo);
	}

	/*****************************************************************/
	// Devuelve los datos del objeto con el siguiente formato:
	// Apellidos    Nombre    DD Mes AAAA   Salario

	string ToString(){

		// Longitudes m�nimas de cada secci�n

		const int LONG_APELLIDOS = 24;
		const int LONG_NOMBRE = 24;
		const int LONG_FECHA = 11;
		const int LONG_SALARIO = 7;

		const string SEPARADOR = "     ";
		const char ESPACIADO = ' ';

		return Formatea(apellidos, LONG_APELLIDOS, ESPACIADO) + SEPARADOR
			+ Formatea(nombre, LONG_NOMBRE, ESPACIADO) + SEPARADOR
			+ Formatea(fecha_nac.ToString(), LONG_FECHA, ESPACIADO) + SEPARADOR
			+ Formatea(FormateaNumero(salario), LONG_SALARIO, ESPACIADO);
	}

	/*****************************************************************/
	// Determina si un empleado es menor que otro o si no

	bool EsMenor(Empleado emp){

		// Los ordena por salario

		return GetSalario() < emp.GetSalario();

		// Los ordena por fecha de nacimiento

		// return GetFecha().SucedeDespues(emp.GetFecha());

		// Los ordena por apellidos y nombre

		/*
		string nombre1 = GetApellidos() + GetNombre();
		string nombre2 = emp.GetApellidos() + emp.GetNombre();

		return nombre1 < nombre2;
		*/
	}

};

/****************************************************************************/

int main(){
	
	const int NUM_EMPLEADOS = 100;

	Empleado empleados[NUM_EMPLEADOS];

	int pos_validas = 0;

	// ENTRADAS

	cout << "Introduzca los empleados con el formato: " 
		 << "Apellidos|Nombre|dd/mm/aaaa|Salario|" << endl;

	cout << endl;

	string linea;

	getline(cin, linea);

	// Lee l�neas hasta toparse con una vac�a

	while(linea != ""){
		
		// Guarda el empleado

		empleados[pos_validas].SetDatos(linea);

		pos_validas++;

		// Lee la siguiente linea

		getline(cin, linea);
	}

	// C�LCULOS Y SALIDAS ***************************************************

	// Si no se introdujo nada

	if(pos_validas == 0){

		cout << "No se introdujo ningun empleado" << endl << endl;

	}else{

		// Muestra el contenido de empleados[]

		cout << "------------------------------------------------" << endl;
		cout << "Empleados registrados sin ordenar: " << endl << endl;
	
		for(int i = 0; i < pos_validas; i++){
	
			cout << empleados[i].ToString() << endl;
	
		}
	
		cout << endl;
	
		// Ordena el array de empleados por selection sort seg�n el criterio 
		// decidido
	
		Empleado minimo, auxiliar;
	
		for(int izda = 0; izda < pos_validas - 1; izda++){
	
			// Calcula el m�nimo entre izda y pos_validas - 1
	
			minimo = empleados[izda];
	
			int pos_min = izda;
	
			for(int i = izda + 1; i < pos_validas; i++){
	
				// Guarda el nuevo m�nimo
	
				if(empleados[i].EsMenor(minimo)){
	
					minimo = empleados[i];
	
					pos_min = i;
	
				}
	
			}
	
			// Intercambia izda y pos_min
	
			auxiliar = empleados[izda];
	
			empleados[izda] = empleados[pos_min];
	
			empleados[pos_min] = auxiliar;
	
		}
	
		// Muestra el contenido de empleados[] 
	
		cout << "------------------------------------------------" << endl;
		cout << "Empleados registrados ordenados: " << endl << endl;
	
		for(int i = 0; i < pos_validas; i++){
	
			cout << empleados[i].ToString() << endl;
	
		}
	
	}

	return 0;
}
