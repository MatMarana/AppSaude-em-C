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

Data criaData(int dia, int mes, int ano);
Paciente criaPaciente(char *nome, int idade, char *RG);
void salvarArquivo();
void lerArquivo();

#endif