#include <stdio.h>

char exibirTabuada(int n){

  int resultado = 1;

  for(int t = 1; t <= n; t++){
    for(int i = 1; i <= 10; i++){

      resultado = t * i;
      
      printf("%d x %d = %d\n", t,i,resultado);
    
    }
    printf("\n");
  }
}

int n;

int main(void) {
  printf("Digite um numero: ");
  scanf("%d", &n);
  printf("\n");

  (exibirTabuada(n));
  return 0;
}
  
