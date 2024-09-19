#include <stdio.h>

int fibonacci(int n)
{
    int vetor[10], i;

    for (i = 0; i < 10; i++)
    {

        printf("Digite um numero: [%d]:", i);
        scanf("%d", &vetor[i]);
    }

    return 0;
}
