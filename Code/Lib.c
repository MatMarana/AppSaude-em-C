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







