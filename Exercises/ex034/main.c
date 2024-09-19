#include <stdio.h>
#define TAM 15

int fibonacci(int n)
{

    int vetor[TAM], i;
    int qtd_pares = 0;

    for (i = 0; i < TAM; i++)
    {

        printf("Digite um numero: ");
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < TAM; i++)
    {

        if (vetor[i] % 2 == 0)
        {
            printf("\nValor: %d", vetor[i]);
            qtd_pares++;
        }
    }

    printf("\nQtd de pares: %d", qtd_pares);

    return 0;
}
