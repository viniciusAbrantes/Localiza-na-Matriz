#include <stdio.h>
#include <locale.h>

int main() {
  //printf("\e[H\e[2J"); //Limpa o terminal
  int num_linhas, num_colunas, num_threads;
  double valor;
  char nome_arq[20];
  printf("Informe o nome do arquivo: ");
  gets(nome_arq); //entre com o nome da matriz: "matriz.txt"
  puts(nome_arq);
  FILE *pfile = fopen(nome_arq, "r");
  if(pfile != NULL) printf("Abriu certo\n");
  else printf("Abriu errado\n");
  fscanf(pfile, "%lf", &valor);
  printf("Primeiro num = %f\n",valor);

  return 0;
}
