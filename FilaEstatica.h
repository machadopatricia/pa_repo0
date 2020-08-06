#ifndef FilaEstatica_h
#define FilaEstatica_h

typedef struct
{
    int v[20];
    char nome[20][25];
    int inicio;
    int fim;
    int tamanho;
}Fila;

Fila * criaFila();

int vaziaFila(Fila * f);

int cheiaFila(Fila * f);

int tamFila(Fila * f);

char * nomeFila(Fila * f);

void pushFila(Fila * f, char nome[25], int x);

int popFila(Fila * f);

void apagaFila(Fila * f);

#endif //FilaEstatica_h
