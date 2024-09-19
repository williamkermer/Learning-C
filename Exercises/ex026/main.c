#include <stdio.h>

int fatorial(int n){

  int r = n;
  if(n == 0){

  return 1; 
  }
  
  n--;
  while(n > 0){

  r *= n;
    n--;
  }
  
  return r;
}

int main(void) {
  printf("%d\n", fatorial(0));
  return 0;
}