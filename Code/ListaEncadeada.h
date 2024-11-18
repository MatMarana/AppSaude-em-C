#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED
#include "Lib.h"

typedef struct Celula{
  Paciente *paciente;
  struct Celula *proximo;
}Elista;

typedef struct Lista{
  int quantidade;
  Elista *primeiro;
}Lista;

Elista *criaElista(Paciente *paciente);
Lista *criaLista();
void inserirPaciente(Lista *lista,Paciente *paciente);
Paciente *consultarPaciente(Lista *lista,char *RG);
void atualizarPaciente(Lista *lista,char *RG);
void mostrarLista(Lista *lista);
void removerPaciente(Lista *lista, char *RG);

void salvarArquivo(Lista *lista, const char *nomeArquivo);
Lista lerArquivo(const char *nomeArquivo);


#endif