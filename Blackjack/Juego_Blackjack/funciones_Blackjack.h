#pragma once
using namespace std;
#include "definicionTipos_Blackjack.h"

//************************************************************************************
//1. FUNCION QUE MUESTRA EL MENU Y RETORNA EL NUMERO SEGUN LA OPCION QUE SE SELECCIONO
int menu() {
	int opcion = 0;

	cout << endl << "\t -------------------- BLACKJACK --------------------" << endl;
	cout << "\t ---------------------------------------------------" << endl;
	cout << "\t SELECCIONE UNA DE LAS SIGUIENTES OPCIONES" << endl;
	cout << "\t 1. INSTRUCCIONES" << endl;
	cout << "\t 2. JUGAR" << endl;
	cout << "\t 3. SALIR" << endl;
	cout << "\t ---------------------------------------------------" << endl;
	cout << "\t Esperando opcion ... ";
	cin >> opcion;
	return opcion;	
}

//************************************************************************************
//2. FUNCION QUE MUESTRA INSTRUCCIONES DEL JUEGO
void instrucciones() {
	system("cls");

	cout << endl << " \t ------------------------------------------- INSTRUCCIONES -------------------------------------------" << endl;
	cout << endl << "\t El BLACKJACK consiste en un juego de cartas, en el que los jugadores deben de lograr alcanzar" << endl;
	cout << "\t con la suma de las mismas respectivamente el numero 21, o algun otro lo mas cercano posible a este." << endl;

	cout << endl << "\t COMO JUGAR..." << endl;
	cout << "\t * Se deben ingresar los nombres de los jugadores" << endl;
	cout << endl << "\t * A cada jugador le seran dadas dos cartas al azar del mazo " << endl;
	cout << endl << "\t * Cada jugador tendra su oportunidad de jugar, en donde podran sacar cuantas cartas del mazo deseen." << endl;
	cout << endl << "\t   Cuando decida no sacar mas cartas debera indicarle al sistema que no desea mas, y asi continuara con" << endl;
	cout << endl << "\t   los otros jugadores" << endl;
	cout << endl << "\t * Cuando la totalidad de jugadores terminaron, el sistema indicara cuales jugadores ganaron y cuales " << endl;
	cout << endl << "\t   perdieron" << endl;
	cout << endl << "\t ";
	system("pause");
	system("cls");
}

//************************************************************************************
//3. FUNCION GENERA TODAS LAS CARTAS DE LA BARAJA
void generaCartas(struct cartas arreglo[]) {
	
	//DECLARACION E INICILIZACION DE LAS VARIABLES
	int contador = 1,
		j = 10,
		q = 11,
		k = 12;
	string corazones = "\3",
		dimantes = "\4",
		treboles = "\5",
		picas = "\6";

	//CICLO QUE GENERA LAS 52 CARTAS
	for (int i = 0; i < 52; i++) {
		arreglo[i].numeros = contador; //CONTADOR GUARDA LOS NUMEROS DE LAS CARTAS Y VA INCREMENTANDO
		contador++;

		arreglo[i].marca = 0; //GUARDA TODAS LAS MARCAS EN 0 (0 NO HA SALIDO LA CARTA / 1 YA SALIO LA CARTA)

		if (contador == 14) { //CUANDO CONTADOR ES 14 SE REINCIA A 1 Y ASÍ GENERA LOS NUMEROS DEL SIGUIENTE PALO
			contador = 1;
		}

		if (i == j) { //CUANDO I ES 10 ASIGNA EN LETRAS LA J Y EL NUMERO EN 10
			arreglo[i].letras = "J";
			arreglo[i].numeros = 10;
			j += 13; //J INCREMENTA EN 13 Y ASI SE DOBLA PARA EL SIGUIENTE PALO
		}

		if (i == q) { //CUANDO I ES 11 ASIGNA EN LETRAS LA Q Y EL NUMERO EN 10
			arreglo[i].letras = "Q";
			arreglo[i].numeros = 10;
			q += 13; //Q INCREMENTA EN 13 Y ASI SE DOBLA PARA EL SIGUIENTE PALO
		}

		if (i == k) {  //CUANDO I ES 12 ASIGNA EN LETRAS LA K Y EL NUMERO EN 10
			arreglo[i].letras = "K";
			arreglo[i].numeros = 10;
			k += 13; //K INCREMENTA EN 13 Y ASI SE DOBLA PARA EL SIGUIENTE PALO
		}

		//ASIGNA CADA PALO SEGUN LOS RANGOS
		if (i >= 0 && i <= 12) { //CUANDO I VAYA DE 0 A 12 ASIGNA LOS CORAZONES EN LOS PALOS
			arreglo[i].palos = corazones;
		}
		else {
			if (i >= 13 && i <= 25) { //CUANDO I VAYA DE 13 A 25 ASIGNA LOS DIMANTES EN LOS PALOS
				arreglo[i].palos = dimantes;
			}
			else {
				if (i >= 26 && i <= 38) { //CUANDO I VAYA DE 26 A 38 ASIGNA LOS TREBOLES EN LOS PALOS
					arreglo[i].palos = treboles;
				}
				else {
					if (i >= 39 && i <= 52) { //CUANDO I VAYA DE 39 A 52 ASIGNA LAS PICAS EN LOS PALOS
						arreglo[i].palos = picas;
					}
				}
			}
		}
	}
}

