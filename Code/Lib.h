#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED


typedef struct Data{
  int dia;
  int mes;
  int ano;
}Data;

typedef struct Paciente{
  char nome[50];
  int idade;
  char RG[15];
  Data *cadastro;
}Paciente;

Data *criaData(int dia, int mes, int ano);
Paciente *criaPaciente(char *nome, int idade, char *RG, int dia, int mes, int ano);

void salvarArquivo(Lista *lista, const char *nomeArquivo);
void lerArquivo(const char *nomeArquivo);

void menuPaciente(Lista *lista);

#endif