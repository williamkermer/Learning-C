#include <stdio.h>

int ingrediente1, ingrediente2;
int decisao = 0;
/*
morango (1) + cacto (2)= sangue de boi
morango (1) + lavanda (3)= morango chernobyl

cacto (2)+ trigo (4)= pocao detox
cacto (2)+ lavanda (3) = pocao alfafa

trigo (4) + morango (1) = poção breja do brejo
trigo (4)+ lavanda (3)= lavanda vândala
*/
int main(void)
{
    while (decisao != 2)
    {
        printf("\nO que deseja fazer?\nDigite 1 para fazer uma poção\nDigite 2 e "
               "suma!!!!\n");
        scanf("%d", &decisao);
        if (decisao == 2)
        {
            break;
        }
        else if (decisao != 1)
        {
            printf("\nOpção inválida !\n");
            continue;
        }
        printf("\nIngredientes:\n 1 - Moranguin\n 2 - Cactu\n 3 - Lavanda\n 4 - "
               "Trigo\nEscolha o primeiro ingrediente: ");
        scanf("%d", &ingrediente1);

        printf("Escolha o segundo ingrediente: ");
        scanf("%d", &ingrediente2);

        while (ingrediente1 > 4 || ingrediente2 > 4)
        {
            printf("\ningredientes inválidos !\n");
            printf("\nIngredientes:\n 1 - Moranguin\n 2 - Cactu\n 3 - Lavanda\n 4 - "
                   "Trigo\nEscolha o primeiro ingrediente: \n");
            scanf("%d", &ingrediente1);

            printf("Escolha o segundo ingrediente: ");
            scanf("%d", &ingrediente2);
        }
        while (ingrediente1 == ingrediente2)
        {

            printf("\nCombinação inexitente!!\n\n");
            printf("Ingredientes:\n 1 - Moranguin\n 2 - Cactu\n 3 - Lavanda\n 4 - "
                   "Trigo\n Escolha o primeiro ingrediente: ");
            scanf("%d", &ingrediente1);
            printf("Escolha o segundo ingrediente: ");
            scanf("%d", &ingrediente2);
        }

        if ((ingrediente1 == 1 && ingrediente2 == 2) ||
            (ingrediente1 == 2 && ingrediente2 == 1))
        {
            printf("Você fez a poção Sangue de boi!!\n");
        }
        if ((ingrediente1 == 1 && ingrediente2 == 3) ||
            (ingrediente1 == 3 && ingrediente2 == 1))
        {
            printf("Você fez um Morango de Chernobyl!!\n");
        }
        if ((ingrediente1 == 1 && ingrediente2 == 4) ||
            (ingrediente1 == 4 && ingrediente2 == 1))
        {
            printf("Você fez a poção Breja do brejo!!\n");
        }
        if ((ingrediente1 == 2 && ingrediente2 == 3) ||
            (ingrediente1 == 3 && ingrediente2 == 2))
        {
            printf("Você fez a poção Alfafa!!\n");
        }
        if ((ingrediente1 == 2 && ingrediente2 == 4) ||
            (ingrediente1 == 4 && ingrediente2 == 2))
        {
            printf("Você fez a poção Detox!!\n");
        }
        if ((ingrediente1 == 3 && ingrediente2 == 4) ||
            (ingrediente1 == 4 && ingrediente2 == 3))
        {
            printf("Você fez um Morango de Chernobyl!!\n");
        }
    }

    return 0;
}