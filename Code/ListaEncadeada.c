#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>  
#include "Lib.h" 
#include "ListaEncadeada.h"  

// cria um novo nó (célula) para a lista com um paciente
Elista *criaElista(Paciente *paciente){
    Elista *celula = malloc(sizeof(Elista));  // aloca memória para o nó
    celula->paciente = paciente;  // associa o paciente ao nó
    celula->proximo = NULL;  // inicializa o ponteiro para o próximo nó como NULL
    return celula;  // retorna o nó criado
}

// cria e inicializa uma lista vazia
Lista *criaLista(){
    Lista *lista = malloc(sizeof(Lista));  // aloca memória para a lista
    lista->quantidade = 0;  // define a quantidade de elementos como 0
    lista->primeiro = NULL;  // inicializa o ponteiro da cabeça da lista como NULL
    return lista;  // retorna a lista criada
}

// insere um novo paciente no início da lista
void inserirPaciente(Lista *lista, Paciente *paciente){
    Elista *nova = criaElista(paciente);  // cria um novo nó para o paciente
    if(lista->quantidade == 0){  // se a lista estiver vazia
        lista->primeiro = nova;  // o novo nó é o primeiro da lista
    } else {  // se a lista não estiver vazia
        Elista *atual = lista->primeiro;  // obtém o primeiro nó
        lista->primeiro = nova;  // o novo nó se torna o primeiro da lista
        nova->proximo = atual;  // conecta o novo nó ao antigo primeiro nó
    }
    lista->quantidade++;  // incrementa a quantidade de elementos na lista
}

// consulta um paciente na lista pelo RG
Paciente *consultarPaciente(Lista *lista, char *RG){ 
    Elista *atual = lista->primeiro;  // começa pelo primeiro nó
    while(atual != NULL){  // percorre a lista até o fim
        if(strcmp(atual->paciente->RG, RG) == 0){  // encontra o paciente pelo RG
            // imprime as informações do paciente
            printf("Paciente encontrado:\n"); 
            printf("Nome: %s\n", atual->paciente->nome); 
            printf("RG: %s\n", atual->paciente->RG); 
            printf("Idade: %d\n", atual->paciente->idade); 
            printf("Data de Registro: %d/%d/%d\n", 
                   atual->paciente->cadastro->dia, 
                   atual->paciente->cadastro->mes,
                   atual->paciente->cadastro->ano);
            return atual->paciente;  // retorna o paciente encontrado
        }
        atual = atual->proximo;  // passa para o próximo nó
    }
    return NULL;  // caso o paciente não seja encontrado, retorna NULL
}

// atualiza as informações de um paciente na lista pelo RG
void atualizarPaciente(Lista *lista, char *RG){
    Elista *atual = lista->primeiro;  // começa pelo primeiro nó
    while(atual->proximo != NULL && (strcmp(atual->paciente->RG, RG) == 0)){
        atual = atual->proximo;  // percorre a lista até encontrar o paciente
    }
    if(atual != NULL){  // se o paciente for encontrado
       int escolha; 
       // menu para selecionar a informação a ser atualizada
       printf("Digite o numero da informacao que deseja atualizar:\n"); 
       printf("1 - Nome\n"); 
       printf("2 - RG\n"); 
       printf("3 - Idade\n"); 
       printf("4 - Data de Registro\n"); 
       scanf("%d", &escolha);  // recebe a escolha do usuário
       // atualiza as informações de acordo com a escolha
       switch (escolha) { 
            case 1: 
                printf("Digite o novo nome: \n"); 
                scanf("%s", atual->paciente->nome);  // atualiza o nome
                break;
            case 2: 
                printf("Digite o novo RG: \n"); 
                scanf("%s", atual->paciente->RG);  // atualiza o RG
                break; 
            case 3: 
                printf("Digite a nova idade: \n"); 
                scanf("%d", &atual->paciente->idade);  // atualiza a idade
                break; 
            case 4: 
                printf("Digite o novo dia de registro: \n"); 
                scanf("%d", &atual->paciente->cadastro->dia);  // atualiza o dia de registro
                printf("Digite o novo mês de registro: \n"); 
                scanf("%d", &atual->paciente->cadastro->mes);  // atualiza o mês de registro
                printf("Digite o novo ano de registro: \n"); 
                scanf("%d", &atual->paciente->cadastro->ano);  // atualiza o ano de registro
                break; 
        } 
       printf("Informacoes do paciente atualizadas com sucesso.\n");
    }
}

// exibe todos os pacientes na lista
void mostrarLista(Lista *lista){
    Elista *atual = lista->primeiro;  // começa pelo primeiro nó
    if(lista->quantidade == 0){  // se a lista estiver vazia
        printf("Nao ha elementos na lista\n");
    } else {  // se houver elementos na lista
        while(atual != NULL){  // percorre a lista até o fim
            // imprime as informações do paciente
            printf("Nome: %s\n", atual->paciente->nome); 
            printf("RG: %s\n", atual->paciente->RG); 
            printf("Idade: %d\n", atual->paciente->idade); 
            printf("Data de Registro: %d/%d/%d\n", 
                   atual->paciente->cadastro->dia, 
                   atual->paciente->cadastro->mes,
                   atual->paciente->cadastro->ano);
            atual = atual->proximo;  // passa para o próximo nó
        }
        printf("\n");
    }
}

// remove um paciente da lista pelo RG
void removerPaciente(Lista *lista, char *RG){
    Elista *anterior = NULL;
    Elista *atual = lista->primeiro;  // começa pelo primeiro nó
    while(atual->proximo != NULL && strcmp(atual->paciente->RG, RG) == 0){
       anterior = atual;  // armazena o nó anterior
       atual = atual->proximo;  // passa para o próximo nó
    }
    if(atual != NULL){  // se o paciente for encontrado
        if(anterior == NULL){  // se for o primeiro da lista
            lista->primeiro = atual->proximo;  // o próximo nó se torna o primeiro
        } else {
            anterior->proximo = atual->proximo;  // remove o nó atual
        }
        lista->quantidade--;  // decrementa a quantidade de elementos na lista
    }
}

// salva os pacientes da lista em um arquivo binário
void salvarArquivo(Lista *lista, const char *nomeArquivo){ 
    FILE *file = fopen(nomeArquivo, "wb");  // abre o arquivo para escrita binária
    if(!file){
        printf("Erro de criacao de Arquivo\n");  // caso haja erro ao abrir o arquivo
        return;   
    }
    Elista *temp = lista->primeiro;  // começa pelo primeiro nó
    while(temp->proximo != NULL){  // percorre a lista até o fim
        fwrite(&temp->paciente, sizeof(Paciente), 1, file);  // escreve o paciente no arquivo
    }
    fclose(file);  // fecha o arquivo após a escrita
}

// lê os pacientes de um arquivo binário e os insere na lista
Lista lerArquivo(const char *nomeArquivo){ 
    FILE *file = fopen(nomeArquivo, "rb");  // abre o arquivo para leitura binária
    if(!file){
        printf("Erro ao abrir Arquivo\n");  // caso haja erro ao abrir o arquivo
    }
    Lista *lista = NULL;  // lista que será preenchida
    Paciente *paciente;
    while(fread(&paciente, sizeof(Paciente), 1, file)){  // lê os pacientes do arquivo
        inserirPaciente(lista, paciente);  // insere os pacientes na lista
    }
    fclose(file);  // fecha o arquivo após a leitura
    return *lista;  // retorna a lista preenchida
}
