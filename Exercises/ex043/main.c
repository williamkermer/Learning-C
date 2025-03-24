#include <stdio.h>
#define TAM 3

int verificaQuadradoMagico(int a[TAM][TAM]){

    int resultado3 = 0;
    int resultado4 = 0;


    for(int i = 0; i < TAM; i++){

        int resultado1 = 0;
        int resultado2 = 0;
        

        for(int col = 0; col < TAM; col++){

            resultado1 += a[i][col];
        }

        for(int lin = 0; lin < TAM; lin++){

            resultado2 += a[lin][i];
        }

        if(resultado1 != resultado2)return 0;

        resultado3 += a[i][i];
        resultado4 += a[i][TAM - i - 1];

        if(i == TAM-1){
            if(resultado1 != resultado3)return 0;
            if(resultado1 != resultado4)return 0;
        }
    }

    return 1;

}

int main(void){

    int a[TAM][TAM] = {{8, 0, 7}, {4, 5, 6}, {3, 10, 2}};
    printf("%d", verificaQuadradoMagico(a));

}