//************************************************************************************
//4. SOLICITA NOMBRES DE LOS JUGADORES Y LOS ALMACENA EN EL VECTOR RESPECTIVO
void solicitaNombres(vector <string>& nombres) {

	//DECLARA E INICIALIZA LAS VARIABLES
	int contador = 1;
	system("cls");

	cin.ignore();

	//CICLO QUE SOLICITA EL NOMBRE 3 VECES Y GUARDA CADA UNO EN EL VECTOR
	for (int i = 0; i < 3; i++) {
		cout << endl << "\t INGRESE EL NOMBRE DEL JUGADOR " << contador << " : ";
		getline(cin, nombres[i]);
		contador++;
	}

	//ESPERA TECLA Y LIMPIA PANTALLA
	cout << endl << "\t ";
	system("pause");
	system("cls");
}

//************************************************************************************
//5. FUNCION RECIBE EL NUMERO GENERADO AL AZAR Y VERIFICA LA MARCA DEL INDICE EN ESA POSICION
int verificaNum(struct cartas arreglo[], int num) {

	int respuesta = 0;//DECLARA E INICIALIZA LA VARIABLE

	if (arreglo[num].marca == 1) { //SI EL ARREGLO EN EL NUMERO TIENE UN 1 EN LA MARCA RETORNA UN 1 Y LA FUNCION SIGUIENTE GENERA OTRO
		respuesta = 1;
	}
	//SI TIENE EN LA MARCA 0, SE RETORNA EL 0 Y SE ALMACENA EN EL VECTOR
	return respuesta;
}

//************************************************************************************
//6. GENERA LOS INDICES DE LAS CARTAS SIN QUE SE REPITAN PARA CADA UNO DE LOS MAZOS DE LOS JUGADORES
void generaMazos(struct cartas arreglo[], vector <int>& mazo) {

	//DECLARA E INICIALIZA LAS VARIABLES
	bool valido = false;
	int temp = 0;

	mazo.resize(2); //SE LE ASIGNA EL TAMAÑO A LOS MAZOS (2 CARTAS)

	srand(time(NULL)); //CREA LA SEMILLA PARA GENERAR LOS NUMEROS ALEATORIOS

	for (int i = 0; i < mazo.size(); i++) { //CICLO QUE GENERA NUMEROS ALEATORIOS SEGUN EL TAMAÑO DEL VECTOR
		while (verificaNum(arreglo, temp = rand() % (29 - 1))); //GENERA NUMEROS PARA EL INDICE, MIENTRAS LA FUNCION QUE VERIFICA LA MARCA DEL NUMERO 
		mazo[i] = temp;//GUARDA EL INDICE EN EL VECTOR			//RETORNE UN 0 (NO HA SALIDO), SI RETORNA UN 1 GENERA OTRO Y VERIFICA OTRA VEZ
		arreglo[temp].marca = 1; //MARCA EN LA POSICION GENERADO UN 1
	}
}

