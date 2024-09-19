#include <stdio.h>

int medmes[12];
int media = 0;
int maior = -273;
int menor = 273;
int i = 0;
int soma = 0;

int TempMed(int soma)
{
    return printf("\nMedia de temperatura: %d°C", soma / 12);
}

int MaisFrio(int menor)
{

    switch (menor)
    {

    case 0:
        return printf("\nMês mais frio: Janeiro (%d°C)", medmes[menor]);
        break;
    case 1:
        return printf("\nMês mais frio: Fevereiro (%d°C)", medmes[menor]);
        break;
    case 2:
        return printf("\nMês mais frio: Março (%d°C)", medmes[menor]);
        break;
    case 3:
        return printf("\nMês mais frio: Abril (%d°C)", medmes[menor]);
        break;
    case 4:
        return printf("\nMês mais frio: Maio (%d°C)", medmes[menor]);
        break;
    case 5:
        return printf("\nMês mais frio: Junho (%d°C)", medmes[menor]);
        break;
    case 6:
        return printf("\nMês mais frio: Julho (%d°C)", medmes[menor]);
        break;
    case 7:
        return printf("\nMês mais frio: Agosto (%d°C)", medmes[menor]);
        break;
    case 8:
        return printf("\nMês mais frio: Setembro (%d°C)", medmes[menor]);
        break;
    case 9:
        return printf("\nMês mais frio: Outubro (%d°C)", medmes[menor]);
        break;
    case 10:
        return printf("\nMês mais frio: Novembro (%d°C)", medmes[menor]);
        break;
    case 11:
        return printf("\nMês mais frio: Dezembro (%d°C)", medmes[menor]);
        break;
    }

    menor = medmes[i];
}

int MaisQuente(int maior)
{

    switch (maior)
    {

    case 0:
        return printf("\nMês mais quente: Janeiro (%d°C)", medmes[maior]);
        break;
    case 1:
        return printf("\nMês mais quente: Fevereiro (%d°C)", medmes[maior]);
        break;
    case 2:
        return printf("\nMês mais quente: Março (%d°C)", medmes[maior]);
        break;
    case 3:
        return printf("\nMês mais quente: Abril (%d°C)", medmes[maior]);
        break;
    case 4:
        return printf("\nMês mais quente: Maio (%d°C)", medmes[maior]);
        break;
    case 5:
        return printf("\nMês mais quente: Junho (%d°C)", medmes[maior]);
        break;
    case 6:
        return printf("\nMês mais quente: Julho (%d°C)", medmes[maior]);
        break;
    case 7:
        return printf("\nMês mais quente: Agosto (%d°C)", medmes[maior]);
        break;
    case 8:
        return printf("\nMês mais quente: Setembro (%d°C)", medmes[maior]);
        break;
    case 9:
        return printf("\nMês mais quente: Outubro (%d°C)", medmes[maior]);
        break;
    case 10:
        return printf("\nMês mais quente: Novembro (%d°C)", medmes[maior]);
        break;
    case 11:
        return printf("\nMês mais quente: Dezembro (%d°C)", medmes[maior]);
        break;
    }

    maior = medmes[i];
}

int main(void)
{

    for (i = 0; i < 12; i++)
    {

        switch (i)
        {

        case 0:
            printf("\nJaneiro: ");
            scanf("%d", &medmes[i]);
            break;
        case 1:
            printf("\nFevereiro: ");
            scanf("%d", &medmes[i]);
            break;
        case 2:
            printf("\nMarço: ");
            scanf("%d", &medmes[i]);
            break;
        case 3:
            printf("\nAbril: ");
            scanf("%d", &medmes[i]);
            break;
        case 4:
            printf("\nMaio: ");
            scanf("%d", &medmes[i]);
            break;
        case 5:
            printf("\nJunho: ");
            scanf("%d", &medmes[i]);
            break;
        case 6:
            printf("\nJulho: ");
            scanf("%d", &medmes[i]);
            break;
        case 7:
            printf("\nAgosto: ");
            scanf("%d", &medmes[i]);
            break;
        case 8:
            printf("\nSetembro: ");
            scanf("%d", &medmes[i]);
            break;
        case 9:
            printf("\nOutubro: ");
            scanf("%d", &medmes[i]);
            break;
        case 10:
            printf("\nNovembro: ");
            scanf("%d", &medmes[i]);
            break;
        case 11:
            printf("\nDezembro: ");
            scanf("%d", &medmes[i]);
            break;
        }

        if (medmes[i] > maior)
        {

            maior = i;
        }
        if (medmes[i] < menor)
        {

            menor = i;
        }

        soma += medmes[i];
    }

    for (i = 0; i < 12; i++)
    {

        switch (i)
        {

        case 0:
            printf("\nJaneiro: %d°C", medmes[i]);
            break;
        case 1:
            printf("\nFevereiro: %d°C", medmes[i]);
            break;
        case 2:
            printf("\nMarço: %d°C", medmes[i]);
            break;
        case 3:
            printf("\nAbril: %d°C", medmes[i]);
            break;
        case 4:
            printf("\nMaio: %d°C", medmes[i]);
            break;
        case 5:
            printf("\nJunho: %d°C", medmes[i]);
            break;
        case 6:
            printf("\nJulho: %d°C", medmes[i]);
            break;
        case 7:
            printf("\nAgosto: %d°C", medmes[i]);
            break;
        case 8:
            printf("\nSetembro: %d°C", medmes[i]);
            break;
        case 9:
            printf("\nOutubro: %d°C", medmes[i]);
            break;
        case 10:
            printf("\nNovembro: %d°C", medmes[i]);
            break;
        case 11:
            printf("\nDezembro: %d°C\n", medmes[i]);
            break;
        }
    }
    MaisFrio(menor);
    MaisQuente(maior);
    TempMed(soma);

    return 0;
}
