#include <iostream>
#include <cmath> // Para poder usar abs()

using namespace std;

int main()
{
	// DECLARACIONES	

	const int VOTANTES = 100000;

	int votos_emitidos, votos_presenciales, votos_correo;
	int votos_validos, votos_nulos;
	int votos_validos_correo, votos_validos_presenciales;
	int votos_A, votos_B, votos_C;

	// ENTRADAS ----------

	cout << "El numero total de votos: ";
	cin >> votos_emitidos;

	cout << "Votos presenciales: ";
	cin >> votos_presenciales;

	cout << "Votos por correo: ";
	cin >> votos_correo;
	
	cout << "Votos validos totales: ";
	cin >> votos_validos;

	cout << "Votos nulos totales: ";
	cin >> votos_nulos;
	
	cout << "Votos validos por correo: ";
	cin >> votos_validos_correo;

	cout << "Votos validos presenciales: ";
	cin >> votos_validos_presenciales;

	cout << "Votos para la opcion A: ";
	cin >> votos_A;

	cout << "Votos para B: ";
	cin >> votos_B;
	
	cout << "Votos para C: ";
	cin >> votos_C;

	// C�LCULOS Y EXPRESIONES L�GICAS ----------

	const double PORC_EMPATE_TECNICO = 0.05;
	const double PORC_POCOS_VOTOS_B = 0.03;
	const double PORC_ALTA_PARTICIPACION = 0.75;
	const double PORC_VOTOS_PRESENCIALES = 0.2;

	//Definimos algunas variables que nos van a hacer falta:
	int mitad_votos = votos_validos * 0.5; //�til para la mayor�a absoluta

	int votos_A_B = votos_A + votos_B;
	int votos_A_C = votos_A + votos_C;
	int votos_B_C = votos_B + votos_C;
	
	int abstenciones = VOTANTES - votos_emitidos;

	int votos_nulos_correo = votos_correo - votos_validos_correo;
	int votos_nulos_presenciales = 
		votos_presenciales - votos_validos_presenciales;

	// Expresiones l�gicas:

	// a) El n�mero de votos emitidos totales es mayor que el n�mero de 
	//	   votos.

	bool mas_votos_que_votantes = votos_emitidos > VOTANTES;

	// b) El n�mero de votos v�lidos no es igual a la suma de los votos 
	//	  recibidos por las tres opciones.

	bool votos_validos_incorrectos = 
		 votos_validos != (votos_A_B + votos_C);

	// c) El n�mero de votos registrados es igual a la suma de los votos 
	//	  v�lidos y nulos.

	bool numero_correcto_votos = 
		 votos_emitidos == (votos_validos + votos_nulos);

	// d) Gana la opci�n A.

	bool gana_A = votos_A > votos_B && votos_A > votos_C;

	// e) Gana la opci�n B.

	bool gana_B = votos_B > votos_A && votos_B > votos_C;

	// f) Gana la opci�n C.

	bool gana_C = votos_C > votos_B && votos_C > votos_A;

	// g) Empatan dos opciones.

	bool empatan_dos = votos_A == votos_B || votos_A == votos_C 
		 || votos_B == votos_C;

	// h) Hay un empate t�cnico entre las opciones A y B.

	bool empate_tecnico_A_B = 
		 abs(votos_A - votos_B) < votos_A_B * PORC_EMPATE_TECNICO;

	// i) La opci�n A obtiene mayor�a absoluta.

	bool mayoria_abs_A = votos_A > mitad_votos;

	// j) La coalici�n A-C obtiene mayor�a absoluta.

	bool mayoria_abs_A_C = votos_A_C > mitad_votos;

	// k) Hay una coalici�n de dos opciones que obtiene mayor�a absoluta.

	bool mayoria_abs_A_B = votos_A_B > mitad_votos; //La usaremos proximamente.

	bool mayoria_abs_dos_opciones = mayoria_abs_A_B || mayoria_abs_A_C 
		 || votos_B_C > mitad_votos;

	// l) La opci�n B obtiene menos de 3 % de los votos v�lidos registrados.

	bool B_menos_de_porcentaje = votos_B < votos_validos * PORC_POCOS_VOTOS_B;

	// m) La participaci�n es mayor que el 75 % del censo de votantes.

	bool participacion_alta = 
		 votos_emitidos > VOTANTES * PORC_ALTA_PARTICIPACION;

	// n) Queremos saber si la opci�n A puede gobernar "s�lo o en compa��a 
	//	  de otros".

	bool A_puede_gobernar = mayoria_abs_A || mayoria_abs_A_B 
		 || mayoria_abs_A_C;

	// �) El n�mero de abstenciones es mayor que el n�mero de votos v�lidos.

	bool alta_abstencion = abstenciones > votos_validos;

	// o) El n�mero de abstenciones es mayor que el n�mero de votos v�lidos, 
	//	  pero las abstenciones no son mayores que los votos nulos.

	bool muchos_votos_nulos = alta_abstencion && abstenciones <= votos_nulos;

	// p) El n�mero de votos por correo es mayor que el 20 % de los votos 
	//	  presenciales o el n�mero de abstenciones.

	bool muchos_votos_correo = 
		 votos_correo > votos_presenciales * PORC_VOTOS_PRESENCIALES 
		 || votos_correo > abstenciones;

	// q) El n�mero de votos nulos por correo es mayor que el n�mero de votos 
	//	  nulos presenciales.

	bool mas_nulos_correo = votos_nulos_correo > votos_nulos_presenciales;

	// r) El n�mero de votos nulos por correo es mayor que el n�mero de votos 
	//	  v�lidos por correo.

	bool mas_nulos_que_validos_correo = 
		 votos_nulos_correo > votos_validos_correo;

	// SALIDAS -----------------------------------

	cout << endl;
	
	// a)
	cout << "Mas votos que numero de votantes: " << boolalpha 
		 << mas_votos_que_votantes << endl;

	// b)
	cout << "Votos validos diferentes de las tres opciones: " << boolalpha 
		 << votos_validos_incorrectos << endl;

	// c)
	cout << "Votos registrados = votos validos + votos nulos: " << boolalpha 
		 << numero_correcto_votos << endl;

	// d)
	cout << "Gana A: " << boolalpha << gana_A << endl;

	// e)
	cout << "Gana B: " << boolalpha << gana_B << endl;

	// f)
	cout << "Gana C: " << boolalpha << gana_C << endl;

	// g)
	cout << "Empatan dos opciones: " << boolalpha << empatan_dos << endl;

	// h)
	cout << "Empate tecnico entre A y B: " << boolalpha << empate_tecnico_A_B 
		 << endl;

	// i)
	cout << "A tiene mayoria absoluta: " << boolalpha << mayoria_abs_A << endl;

	// j)
	cout << "Coalicion A-C tiene mayoria absoluta: " << boolalpha 
		 << mayoria_abs_A_C << endl;

	// k)
	cout << "Hay una coalicion de dos que tiene mayoria absoluta: " 
		 << boolalpha << mayoria_abs_dos_opciones << endl;

	// l)
	cout << "B tiene menos del " << (PORC_POCOS_VOTOS_B*100) 
		 << "% de los votos validos: " << boolalpha << B_menos_de_porcentaje 
		 << endl;

	// m)
	cout << "Participacion mayor que el " << (PORC_ALTA_PARTICIPACION*100) 
		 << "% de los votantes: " << boolalpha << participacion_alta << endl;

	// n)
	cout << "A puede gobernar solo o en compania de otros: " << boolalpha 
		 << A_puede_gobernar << endl;

	// �)
	cout << "Mas abstenciones que votos validos: " << boolalpha 
		 << alta_abstencion << endl;

	// o)
	cout << "Mas abstenciones que votos validos pero no que votos nulos: " 
		 << boolalpha << muchos_votos_nulos << endl;

	// p)
	cout << "Mas votos por correo que el " << (PORC_VOTOS_PRESENCIALES*100) 
		 << "% de los presenciales o que abstenciones: " << boolalpha 
		 << muchos_votos_correo << endl;

	// q)
	cout << "Mas votos nulos por correo que presenciales: " << boolalpha 
		 << mas_nulos_correo << endl;

	// r)
	cout << "Mas votos nulos que validos por correo: " << boolalpha 
		 << mas_nulos_que_validos_correo << endl;

	cout << endl;

	return 0;
}
