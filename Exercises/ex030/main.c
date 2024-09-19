#include <stdio.h>

int fibonacci(int n)
{
    int v[12];
    int i, v1, v2, vr;

    for (i = 0; i < 12; i++)
    {

        printf("Digite um numero: ");
        scanf("%d", &v[i]);
    }

    for (i = 0; i < 12; i++)
    {

        printf("\n%d) %d", i + 1, v[i]);
    }

    printf("\nescolha uma posição do vetor de 1 a 12: ");
    scanf("%d", &i);

    v1 = v[i - 1];

    printf("\nescolha uma posição do vetor de 1 a 12: ");
    scanf("%d", &i);

    v2 = v[i - 1];

    vr = v1 + v2;

    printf("%d", vr);

    return 0;
}