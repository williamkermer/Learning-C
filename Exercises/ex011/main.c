#include <stdio.h>

int main() {

    float num = 0;
    int cont = 0;

    printf("Digite N: ");
    scanf("%f", &num);

    while(num >= 1){

      num = num / 2; // ou num /= 2;
      cont++;

    }

    printf("Ultimo resultado = %g\nForam feitas %d divisoes", num, cont);

    return 0;
}