//************************************************************************************
//7. AGREGA UNA CARTA AL MAZO DEL JUGADOR RESPECTIVAMENTE
void agregaCarta(struct cartas arreglo[], vector <int>& mazo) {

	//DECLARA E INICIALIZA LAS VARIABLES
	int temp = 0;
	bool valido = false;

	srand(time(NULL)); //CREA LA SEMILLA PARA GENERAR LOS NUMEROS ALEATORIOS

	for (int i = 0; i < 1; i++)	{
		//GENERA NUMEROS PARA EL INDICE, MIENTRAS LA FUNCION QUE VERIFICA LA MARCA DEL NUMERO RETORNE UN 0, SI RETORNA UN 1 GENERA OTRO Y VERIFICA OTRA VEZ
		while (verificaNum(arreglo, temp = rand() % (53 - 1))); 
		mazo.insert(mazo.end(), temp); //INSERTA EL NUMERO AL FINAL DELVECTOR
		arreglo[temp].marca = 1; //MARCA EN LA POSICION GENERADO UN 1
	}
}

//************************************************************************************
//8. MUESTRA LAS CARTAS DEL MAZO DE CADA JUGADOR
void muestraJugadas(struct cartas arreglo[], vector <int>& mazo) {
	
	//DECLARA E INICIALIZA LAS VARIABLES
	bool esNumero = false,
		bandera = false;
	int cont = 0;

	//CICLO QUE EJECUTA MIENTRAS LA BANDERA SEA FALSA
	do{
		//CICLO QUE GENERA LA PRIMERA LINEA DE LAS CARTAS
		for (int i = 0; i < mazo.size(); i++) {
			printf("\t %c", 201); //CARACTER DE LA ESQUINA IZQUIERDA
			for (int i = 0; i <= 11; i++) { //CICLO GENERA LOS 11 CARACTERES
				printf("%c", 205);
			}
			printf("%c", 187); //CARACTER DE LA ESQUINA DERECHA
		}
		cout << endl;
		
		//CICLO IMPRIME PRIMERA LETRA O PRIMER NUMERO	
		for (int i = 0; i < mazo.size(); i++) {
			printf("\t %c ", 186); //IMPRIME UNA LINEA
			if (arreglo[mazo[i]].letras == "J" || arreglo[mazo[i]].letras == "K" || arreglo[mazo[i]].letras == "Q") { //SI ES UNA LETRA IMPRIME LA LETRA
				cout << arreglo[mazo[i]].letras;
				esNumero = false;
			}
			else {
				cout << arreglo[mazo[i]].numeros; //SI ES UN NUMERO IMPRIME EL NUMERO
				esNumero = true;
			}

			if (esNumero == true && arreglo[mazo[i]].numeros > 9) { //SI EL NUMERO ES 10
				printf("         %c", 186); //IMPRIME CON UN ESPACIO MENOS
			}
			else {
				printf("          %c", 186); //SINO IMPRIME LOS MISMOS ESPACIOS 
			}
		}
		cout << endl;

		//CICLO QUE IMPRIME DOS LINEAS A LOS LADOS
		for (int i = 0; i < mazo.size(); i++) {
			printf("\t %c            %c", 186, 186);
		}
		cout << endl;

		//CICLO QUE IMPRIME DOS LINEAS A LOS LADOS
		for (int i = 0; i < mazo.size(); i++) {
			printf("\t %c            %c", 186, 186);
		}
		cout << endl;

		//IMPRIME LOS PALOS
		for (int i = 0; i < mazo.size(); i++) {
			printf("\t %c     ", 186); //LINEA A LA IZQUIERDA CON ESPACIOS
			cout << arreglo[mazo[i]].palos; //MUESTRA EL PALO
			printf("      %c", 186); //LINEA A LA DERECHA CON ESPACIOS
		}
		cout << endl;

		//CICLO QUE IMPRIME DOS LINEAS A LOS LADOS
		for (int i = 0; i < mazo.size(); i++) {
			printf("\t %c            %c", 186, 186);
		}
		cout << endl;

		//CICLO QUE IMPRIME DOS LINEAS A LOS LADOS
		for (int i = 0; i < mazo.size(); i++) {
			printf("\t %c            %c", 186, 186);
		}
		cout << endl;

		//CICLO IMPRIME PRIMERA LETRA O PRIMER NUMERO	
		for (int i = 0; i < mazo.size(); i++) {
			if (arreglo[mazo[i]].letras == "J" || arreglo[mazo[i]].letras == "K" || arreglo[mazo[i]].letras == "Q") { //SI ES UNA LETRA IMPRIME LA LETRA
				printf("\t %c          ", 186);	//LINEA IZQUIERDA	
				cout << arreglo[mazo[i]].letras;
			}
			else {
				if (arreglo[mazo[i]].numeros > 9) { //SI EL NUMERO ES 10
					printf("\t %c         ", 186);//IMPRIME CON UN ESPACIO MENOS
				}
				else {
					printf("\t %c          ", 186); //SINO IMPRIME LOS MISMOS ESPACIOS 
				}
				cout << arreglo[mazo[i]].numeros; //SI ES UN NUMERO IMPRIME EL NUMERO
			}
			printf(" %c", 186); //LINEA DERECHA
		}
		cout << endl;

		//CICLO QUE IMPRIME LA PRIMERA LINEA DE LAS CARTAS
		for (int i = 0; i < mazo.size(); i++) {
			printf("\t %c", 200);  //CARACTER DE LA ESQUINA IZQUIERDA
			for (int i = 0; i <= 11; i++) {  //CICLO GENERA LOS 11 CARACTERES
				printf("%c", 205);
			}
			printf("%c", 188);  //CARACTER DE LA ESQUINA DERECHA
		}
		cout << endl;

		bandera = true; //CONVIERTE LA BANDERA EN VERDADERA Y TERMINA EL DO
	} while (bandera == false);

}
//************************************************************************************
//9. SUMA LOS VALORES DE LAS CARTAS EN EL MAZO DEL RESPECTIVO JUGADOR
int sumatoria(struct cartas arreglo[], vector <int>& mazo) {

	//DECLARA E INICIALIZA LAS VARIABLES
	int suma = 0,
		temp = 0;
	bool as = false;

	//CICLO QUE SUMA EL NUMERO DE LA CANTIDAD DE CARTAS QUE CONTENGA EL VECTOR (DE CADA MAZO)
	for (int i = 0; i < mazo.size(); i++) {
		suma += arreglo[mazo[i]].numeros;	
	}

	return suma;
}

