#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct matriz {
  double valor;
  int x, y;
  struct matriz *prox_linha, *ante_linha, *prox_coluna;
}tmatriz;

int geraMatrizEsparca(tmatriz **ini, FILE *pfile, int num_linha, int num_coluna);
void insereElemento(tmatriz **ini, int i, int j, double valor);

int main() {
  //inicio da matriz esparça:
  tmatriz *ini = NULL;

  //código para imprimir caracteres com acento:
  setlocale(LC_ALL, "portuguese");
  //printf("\e[H\e[2J"); //Limpa o terminal
  int num_linhas, num_colunas, num_threads;
  double valor;
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

  //chamando a função para a criação da matriz esparça:
  //geraMatrizEsparca(&ini,pfile, num_linha, num_coluna);

  fscanf(pfile, "%lf", &valor);
  printf("Primeiro num = %f\n",valor);

  return 0;
}

int geraMatrizEsparca(tmatriz **ini, FILE *pfile, int num_linha, int num_coluna) {
  int i, j;
  double valor;
  for(i = 1; i < num_linha; i++) {
    for(j = 0; j < num_coluna; j++) {
      fscanf(pfile, "%lf", &valor);
      insereElemento(ini, i, j, valor);
    }
  }
}

void insereElemento(tmatriz **ini, int i, int j, double valor) {
  tmatriz *novo_elemento = (tmatriz*) malloc(sizeof(tmatriz));

  novo_elemento->valor = valor;
  novo_elemento->x = i;
  novo_elemento->y = j;
  novo_elemento->prox_linha = NULL;
  novo_elemento->ante_linha = NULL;
  novo_elemento->prox_coluna = NULL;

  if
}
