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


#endif