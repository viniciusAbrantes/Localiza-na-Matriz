#include <stdio.h>
#include "funções.h" //Arquivo contendo o cabeçalho das funções

void geraMatriz(FILE *pfile, int num_linhas, int num_colunas, double matriz[num_linhas][num_colunas]) {
  double vtemp;
  int i, j;

  printf("Carregando a matriz do arquivo...\n");

  for(i = 0; i < num_linhas; i++) {
    for(j = 0; j < num_colunas; j++) {
      fscanf(pfile, "%lf", &vtemp);
      matriz[i][j] = vtemp;
    }
  }
}

void* procuraValor(void* arg) {
  tipo_arg* parg = arg;
  int i, j;

  for (i = parg->num_thread; i < parg->num_linhas; i+=parg->qtd_threads) {
    for(j = 0; j < parg->num_colunas; j++) {
      if(parg->matriz[i*parg->num_colunas+j] == parg->valor)
        parg->matriz[i*parg->num_colunas+j] = 1.0;
      else parg->matriz[i*parg->num_colunas+j] = 0.0;
    }
  }
}

void printCoordenadas(int num_linhas, int num_colunas, double matriz[num_linhas][num_colunas]) {
  int i, j;

  for(i = 0; i < num_linhas; i++) {
    for(j = 0; j < num_colunas; j++) {
      if(matriz[i][j] == 1.0)
        printf("(%d,%d)\n", i, j);
    }
  }
}
