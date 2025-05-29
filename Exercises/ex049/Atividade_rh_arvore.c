#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct T_no T_no;
struct T_no {
    int CPF;
    char Nome[50];
    T_no *esq, *dir;
};

T_no *arvoreCPF = NULL;

T_no* criar_no(int cpf, char nome[]) {
    T_no *novo = malloc(sizeof(T_no));
    novo->CPF = cpf;
    strcpy(novo->Nome, nome);
    novo->esq = novo->dir = NULL;
    return novo;
}

T_no* buscar(T_no *raiz, int cpf) {
    if (!raiz || raiz->CPF == cpf)
        return raiz;
    return cpf < raiz->CPF ? buscar(raiz->esq, cpf) : buscar(raiz->dir, cpf);
}

T_no* inserir(T_no *raiz, int cpf, char nome[], int *sucesso) {
    if (!raiz) {
        *sucesso = 1;
        return criar_no(cpf, nome);
    }
    if (cpf < raiz->CPF)
        raiz->esq = inserir(raiz->esq, cpf, nome, sucesso);
    else if (cpf > raiz->CPF)
        raiz->dir = inserir(raiz->dir, cpf, nome, sucesso);
    return raiz;
}

T_no* menor_valor(T_no *no) {
    while (no && no->esq)
        no = no->esq;
    return no;
}

T_no* remover(T_no *raiz, int cpf, int *sucesso, char nomeRemovido[]) {
    if (!raiz) return NULL;
    if (cpf < raiz->CPF)
        raiz->esq = remover(raiz->esq, cpf, sucesso, nomeRemovido);
    else if (cpf > raiz->CPF)
        raiz->dir = remover(raiz->dir, cpf, sucesso, nomeRemovido);
    else {
        *sucesso = 1;
        strcpy(nomeRemovido, raiz->Nome);
        if (!raiz->esq || !raiz->dir) {
            T_no *temp = raiz->esq ? raiz->esq : raiz->dir;
            free(raiz);
            return temp;
        }
        T_no *sucessor = menor_valor(raiz->dir);
        raiz->CPF = sucessor->CPF;
        strcpy(raiz->Nome, sucessor->Nome);
        raiz->dir = remover(raiz->dir, sucessor->CPF, sucesso, nomeRemovido);
    }
    return raiz;
}

void listar(T_no *raiz) {
    if (raiz) {
        listar(raiz->esq);
        printf("%s %d\n", raiz->Nome, raiz->CPF);
        listar(raiz->dir);
    }
}

void liberar(T_no *raiz) {
    if (raiz) {
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}

void processar(char *linha) {
    if (linha[0] == 'i') {
        char nome[50];
        int cpf;
        char *sep = strchr(linha + 2, ';');
        if (sep) {
            *sep = '\0';
            strcpy(nome, linha + 2);
            cpf = atoi(sep + 1);
            if (buscar(arvoreCPF, cpf)) {
                printf("CPF %d já cadastrado\n", cpf);
            } else {
                int sucesso = 0;
                arvoreCPF = inserir(arvoreCPF, cpf, nome, &sucesso);
                if (sucesso)
                    printf("Inseriu %s\n", nome);
            }
        }
    } else if (linha[0] == 'r') {
        int cpf = atoi(linha + 2), sucesso = 0;
        char nomeRemovido[50];
        arvoreCPF = remover(arvoreCPF, cpf, &sucesso, nomeRemovido);
        if (sucesso)
            printf("Removeu %s %d\n", nomeRemovido, cpf);
        else
            printf("CPF %d não encontrado\n", cpf);
    } else if (linha[0] == 'b') {
        int cpf = atoi(linha + 2);
        T_no *encontrado = buscar(arvoreCPF, cpf);
        if (encontrado)
            printf("Encontrou: %s %d\n", encontrado->Nome, encontrado->CPF);
        else
            printf("CPF %d não localizado\n", cpf);
    } else if (linha[0] == 'l') {
        listar(arvoreCPF);
    } else if (linha[0] == 's') {
        liberar(arvoreCPF);
        exit(0);
    } else {
        printf("Comando inválido\n");
    }
}