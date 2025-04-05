#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        printf("Passe mais de uma palavra\n");
        return 0;
    }

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], argv[i - 1]) < 0) {
            printf("Nao\n");
            return 0;
        }
    }

    printf("Sim\n");
    return 0;
}