#include <stdio.h>

int fibonacci(int n)
{
int v[20];
    int i;

    for(i = 0; i < 20; i++){

      if(v[i] < 0){

      v[i] = 0;

      }
       printf("\n%d", v[i]);
    }
    return 0;
}
