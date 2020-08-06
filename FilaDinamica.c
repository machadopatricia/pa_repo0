#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaDinamica.h"

Fila * criaFila()
{
    Fila * f = (Fila*)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    f->tamFila = 0;

    return f;
}

int vaziaFila(Fila * f)
{
    if(f->inicio == NULL)
        return 1;
    else
        return 0;
}

int cheiaFila(Fila * f)
{
    if(tamFila(f) < 20)
        return 0;
    else
        return 1;
}

int tamFila(Fila * f)
{
    return f->tamFila;
}

char * nomeFila(Fila * f)
{
    return f->inicio->nome;
}

void pushFila(Fila * f, char nome[25], int x)
{
    nodoFila * novo = (nodoFila*)malloc(sizeof(nodoFila));
    novo->reg = x;
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if(f->fim != NULL)
        f->fim->prox = novo;

    f->fim = novo;

    if(f->inicio == NULL)
        f->inicio = novo;

    f->tamFila++;
}

int popFila(Fila * f)
{
    int x = f->inicio->reg;
    nodoFila * prox = f->inicio->prox;
    free(f->inicio);
    f->inicio = prox;

    if(f->inicio == NULL)
        f->fim = NULL;

    f->tamFila--;

    return x;
}

void apagaFila(Fila * f)
{
    while(f->inicio != NULL)
    {
        nodoFila * aux = f->inicio->prox;
        free(f->inicio);
        f->inicio = aux;
    }
}
