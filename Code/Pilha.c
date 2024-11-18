#include <stdio.h>  
#include <stdlib.h>  
#include <string.h> 
#include "Lib.h" 
#include "Pilha.h" 

// cria um novo nó (célula) para a pilha com um paciente e uma ação
EPilha *criarEPilha(int verificaAcao, Paciente *paciente){
    EPilha *celula = malloc(sizeof(EPilha));  // aloca memória para o nó
    celula->verificaAcao = verificaAcao;  // armazena a ação a ser realizada
    celula->paciente = paciente;  // associa o paciente ao nó
    celula->proximo = NULL;  // inicializa o ponteiro para o próximo nó como NULL
    return celula;  // retorna o nó criado
}

// cria e inicializa uma pilha vazia
Pilha *criarPilha(){
    Pilha *pilha = malloc(sizeof(Pilha));  // aloca memória para a pilha
    pilha->quantidade = 0;  // define a quantidade de elementos como 0
    pilha->topo = NULL;  // inicializa o ponteiro do topo da pilha como NULL
    return pilha;  // retorna a pilha criada
}

// empilha um novo elemento (paciente com ação) na pilha
void push(Pilha *pilha, int verificaAcao, Paciente *paciente){
    EPilha *nova = criarEPilha(verificaAcao, paciente);  // cria um novo nó
    if(pilha->quantidade == 0){  // se a pilha estiver vazia
        pilha->topo = nova;  // o novo nó se torna o topo da pilha
    } else {  // se a pilha não estiver vazia
        EPilha *atual = pilha->topo;  // obtém o topo atual da pilha
        pilha->topo = nova;  // o novo nó se torna o topo da pilha
        nova->proximo = atual;  // conecta o novo nó ao antigo topo
    }
    pilha->quantidade++;  // incrementa a quantidade de elementos na pilha
}

// desempilha o topo da pilha, removendo o elemento
void pop(Pilha *pilha){
    EPilha *temp = pilha->topo;  // armazena o topo atual
    if(pilha->quantidade == 1){  // se a pilha tiver apenas um elemento
        pilha->topo = NULL;  // a pilha ficará vazia
    } else {  // se a pilha tiver mais de um elemento
        pilha->topo = temp->proximo;  // o topo é atualizado para o próximo nó
    }
    free(temp);  // libera a memória do nó desempilhado
    pilha->quantidade--;  // decrementa a quantidade de elementos na pilha
}

// imprime todos os elementos da pilha
void printPilha(Pilha *pilha){
    EPilha *atual = pilha->topo;  // começa pelo topo da pilha
    while(atual != NULL){  // percorre a pilha até o fim
        printf("%d", atual->verificaAcao);  // imprime a ação do nó atual
        atual = atual->proximo;  // passa para o próximo nó
    }
}
