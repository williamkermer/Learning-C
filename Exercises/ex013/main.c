#include <stdio.h>

int main(void) {
    int fahrenheit, celsius;

    while (1) {
        printf("Graus F: ");
        scanf("%d", &fahrenheit);

        if (fahrenheit < -459.67) {
            break;
        }

        celsius = (fahrenheit - 32) * 5 / 9;
        printf("%d", celsius);
    }

    return 0;
}