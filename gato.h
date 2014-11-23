/** Encabezado principal **/
/* Definiciones de funciones y constantes generales
  * del programa */

#ifndef __GATO_HEADER_H
#define __GATO_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


#ifdef _WIN32
#define pause()		system("PAUSE")
#define clear()		system("CLS")
#else
#define pause()		1
#define clear()		1
#endif

#define MAXSIZE 9
#define N 3 //candidad de filas/columanas de la tabla

#define C_VACIO		' '
#define C_CIRCULO	'O'
#define C_EQUIS		'X'

//valor importante para calculo min/max AI
#define GANO 1
#define PERDIO -1
#define EMPATE 0
#define INCOMPLETO 2

/** Estructuras de recorrido **/
typedef enum  { G_VACIO, G_CIRCULO, G_EQUIS, G_LAST } estado_t;
enum users_n {USERS_NOWIN, USERS_PC, USERS_HUMAN };

typedef enum {false, true} bool;

void initTablero(char tablaJuego[N][N]);
bool isCellEmpty(char tablaJuego[N][N], int ncelda);
void juegaHumano(char tablaJuego[N][N],int ncelda, int simbol);

/* ---------------------------------------------*/
/* Funciones de control de consola **************/
void draw(char tablaJuego[N][N]);

#endif
