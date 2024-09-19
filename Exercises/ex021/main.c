#include <stdio.h>

int num = 0;

void oddoreven(int num){

  if(num % 2 == 0){
    printf("\nPar");

  }else{
  printf("\nImpar");
}
}

int main(void) {

  printf("Digite um numero: ");
  scanf("%d", &num);

  oddoreven(num);

  return 0;
}