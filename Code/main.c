#include <stdio.h>

#include "Lib.h"
#include "ListaEncadeada.h"
#include "Fila.h"
#include "Pilha.h"
#include "ArvoreBin.h"

int main(void) {
  int escolha;
  
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
    printf("5 - Salvar / Ler Arquivo\n");
    printf("6 - Sobre\n");
    printf("0 - SAIR\n");
    printf("-----------------------\n");
    scanf('&d' , escolha);

    switch (escolha){
    case 1:
      break;
    case 2:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      prinf("Nome dos integrantes: Isabella Benevenuto e Mateus Marana\n");
      printf("Cilco: 4 Semestre\n");
      printf("Curso: Ciencia da Computacao\n");
      prinf("Disciplina: Estrutura de Dados\n");
      printf("Data: 14/11/2024\n");
      break;
    }
  }while(escolha != 0);
  
  return 0;
}