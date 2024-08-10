#include <stdio.h>

/*

Exemplo IMC

Peso / Altura²

*/

int main(void) {
  
  //Variaveis do mesmo tipo podem ser delaradas na mesma linha
  
  double peso = 0, altura = 0, imc = 0;

  //receber os dados 

  printf("Digite o Peso: ");
  scanf("%lf", &peso);

  printf("Digite a Altura: ");
  scanf("%lf", &altura);

  imc = peso/(altura * altura);
  printf("O IMC é: %g", imc);
  
  
  return 0;
}