#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstatica.h"

//não preciso de um tamanhoPilha na estatica, pois o top guarda esse tamanho

Pilha * criaPilha(int cap)
{
    Pilha * pPilha = (Pilha*)malloc(sizeof(Pilha));

    pPilha->top = -1;

    return pPilha;
}

int vaziaPilha(Pilha * pPilha)
{
    return pPilha->top == -1;
}

int cheiaPilha(Pilha * pPilha)
{
    return pPilha->top == 1999;
}

void pushPilha(Pilha * pPilha, int N)
{
    pPilha->vetor[++(pPilha->top)] = N;
}

int popPilha(Pilha * pPilha)
{
    return pPilha->vetor[(pPilha->top)--];
}

void apagaPilha(Pilha * pPilha)
{
    free(pPilha);
}
