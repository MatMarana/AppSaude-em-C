#ifndef ARVOREBIN_H_INCLUDED
#define ARVOREBIN_H_INCLUDED
#include "Lib.h"

typedef struct EArvore{
    struct EArvore *esquerdo;
    struct EArvore *direito;
    Paciente *paciente;
}EArvore;

typedef struct ArvoreBin{
    EArvore *raiz;
    int altura;
    int quantidade;
} Arvore;

EArvore *criaEArvore(Paciente *paciente);
Arvore *criaArvore();
void visitarEArvore(EArvore *celula);
void mostrarEmOrdem(EArvore *raiz);
EArvore *balanceamento(Arvore *arvore, Paciente *paciente, int tipoArvore);
void inserirNaArvore(Arvore *arvore, Paciente *paciente, int tipoArvore);

#endif