#include <stdio.h>

int fibonacci(int n)
{

    int vetor[10], i;

    for (i = 0; i < 10; i++)
    {

        printf("Digite um numero: ");
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < 10; i++)
    {

        printf("\nvetor[%d] = %d", i, vetor[i]);
    }

    return 0;
}
