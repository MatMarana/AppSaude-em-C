#include <stdio.h>
#include <stdlib.h>

#include "Lib.h"
#include "ListaEncadeada.h"

Elista *criaElista(Paciente *paciente){
    Elista *celula = malloc(sizeof(Elista));
    celula->paciente = paciente;
    celula->proximo = NULL;
    return celula;
}

Lista *criaLista(){
    Lista *lista = malloc(sizeof(Lista));
    lista->quantidade = 0;
    lista->primeiro = NULL;
    return lista;
}

void inserirPaciente(Lista *lista,Paciente *paciente){
    Elista *nova = criaCelula(paciente);
    if(lista->quantidade == 0){
        lista->primeiro = nova;
    } else {
        Elista *atual = lista->primeiro;
        lista->primeiro = nova;
        nova->proximo = atual;
    }
    lista->quantidade++;
}

Paciente *consultarPaciente(Lista *lista,char *RG){ // arrumar
    Elista *anterior = NULL;
    Elista *atual = lista->primeiro;
    while(atual->proximo != NULL){
        if(strcmp(atual->paciente->RG, RG) == 0){
            printf("Paciente encontrado:\n"); 
            printf("Nome: %s\n", atual->paciente->nome); 
            printf("RG: %s\n", atual->paciente->RG); 
            printf("Idade: %d\n", atual->paciente->idade); 
            printf("Data de Registro: %d/%d/%d\n", atual->paciente->cadastro->dia, atual->paciente->cadastro->mes,atual->paciente->cadastro->ano);
            return atual->paciente;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return NULL;
}

void atualizarPaciente(Lista *lista,char *RG){
    Elista *anterior = NULL;
    Elista *atual = lista->primeiro;
    while(atual->proximo != NULL && (strcmp(atual->paciente->RG, RG) == 0)){
        anterior = atual;
        atual = atual->proximo;
    }
    if(atual != NULL){
       int escolha; 
       printf("Digite o número da informação que deseja atualizar:\n"); 
       printf("1 - Nome\n"); printf("2 - RG\n"); printf("3 - Idade\n"); 
       printf("4 - Data de Registro\n"); 
       scanf("%d", &escolha); 
       switch (escolha) { 
            case 1: 
                printf("Digite o novo nome: "); 
                scanf("%s", atual->paciente->nome); 
                break;
            case 2: 
                printf("Digite o novo RG: "); 
                scanf("%s", atual->paciente->RG); 
                break; 
            case 3: 
                printf("Digite a nova idade: "); 
                scanf("%d", &atual->paciente->idade); 
                break; 
            case 4: 
                printf("Digite o novo dia de registro: "); 
                scanf("%d", &atual->paciente->cadastro->dia); 
                printf("Digite o novo mês de registro: "); 
                scanf("%d", &atual->paciente->cadastro->mes); 
                printf("Digite o novo ano de registro: "); 
                scanf("%d", &atual->paciente->cadastro->ano); 
                break; 
        } 
       printf("Informações do paciente atualizadas com sucesso.\n");
    }
}

void mostrarLista(Lista *lista){
    Elista *anterior = NULL;
    Elista *atual = lista->primeiro;
    if(lista->quantidade == 0){
        printf("Nao ha elementos na lista\n");
    } else {
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
}

void removerPaciente(Lista *lista, char *RG){
    Elista *anterior = NULL;
    Elista *atual = lista->primeiro;
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