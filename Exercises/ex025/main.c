#include <stdio.h>

  int idadeEmDias(int n1, int n2, int n3){
  int res = 0;

    if(n2 > 12 || n3 > 30){
    
      return -1;
    }
      
    res = (n1*365) + (n2*30) + n3;
    
    return res;
    
  }

int main(void) {
  printf("%d", idadeEmDias(10, 10, 10));
  return 0;
}