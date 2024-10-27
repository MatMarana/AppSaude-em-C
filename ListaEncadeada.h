#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED
#include "Lib.h"

typedef struct Celula{
  Paciente *paciente;
  struct Celula *proximo;
}Celula;

typedef struct Lista{
  int quantidade;
  Celula *primeiro;
}Lista;

Lista criarlista();
void inserirPaciente(Lista *lista,Paciente *paciente);
int consultarPaciente(Lista *lista,char *RG);
void atualizarPaciente(Lista *lista,char *RG);
void mostrarLista(Lista *lista);
void removerPaciente(Lista *lista, char *RG);

#endif