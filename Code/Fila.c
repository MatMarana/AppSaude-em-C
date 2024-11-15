#include <stdio.h>
#include <stdlib.h>
#include "Lib.h"
#include "Fila.h"

Efila *criaEfila(Paciente *paciente){ 
    Efila *celula = malloc(sizeof(Efila));
    celula->paciente = paciente;
    celula->proximo = NULL;
    return celula;
}

Fila *criarFila(){ 
    Fila *fila = malloc(sizeof(Fila));
    fila->head = NULL;
    fila->tail = NULL;
    fila->quantidade = 0;
    return fila;
}

void enfileirarPaciente(Fila *fila,Paciente *paciente){ 
    Efila *nova = criaCelula(paciente);
    if(fila->quantidade = 0){
        fila->head = nova;
        fila->tail = nova;
    } else {
        Efila *atual = fila->tail;
        atual->proximo = nova;
        fila->tail = nova;
    }
    fila->quantidade++;
}

void desenfileirarPaciente(Fila *fila){ 
    Efila *temp = fila->head;
    fila->head = temp->proximo;
    if(fila->quantidade == 1){
        fila->tail = NULL;
    }
    fila->quantidade--;
    free(temp);
}

void mostrarFila(Fila *fila){
    Efila *anterior = NULL;
    Efila *atual = fila->head;
    while(atual->proximo != NULL){
       printf("Paciente encontrado:\n"); 
        printf("Nome: %s\n", atual->paciente->nome); 
        printf("RG: %s\n", atual->paciente->RG); 
        printf("Idade: %d\n", atual->paciente->idade); 
        printf("Data de Registro: %d/%d/%d\n", atual->paciente->cadastro->dia, atual->paciente->cadastro->mes,atual->paciente->cadastro->ano);
        anterior = atual;
        atual = atual->proximo;
    }
    printf("\n");
}