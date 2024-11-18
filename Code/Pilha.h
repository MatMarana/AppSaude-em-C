#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "Lib.h"

typedef struct EPilha{
    int verificaAcao;
    struct EPilha *proximo;
    Paciente *paciente;
}EPilha;

typedef struct Pilha{
    int quantidade;
    EPilha *topo;
}Pilha;

EPilha *criarEPilha(int verificaAcao, Paciente *paciente);
Pilha *criarPilha();
void push(Pilha *pilha, int verificaAcao,Paciente *paciente);
void pop(Pilha *pilha);
void printPilha(Pilha *pilha);

#endif