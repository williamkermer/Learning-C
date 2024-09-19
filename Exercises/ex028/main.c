#include <stdio.h>

int fibonacci(int n)
{

    int val = 1;
    int c = val;

    while (n > 2)
    {

        val += c;

        c = val - c;
        n--;
    }

    return val;
}

int main(void)
{
    printf("%d", fibonacci(7));
    return 0;
}