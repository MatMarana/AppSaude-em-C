#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "Lib.h"

typedef struct EPilha{
    char operacao;
    struct EPilha *proximo;
    Paciente *paciente;
}EPilha;

typedef struct Pilha{
    int quantidade;
    EPilha *topo;
}Pilha;

EPilha *criarEPilha(char *operacao, Paciente *paciente);
Pilha *criarPilha();
void push(Pilha *pilha, char *operacao,Paciente *paciente);
EPilha *pop(Pilha *pilha);
void printPilha(Pilha *pilha);

#endif