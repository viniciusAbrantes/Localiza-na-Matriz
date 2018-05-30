#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct elemento_matriz {
  double valor;
  int x, y;
  struct elemento_matriz *prox_l, *l_ant, *prox_c;
}tmatriz;

void insereElemento(tmatriz **ini_l, tmatriz **percorre, int i, int j, double valor);

int main() {
  //inicio da matriz esparça:
  tmatriz *inicio = NULL;
  tmatriz *ini_l = NULL, percorre = NULL;

  //código para imprimir caracteres com acento:
  setlocale(LC_ALL, "portuguese");
  //printf("\e[H\e[2J"); //Limpa o terminal
  int num_linhas, num_colunas, num_threads;
  int i, j;
  double valor, vtemp;
  char nome_arq[20];

  printf("Informe o número de linhas da matriz: ");
  scanf("%d", &num_linhas);
  printf("Informe o número de colunas da matriz: ");
  scanf("%d", &num_colunas);
  printf("Informe o nome do arquivo matriz: ");
  scanf("%s", nome_arq);
  FILE *pfile = fopen(nome_arq, "r");
  if(pfile == NULL) {
    printf("Erro!\nArquivo não encontrado!\n");
    return 0;
  }
  printf("Informe o número de threads: ");
  scanf("%d", &num_threads);

  //criando a primeirra linha da matriz:
  fscanf(pfile, "%lf", &vtemp);
  insereElemento(&ini_l, &percorre, 0, 0, vtemp);
  inicio = ini_l;

  //for(j = 1; j < num_colunas; j++) {
  //  fscanf(pfile, "%lf", &vtemp);
  //  insereElemento(&ini_l, &percorre, 0, j, vtemp);
  //}

  //for(i = 1; i < num_linha; i++) {
  //  for(j = 0; j < num_colunas; j++) {
  //    fscanf(pfile, "%lf", &valor);
  //    insereElemento(&ini_l, &percore, i, j, vtemp);
  //  }
  //}

  return 0;
}

void insereElemento(tmatriz **pini_l, tmatriz **ppercorre, int i, int j, double valor) {
  tmatriz *novo_elemento = (tmatriz*) malloc(sizeof(tmatriz));

  novo_elemento->valor = valor;
  novo_elemento->x = i;
  novo_elemento->y = j;
  novo_elemento->prox_l = NULL;
  novo_elemento->prox_c = NULL;
  novo_elemento->l_ant = NULL; //Não existe elemento anterior

  if(*ppercorre == NULL) { //Primeiro elemento da matriz
    *ppercorre = novo_elemento;
    *pini_l = novo_elemento;
  }
  else { //Não é o primeiro elemento da matriz
    if(j == 0) { //Se for o primeiro elemento da linha
      (*ppercorre)->prox_l = novo_elemento;
      (*pini_l)->prox_l = novo_elemento;
      novo_elemento->l_ant = pini_l;
      *ppercorre = novo_elemento;
      *pini_l = novo_elemento;
    }
    else{
    (*ppercorre)->prox_c = novo_elemento;
    novo_elemento->l_ant = (*pini_l)->l_ant;
    *ppercorre = novo_elemento;
  }
}
