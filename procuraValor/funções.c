/**
 * Conjunto de funcoes para carregar matriz de um arquivo, procurar determinado valore na matriz e imprimir cordenadas do número encontrado.
 *
 * Autor Alfredo Albélis, Cléofas Santos e Vinícius Pereira
 *
 * Ultima atualizacao: Sáb 16 Julho 2018 19:50:44
 *
 */
#include <stdio.h>
#include "funções.h" //Arquivo contendo o cabeçalho das funções
/**
 * Funcao para carregar matriz de um arquivo.
 *
 * @param *pfile Ponteiro para arquivo contendo os números que serão carregados.
 * @param numa_linhas Numero de linhas da matriz.
 * @param num_colunas Numero de colunas da matriz.
 * @param matriz Nome da variável que receberá o arquivo.
 */
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
/**
 * Funcao para procurar determinado valore na matriz.
 *
 * @param arg contendo as seguintes variáveis:
 *		  	num_linhas = num_linhas;
 *   	    num_colunas = num_colunas;
 *   	    num_thread = i;
 *   	    qtd_threads = qtd_threads;
 *   	    valor = valor;
 *   	    matriz = matriz[0];.
 */
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
/**
 * Funcao para imprimir cordenadas do número encontrado.
 *
 * @param numa_linhas Numero de linhas da matriz.
 * @param num_colunas Numero de colunas da matriz.
 * @param matriz Matriz binária.
 */
void printCoordenadas(int num_linhas, int num_colunas, double matriz[num_linhas][num_colunas]) {
  int i, j;

  for(i = 0; i < num_linhas; i++) {
    for(j = 0; j < num_colunas; j++) {
      if(matriz[i][j] == 1.0)
        printf("(%d,%d)\n", i, j);
    }
  }
}
