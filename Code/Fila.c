#include <stdio.h>
#include <stdlib.h>
#include "Lib.h"
#include "Fila.h"

Celula *criaCelula(Paciente *paciente){
    Celula *celula = malloc(sizeof(Celula));
    celula->paciente = paciente;
    celula->proximo = NULL;
    return celula;
}

Fila criarFila(){
    Fila *fila = malloc(sizeof(Fila));
    fila->head = NULL;
    fila->tail = NULL;
    fila->quantidade = 0;
    return *fila;
}

void enfileirarPaciente(Fila *fila,Paciente *paciente){
    Celula *nova = criaCelula(paciente);
    if(fila->quantidade = 0){
        fila->head = nova;
        fila->tail = nova;
    } else {
        Celula *atual = fila->tail;
        atual->proximo = nova;
        fila->tail = nova;
    }
    fila->quantidade++;
}

void desenfileirarPaciente(Fila *fila){
    Celula *temp = fila->head;
    fila->head = temp->proximo;
    if(fila->quantidade == 1){
        fila->tail = NULL;
    }
    fila->quantidade--;
    free(temp);
}

void mostrarFila(Fila *fila){
    Celula *anterior = NULL;
    Celula *atual = fila->head;
    while(atual->proximo != NULL){
        printf(atual);
        anterior = atual;
        atual = atual->proximo;
    }
    printf("\n");
}