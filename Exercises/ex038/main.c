#include <stdio.h>

int cont(int v[],int x){

    int result = 0;
    int i = 0;

    for(i = 0; i <= x - 1; i++){

        if(v[i] % 2 == 0){
            result++;
        };

    }

    return result;

}


int main(void){

    int v[] = {1,2,3,4,5,6};
    printf("%d", cont(v,6) );

    return 0;
}