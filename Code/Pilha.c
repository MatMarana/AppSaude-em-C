#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lib.h"
#include "Pilha.h"

EPilha *criarEPilha(char *operacao, Paciente *paciente){
    EPilha *celula = malloc(sizeof(EPilha));
    printf("B");
    strcpy(&celula->operacao,operacao);
    printf("C");
    celula->paciente = paciente;
    printf("D");
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
    EPilha *nova = criarEPilha(operacao,paciente);
    if(pilha->quantidade == 0){
        pilha->topo = nova;
    } else {
        EPilha *atual = pilha->topo;
        pilha->topo = nova;
        nova->proximo = atual;
    }
    pilha->quantidade++;
}

EPilha *pop(Pilha *pilha){
    EPilha *temp = pilha->topo;
    if(pilha->quantidade == 1){
        pilha->topo = NULL;
    } else {
        pilha->topo = temp->proximo;
    }
    free(temp);
    pilha->quantidade--;
    return temp;
}

void printPilha(Pilha *pilha){
    EPilha *atual = pilha->topo;
    while(atual->proximo != NULL){
        printf("%s",&atual->operacao);
        atual = atual->proximo;
    }
}
