#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaEstatica.h"

Fila * criaFila()
{
    Fila * f = (Fila*)malloc(sizeof(Fila));
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;

    return f;
}

int vaziaFila(Fila * f)
{
    if(tamFila(f) == 0)
        return 1;
    else return 0;
}

int cheiaFila(Fila * f)
{
    if(tamFila(f) == 20)
        return 1;
    else return 0;
}

int tamFila(Fila * f)
{
    return f->tamanho;
}

char * nomeFila(Fila * f)
{
    return f->nome[f->inicio];
}

void pushFila(Fila * f, char nome[25], int x)
{
    f->v[f->fim] = x;
    strcpy(f->nome[f->fim], nome);
    f->fim = (f->fim + 1) % 20;

    f->tamanho++;
}

int popFila(Fila * f)
{
    int x = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % 20;

    f->tamanho--;

    return x;
}

void apagaFila(Fila * f)
{
    free(f);
}
