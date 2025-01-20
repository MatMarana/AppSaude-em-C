#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Lib.h"
#include "ListaEncadeada.h"
#include "Fila.h"
#include "Pilha.h"
#include "ArvoreBin.h"

int main(void) {
  int escolha; // cria a váriavel escolha
  int segundaEscolha; // cria a váriavel segunda escolha

  char nome[100]; // cria a variável nome
  char RG[15]; // cria a variável RG
  int idade; // cria a variável idade

  int dia; // cria a variável dia
  int mes; // cria a variável mes
  int ano; // cria a variável ano

   

  Lista *lista = criaLista(); // cria a lista
  Pilha *pilha = criarPilha(); // cria a pilha
  Fila *fila = criarFila(); // cria a fila
  Arvore *arvoreIdade = criaArvore(); // cria a arvore de idade
  Arvore *arvoreDia = criaArvore(); // cria a arvore de dia
  Arvore *arvoreMes = criaArvore(); // cria a arvore de mes
  Arvore *arvoreAno = criaArvore(); // cria a arvore de ano

  EPilha *atual = pilha->topo; // cria a variável operação, um elemento da Pilha


  do{ // incia o menu
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
    scanf("%d", &escolha); // lê a variável escolha

    switch (escolha){
    case 1: // se escolha for 1
      printf("Digite 1 - Cadastrar um Paciente\n");
      printf("Digite 2 - Consultar um Paciente\n");
      printf("Digite 3 - Atualizar um Paciente\n");
      printf("Digite 4 - Mostrar os Paciente Cadastrados\n");
      printf("Digite 5 - Remover um Paciente\n");
      scanf("%d", &segundaEscolha); // lê a variável segunda escolha
      if(segundaEscolha == 1){ // se segunda escolha for 1
        printf("Digite o nome do Paciente\n");
        scanf("%s", nome); // Lê o nome do paciente a ser cadastrado
        printf("Digite o RG do Paciente\n");
        scanf("%s", RG); // Lê o RG do paciente a ser cadastrado
        printf("Digite a idade do Paciente\n");
        scanf("%d", &idade); // Lê a idade do paciente a ser cadastrado

        printf("Digite o dia de hoje\n");
        scanf("%d", &dia); // Lê o dia do cadastro
        printf("Digite o mes atual\n");
        scanf("%d", &mes); // Lê o mes do cadastro
        printf("Digite o ano atual\n");
        scanf("%d", &ano); // Lê o ano do cadastro
        Paciente *paciente = criaPaciente(nome,idade,RG,dia,mes,ano); // cria o paciente com as informações digitadas
        inserirPaciente(lista,paciente); // insere o paciente na lista
        //inserirNaArvore(arvoreIdade,paciente,1); //insere o paciente na arvore de idade
        //inserirNaArvore(arvoreDia,paciente,2); //insere o paciente na arvore de dia
        //inserirNaArvore(arvoreMes,paciente,3); //insere o paciente na arvore de mes 
        //inserirNaArvore(arvoreAno,paciente,4); //insere o paciente na arvore de ano
      } else if (segundaEscolha ==  2){ // se segunda esolha for 2
        printf("Digite o RG do Paciente\n"); 
        scanf("%s", RG); // Lê o Rg do paciente

        consultarPaciente(lista,RG); //consulta o paciente pelo RG
      } else if (segundaEscolha == 3){ // se a segunda escolha for 3
        printf("Digite o RG do Paciente\n");
        scanf("%s", RG); // Lê o Rg do paciente

        atualizarPaciente(lista,RG); // atualiza os dados do paciente
      } else if(segundaEscolha == 4){ // se a segunda escolha for 4
        mostrarLista(lista); // mostra a lista completa
      } else if(segundaEscolha == 5){ // se a segunda escolha for 5
        printf("Digite o RG do Paciente\n");
        scanf("%s", RG); // Lê o Rg do paciente

        removerPaciente(lista,RG); // remove o paciente da lista
      } else {
        printf("Escolha invalida, tente novamente\n");
      }
      break;
    case 2: // se a escolha for 2
      printf("Digite 1 - Adicionar um Paciente a Fila\n");
      printf("Digite 2 - Remover um Paciente da Fila\n");
      printf("Digite 3 - Mostrar os Paciente na Fila\n");
      scanf("%d", &segundaEscolha); // le a segunda escolha
      if(segundaEscolha == 1){ // se a segunda escolha for 1
        printf("Digite o RG do Paciente\n");
        scanf("%s", RG); // Lê o Rg do paciente
        Paciente *paciente = consultarPaciente(lista, RG); // busca o paciente pelo RG

        push(pilha, 0,paciente);
        enfileirarPaciente(fila, paciente); // adiciona o paciente na fila
      } else if (segundaEscolha == 2){ // se a segunda escolha for 2
        Paciente *paciente  = desenfileirarPaciente(fila); //remove o paciente da fila
        push(pilha, 1, paciente); // adiciona paciente na pilha
      } else if(segundaEscolha == 3){ // se a segunda escolha for 3
        mostrarFila(fila); // mostra a fila
      } else {
        printf("Escolha invalida, tente novamente\n");
      }
      break;
    case 3:
      printf("Digite 1 - Ordenar por Idade\n");
      printf("Digite 2 - Ordenar por Dia\n");
      printf("Digite 3 - Ordenar por Mes\n");
      printf("Digite 4 - Ordenar por Ano\n");
      scanf("%d", &segundaEscolha);
      if(segundaEscolha == 1){
        mostrarEmOrdem(arvoreIdade->raiz);
      } else if(segundaEscolha == 2){
        mostrarEmOrdem(arvoreDia->raiz);
      } else if(segundaEscolha == 3){
        mostrarEmOrdem(arvoreMes->raiz);
      }else if(segundaEscolha == 4){
        mostrarEmOrdem(arvoreAno->raiz);
      }
      break;  
    case 4:
      if(atual->verificaAcao == 0){
        desenfileirarPaciente(fila);
      } else if(atual->verificaAcao == 1){
        enfileirarPaciente(fila,atual->paciente);
      }
      pop(pilha);
      break;
    case 5:
      printf("Digite 1 - Salvar os Pacientes em um Aquivo\n");
      printf("Digite 2 - Ler um Arquivo de Pacientes\n");
      scanf("%d", &segundaEscolha); //Le a segunda escolha
      if(segundaEscolha == 1){ // se for 1
        salvarArquivo(lista, "Arquivo"); // salva o arquivo
      } else if(segundaEscolha == 2){ //  se for 2
        lerArquivo("Arquivo"); // le o arquivo salvo
      }
      break;
    case 6: // se a escolha for 6
      printf("Nome dos integrantes: Isabella Benevenuto e Mateus Marana\n");
      printf("Cilco: 4 Semestre\n");
      printf("Curso: Ciencia da Computacao\n");
      printf("Disciplina: Estrutura de Dados\n");
      printf("Data: 14/11/2024\n");
      break;
    }
  }while(escolha != 0); // só sai do loop quando a escolha for 0

  return 0;
}