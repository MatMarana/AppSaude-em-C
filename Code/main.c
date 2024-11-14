#include <stdio.h>

#include "Lib.h"
#include "ListaEncadeada.h"
#include "Fila.h"
#include "Pilha.h"
#include "ArvoreBin.h"

int main(void) {
  int escolha;
  int segundaEscolha;

  char nome;
  char RG;
  int idade;
  int dia;
  int mes;
  int ano;

  Lista *lista = criaLista();
  Pilha *pilha = criaPilha();
  Fila *fila = criaFila();

  do{
    printf("----------------------\n");
    printf("Digite a opcao desejada\n");
    printf("1 - Acessar os Pacientes\n");
    printf("2 - Antendimento\n");
    printf("3 - Filtar os Pacientes\n");
    printf("4 - Desfazer a Ultima Acao\n");
    printf("0 - SAIR\n");
    printf("-----------------------\n");
    scanf('&d' , escolha);

    switch (escolha){
    case 1:
      menuPaciente(lista);
      break;
    case 2:
      break;
    default:
      break;
    }
  }while(escolha != 0);
  
  return 0;
}