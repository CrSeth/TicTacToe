/**
	Implementa la inteligencia artificial de la CPU contra
	el jugador humano.

	Vinicio Flores Hernández / Seth Michael Stalley, Ingeniería en Computación
	Tecnológico de Costa Rica, 2014

**/

#include "gato.h"
#include "gatoAI.h"

char cambiar(char jugador){
	return jugador == C_EQUIS ? C_CIRCULO : C_EQUIS;
}

//si el jugador gana
int ganador(char tablaJuego[N][N], char jugador)
{
	int i, j;
	//Row and Column Checks
	for(i = 0; i < N; ++i)
	{
		//Row
		if(tablaJuego[0][i] != ' ')
		{
			if(tablaJuego[0][i] == tablaJuego[1][i] && tablaJuego[1][i] == tablaJuego[2][i])
				return tablaJuego[0][i] == jugador ? GANO: PERDIO;
		}

		//Column
		if(tablaJuego[i][0] != ' ')
		{
			if(tablaJuego[i][0] == tablaJuego[i][1] && tablaJuego[i][1] == tablaJuego[i][2])
				return tablaJuego[i][0] == jugador ? GANO : PERDIO;
		}
	}

	//Digonal Izquierdo
	if(tablaJuego[0][0] != ' ' && tablaJuego[0][0] == tablaJuego[1][1] && tablaJuego[1][1] == tablaJuego[2][2]){
		return tablaJuego[0][0] == jugador ? GANO : PERDIO;
	}

	//Diagonal derecho
	if(tablaJuego[2][0] != ' ' && tablaJuego[2][0] == tablaJuego[1][1] && tablaJuego[1][1] == tablaJuego[0][2]){
		//printf("\nhere symbol: %c and other: %c\n", tablaJuego[2][0], tablaJuego[1][1]);
		return tablaJuego[2][0] == jugador ? GANO : PERDIO;
	}

	//Revisar por empate
	for(i = 0; i < N; ++i)
	{
		for(j = 0; j < N; ++j)
		{
			if(tablaJuego[i][j] == C_VACIO)
				break;
		}
		if(tablaJuego[i][j] == C_VACIO)
			break;
	}
	//un empate
	if(i*j==9)
		return EMPATE;

	// tabla incompleto
	return INCOMPLETO;
}

int my_max(char tablaJuego[N][N], char jugador){
	int result = ganador(tablaJuego, jugador);

	if(result != INCOMPLETO)
		return result;

	int i, j, max = -10;
	for(i = 0; i < N; ++i)
	{
		for(j = 0; j < N; j++){
			if(tablaJuego[i][j] != C_VACIO)
				continue;

			char tablaNuevo[N][N];
			//copiar tabla para enviar recursion
			for(int x = 0; x < N; ++x){
				for(int y = 0; y < N; ++y){
					tablaNuevo[x][y] = tablaJuego[x][y];
				}
			}

			tablaNuevo[i][j] = jugador;
			int temp = my_min(tablaNuevo, cambiar(jugador));
			if(temp > max)
				max = temp;
		}
	}
	return max;
}

int my_min(char tablaJuego[N][N], char jugador)
{
	int result = ganador(tablaJuego, cambiar(jugador));
	if(result != INCOMPLETO)
		return result;

	int i, j, min;
	min = 10;
	for(i = 0; i < N; ++i)
	{
		for(j = 0; j < N; ++j)
		{
			if(tablaJuego[i][j] != C_VACIO)
				continue;

			char tablaNuevo[N][N];
			int x, y;
			for(x = 0; x < N; ++x)
			{
				for(y = 0; y < N; ++y)
				{
					tablaNuevo[x][y] = tablaJuego[x][y];
				}
			}

			tablaNuevo[i][j] = jugador;
			int temp = my_max(tablaNuevo, cambiar(jugador));
			if(temp < min)
				min = temp;
		}
	}
	return min;
}

void minmax(char tablaJuego[N][N], char jugador){
	int i, j, max, max_i, max_j;
	max = -10;
	for(i = 0; i < N; ++i)
	{
		for(j = 0; j < N; ++j)
		{
			if(tablaJuego[i][j] != C_VACIO)
				continue;

			char tablaNuevo[N][N];
			int x,y;
			for(x = 0; x < N; ++x){
				for(y = 0; y < N; ++y)
				{
					tablaNuevo[x][y] = tablaJuego[x][y];
				}
			}

			tablaNuevo[i][j] = jugador;
			int temp = my_min(tablaNuevo,cambiar(jugador));
			//max siempre arriba
			if(temp > max)
			{
				max = temp;
				max_i = i;
				max_j = j;
			}
		}
	}

	//hacerMovimiento(tablaJuego, jugador, max_i, max_j);
	tablaJuego[max_i][max_j] = jugador;
}

// void hacerMovimiento(char board[N][N], char player, int x, int y)
// {
// 	board[x][y] = player;
// }
