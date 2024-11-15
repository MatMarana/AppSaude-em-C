#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lib.h"
#include "ListaEncadeada.h"
#include "Fila.h"
#include "ArvoreBin.h"
#include "Pilha.h"

Data *criaData(int dia, int mes, int ano){ 
    Data *data = malloc(sizeof(Data)); 
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    return data;
}

Paciente  *criaPaciente(char *nome, int idade, char *RG, int dia, int mes, int ano){ 
    Paciente *paciente = malloc(sizeof(Paciente));
    strcpy(paciente->nome, nome);
    paciente->idade = idade;
    strcpy(paciente->RG, RG);
    paciente->cadastro = criaData(dia,mes,ano);
    return paciente;
}

void salvarArquivo(Lista *lista, const char *nomeArquivo){ 
    FILE *file = fopen(nomeArquivo, "wb");
    if(!file){
        printf("Erro de criacao de Arquivo");
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
        printf("Erro ao abrir Arquivo");
    }
    Lista *lista = NULL;
    Paciente *paciente;
    while(fread(&paciente, sizeof(Paciente), 1, file)){
        inserirPaciente(&lista, paciente);
    }
    fclose(file);
    return *lista;
}





