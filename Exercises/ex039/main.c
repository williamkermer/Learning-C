#include <stdio.h>

int main(void){

    float total = 0;
    float num[5];

    for(int i= 0; i <= 4; i++){

        printf("Digite o elemento:\n");
        scanf("%f", &num[i]);

        total += num[i];
    }

    float media = total/5;

    for(int i= 0; i <= 4; i++){

        if(num[i] > media){

            if ((int)num[i] == num[i]) {
                printf("%d ", (int)num[i]); // Exibe como inteiro se não tiver parte decimal
            } else {
                printf("%.1f ", num[i]); // Exibe com uma casa decimal
            }

        }

    }

    return 0;
}