//************************************************************************************
//10. MUESTRA LOS MENSAJES DEL JUGADOR QUE ESTA JUGANDO
char turno(vector <string>& nombres, int i) {

	//DECLARA E INICIALIZA LAS VARIABLES
	char continuar;
	int respuesta = 0;

	//MUESTRA EL NOMBRE DEL JUGADOR Y LE PREGUNTA SI DESEA OTRO CARTA O NO Y RETORNA LA RESPUESTA
	cout << endl << "\t TURNO DE " << nombres[i] << endl;
	cout << "\t DESEA OTRA CARTA DE LA BARAJA (S/N) ";
	cout << "\t ESPERANDO RESPUESTA... ";
	cin >> continuar;

	return continuar;
}

//************************************************************************************
//11. VERIFICA LA SUMATORIA QUE CADA JUGADOR POSEE EN LAS CARTAS
int verificaSumatoria(int sumatoria) {
	
	//DECLARA E INICIALIZA LAS VARIABLES
	int respuesta = 0;

	if (sumatoria == 21) { //SI LA SUMATORIA ES EXACTA A 21 RETORNA UN 1
		respuesta = 1;
	}
	else {
		if (sumatoria > 21) { //SILES MAYOR A 21 RETORNA UN 0
			respuesta = 0;
		}
	}
	return respuesta;
}

