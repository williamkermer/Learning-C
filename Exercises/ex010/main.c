#include <stdio.h>

int main(void) {

  int  digitados = 0, atual = 0, maior = 0;

  printf("digite um número: \n");
  scanf("%d", &maior);
  digitados++;

  while( digitados < 15){

    printf("digite um número: \n");
    scanf("%d", &atual);
  
    if( atual > maior){

  maior = atual;

  }

    digitados++;


  }

  printf("Maior numero digitado: %d", maior);


  return 0;
}