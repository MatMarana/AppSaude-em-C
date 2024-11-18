#include <stdio.h>  
#include <stdlib.h> 
#include "Lib.h"  
#include "Fila.h"  

// cria um novo nó (célula) para a fila com um paciente
Efila *criaEfila(Paciente *paciente){ 
    Efila *celula = malloc(sizeof(Efila));  // aloca memória para a célula
    celula->paciente = paciente;  // associa o paciente à célula
    celula->proximo = NULL;  // inicializa o ponteiro para o próximo nó como NULL
    return celula;  // retorna a célula criada
}

// cria e inicializa uma fila vazia
Fila *criarFila(){ 
    Fila *fila = malloc(sizeof(Fila));  // aloca memória para a fila
    fila->head = NULL;  // inicializa o ponteiro da cabeça da fila como NULL
    fila->tail = NULL;  // inicializa o ponteiro da cauda da fila como NULL
    fila->quantidade = 0;  // define a quantidade de elementos na fila como 0
    return fila;  // retorna a fila criada
}

// adiciona um paciente na fila (enfileira)
void enfileirarPaciente(Fila *fila, Paciente *paciente){ 
    Efila *nova = criaEfila(paciente);  // cria um novo nó para o paciente
    if(fila->quantidade == 0){  // se a fila estiver vazia
        fila->head = nova;  // o novo nó é a cabeça e cauda da fila
        fila->tail = nova;
    } else {  // se a fila não estiver vazia
        Efila *atual = fila->tail;  // obtém o último nó (cauda)
        atual->proximo = nova;  // conecta o último nó ao novo nó
        fila->tail = nova;  // o novo nó se torna a cauda da fila
    }
    fila->quantidade++;  // incrementa a quantidade de elementos na fila
}

// remove um paciente da fila (desenfileira) e retorna o paciente removido
Paciente *desenfileirarPaciente(Fila *fila){ 
    if(fila->quantidade != 0){  // se a fila não estiver vazia
        Efila *atual = fila->head;  // obtém o primeiro nó (cabeça)
        if(fila->quantidade == 1){  // se houver apenas um elemento na fila
            fila->head = NULL;  // a fila fica vazia
            fila->tail = NULL;
        } else {  // se houver mais de um elemento
            fila->head = atual->proximo;  // a cabeça da fila passa a ser o próximo nó
        }
        free(atual);  // libera a memória do nó removido
        fila->quantidade--;  // decrementa a quantidade de elementos na fila
        return atual->paciente;  // retorna o paciente removido
    }
    return NULL;  // caso a fila esteja vazia, retorna NULL
}

// exibe os dados de todos os pacientes na fila
void mostrarFila(Fila *fila){
    Efila *atual = fila->head;  // começa da cabeça da fila
    while(atual != NULL){  // enquanto houver elementos na fila
        // imprime os dados do paciente
        printf("Nome: %s\n", atual->paciente->nome); 
        printf("RG: %s\n", atual->paciente->RG); 
        printf("Idade: %d\n", atual->paciente->idade); 
        printf("Data de Registro: %d/%d/%d\n", atual->paciente->cadastro->dia, 
               atual->paciente->cadastro->mes, atual->paciente->cadastro->ano);
        atual = atual->proximo;  // passa para o próximo nó da fila
    }
    printf("\n");  // adiciona uma linha em branco após a exibição da fila
}
