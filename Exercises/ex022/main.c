#include <stdio.h>

double soma(double n1, double n2)
{
    return n1 + n2;
}
double mult(double n1, double n2)
{
    return n1 * n2;
}
double sub(double n1, double n2)
{
    return n1 - n2;
}
double div(double n1, double n2)
{
    return n1 / n2;
}

int main(void)
{

    int opc = 0;
    double numero1, numero2 = 0;
    char continuar;

    do
    {

        printf("Escolha o primeiro numero: \n");
        scanf("%lf", &numero1);
        printf("Escolha o segundo numero: \n");
        scanf("%lf", &numero2);

        printf("Escolha a ação:\n 1 - Soma\n 2 - Subtração\n 3 - Multiplicação\n 4 - Divisão\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("Soma: %g\n", soma(numero1, numero2));
            break;

        case 2:
            printf("Subtração: %g\n", sub(numero1, numero2));
            break;

        case 3:
            printf("Multiplicação: %g\n", mult(numero1, numero2));
            break;

        case 4:
            if (numero1 == 0 || numero2 == 0)
            {
                printf("Operação invalida\n");
            }
            else
            {
                printf("Divisão: %g\n", div(numero1, numero2));
            }
            break;

        default:
            printf("Opção não encontrada\n");
            break;
        }

        printf("deseja continuar? [s/n]\n");
        scanf(" %c", &continuar);

    } while (continuar == 's');

    return 0;
}