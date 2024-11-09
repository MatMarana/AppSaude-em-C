#include <stdio.h>
#include <stdlib.h>
#include "Lib.h"
#include "ListaEncadeada.h"

Lista criaLista(){
    Lista *lista = malloc(sizeof(Lista));
    lista->quantidade = 0;
    lista->primeiro = NULL;
    return *lista;
}
