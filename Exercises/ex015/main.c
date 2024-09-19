#include <stdio.h>

int main() {

  int numeros[10];
  int i;
  int numPosi = 0, numNeg = 0;
  int somaPositivos = 0, somaNegativos = 0;

  printf("Digite 10 numeros inteiros\n");
  for (i = 0; i < 10; i++) {
    printf("Numero %d: ", i + 1);
    scanf("%d", &numeros[i]);
  }

  for (i = 0; i < 10; i++) {
    if (numeros[i] >= 0) {
      numPosi++;
      somaPositivos += numeros[i];
    } else {
      numNeg++;
      somaNegativos += numeros[i];
    }
  }

  printf("\nNumeros digitados maiores ou igual a 0: %d\n", numPosi);
  printf("Numeros digitados menores que 0: %d\n", numNeg);
  printf("Soma de todos os numeros digitados maiores que zero: %d\n",
         somaPositivos);
  printf("Soma dos numeros digitados menores que zero: %d\n", somaNegativos);

  return 0;
}