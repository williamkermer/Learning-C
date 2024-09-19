#include <stdio.h>

int main(void) {

  int numero, cImpar, cPar;

  printf("digite um numero ou 0 para sair: ");
  scanf("%d", &numero);

  while( numero != 0){

  if((numero % 2) == 0){

  cPar = cPar + 1;
    
  }else{

    cImpar = cImpar + 1;

  }

    printf("digite um numero ou 0 para sair: ");
    scanf("%d", &numero);

  }

  printf("\nPares = %d \nImpares = %d", cPar, cImpar);

  
  return 0;
}