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
        prinf("Erro ao abrir Arquivo");
    }
    Lista *lista = NULL;
    Paciente *paciente;
    while(fread(&paciente, sizeof(Paciente), 1, file)){
        inserirPaciente(&lista, paciente);
    }
    fclose(file);
    return *lista;
}

void menuPaciente(Lista *lista){
    int escolha;

    char nome;
    char RG;
    int idade;
    int dia;
    int mes;
    int ano;

    printf("Qual Acao Deseja Realizar\n");
    printf("1 - Cadastrar um paciente\n");
    printf("2 - Remover um paciente\n");
    printf("3 - Atualizar um paciente\n");
    printf("4 - Consultar um paciente\n");
    printf("5 - Mostar todos pacientes\n");
    scanf('%d', escolha);

    switch(escolha){
    case 1:
        printf("Digite o nome do paciente: \n");
        scanf('%c', nome);
        printf("Digite o RG do paciente: \n");
        scanf('%c', RG);
        printf("Digite a idade do paciente: \n");
        scanf('%d', idade);
        printf("Digite o dia de hoje: \n");
        scanf('%d', dia);
        printf("Digite o mes atual: \n");
        scanf('%d', mes);
        printf("Digite o ano atual: \n");
        scanf('%d', ano);

        Paciente *paciente = criaPaciente(&nome,idade,&RG,dia,mes,ano);
        inserirPaciente(lista, paciente);
        break;
    case 2:
        printf("Digite o RG do paciente que deseja remover\n");
        scanf('%c', &RG);

        removerPaciente(lista, RG);
        break;
    case 3:
        printf("Digite o RG do paciente que deseja atualizar\n");
        scanf('%c', &RG);

        atualizarPaciente(lista, RG);
        break;
    case 4:
        printf("Digite o RG do paciente que deseja consultar\n");
        scanf('%c', &RG);

        consultarPaciente(lista, RG);
        break;
    case 5:
        mostrarLista(lista);
        break;
    }
}