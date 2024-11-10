#include <stdio.h>
#include <stdlib.h>
#include "Lib.h"
#include "ListaEncadeada.h"

Celula *criaCelula(Paciente *paciente){
    Celula *celula = malloc(sizeof(Celula));
    celula->paciente = paciente;
    celula->proximo = NULL;
    return celula;
}

Lista criaLista(){
    Lista *lista = malloc(sizeof(Lista));
    lista->quantidade = 0;
    lista->primeiro = NULL;
    return *lista;
}

void inserirPaciente(Lista *lista,Paciente *paciente){
    Celula *nova = criaCelula(paciente);
    if(lista->quantidade == 0){
        lista->primeiro = nova;
    } else {
        Celula *atual = lista->primeiro;
        lista->primeiro = nova;
        nova->proximo = atual;
    }
}

int consultarPaciente(Lista *lista,char *RG){
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;
    int i;
    while(atual->proximo != NULL){
        if(atual->paciente->RG == RG){
            printf(atual->paciente);
            return i;
        }
        i++;
    }
    return 0;
}

void mostrarLista(Lista *lista){
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;
    if(lista->quantidade == 0){
        printf("Nao ha elementos na lista\n");
    } else {
        while(atual->proximo != NULL){
            anterior = atual;
            atual = atual->proximo;
            printf(atual);
        }
        printf("\n");
    }
}