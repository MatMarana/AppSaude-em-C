#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Elista *nova = criaElista(paciente);
    if(lista->quantidade == 0){
        lista->primeiro = nova;
    } else {
        Elista *atual = lista->primeiro;
        lista->primeiro = nova;
        nova->proximo = atual;
    }
    lista->quantidade++;
}

Paciente *consultarPaciente(Lista *lista,char *RG){ 
    Elista *atual = lista->primeiro;
    while(atual != NULL){
        if(strcmp(atual->paciente->RG, RG) == 0){
            printf("Paciente encontrado:\n"); 
            printf("Nome: %s\n", atual->paciente->nome); 
            printf("RG: %s\n", atual->paciente->RG); 
            printf("Idade: %d\n", atual->paciente->idade); 
            printf("Data de Registro: %d/%d/%d\n", atual->paciente->cadastro->dia, atual->paciente->cadastro->mes,atual->paciente->cadastro->ano);
            return atual->paciente;
            break;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void atualizarPaciente(Lista *lista,char *RG){
    Elista *atual = lista->primeiro;
    while(atual->proximo!= NULL && (strcmp(atual->paciente->RG, RG) == 0)){
        atual = atual->proximo;
    }
    if(atual != NULL){
       int escolha; 
       printf("Digite o numero da informacao que deseja atualizar:\n"); 
       printf("1 - Nome\n"); 
       printf("2 - RG\n"); 
       printf("3 - Idade\n"); 
       printf("4 - Data de Registro\n"); 
       scanf("%d", &escolha); 
       switch (escolha) { 
            case 1: 
                printf("Digite o novo nome: \n"); 
                scanf("%s", atual->paciente->nome); 
                break;
            case 2: 
                printf("Digite o novo RG: \n"); 
                scanf("%s", atual->paciente->RG); 
                break; 
            case 3: 
                printf("Digite a nova idade: \n"); 
                scanf("%d", &atual->paciente->idade); 
                break; 
            case 4: 
                printf("Digite o novo dia de registro: \n"); 
                scanf("%d", &atual->paciente->cadastro->dia); 
                printf("Digite o novo mês de registro: \n"); 
                scanf("%d", &atual->paciente->cadastro->mes); 
                printf("Digite o novo ano de registro: \n"); 
                scanf("%d", &atual->paciente->cadastro->ano); 
                break; 
        } 
       printf("Informacoes do paciente atualizadas com sucesso.\n");
    }
}

void mostrarLista(Lista *lista){
    Elista *atual = lista->primeiro;
    if(lista->quantidade == 0){
        printf("Nao ha elementos na lista\n");
    } else {
        while(atual != NULL){
            printf("Nome: %s\n", atual->paciente->nome); 
            printf("RG: %s\n", atual->paciente->RG); 
            printf("Idade: %d\n", atual->paciente->idade); 
            printf("Data de Registro: %d/%d/%d\n", atual->paciente->cadastro->dia, atual->paciente->cadastro->mes,atual->paciente->cadastro->ano);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

void removerPaciente(Lista *lista, char *RG){
    Elista *anterior = NULL;
    Elista *atual = lista->primeiro;
    while(atual->proximo != NULL && strcmp(atual->paciente->RG, RG) == 0){
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

void salvarArquivo(Lista *lista, const char *nomeArquivo){ 
    FILE *file = fopen(nomeArquivo, "wb");
    if(!file){
        printf("Erro de criacao de Arquivo\n");
        return;   
    }
    Elista *temp = lista->primeiro;
    while(temp->proximo != NULL){
        fwrite(&temp->paciente,sizeof(Paciente),1,file);
    }
    fclose(file);
}

Lista lerArquivo(const char *nomeArquivo){ 
    FILE *file = fopen(nomeArquivo, "rb");
    if(!file){
        printf("Erro ao abrir Arquivo\n");
    }
    Lista *lista = NULL;
    Paciente *paciente;
    while(fread(&paciente, sizeof(Paciente), 1, file)){
        inserirPaciente(lista, paciente);
    }
    fclose(file);
    return *lista;
}