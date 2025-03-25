#include <stdio.h>

struct Horario {
    int hora;
    int minuto;
    int segundo;
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Compromisso {
    struct Data data;
    struct Horario horario;
    char descricao[51];
};
