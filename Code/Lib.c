#include <stdio.h>
#include <stdlib.h>
#include "Lib.h"

Data criaData(int dia, int mes, int ano){
    Data *data = malloc(sizeof(Data)); 
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    return *data;
}

Paciente  criaPaciente(char *nome, int idade, char *RG){
    Paciente *paciente = malloc(sizeof(Paciente));
    return *paciente;
}