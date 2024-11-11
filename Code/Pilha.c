#include <stdio.h>
#include <stdlib.h>
#include "Lib.h"
#include "Pilha.h"

Celula *criarCelula(char *operacao){
    Celula *celula = malloc(sizeof(Celula));
    celula->operacao = operacao;
    celula->proximo = NULL;
    return celula;
}

Pilha criarPilha(){
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->quantidade = 0;
    pilha->topo = NULL;
    return *pilha;
}

void push(Pilha *pilha, char *operacao){
    Celula *nova = criarCelula(operacao);
    if(pilha->quantidade == 0){
        pilha->topo = nova;
    } else {
        Celula *atual = pilha->topo;
        pilha->topo = nova;
        nova->proximo = atual;
    }
    pilha->quantidade++;
}

void pop(Pilha *pilha){
    Celula *temp = pilha->topo;
    if(pilha->quantidade == 1){
        pilha->topo = NULL;
    } else {
        pilha->topo = temp->proximo;
    }
    free(temp);
    pilha->quantidade--;
}

void printPilha(Pilha *pilha){
    Celula *atual = pilha->topo;
    Celula *anterior = NULL;
    while(atual->proximo != NULL){
        print(atual);
        anterior = atual;
        atual = atual->proximo;
    }
}