#include <stdio.h>

int main(void) {
  
  int Idade = 0;
  
  printf("Digite a sua idade: ");

  scanf("%d", &Idade); //O Comando "%d" é a mascara para numero inteiros, usar "&" antes do nome da variavel

  printf("A idade é: %d", Idade);
  
  
  return 0;
}