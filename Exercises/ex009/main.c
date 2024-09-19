#include <stdio.h>

int main(void) {

  int num = 0, cont = 0, maior = 0, menor = 1000;
  

  while(cont < 5){

  printf("Digite um numero entre zero e mil: ");
  scanf("%d", &num);
  cont++;

    if(num < menor){
      
      menor = num;
    
    }
    
    if (num > maior){

      maior = num;
    
    }
    
  }

  printf("Maior: %d\nMenor: %d", maior, menor);
  
  return 0;
}