/**
	* Implementación de un juego de Gato (3 IN A ROW)
	* para Estructuras de Datos

	* Tecnológico de Costa Rica, 2014

	* Vinicio Flores Hernández / Seth Michael Stalley
**/

#include "gato.h"
#include "gatoAI.h"

void printwinner(int);
void turnoHumano(char tablaJuego[N][N], char simbol, int *, bool*);
void turnoCPU(char tablaJuego[N][N], char simbol, int *, bool*);

int main(void) {
	int winner,simbol,continuePlaying=-1;
	bool finpartida;
	char simbolA, simbolB;

	char tablaJuego[N][N];

	do{
		initTablero(tablaJuego);
		winner = USERS_NOWIN;
		simbol = -1;
		finpartida = false;

		draw(tablaJuego);// Si la celda ya está ocupada por alguna jugada o no existe

		do{
			printf("Inserte cual simbolo usara para jugar ([1].CIRCULO / [2].EQUIS): ");
			scanf("%d", &simbol);
			#ifdef _WIN32
				fflush(stdin);
				fflush(stdout);
			#endif
		}while (simbol < G_CIRCULO || simbol > G_EQUIS);

		if(simbol == 1){
			simbolA = C_CIRCULO;
			simbolB = C_EQUIS;
		}else{
			simbolA = C_EQUIS;
			simbolB = C_CIRCULO;
		}

		while(1) {
			int estadoJuego;

			turnoHumano(tablaJuego, simbolA, &winner, &finpartida);
			estadoJuego = ganador(tablaJuego, simbolA);
			if(estadoJuego == EMPATE){
				winner = USERS_NOWIN;
				break;
			}

			turnoCPU(tablaJuego, simbolB, &winner, &finpartida);
			estadoJuego = ganador(tablaJuego, simbolB);
			//printf("estado juego: %d simbol %c", estadoJuego, simbol);
			if(estadoJuego == GANO){
				winner = USERS_PC;
				break;
			}else if(estadoJuego == EMPATE){
				winner = USERS_NOWIN;
				break;
			}
		}

		//felicitar al ganador
		printwinner(winner);
		printf("\n\nDesea jugar otra partida: (1/Si, 0/No): ");
		scanf("%d", &continuePlaying);
	}while(continuePlaying);//preguntar is jugar otra vez
		return 0;
}

void turnoHumano(char tablaJuego[N][N], char simbol, int *winner, bool *finpartida){
	int ncelda;
	bool empty = false;
	do{
		printf("\nInserte el numero de celda: ");
		scanf("%d", &ncelda);
		empty = isCellEmpty(tablaJuego,ncelda);
	} while( (ncelda < 0 || ncelda >= MAXSIZE || !empty) );

	juegaHumano(tablaJuego, ncelda, simbol);
	draw(tablaJuego);


}

void turnoCPU(char tablaJuego[N][N], char simbol, int *winner, bool *finpartida){
	puts("CPU jugando!");
	//movimiento del computador usando Min/Max
	minmax(tablaJuego, simbol);
	draw(tablaJuego);
}

/** ********************************************************************** **/
void printwinner(int winner)
{
	switch(winner) {
		case USERS_NOWIN:
			printf("Ningun ganador!\n");
			break;
		case USERS_PC:
			printf("CPU Ganador!\n");
			break;
		case USERS_HUMAN:
			printf("Humano ganador!\n");
			break;
		default:
			printf("Game Over!\n");
			break;
		}
}
