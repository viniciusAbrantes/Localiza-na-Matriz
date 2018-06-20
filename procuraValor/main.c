#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include "funções.h" //Arquivo contendo o cabeçalho das funções

int main(int argc, char *argv[]) {
  int num_linhas, num_colunas, qtd_threads;
  int i;
  double valor;
  char nome_arq[20];

  //Entrada de dados---------------------------------
  num_linhas = atoi(argv[1]);
  num_colunas = atoi(argv[2]);
  strcpy (nome_arq,(argv[3]));

  FILE *pfile = fopen(nome_arq, "r");
  if(pfile == NULL) {
    printf("Erro!\nArquivo não encontrado!\n");
    return 0;
  }
  qtd_threads = atoi(argv[4]);
  valor = atof(argv[5]);
  //-------------------------------------------------

  //Criando a matriz---------------------------------
  double matriz[num_linhas][num_colunas];
  geraMatriz(pfile, num_linhas, num_colunas, matriz);
  fclose(pfile); //Fechando arquivo
  //-------------------------------------------------

  //Criando vetor de threads e argumentos------------
  printf("\nGerando vetor de threads e argumentos...\n");
  pthread_t threads[qtd_threads];
  tipo_arg arg[qtd_threads];
  for(i = 0; i < qtd_threads; i++) {
    arg[i].num_linhas = num_linhas;
    arg[i].num_colunas = num_colunas;
    arg[i].num_thread = i;
    arg[i].qtd_threads = qtd_threads;
    arg[i].valor = valor;
    arg[i].matriz = matriz[0];
  }
  //-------------------------------------------------

  //Criando as threads-------------------------------
  for(i = 0; i < qtd_threads; i++)
    pthread_create(&threads[i], NULL, procuraValor, (void*) &arg[i]);
  //-------------------------------------------------

  //Esperando as threads finalizarem-----------------
  for(i = 0; i < qtd_threads; i++)
    pthread_join(threads[i], NULL);
  //-------------------------------------------------

  //Printando as coordenadas-------------------------
  printf("\n");
  printCoordenadas(num_linhas, num_colunas, matriz);
  //-------------------------------------------------

  return 0;
}
