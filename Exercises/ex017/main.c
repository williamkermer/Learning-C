#include <stdio.h>

int main()
{

    int n;
    int numero = 1;
    int linha, coluna;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    for (linha = 1; linha <= n; linha++)
    {
        for (coluna = 1; coluna <= linha; coluna++)
        {
            printf("%d ", numero);
            numero++;
        }
        printf("\n");
    }

    return 0;
}