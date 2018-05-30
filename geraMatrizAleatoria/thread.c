#include <stdio.h>
#include <locale.h>

int main() {

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

  //Criando a matriz
  double matriz[num_linhas][num_colunas];
  for(i = 0; i < num_linhas; i++) {
    for(j = 0; j < num_colunas; j++) {
      fscanf(pfile, "%lf", &vtemp);
      matriz[i][j] = vtemp;
    }
  }

  //Printando os elementos para testar
  for(i = 0; i < num_linhas; i++) {
    for(j = 0; j < num_colunas; j++) {
      printf("(%d,%d) = %lf\n", i, j, matriz[i][j]);
    }
  }

  return 0;
}
