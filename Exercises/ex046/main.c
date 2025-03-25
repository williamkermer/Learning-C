#include <stdio.h>

struct Aluno{

    char nome[51];
    int matricula;
    char curso[51];

};

int main(void){

    struct Aluno a[5];

    for(int i = 0;i < 5; i++){
    
        printf("Qual o nome?");
        scanf(" %[^\n]s", a[i].nome);
        printf("Qual a matricula?");
        scanf("%d", &a[i].matricula);
        printf("Qual o curso?");
        scanf(" %[^\n]s", a[i].curso);
        printf("\n");
    
    }

    for(int i = 0;i < 5; i++){
        printf("%s tem a matricula numero %d e estuda %s\n", a[i].nome, a[i].matricula, a[i].curso);
    }

}