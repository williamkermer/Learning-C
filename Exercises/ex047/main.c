#include <stdio.h>
#include <string.h>

struct AlunosLetras{

    char nome[51];
    int matricula;
    float p1;
    float p2;
    float p3;
    float media;
    char situacao[51];

};

int main(void){

    struct AlunosLetras a[5];

    for(int i = 0;i < 5; i++){

        printf("Qual o nome?");
        scanf("%[^\n]s", a[i].nome);
        printf("Qual a matricula?");
        scanf("%d", &a[i].matricula);
        printf("Qual a nota da primeira prova?");
        scanf("%f", &a[i].p1);
        printf("Qual a nota da segunda prova?");
        scanf("%f", &a[i].p2);
        printf("Qual a nota da terceira prova?");
        scanf("%f", &a[i].p3);
        printf("\n");

        a[i].media = (a[i].p1+a[i].p2+a[i].p3)/3;


        if(a[i].media > 6){

            strcpy(a[i].situacao, "Aprovado");
            printf("%s\n", a[i].situacao);

        }else{
            strcpy(a[i].situacao, "Reprovado");
            printf("%s\n", a[i].situacao);
        }
    }

    int comp = 0;
    char alunop1[51];
    char alunoMaiorM[51];
    char alunoMenorM[51];

    for(int i = 0;i < 5; i++){

        if(a[i].p1 > comp){
            comp = a[i].p1;
            strcpy(alunop1, a[i].nome);
        }
    }
    comp = 0;

    for(int i = 0;i < 5; i++){

        if(a[i].media > comp){ 
            comp = a[i].media;
            strcpy(alunoMaiorM, a[i].nome);
        }
    }
    comp = 999;

    for(int i = 0;i < 5; i++){

        if(a[i].media < comp){
            comp = a[i].media;
            strcpy(alunoMenorM, a[i].nome);
        }
    }

    printf("Maior nota p1: %s\nMaior nota média: %s\nMenor nota média: %s", alunop1, alunoMaiorM, alunoMenorM);

}