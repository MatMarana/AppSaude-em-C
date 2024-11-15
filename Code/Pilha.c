#include <stdio.h>
#include <stdlib.h>
#include "Lib.h"
#include "Pilha.h"

EPilha *criarCelula(char *operacao, Paciente *paciente){
    EPilha *celula = malloc(sizeof(EPilha));
    celula->operacao = operacao;
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

void push(Pilha *pilha, char *operacao, Paciente *paciente){
    EPilha *nova = criarCelula(operacao,paciente);
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
    EPilha *anterior = NULL;
    while(atual->proximo != NULL){
        print(atual);
        anterior = atual;
        atual = atual->proximo;
    }
}
