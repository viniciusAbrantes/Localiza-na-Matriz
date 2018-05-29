#include <stdio.h>
#include <locale.h>

int main() {
  printf("Teste\n");
  printf("\e[H\e[2J");
  return 0;
}
