#include <stdio.h>

int main() {
    int num;
    int i;
    int primo = 1; 

    printf("Digite um numero inteiro e positivo: ");
    scanf("%d", &num);


    if (num <= 1) {
        primo = 0; 
    } else {
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                primo = 0; 
                break;
            }
        }
    }


    if (primo != 0){
        printf("É primo.\n");
    }else{
        printf("Não é primo.\n");
    }
    return 0;
}