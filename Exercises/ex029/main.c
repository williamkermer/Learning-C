#include <stdio.h>

int a,b,c = 0;

int fibonacci(int n)
{
printf("Digite o valor de a: ");
scanf("%lf", &a);

printf("Digite o valor de b: ");
scanf("%lf", &b);

printf("Digite o valor de c: ");
scanf("%lf", &c);

if(a + b > c && a+c > b && b+c >a){

printf("Pode ser um triangulo");

}else{

printf("Nao pode ser um triangulo");

}
    return 0;
}