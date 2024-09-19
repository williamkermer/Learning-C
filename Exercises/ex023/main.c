#include <stdio.h>

char conceito(double nota){

  if(nota <= 4.9){

  return 'D';
    
  }else if(nota >= 5 && nota <= 6.9){

    return 'C';
  
  }else if(nota >= 7 && nota <= 8.9){

    return 'B';
  
  }else{

    return 'A';
  }
    
}

int main(void) {
  
  printf("%c", conceito(8.0));
  
  return 0;
}