#include <stdio.h>
int sistema;
int animal, qtdanimal;
double peso, peso0, pesado, leve = 1555555;
int idade, maisvelho, maisnovo = 1555555, idade0 = 0;
double mediapeso, mediaidade;

int main(void)
{
    do
    {
        printf("Olá! O que deseja fazer?\n 1. Ver a quantidade de animais.\n 2. "
               "inserir algum animal.\n 3. Exibir relatório.\n 4. Sair do sistema.\n");
        scanf("%d", &sistema);

        if (sistema == 1)
        {
            printf("Existem %d animais registrados\n", qtdanimal);
        }
        else if (sistema == 2)
        {
            printf("Qual o peso do animal?\n");
            scanf("%lf", &peso0);
            if (peso0 > pesado)
            {
                pesado = peso0;
            }
            if (peso0 < leve)
            {
                leve = peso0;
            }
            printf("Qual a idade do animal?\n");
            scanf("%d", &idade0);
            if (idade0 > maisvelho)
            {
                maisvelho = idade0;
            }
            if (idade0 < maisnovo)
            {
                maisnovo = idade0;
            }

            qtdanimal++;
            peso += peso0;
            idade += idade0;
            mediapeso = peso / qtdanimal;
            mediaidade = idade / qtdanimal;
        }
        else if (sistema == 3)
        {

            printf("O animal mais leve tem: %lf\n", leve);
            printf("O animal mais pesado tem: %lf\n", pesado);
            printf("A média do peso deles é: %g\n", mediapeso);
            printf("O animal mais novo tem: %d\n", maisnovo);
            printf(" O animal mais velho tem: %d\n", maisvelho);
            printf("A média da idade deles é: %g\n\n", mediaidade);

            mediapeso = peso / qtdanimal;
            mediaidade = idade / qtdanimal;
        }
    } while (sistema != 4);

    printf("Saiu.");

    return 0;
}