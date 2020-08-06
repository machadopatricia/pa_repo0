#ifndef PilhaDinamica_h
#define PilhaDinamica_h

typedef struct nodoPilha
{
    int reg;
    struct nodoPilha * prox;
} nodoPilha;

typedef struct Pilha
{
    int tamPilha;
    nodoPilha * top;
} Pilha;

Pilha * criaPilha();

int vaziaPilha(Pilha *pPilha);

int cheiaPilha(Pilha * pPilha);

void pushPilha(Pilha *pPilha, int N);

int popPilha(Pilha *pPilha);

void apagaPilha(Pilha * pPilha);

#endif //PilhaDinamica_h
