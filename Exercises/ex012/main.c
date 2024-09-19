#include <stdio.h>

int main(void) {

  int num, ft, numerotal = 0;
  
  printf("Digite N: ");
  scanf("%d", &num);
  numerotal = num - 1;
  ft = num;


  if(num == 0){
    
    ft = 1;
    
  }else{

    while(numerotal >= 1){

    ft = ft * numerotal;
    numerotal--;
  
  }
    
  }

printf("O fatorial de %d e' %d", num, ft);
  
  return 0;
}