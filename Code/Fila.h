#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "Lib.h"

typedef struct Efila{
  Paciente *paciente;
  struct Efila *proximo;
} Efila;

typedef struct Fila{
  Efila *head;
  Efila *tail;
  int quantidade;
}Fila;

Efila *criaEfila(Paciente *paciente);
Fila *criarFila();
void enfileirarPaciente(Fila *fila,Paciente *paciente);
void desenfileirarPaciente(Fila *fila);
void mostrarFila(Fila *fila);

#endif