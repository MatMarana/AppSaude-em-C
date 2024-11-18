#include <stdio.h>   
#include <stdlib.h>  
#include <string.h> 
#include "Lib.h"  
#include "ListaEncadeada.h"  
#include "Fila.h" 
#include "ArvoreBin.h" 
#include "Pilha.h"  

// cria uma nova data com dia, mês e ano
Data *criaData(int dia, int mes, int ano){ 
    Data *data = malloc(sizeof(Data));  // aloca memória para a estrutura Data
    data->dia = dia;   // atribui o dia
    data->mes = mes;   // atribui o mês
    data->ano = ano;   // atribui o ano
    return data;  // retorna o ponteiro para a data criada
}

// cria um novo paciente com nome, idade, RG e a data de cadastro
Paciente *criaPaciente(char *nome, int idade, char *RG, int dia, int mes, int ano){ 
    Paciente *paciente = malloc(sizeof(Paciente));  // aloca memória para o paciente
    strcpy(paciente->nome, nome);  // copia o nome para a estrutura
    paciente->idade = idade;  // atribui a idade
    strcpy(paciente->RG, RG);  // copia o RG para a estrutura
    paciente->cadastro = criaData(dia, mes, ano);  // cria a data de cadastro e associa ao paciente
    return paciente;  // retorna o ponteiro para o paciente criado
}
