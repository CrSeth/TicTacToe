#include "gato.h"

void initTablero(char tablaJuego[N][N])
{
  for(int i=0;i<N;i++)
    for(int j = 0; j < N; j++)
      tablaJuego[i][j] = C_VACIO;
}

void juegaHumano(char tablaJuego[N][N],int ncelda, int simbol){
  int j = ncelda / N;
  int i = ncelda % N;
  //printf("inserted i: %d j: %d", i, j);
  tablaJuego[i][j] = simbol;
}

bool isCellEmpty(char tablaJuego[N][N], int ncelda){
  int j = ncelda / N;
  int i = ncelda % N;
  if(tablaJuego[i][j] == C_VACIO)
    return true;
	return false;
}
