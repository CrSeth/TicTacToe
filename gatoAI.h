#ifndef __GATOAI_HEADER_H
#define __GATOAI_HEADER_H

#include "gato.h"

int ganador(char tablaJuego[N][N], char jugador);
void minmax(char tablaJuego[N][N], char jugador);
int my_min(char tablaJuego[N][N], char jugador);
int hacerMovimiento(char board[N][N], char player, int x, int y);
char cambiar(char jugador);

#endif