//************************************************************************************
//12. FUNCION MUESTRA LOS MAZOS Y LA SUMATORIA DE CADA UNO DE LOS JUGADORES
void muestraMazos(struct cartas arreglo[], vector <int>& mazo1, vector <int>& mazo2, vector <int>& mazo3, vector <string>& nombres, int& sumaMazo1, int& sumaMazo2, int& sumaMazo3) {
	cout << endl << "\t JUEGO DE " << nombres[0] << endl;
	muestraJugadas(arreglo, mazo1); //LAMADO FUNCION MUESTRA LAS CARTAS
	sumaMazo1 = sumatoria(arreglo, mazo1); //LLAMADO FUNCION CALCULA LA SUMA DE LAS CARTAS
	cout << "\t\t\t\t SUMATORIA " << sumaMazo1 << endl; //MUESTRA SUMA

	cout << endl << "\t JUEGO DE " << nombres[1] << endl;
	muestraJugadas(arreglo, mazo2); //LAMADO FUNCION MUESTRA LAS CARTAS
	sumaMazo2 = sumatoria(arreglo, mazo2); //LLAMADO FUNCION CALCULA LA SUMA DE LAS CARTAS
	cout << "\t\t\t\t SUMATORIA " << sumaMazo2 << endl; //MUESTRA SUMA

	cout << endl << "\t JUEGO DE " << nombres[2] << endl;
	muestraJugadas(arreglo, mazo3); //LAMADO FUNCION MUESTRA LAS CARTAS
	sumaMazo3 = sumatoria(arreglo, mazo3); //LLAMADO FUNCION CALCULA LA SUMA DE LAS CARTAS
	cout << "\t\t\t\t SUMATORIA " << sumaMazo3 << endl; //MUESTRA SUMA
}
//************************************************************************************
//13. FUNCION QUE MUESTRA LA TABLA CON LOS RESULTADOS FINALES
void muestraResultados(int sumaMazo1, int sumaMazo2, int sumaMazo3, vector <string>& nombres) {

	//DECLARA E INICIALIZA LAS VARIABLES
	int resultadoJug1 = 0,
		resultadoJug2 = 0,
		resultadoJug3 = 0,

		diferenciaJug1 = 0,
		diferenciaJug2 = 0,
		diferenciaJug3 = 0;

	//SE ASIGNAN LAS SUMATORIAS QUE OBTUVO A LA VARIABLE RESPECTIVA
	resultadoJug1 = verificaSumatoria(sumaMazo1);
	resultadoJug2 = verificaSumatoria(sumaMazo2);
	resultadoJug3 = verificaSumatoria(sumaMazo3);
		
	cout << endl << "\t ------------------------------- RESULTADOS -------------------------------";
	
	// RESULTADOS DEL PRIMER JUGADOR
	cout << endl << endl << "\t " << nombres[0];
	cout << endl << "\t\t OBTUVO UN TOTAL DE " << sumaMazo1; //MUESTRA LA SUMA

	if (resultadoJug1 == 1) { //SI LA FUNCION RETORNA UN 1 (OBTUVO 21) GANO EL JUEGO
		cout << endl << "\t\t GANO EL JUEGO" << endl;
	}
	else { //SINO, CALCULA LA DIFERENCIA (PUNTOS FALTANTES PARA ALCANZAR EL 21)
		diferenciaJug1 = 21 - sumaMazo1;
		if (diferenciaJug1 < 1) { //SI LA DIFERENCIA ES MENOR A 1 (SE PASO DEL 21) MUESTRA SOLO UN MENSAJE QUE PERDIO
			cout << endl << "\t\t PERDIO EL JUEGO" << endl;
		}
		else { //SINO MUESTRA UN MENSAJE CON LA DIFERENCIA
			cout << endl << "\t\t TUVO UNA DIFERENCIA DE " << diferenciaJug1 << endl;
		}
	}
	cout << endl << "\t --------------------------------------------------------------------------" << endl;

	// RESULTADOS DEL SEGUNDO JUGADOR
	cout << endl << endl << "\t " << nombres[1];
	cout << endl << "\t\t OBTUVO UN TOTAL DE " << sumaMazo2; //MUESTRA LA SUMA

	if (resultadoJug2 == 1) { //SI LA FUNCION RETORNA UN 1 (OBTUVO 21) GANO EL JUEGO
		cout << endl << "\t\t GANO EL JUEGO" << endl;
	}
	else { //SINO, CALCULA LA DIFERENCIA (PUNTOS FALTANTES PARA ALCANZAR EL 21)
		diferenciaJug2 = 21 - sumaMazo2;
		if (diferenciaJug2 < 1) {  //SI LA DIFERENCIA ES MENOR A 1 (SE PASO DEL 21) MUESTRA SOLO UN MENSAJE QUE PERDIO
			cout << endl << "\t\t PERDIO EL JUEGO" << endl;
		}
		else { //SINO MUESTRA UN MENSAJE CON LA DIFERENCIA
			cout << endl << "\t\t TUVO UNA DIFERENCIA DE " << diferenciaJug2 << endl;
		}
	}
	cout << endl << "\t --------------------------------------------------------------------------" << endl;

	// RESULTADOS DEL TERCER JUGADOR
	cout << endl << endl << "\t " << nombres[2];
	cout << endl << "\t\t OBTUVO UN TOTAL DE " << sumaMazo3;

	if (resultadoJug3 == 1) { //SI LA FUNCION RETORNA UN 1 (OBTUVO 21) GANO EL JUEGO
		cout << endl << "\t\t GANO EL JUEGO" << endl;
	}
	else { //SINO, CALCULA LA DIFERENCIA (PUNTOS FALTANTES PARA ALCANZAR EL 21)
		diferenciaJug3 = 21 - sumaMazo3;
		if (diferenciaJug3 < 1)	{ //SI LA DIFERENCIA ES MENOR A 1 (SE PASO DEL 21) MUESTRA SOLO UN MENSAJE QUE PERDIO
			cout << endl << "\t\t PERDIO EL JUEGO" << endl;
		}
		else { //SINO MUESTRA UN MENSAJE CON LA DIFERENCIA
			cout << endl << "\t\t TUVO UNA DIFERENCIA DE " << diferenciaJug3 << endl;
		}
	}
	cout << endl << "\t --------------------------------------------------------------------------" << endl << endl << "\t ";
	system("pause");

}

