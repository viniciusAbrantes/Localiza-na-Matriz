#include <stdio.h>
#include <locale.h>

void printMatriz(int num_linhas, int num_colunas, double matriz[num_linhas][num_colunas]);
void geraMatriz(FILE *pfile, int num_linhas, int num_colunas, double matriz[num_linhas][num_colunas]);

int main() {
  setlocale(LC_ALL, "portuguese"); //código para imprimir caracteres com acento
  printf("\e[H\e[2J"); //Limpa o terminal
  int num_linhas, num_colunas, num_threads;
  double valor;
  char nome_arq[20];

  //Entrada de dados---------------------------------
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
  //-------------------------------------------------

  //Criando a matriz---------------------------------
  double matriz[num_linhas][num_colunas];
  geraMatriz(pfile, num_linhas, num_colunas, matriz);
  printMatriz(num_linhas, num_colunas, matriz);
  //-------------------------------------------------

  return 0;
}

void geraMatriz(FILE *pfile, int num_linhas, int num_colunas, double matriz[num_linhas][num_colunas]) {
  double vtemp;
  int i, j;

  printf("\nCarregando a matriz do arquivo...\n");

  for(i = 0; i < num_linhas; i++) {
    for(j = 0; j < num_colunas; j++) {
      fscanf(pfile, "%lf", &vtemp);
      matriz[i][j] = vtemp;
    }
  }
}

void printMatriz(int num_linhas, int num_colunas, double matriz[num_linhas][num_colunas]) {
  int i, j;
  printf("\nMatriz gerada:\n");
  for(i = 0; i < num_linhas; i++) {
    for(j = 0; j < num_colunas; j++) {
      printf("%lf ", matriz[i][j]);
    }
    printf("\n");
  }
}
