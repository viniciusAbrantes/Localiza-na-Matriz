#include <stdio.h>
#include <pthread.h>

#define N_THREAD 4

void delay() {
  int i, j, k, valor = 1000;
  for(i = 0; i < valor; i++)
    for(j = 0; j < valor; j++)
      for(k = 0; k < valor; k++)
        valor = valor;
}

void *function(void* arg) {
  int* pvalor = arg;
  printf("Thread %d executando...\n", *pvalor);
  delay();
  printf("Thread %d finalizada!\n", *pvalor);
}

int main() {
  pthread_t threads[N_THREAD];
  int i, arg[N_THREAD];

  for(i = 0; i < N_THREAD; i++) {
    arg[i] = i + 1;
    pthread_create(&threads[i], NULL, function, (void*) &arg[i]);
  }

  for(i = 0; i < N_THREAD; i++)
    pthread_join(threads[i], NULL);

  printf("\n");
  return 0;
}
