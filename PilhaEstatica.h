#ifndef PilhaDinamica_h
#define PilhaDinamica_h

typedef struct
{
    int top;
    int vetor[2010];
}Pilha;

Pilha * criaPilha();

int vaziaPilha(Pilha * pPilha);

int cheiaPilha(Pilha * pPilha);

void pushPilha(Pilha * pPilha, int N);

int popPilha(Pilha * pPilha);

void apagaPilha(Pilha * pPilha);

#endif //PilhaEstatica_h
