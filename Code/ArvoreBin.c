#include  <stdio.h>
#include <stdlib.h>
#include "ArvoreBin.h"
#include "Lib.h"

EArvore *criaEArvore(Paciente *paciente){
    EArvore *celula = malloc(sizeof(EArvore));
    celula->paciente = paciente;
    celula->direito = NULL;
    celula->esquerdo = NULL;

    return celula;
}

Arvore *criaArvore(){
    Arvore *arvore = malloc(sizeof(Arvore));
    arvore->altura = 0;
    arvore->quantidade = 0;
    arvore->raiz = NULL;

    return arvore;
}

void visitarEArvore(EArvore *celula){
    if(celula != NULL){
        Paciente *paciente = celula->paciente;
        printf("Nome: %s, Idade: %d, RG: %s, Data de Cadastro: %02d/%02d/%d\n",
               paciente->nome, paciente->idade,paciente->RG, 
               paciente->cadastro->dia, paciente->cadastro->mes, paciente->cadastro->ano);
    }
}

void mostrarEmOrdem(EArvore *raiz){
     if (raiz != NULL) {
        mostrarEmOrdem(raiz->esquerdo);
        visitarEArvore(raiz);
        mostrarEmOrdem(raiz->direito);
    }
}

EArvore *balanceamento(Arvore *arvore, Paciente *paciente, int tipoArvore){
    EArvore *anterior = NULL;
    EArvore *atual = arvore->raiz;

    while(atual != NULL){
        if(tipoArvore == 1){
            if(paciente->idade <= atual->paciente->idade){
                anterior = atual;
                atual = atual->esquerdo;
            } else {
                anterior = atual;
                atual = atual->direito;
            }
        } else if(tipoArvore == 2){
            if(paciente->cadastro->dia <= atual->paciente->cadastro->dia){
                anterior = atual;
                atual = atual->esquerdo;
            } else {
                anterior = atual;
                atual = atual->direito;
            }
        } else if(tipoArvore == 3){
            if(paciente->cadastro->mes <= atual->paciente->cadastro->mes){
                anterior = atual;
                atual = atual->esquerdo;
            } else {
                anterior = atual;
                atual = atual->direito;
            }
        } else if(tipoArvore == 4){
            if(paciente->cadastro->ano <= atual->paciente->cadastro->ano){
                anterior = atual;
                atual = atual->esquerdo;
            } else {
                anterior = atual;
                atual = atual->direito;
            }
        }
    }
    return anterior;
}

void inserirNaArvore(Arvore *arvore, Paciente *paciente, int tipoArvore){
    EArvore *novo = criaEArvore(paciente);
    if(arvore->raiz = NULL){
        arvore->raiz = novo;
    } else {
        EArvore *posicao = balanceamento(arvore, paciente, tipoArvore);
        if (tipoArvore == 1) {
            if (paciente->idade <= posicao->paciente->idade) {
                posicao->esquerdo = novo;
            } else {
                posicao->direito = novo;
            }
        } else if (tipoArvore == 2) {
            if (paciente->cadastro->dia <= posicao->paciente->cadastro->dia) {
                posicao->esquerdo = novo;
            } else {
                posicao->direito = novo;
            }
        } else if (tipoArvore == 3) {
            if (paciente->cadastro->mes <= posicao->paciente->cadastro->mes) {
                posicao->esquerdo = novo;
            } else {
                posicao->direito = novo;
            }
        } else if (tipoArvore == 4) {
            if (paciente->cadastro->ano <= posicao->paciente->cadastro->ano) {
                posicao->esquerdo = novo;
            } else {
                posicao->direito = novo;
            }
        }
    }
    arvore->quantidade++;
}