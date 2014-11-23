/**
	* Implementa la interfaz en modo texto
	* del programa
**/

#include "gato.h"

void draw(char tablaJuego[N][N])
{
	printf("\n");
	int i;
	for(i = 0; i < N; ++i)
	{
		printf("| %d | %d | %d |\t\t",(N*i),1+(N*i),2+(N*i));
		printf("| %c | %c | %c |\n",tablaJuego[0][i], tablaJuego[1][i], tablaJuego[2][i]);
	}

	printf("\n");
}
