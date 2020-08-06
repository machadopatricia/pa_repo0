#include <stdio.h>
#include <stdlib.h>
#include "PilhaDinamica.h"

Pilha * criaPilha()
{
    Pilha * pPilha = (Pilha*)malloc(sizeof(Pilha));
    pPilha->top = NULL;
    pPilha->tamPilha = 0;

    return pPilha;
}

int vaziaPilha(Pilha * pPilha)
{
    return pPilha->top == NULL;
}

int cheiaPilha(Pilha * pPilha)
{
    if(pPilha->tamPilha < 2000)
        return 0;
    else
        return 1;
}

void pushPilha(Pilha * pPilha, int N)
{
    if(vaziaPilha(pPilha))
    {
        pPilha->top = (nodoPilha*)malloc(sizeof(nodoPilha));

        pPilha->top->reg = N;
        pPilha->top->prox = NULL;

        pPilha->tamPilha++;
    }
    else
    {
        nodoPilha * aux = (nodoPilha*)malloc(sizeof(nodoPilha));

        aux->reg = N;
        aux->prox = pPilha->top;
        pPilha->top = aux;

        pPilha->tamPilha++;
    }
}

int popPilha(Pilha * pPilha)
{
    int aux = pPilha->top->reg;

    nodoPilha * prox = pPilha->top->prox;
    free(pPilha->top);
    pPilha->top = prox;

    pPilha->tamPilha--;

    return aux;
}

void apagaPilha(Pilha * pPilha)
{
    while(pPilha->top != NULL)
    {
        nodoPilha * aux = pPilha->top;
        pPilha->top = pPilha->top->prox;
        aux->prox = NULL;
        free(aux);
    }
}
