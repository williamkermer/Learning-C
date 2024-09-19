#include <stdio.h>

int main() {

  int populacaoA = 5000000;
  int populacaoB = 7000000;
  float NatalA = 0.03; // 3% ao ano
  float NatalB = 0.02; // 2% ao ano
  int anos = 0;

  while (populacaoA <= populacaoB) {
    populacaoA += populacaoA * NatalA;
    populacaoB += populacaoB * NatalB;
    anos++;
  }

  printf(
      "A populacao do Pais A ultrapassara a populacao do Pais B em %d anos.\n",
      anos);

  return 0;
}