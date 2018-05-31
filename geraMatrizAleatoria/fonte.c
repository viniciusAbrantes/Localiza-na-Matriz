#include <stdio.h>
#include <locale.h>
#include <pthread.h>

typedef struct argumento {
  int num_linhas;
  int num_colunas;
  int num_thread;
  int qtd_threads;
  double valor;
  double *matriz;
}tipo_arg;

void printCoordenadas(int num_linhas, int num_colunas, double matriz[num_linhas][num_colunas]);
void geraMatriz(FILE *pfile, int num_linhas, int num_colunas, double matriz[num_linhas][num_colunas]);
void* procuraValor(void* arg);

int main() {
  setlocale(LC_ALL, "portuguese"); //código para imprimir caracteres com acento
  printf("\e[H\e[2J"); //Limpa o terminal
  int num_linhas, num_colunas, qtd_threads;
  int i;
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
  scanf("%d", &qtd_threads);
  printf("Informe o valor a ser buscado: ");
  scanf("%lf", &valor);
  //-------------------------------------------------

  //Criando a matriz---------------------------------
  double matriz[num_linhas][num_colunas];
  geraMatriz(pfile, num_linhas, num_colunas, matriz);
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

  //Ordenando a lista encadeada----------------------
  printf("\n");
  printCoordenadas(num_linhas, num_colunas, matriz);
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
      if(matriz[i][j] == 1)
        printf("(%d,%d)\n", i, j);
    }
  }
}
