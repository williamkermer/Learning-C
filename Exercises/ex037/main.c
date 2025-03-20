#include <stdio.h>
#include <string.h>

int main(void){

    char vet[] = "algoritmos";

    int i = 0;

    while(vet[i] != 0){

        i++;

    };

    printf("%d", i);

    printf("%d", strlen(vet));

    return 0;
}