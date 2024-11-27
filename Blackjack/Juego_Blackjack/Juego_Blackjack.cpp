// Eddy Campos Jimenez
// Creado: 26 Noviembre 2022
// Actualizado:
// Juego BlackJack

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h> 
#include <time.h>
#include "funciones_Blackjack.h"

using namespace std;

int main()
{
	//DECLARACION E INICILIAZACION DE VARIABLES
	int opcion = 0,
		indice = 0;

	cartas baraja[52]; //VECTOR STRUCT QUE CONTIENE TODAS LAS CARTAS
	vector <string> nombres(3); //ALMACENA LOS NOMBRES DE LOS JUGADORES
	vector <int> mazo1; //VECTOR QUE ALMACENA LAS CARTAS DEL MAZO 1
	vector <int> mazo2; //VECTOR QUE ALMACENA LAS CARTAS DEL MAZO 2
	vector <int> mazo3; //VECTOR QUE ALMACENA LAS CARTAS DEL MAZO 1
	
	//DO EJECUTA TODO EL SISTEMA HASTA QUE SE INGRESE UNA OPCION MAYOR A 4
	do {
		opcion = menu(); //LLAMADO FUNCION CON EL MENU Y RETORNA LA OPCION SELECCIONADA
		
		switch (opcion) {

		//MUESTRA INSTRUCCIONES
		case 1: {
			instrucciones(); //LLAMADO A LA FUNCION
			break;
		}

		//JUGAR
		case 2:	{ 
			solicitaNombres(nombres); //LLAMADO FUNCION SOLICITA Y GUARDA LOS NOMBRES
			generaCartas(baraja); //LLAMADO FUNCION GENERA LA BARAJA TOTAL
			
			generaMazos(baraja, mazo1); //FUNCION QUE GENERA EL MAZO 1
			generaMazos(baraja, mazo2); //FUNCION QUE GENERA EL MAZO 2
			generaMazos(baraja, mazo3); //FUNCION QUE GENERA EL MAZO 3

			ejecutaJuego(baraja, mazo1, mazo2, mazo3, nombres); //FUNCION QUE EJECUTA TODO EL JUEGO
			break;
		}

		//SALIR DE LA EJECUCION
		case 3: {
			cout << endl << "\t GRACIAS!" << endl;
			opcion = 4;
			break;
		}

		//SI SE INGRESA UNA OPCION INCORRECTA
		default:
			cout << endl << "\t OPCION INVALIDA" << endl << "\t ";
			system("pause");
			break;
		}

	} while (opcion < 4);
}


