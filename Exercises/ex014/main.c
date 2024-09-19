#include <stdio.h>

int main(void) {

  double altura = 0, somaAltura = 0, mediaAltura = 0, mediaIdade = 0;
  int idade = 0, somaIdade = 0, cont = 0, contIdade = 0, contAltura = 0;

  printf("Idade: ");
  scanf("%d", &idade);
  printf("Altura: ");
  scanf("%lf", &altura);

  while (idade != 0) {
    cont++;

    if (altura < 1.70) {
      somaIdade = somaIdade + idade;
      contIdade++;
    }
    if (idade > 20) {
      somaAltura = somaAltura + altura;
      contAltura++;
    }

    printf("Idade: ");
    scanf("%d", &idade);
    if (idade != 0) {
      printf("Altura: ");
      scanf("%lf", &altura);
    }
  }
  printf("A classe tem %d alunos\n", cont);
  if (contIdade == 0) {
    printf("Nao ha' alunos com menos de 1,70m de altura\n");
  } else {
    mediaIdade = somaIdade / contIdade;
    printf("A idade media dos alunos com menos de 1,70m de altura e' %g anos\n",
           mediaIdade);
  }
  if (contAltura == 0) {
    printf("Nao ha' alunos com mais de 20 anos\n");
  } else {
    mediaAltura = somaAltura / contAltura;
    printf("A altura media dos alunos com mais de 20 anos e' %gm\n",
           mediaAltura);
  }

  return 0;
}