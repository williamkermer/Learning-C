#include <stdio.h>

int main(void) {

  int media = 0, par1 = 0, par2 = 0, par3 = 0;

  printf("Insira aqui o Parametro 1: ");
  scanf("%d", &par1);

  printf("Insira aqui o Parametro 2: ");
  scanf("%d", &par2);

  printf("Insira aqui o Parametro 3: ");
  scanf("%d", &par3);

  media = (par1 / par2) * par3;

  printf("A media dos parametros é: %d ", media );
  
  return 0;
}