#include  <stdio.h>  
#include <stdlib.h> 
#include "ArvoreBin.h"  
#include "Lib.h"  

// cria um nó da árvore com um paciente
EArvore *criaEArvore(Paciente *paciente){
    EArvore *celula = malloc(sizeof(EArvore));  // aloca memória para a célula
    celula->paciente = paciente;  // associa o paciente à célula
    celula->direito = NULL;  // inicializa o ponteiro direito como NULL
    celula->esquerdo = NULL;  // inicializa o ponteiro esquerdo como NULL

    return celula;  // retorna a célula criada
}

// cria a árvore binária e inicializa suas variáveis
Arvore *criaArvore(){
    Arvore *arvore = malloc(sizeof(Arvore));  // aloca memória para a árvore
    arvore->altura = 0;  // define a altura inicial como 0
    arvore->quantidade = 0;  // define a quantidade de nós como 0
    arvore->raiz = NULL;  // define a raiz como NULL

    return arvore;  // retorna a árvore criada
}

// exibe os dados do paciente de um nó da árvore
void visitarEArvore(EArvore *celula){
    if(celula != NULL){  // verifica se a célula não é NULL
        Paciente *paciente = celula->paciente;  // obtém o paciente
        // imprime os dados do paciente
        printf("Nome: %s\n Idade: %d\n RG: %s\n Data de Cadastro: %02d/%02d/%d\n",
               paciente->nome, paciente->idade, paciente->RG, 
               paciente->cadastro->dia, paciente->cadastro->mes, paciente->cadastro->ano);
    }
}

// percorre a árvore em ordem e exibe os dados de todos os pacientes
void mostrarEmOrdem(EArvore *raiz){
    if (raiz != NULL) {
        mostrarEmOrdem(raiz->esquerdo);  // percorre a subárvore esquerda
        visitarEArvore(raiz);  // visita o nó atual
        mostrarEmOrdem(raiz->direito);  // percorre a subárvore direita
    }
}

// encontra a posição adequada para inserir um novo nó na árvore, com base no tipo de ordenação
EArvore *balanceamento(Arvore *arvore, Paciente *paciente, int tipoArvore){
    EArvore *anterior = NULL;  // armazena o nó anterior
    EArvore *atual = arvore->raiz;  // começa da raiz

    while(atual != NULL){  // percorre a árvore até encontrar a posição
        // dependendo do tipo da árvore, a comparação é feita com diferentes critérios (idade, dia, mês, ano)
        if(tipoArvore == 1){  // ordenação por idade
            if(paciente->idade <= atual->paciente->idade){
                anterior = atual;
                atual = atual->esquerdo;
            } else {
                anterior = atual;
                atual = atual->direito;
            }
        } else if(tipoArvore == 2){  // ordenação por dia de cadastro
            if(paciente->cadastro->dia <= atual->paciente->cadastro->dia){
                anterior = atual;
                atual = atual->esquerdo;
            } else {
                anterior = atual;
                atual = atual->direito;
            }
        } else if(tipoArvore == 3){  // ordenação por mês de cadastro
            if(paciente->cadastro->mes <= atual->paciente->cadastro->mes){
                anterior = atual;
                atual = atual->esquerdo;
            } else {
                anterior = atual;
                atual = atual->direito;
            }
        } else if(tipoArvore == 4){  // ordenação por ano de cadastro
            if(paciente->cadastro->ano <= atual->paciente->cadastro->ano){
                anterior = atual;
                atual = atual->esquerdo;
            } else {
                anterior = atual;
                atual = atual->direito;
            }
        }
    }
    return anterior;  // retorna o nó onde o paciente deve ser inserido
}

// insere um novo paciente na árvore, balanceando a árvore de acordo com o critério especificado
void inserirNaArvore(Arvore *arvore, Paciente *paciente, int tipoArvore){
    EArvore *novo = criaEArvore(paciente);  // cria o novo nó
    if(arvore->raiz == NULL){  // se a árvore estiver vazia
        arvore->raiz = novo;  // a nova célula se torna a raiz
    } else {
        EArvore *posicao = balanceamento(arvore, paciente, tipoArvore);  // encontra a posição correta para o novo nó
        // insere o novo nó dependendo do critério de ordenação
        if (tipoArvore == 1) {  // ordenação por idade
            if (paciente->idade <= posicao->paciente->idade) {
                posicao->esquerdo = novo;  // insere à esquerda
            } else {
                posicao->direito = novo;  // insere à direita
            }
        } else if (tipoArvore == 2) {  // ordenação por dia de cadastro
            if (paciente->cadastro->dia <= posicao->paciente->cadastro->dia) {
                posicao->esquerdo = novo;  // insere à esquerda
            } else {
                posicao->direito = novo;  // insere à direita
            }
        } else if (tipoArvore == 3) {  // ordenação por mês de cadastro
            if (paciente->cadastro->mes <= posicao->paciente->cadastro->mes) {
                posicao->esquerdo = novo;  // insere à esquerda
            } else {
                posicao->direito = novo;  // insere à direita
            }
        } else if (tipoArvore == 4) {  // ordenação por ano de cadastro
            if (paciente->cadastro->ano <= posicao->paciente->cadastro->ano) {
                posicao->esquerdo = novo;  // insere à esquerda
            } else {
                posicao->direito = novo;  // insere à direita
            }
        }
    }
    arvore->quantidade++;  // incrementa a quantidade de pacientes na árvore
}
