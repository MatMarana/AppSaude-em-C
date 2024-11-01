#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "Lib.h"

typedef struct Celula{
  Paciente *paciente;
  struct Celula *proximo;
} Celula;

typedef struct Fila{
  Celula *head;
  Celula *tail;
  int quantidade;
}Fila;

Fila criarFila();
void enfileirarPaciente(Fila *fila,Paciente *paciente);
void desenfileirarPaciente(Fila *fila);
void mostrarFila(Fila *fila);

#endif