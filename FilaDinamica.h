#ifndef FilaDinamica_h
#define FilaDinamica_h

typedef struct nodoFila
{
    char nome[25];
    int reg;
    struct nodoFila * prox;
} nodoFila;

typedef struct
{
    int tamFila;
    nodoFila * inicio, *fim;
} Fila;

Fila * criaFila();

int vaziaFila(Fila * f);

int cheiaFila(Fila * f);

int tamFila(Fila * f);

char * nomeFila(Fila * f);

void pushFila(Fila * f, char nome[25], int x);

int popFila(Fila * f);

void apagaFila(Fila * f);

#endif //FilaDinamica_h
