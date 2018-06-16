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
void* procuraValor(void *arg);
