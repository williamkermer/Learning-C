#include <stdio.h>

struct Pessoa{

    char nome[51];
    int idade;
    char endereco[51];

};

int main(void){

    struct Pessoa p1;

    printf("Qual o nome?");
    scanf(" %[^\n]s", p1.nome);
    printf("Qual a idade?");
    scanf("%d", &p1.idade);
    printf("Qual o endereço?");
    scanf(" %[^\n]s", p1.endereco);


    printf("O %s tem %d anos e mora na: %s", p1.nome, p1.idade, p1.endereco);
}