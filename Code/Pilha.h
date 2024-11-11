#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "Lib.h"

typedef struct Celula{
    char operacao;
    struct Celula *proximo;
}Celula;

typedef struct Pilha{
    int quantidade;
    Celula *topo;
}Pilha;

Celula *criarCelula(char *operacao);
Pilha criarPilha();
void push(Pilha *pilha, char *operacao);
void pop(Pilha *pilha);
void printPilha(Pilha *pilha);

#endif