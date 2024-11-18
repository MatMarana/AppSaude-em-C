#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lib.h"
#include "Pilha.h"

EPilha *criarEPilha(int verificaAcao, Paciente *paciente){
    EPilha *celula = malloc(sizeof(EPilha));
    celula->verificaAcao = verificaAcao;
    celula->paciente = paciente;
    celula->proximo = NULL;
    return celula;
}

Pilha *criarPilha(){
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->quantidade = 0;
    pilha->topo = NULL;
    return pilha;
}

void push(Pilha *pilha,  int verificaAcao, Paciente *paciente){
    EPilha *nova = criarEPilha(verificaAcao,paciente);
    if(pilha->quantidade == 0){
        pilha->topo = nova;
    } else {
        EPilha *atual = pilha->topo;
        pilha->topo = nova;
        nova->proximo = atual;
    }
    pilha->quantidade++;
}

void pop(Pilha *pilha){
    EPilha *temp = pilha->topo;
    if(pilha->quantidade == 1){
        pilha->topo = NULL;
    } else {
        pilha->topo = temp->proximo;
    }
    free(temp);
    pilha->quantidade--;
}

void printPilha(Pilha *pilha){
    EPilha *atual = pilha->topo;
    while(atual->proximo != NULL){
        printf("%d",&atual->verificaAcao);
        atual = atual->proximo;
    }
}
