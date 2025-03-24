#include <string.h>

int verificarPalindromo(char palavra[]){

    int TAM = strlen(palavra);
    int i2 = TAM - 1;

    for(int i = 0; i < TAM; i++){

        if(palavra[i] != palavra[i2]){

            return 0;
            

        }

        i2--;
    }

    return 1;
}

int main(void){

    char palavra[] = {"macaco"};

    verificarPalindromo(palavra);

}