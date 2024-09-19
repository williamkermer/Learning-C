#include <stdio.h>

int numero = 0, qtdMaiores = 0, qtdMenores = 0;
int somaMaiores = 0, somaMenores = 0;

int main(void) {

    for(int i = 0; i < 10; i++){

      printf("Digite um numero: ");
      scanf("%d", &numero);

    

    if(numero >= 0){

      qtdMaiores += 1; // pode se usar tbm qtdMaiores++ para adicionar mais 1 caso "true"
      somaMaiores+= numero;
      
    }else{
      
      qtdMenores++;
      somaMenores+= numero;
      
    }

    }

  printf("\na) %d", qtdMaiores);
  printf("\nb) %d", qtdMenores);
  printf("\nc) %d", somaMaiores);
  printf("\nd) %d", somaMenores);



  
  return 0;
}