//************************************************************************************++
//14. FUNCION QUE EJECUTA TODO PARA EL FUNCIONAMIENTO DEL JUEGO
void ejecutaJuego(struct cartas arreglo[], vector <int>& mazo1, vector <int>& mazo2, vector <int>& mazo3, vector <string>& nombres) {
	
	//DECLARA E INICIALIZA LAS VARIABLES
	int sumaMazo1 = 0,
		sumaMazo2 = 0,
		sumaMazo3 = 0,
		cont = 0;
	char continuar = 'n';
	bool ganador = false;

	//CICLO DO QUE EJECUTA SOLO UNA VEZ EL SISTEMA
	do{
		muestraMazos(arreglo, mazo1, mazo2, mazo3, nombres, sumaMazo1, sumaMazo2, sumaMazo3); //LLAMADO FUNCION MUESTRA MAZOS, SUMA Y NOMBRE DE TODOS LOS JUGADORES JUNTOS
		cout << endl << "\t INICIAR EL JUEGO... " << endl << "\t ";
		system("pause");
		system("cls");

		//CICLO QUE AGREGA UNA CARTA AL MAZO DEL JUGADOR 1 HASTA QUE YA NO QUIERA MÁS
		do {
			cout << endl;
			muestraJugadas(arreglo, mazo1); //LLAMADO FUNCION MUESTRA LA BARAJA DEL JUGADOR 1
			cout << "\t\t\t\t SUMATORIA " << sumaMazo1 << endl; //MUESTRA LA SUMA QUE LLEVAN

			continuar = turno(nombres, cont); //LLAMADO FUNCION MUESTRA MENSAJE SI QUIERE OTRA CARTA O NO Y RETORNA LA RESPUESTA
			continuar = toupper(continuar); //VUELVE A MAYUSCULA LA RESPUESTA

			if (continuar == 'S') { //SI LA RESPUESTA ES S (DESEA OTRA CARTA) Y SI ES N (NO QUIERE MAS) PASA AL SIGUIENTE
				agregaCarta(arreglo, mazo1); //LLAMADO FUNCION QUE AGREGA CARTAS DE UNO EN UNO
				system("cls");
				sumaMazo1 = sumatoria(arreglo, mazo1); //SE VUELVE A LLAMAR LA FUNCION QUE CALCULA LA SUMA CON LA NUEVA CARTA
				muestraJugadas(arreglo, mazo1); //SE VUELVE A LLAMAR LA FUNCION QUE MUESTRA EL MAZO DEL JUGADOR CON LA NUEVA CARTA
				system("cls");
			}
		
		} while (continuar == 'S');			

		system("cls");
		muestraMazos(arreglo, mazo1, mazo2, mazo3, nombres, sumaMazo1, sumaMazo2, sumaMazo3); //LLAMADO FUNCION MUESTRA MAZOS, SUMA Y NOMBRE DE TODOS LOS JUGADORES JUNTOS

		cout << endl << "\t";
		system("pause");
		system("cls");

		//CICLO QUE AGREGA UNA CARTA AL MAZO DEL JUGADOR 2 HASTA QUE YA NO QUIERA MÁS
		do {
			cout << endl;
			muestraJugadas(arreglo, mazo2); //LLAMADO FUNCION MUESTRA LA BARAJA DEL JUGADOR 1
			cout << "\t\t\t\t SUMATORIA " << sumaMazo2 << endl; //MUESTRA LA SUMA QUE LLEVAN

			continuar = turno(nombres, cont + 1); //LLAMADO FUNCION MUESTRA MENSAJE SI QUIERE OTRA CARTA O NO Y RETORNA LA RESPUESTA
			continuar = toupper(continuar); //VUELVE A MAYUSCULA LA RESPUESTA

			if (continuar == 'S') { //SI LA RESPUESTA ES S (DESEA OTRA CARTA) Y SI ES N (NO QUIERE MAS) PASA AL SIGUIENTE
				agregaCarta(arreglo, mazo2); //LLAMADO FUNCION QUE AGREGA CARTAS DE UNO EN UNO
				system("cls");
				sumaMazo2 = sumatoria(arreglo, mazo2); //SE VUELVE A LLAMAR LA FUNCION QUE CALCULA LA SUMA CON LA NUEVA CARTA
				muestraJugadas(arreglo, mazo2); //SE VUELVE A LLAMAR LA FUNCION QUE MUESTRA EL MAZO DEL JUGADOR CON LA NUEVA CARTA
				system("cls");
			}
		
		} while (continuar == 'S');

		system("cls");
		muestraMazos(arreglo, mazo1, mazo2, mazo3, nombres, sumaMazo1, sumaMazo2, sumaMazo3); //LLAMADO FUNCION MUESTRA MAZOS, SUMA Y NOMBRE DE TODOS LOS JUGADORES JUNTOS

		cout << endl << "\t";
		system("pause");
		system("cls");

		//CICLO QUE AGREGA UNA CARTA AL MAZO DEL JUGADOR 3 HASTA QUE YA NO QUIERA MÁS
		do {
			cout << endl;
			muestraJugadas(arreglo, mazo3); //LLAMADO FUNCION MUESTRA LA BARAJA DEL JUGADOR 1
			cout << "\t\t\t\t SUMATORIA " << sumaMazo3 << endl;  //MUESTRA LA SUMA QUE LLEVAN

			continuar = turno(nombres, cont + 2); //LLAMADO FUNCION MUESTRA MENSAJE SI QUIERE OTRA CARTA O NO Y RETORNA LA RESPUESTA
			continuar = toupper(continuar); //VUELVE A MAYUSCULA LA RESPUESTA

			if (continuar == 'S') { //SI LA RESPUESTA ES S (DESEA OTRA CARTA) Y SI ES N (NO QUIERE MAS) PASA AL SIGUIENTE
				agregaCarta(arreglo, mazo3); //LLAMADO FUNCION QUE AGREGA CARTAS DE UNO EN UNO
				system("cls");
				sumaMazo3 = sumatoria(arreglo, mazo3); //SE VUELVE A LLAMAR LA FUNCION QUE CALCULA LA SUMA CON LA NUEVA CARTA
				muestraJugadas(arreglo, mazo3); //SE VUELVE A LLAMAR LA FUNCION QUE MUESTRA EL MAZO DEL JUGADOR CON LA NUEVA CARTA
				system("cls");
			}
		
		} while (continuar == 'S');

		system("cls");
		muestraMazos(arreglo, mazo1, mazo2, mazo3, nombres, sumaMazo1, sumaMazo2, sumaMazo3); //LLAMADO FUNCION MUESTRA MAZOS, SUMA Y NOMBRE DE TODOS LOS JUGADORES JUNTOS

		cout << endl << "\t JUEGO FINALIZADO "; //MUESTRA MENSAJES DE QUE EL JUEGO YA FINALIZÓ
		cout << endl << "\t VER RESULTADOS... ";
		cout << endl << "\t ";
		system("pause");
		system("cls");

		muestraResultados(sumaMazo1, sumaMazo2, sumaMazo3, nombres); //LLAMADO A LA FUNCION QUE MUESTRA LOS RESULTADOS FINALES
		ganador = true; //SE ASIGNA LA VARIABLE EN TRUE Y SE TERMINA EL JUEGO
		
		system("cls");

	} while (ganador == false);

}

