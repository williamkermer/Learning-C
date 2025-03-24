#include <stdio.h>
#include <math.h>

int main(void) {

    double v[6];
    int i = 0;

    while(i < 6) {
        printf("Digite o coeficiente %d:\n", i);
        scanf("%lf", &v[i]);
        i++;
    }

    while(1) {

        double x;
        printf("Digite X: ");
        scanf("%lf", &x);

        if(x == 0) {
            break;
        }

        double resultado = 0;

        for(i = 0; i < 6; i++) {
            resultado += v[i] * pow(x, i);
        }

        printf("p(%g) = %g\n", x, resultado);
    }

    return 0;
}