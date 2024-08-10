#include <stdio.h>

int main(void) {

  double mEnem = 0, matematica = 0, portugues = 0, natureza = 0, humanas = 0;

  printf("Digite a Nota de Matematica: ");
  scanf("%lf", &matematica);

  printf("Digite a nota de Português: ");
  scanf("%lf", &portugues);
  
  printf("Digite a nota de Ciências da Natureza: ");
  scanf("%lf", &natureza);

  printf("Digite a nota de Ciências Humanas: ");
  scanf("%lf", &humanas);

  mEnem = (matematica + portugues + natureza + humanas)/ 4;
  printf("A sua Media no ENEM foi: %lf", mEnem);
  
  
  return 0;
}