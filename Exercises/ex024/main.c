#include <stdio.h>

int potencia(int n1, int n2){

  int r = n1;
  
  while(n2 > 1){
    
  r *= n1;
    
  n2--;
    
  }

  return r;

}

int main(void) {
  printf("%d", potencia(10,1));
  return 0;
}