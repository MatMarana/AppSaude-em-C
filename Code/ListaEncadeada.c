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
    lista->quantidade++;
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
        anterior = atual;
        atual = atual->proximo;
        i++;
    }
    return 0;
}

void atualizarPaciente(Lista *lista,char *RG){
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;
    while(atual->proximo != NULL && atual->paciente->RG != RG){
        anterior = atual;
        atual = atual->proximo;
    }
    if(atual != NULL){
        printf("Digite qual informacao deseja atualizar\n");
    }
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

void removerPaciente(Lista *lista, char *RG){
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;
    while(atual->proximo != NULL && atual->paciente->RG != RG){
       anterior = atual;
       atual = atual->proximo;
    }
    if(atual != NULL){
        if(anterior == NULL){
            lista->primeiro = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }
        lista->quantidade--;
    }
}