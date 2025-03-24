#include <stdio.h>

int segundoMaior(int v[], int n){

    int maior = 0;
    int seg = 0;

    for(int i = 0; i < n; i++){


        if(v[i] > maior){

            seg = maior;   
            maior = v[i];
        }

        if(seg < maior && seg < v[i] && v[i] != maior) seg = v[i];

    }

    return seg;
}
