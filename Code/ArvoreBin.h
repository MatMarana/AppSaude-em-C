#ifndef ARVOREBIN_H_INCLUDED
#define ARVOREBIN_H_INCLUDED
#include "Lib.h"

typedef struct Celula{
    struct Celula *esquerdo;
    struct Celula *direito;
    Paciente *paciente;
} Celula;

typedef struct ArvoreBin{
    Celula *raiz;
    int altura;
    int quantidade;
} Arvore;

Arvore *iniciaArvore();
Celula *iniciaCelula();
Celula *buscarValor(Arvore arvore, Data *data);
Celula *encontraPosicao(Arvore arvore, Paciente *paciente);
int verificaFolha(Celula *vertice);
int doisFilhos(Celula *vertice);
void visitaValor(Celula *raiz);
void inOrdem(Celula *raiz);
void preOrdem(Celula *raiz);
void posOrdem(Celula *raiz);
void liberarArvore(Celula *raiz);
void inserirElemento(Arvore *arvore, Paciente *paciente);
void removerVertice(Arvore *arvore, Celula *vertice);

#endif